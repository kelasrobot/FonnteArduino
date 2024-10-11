#include "FonnteArduino.h"

// Constructor dengan token, serverName tetap, country code default "62"
FonnteArduino::FonnteArduino(const char* token) {
  this->token = token;
}

// Fungsi untuk koneksi ke WiFi dengan parameter ssid dan password
void FonnteArduino::connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

// Fungsi untuk mengirim pesan menggunakan API Fonnte
void FonnteArduino::sendMessage(const String& target, const String& message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Authorization", token); // Tambah Authorization header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Tambah Content-Type

    // Data POST dengan URL-encoded
    String postData = "target=" + target + "&message=" + message + "&countryCode=" + countryCode;

    // Kirim POST request
    int httpResponseCode = http.POST(postData);

    // Cek response dari server
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("HTTP Response code: " + String(httpResponseCode));
      Serial.println("Response: " + response);
    } else {
      Serial.println("Error on sending POST: " + String(httpResponseCode));
    }

    // Tutup koneksi HTTP
    http.end();
  } else {
    Serial.println("Error in WiFi connection");
  }
}

// Fungsi untuk mengirim pesan dengan delay
void FonnteArduino::sendMessageWithDelay(const String& target, const String& message, unsigned long delayTime) {
  Serial.println("Delaying message send for " + String(delayTime) + " milliseconds...");
  delay(delayTime); // Delay selama waktu yang ditentukan

  sendMessage(target, message); // Setelah delay, kirim pesan
}

// Fungsi untuk mengubah kode negara
void FonnteArduino::setCountryCode(const String& newCountryCode) {
  countryCode = newCountryCode;
}

// Fungsi untuk mendapatkan kode negara saat ini
String FonnteArduino::getCountryCode() const {
  return countryCode;
}
