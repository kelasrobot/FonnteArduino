# FonnteArduino

**FonnteArduino** adalah library Arduino yang memudahkan pengiriman pesan WhatsApp melalui API Fonnte menggunakan ESP32 atau ESP8266. Library ini memungkinkan Anda untuk menghubungkan perangkat ke jaringan WiFi, mengonfigurasi token API Anda, dan mengirim pesan dengan mudah melalui platform Fonnte. Library ini ideal digunakan untuk aplikasi IoT yang memerlukan notifikasi atau peringatan langsung melalui WhatsApp.

## Fitur

- Menghubungkan ke jaringan WiFi dengan ESP32 atau ESP8266
- Mengirim pesan WhatsApp melalui Fonnte API
- Konfigurasi kode negara yang dapat disesuaikan
- Mendukung pengiriman pesan dengan atau tanpa delay

## Cara Mendapatkan Token Fonnte

Untuk menggunakan API Fonnte, Anda perlu mendaftar dan mendapatkan token. Anda bisa mendaftar melalui link berikut:  
[Daftar Fonnte](https://bit.ly/daftar-fonnte)

## Instalasi

1. **Unduh atau Clone Repository ini**:  
   Anda bisa mengunduh file `.zip` atau melakukan clone repository ini ke komputer Anda.

2. **Install Library melalui Arduino IDE**:  
   - Buka Arduino IDE
   - Pilih **Sketch** > **Include Library** > **Add .ZIP Library**
   - Pilih file `.zip` dari library **FonnteArduino** yang sudah diunduh.

3. **Gunakan Library**:  
   Setelah library terinstal, Anda dapat langsung menggunakan **FonnteArduino** di sketch Arduino Anda.

## Contoh Penggunaan

Berikut adalah contoh penggunaan sederhana library ini:

```cpp
#include <FonnteArduino.h>

// Inisialisasi objek FonnteArduino dengan token API Anda
FonnteArduino fonnte("YOUR_FONNTE_TOKEN");

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke WiFi
  fonnte.connectToWiFi("SSID", "PASSWORD");

  // Mengirim pesan WhatsApp
  fonnte.sendMessage("08123456789", "Hello, ini pesan dari ESP32!");
}

void loop() {
  // Tidak ada aktivitas di loop
}
```

## Fitur Tambahan

1. **Mengirim Pesan dengan Delay**  
   Anda bisa mengirim pesan dengan delay menggunakan fungsi `sendMessageWithDelay()`. Contoh:
   ```cpp
   fonnte.sendMessageWithDelay("08123456789", "Pesan dengan delay", 5000); // Delay 5 detik
   ```

2. **Mengubah Kode Negara**  
   Secara default, kode negara adalah "62" (Indonesia), tetapi Anda bisa mengubahnya menggunakan fungsi `setCountryCode()`. Contoh:
   ```cpp
   fonnte.setCountryCode("1"); // Mengubah kode negara menjadi USA (1)
   ```

## Uji Coba

- Library ini sudah berhasil diuji di **ESP32** dengan Library Board versi **2.0.17**.
- Library ini juga berhasil diuji di **ESP8266** dengan Library Board versi **2.7.4**.

## Lisensi

Library ini dirilis di bawah lisensi MIT. Silakan lihat file [LICENSE](./LICENSE) untuk detail lebih lanjut.
