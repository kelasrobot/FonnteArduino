#include "FonnteArduino.h"

// Constructor untuk inisialisasi token
FonnteArduino::FonnteArduino(const char* token) {
    this->apiToken = token;
}

// Fungsi untuk menghubungkan ke WiFi dengan parameter ssid dan password
void FonnteArduino::connectToWiFi(const char* ssid, const char* password) {
    this->ssid = ssid;
    this->password = password;

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

// Fungsi untuk mengirim pesan melalui API Fonnte
void FonnteArduino::sendMessage(const String& target, const String& message) {
    if (WiFi.status() == WL_CONNECTED) {
#if defined(ESP8266)
        std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
        client->setInsecure();  // Disable certificate validation for ESP8266
        HTTPClient http;
        http.begin(*client, serverName);
#elif defined(ESP32)
        HTTPClient http;
        http.begin(serverName);
#endif
        http.addHeader("Authorization", this->apiToken);
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");

        // Data POST yang dikirim ke server
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
        http.end();
    } else {
        Serial.println("Error in WiFi connection");
    }
}

// Fungsi untuk mengirim pesan dengan delay
void FonnteArduino::sendMessageWithDelay(const String& target, const String& message, unsigned long delayTime) {
    delay(delayTime);  // Penundaan dalam milidetik
    sendMessage(target, message);  // Panggil fungsi sendMessage setelah delay
}

// Fungsi untuk mengubah kode negara
void FonnteArduino::setCountryCode(const String& newCountryCode) {
    this->countryCode = newCountryCode;
}

// Fungsi untuk mendapatkan country code saat ini
String FonnteArduino::getCountryCode() const {
    return this->countryCode;
}