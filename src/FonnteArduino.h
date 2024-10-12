#ifndef FONNTE_ARDUINO_H
#define FONNTE_ARDUINO_H

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClientSecureBearSSL.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <HTTPClient.h>
#endif

class FonnteArduino {
  private:
    String apiToken;
    const char* ssid;
    const char* password;
    const char* serverName = "https://api.fonnte.com/send"; // API URL
    String countryCode = "62"; // Default country code for Indonesia

  public:
    // Constructor untuk inisialisasi token
    FonnteArduino(const char* token);

    // Fungsi untuk menghubungkan ke WiFi dengan parameter ssid dan password
    void connectToWiFi(const char* ssid, const char* password);

    // Fungsi untuk mengirim pesan melalui API Fonnte
    void sendMessage(const String& target, const String& message);

    // Fungsi untuk mengirim pesan dengan delay
    void sendMessageWithDelay(const String& target, const String& message, unsigned long delayTime);

    // Fungsi untuk mengubah kode negara
    void setCountryCode(const String& newCountryCode);

    // Fungsi untuk mendapatkan country code saat ini
    String getCountryCode() const;
};

#endif