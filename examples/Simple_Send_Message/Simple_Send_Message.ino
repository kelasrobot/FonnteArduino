#include <FonnteArduino.h>
FonnteArduino wa("isi token");

void setup() {
  Serial.begin(115200);
  wa.connectToWiFi("nama wifi", "pass wifi");
  wa.sendMessage("0812XXXXXXXX", "Hello from ESP32!");
}

void loop() {}
