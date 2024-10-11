#ifndef FONNTE_ARDUINO_H
#define FONNTE_ARDUINO_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class FonnteArduino {
  private:
    const char* token;
    const char* serverName = "https://api.fonnte.com/send"; // URL API Fonnte
    String countryCode = "62"; // Default country code Indonesia

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
