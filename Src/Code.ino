#include <WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"

#define DHTPIN 26
#define DHTTYPE DHT11
#define LDR_PIN 34

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

unsigned long myChannelNumber = ID_CHANNEL_THINGSPEAK;
const char* myWriteAPIKey = "YOUR_API_KEY";

const float GAMMA = 0.7;
const float RL10 = 50;

unsigned long lastTime = 0;
unsigned long timerDelay = 30000;


void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.mode(WIFI_STA);
  connectToWiFi();

  ThingSpeak.begin(client);
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() != WL_CONNECTED) {
      connectToWiFi();
    }

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    int analogValue = analogRead(LDR_PIN);

    float voltage = analogValue / 4095.0 * 3.3;
    float resistance = 2000 * voltage / (1 - voltage / 3.3);
    float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

    Serial.println("Temp: " + String(temperature, 2) + "°C");
    Serial.println("Humidity: " + String(humidity, 1) + "%");
    Serial.println("LDR Analog Value : " + String(analogValue));
    Serial.println("LDR Voltage : " + String(voltage, 2) + " volts");
    Serial.println("LDR Resistance : " + String(resistance, 2) + " Ohms");
    Serial.println("LDR Illuminance: " + String(lux, 2) + " lux");
    Serial.println("---");

    ThingSpeak.setField(1, temperature);
    ThingSpeak.setField(2, humidity);
    ThingSpeak.setField(3, lux);

    int responseCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

    if (responseCode == 200) {
      Serial.println("Channel update successful.");
    } else {
      Serial.println("Problem updating channel. HTTP error code: " + String(responseCode));
    }
    lastTime = millis();
  }
}

void connectToWiFi() {
  Serial.print("Attempting to connect to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConnected to WiFi.");
}
