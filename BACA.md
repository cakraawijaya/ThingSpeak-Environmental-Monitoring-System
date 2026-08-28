[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/ThingSpeak-Environmental-Monitoring-System?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# ThingSpeak Environmental Monitoring System
Sistem pemantauan lingkungan — memantau suhu, kelembapan, dan intensitas cahaya dengan pencatatan data berbasis cloud serta visualisasi dasbor secara real-time melalui ThingSpeak.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | DOIT ESP32 DEVKIT V1 |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Driver | CP210X USB Driver |
| Platform IoT | ThingSpeak |
| Protokol Komunikasi | Hypertext Transfer Protocol (HTTP) |
| Arsitektur IoT | 3 Lapisan |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • WiFi (bawaan)<br>• DHT sensor library oleh Adafruit (Versi: 1.4.6)<br>• ThingSpeak oleh MathWorks (Versi: 2.1.1) |
| Sensor | • DHT11: Suhu & Kelembapan Udara (x1)<br>• Modul Sensor LDR (x1) |
| Komponen Lainnya | • Kabel USB Mikro - USB tipe A (x1)<br>• Papan ekspansi ESP32 (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Kabel jumper (1 set) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. CP210X USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CP210X_USBdriver
   ```

   </td></tr></table>
   
<br><br>

## Rancangan Proyek

<table>
<tr>
<th width="840">Arsitektur</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Desain Perangkat Lunak</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Flowchart Firmware.jpg" alt="flowchart"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Diagram Ilustrasi</th>
<th width="420">Diagram Blok</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      ``` Code.ino ```
         
   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```
         
   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` DOIT ESP32 DEVKIT V1 ```
            
      </th></tr>
      <tr><td width="810">
         
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp32 ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```
         
   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">

      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```
         
   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```
         
   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>
    
10. Beberapa hal yang perlu anda lakukan saat menggunakan ``` board ESP32 ``` :

    <table><tr><td width="810">
       
       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara total -> Tekan tombol ``` EN (RST) ``` -> ``` Restart ```.

       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara otomatis maka :<br>

      - Ketika informasi: ``` Uploading... ``` telah muncul -> segera tekan dan tahan tombol ``` BOOT ```.<br>

      - Ketika informasi: ``` Writing at .... (%) ``` telah muncul -> lepaskan tombol ``` BOOT ```.

       • Jika pesan: ``` Done Uploading ``` telah muncul -> ``` Program yang diisikan tadi sudah bisa dioperasikan ```.

       • Jangan tekan tombol ``` BOOT ``` dan ``` EN ``` secara bersamaan karena hal ini bisa beralih ke mode ``` Unggah Firmware ```.

    </td></tr></table><br>

11. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan ThingSpeak
1. Memulai ThingSpeak : 

   <table><tr><td width="810">
   
      • Silakan <a href="https://thingspeak.com/login">Masuk</a> agar dapat mengakses layanan ThingSpeak.
      
      • Jika anda belum memiliki akun ThingSpeak, silakan buat dulu.

   </td></tr></table><br>

2. Membuat channel : 

   <table><tr><td width="810">
   
      • Setelah masuk ke dalam akun -> klik ``` New Channel ```.
   
      • Isi form sesuai dengan kebutuhan anda.
   
      • Klik ``` Save Channel ```.
   
      • Klik ``` Sharing ``` -> pada bagian ``` Channel Sharing Settings ```, silakan pilih -> ``` Keep channel view private ```.

   </td></tr></table><br>

3. Membuat visualization :

   <table><tr><td width="810">

      • Pastikan anda berada di menu ``` Channel ``` -> bagian ``` Private View ```.
   
      • Klik ``` + Add Visualization ```.
   
      • Klik ``` Field Chart ``` -> kemudian pilih ``` Save ```.
   
      • Jika ingin mengubah isi visualisasi, silakan klik ``` Field Chart Option ``` -> kemudian pilih ``` Save ``` untuk menyimpan.

   </td></tr></table><br>

4. Konfigurasi firmware : 

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Channel ``` -> bagian ``` Private View ``` section.
   
      • Salin ``` Channel ID ``` -> tempelkan pada kode firmware. Contohnya :
   
      <table><tr><td width="780">

      ```ino
      unsigned long myChannelNumber = '1504372'; // ID Channel ThingSpeak
      ```

      </td></tr></table>
   
      • Silakan beralih ke bagian ``` API Keys ``` -> tempelkan pada kode firmware. Contohnya :
   
      <table><tr><td width="780">

      ```ino
      const char* myWriteAPIKey = "TF3UPJK9O1QA5FAU"; // Apikey ThingSpeak
      ```

      </td></tr></table>

   </td></tr></table>

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
    
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan

<table>
<tr>
<th width="840" colspan="4">Perangkat</th>
</tr>
<tr>
<th width="420" colspan="2">Sensor DHT11</th>
<th width="420" colspan="2">Sensor LDR</th>
</tr>
<tr>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/DHT11 Sensor/Device.jpg" alt="device"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/DHT11 Sensor/Serial Monitor.jpg" alt="serial-monitor"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/LDR Sensor/Device.jpg" alt="device"></td>
<td width="210" align="center"><img src="Assets/Documentation/Experiment/LDR Sensor/Serial Monitor.jpg" alt="serial-monitor"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Dasbor ThingSpeak</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/ThingSpeak Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>

<br>
<strong>Informasi lebih lanjut:</strong> <a href="https://github.com/cakraawijaya/ThingSpeak-Environmental-Monitoring-System/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-2-13.pdf"><u>Click Here</u></a>

<br><br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil pengembangan dari Bootcamp Edutic.id x BNSP 2026. Saya tidak memungkiri bahwa saya masih menggunakan layanan pihak ketiga dalam pengerjaan ini, antara lain: library, framework, dan lain sebagainya.
