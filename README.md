# FonnteArduino Library

**FonnteArduino** is an Arduino library that simplifies sending WhatsApp messages via the **Fonnte API** using ESP32/ESP8266. This library allows you to connect to a WiFi network, configure your API token, and send messages easily through Fonnte's platform. It is ideal for IoT applications where notifications or alerts need to be sent directly to WhatsApp.

## Features
- Simple interface for sending WhatsApp messages through the Fonnte API.
- Built-in WiFi connection support (ESP32/ESP8266).
- Set and change country code dynamically.
- Send messages with an optional delay.
- Supports both ESP32 and ESP8266.

## Installation

1. Download this repository and extract it.
2. Move the folder `FonnteArduino` to your Arduino libraries directory:
   - On Windows: `Documents/Arduino/libraries/`
   - On Mac: `~/Documents/Arduino/libraries/`
   - On Linux: `~/Arduino/libraries/`
3. Restart your Arduino IDE.
4. Go to **Sketch > Include Library > FonnteArduino** to include the library in your project.

## Usage

### 1. Basic Example to Send WhatsApp Message

```cpp
#include <FonnteArduino.h>

// Initialize the library with your Fonnte API token
FonnteArduino fonnte("YOUR_API_TOKEN");  // Replace with your actual Fonnte token

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  fonnte.connectToWiFi("your-SSID", "your-password");  // Replace with your WiFi credentials

  // Send a message (default country code is +62)
  fonnte.sendMessage("08123456789", "Hello from FonnteArduino!");
}

void loop() {
  // No looping necessary
}
```

### 2. Example with Delay and Custom Country Code

```cpp
#include <FonnteArduino.h>

FonnteArduino fonnte("YOUR_API_TOKEN");  // Replace with your actual Fonnte token

void setup() {
  Serial.begin(115200);
  
  // Connect to WiFi
  fonnte.connectToWiFi("your-SSID", "your-password");

  // Change country code to +1 (USA) and send a delayed message
  fonnte.setCountryCode("1");  // USA country code
  fonnte.sendMessageWithDelay("1234567890", "Hello from USA!", 5000);  // Delay for 5 seconds
}

void loop() {
  // No looping necessary
}
```

### API Reference

#### **`FonnteArduino(String token)`**
Constructor to initialize the library with your API token.
- `token`: Your Fonnte API token.

#### **`void connectToWiFi(const char* ssid, const char* password)`**
Connects to the specified WiFi network.
- `ssid`: The SSID (name) of the WiFi network.
- `password`: The password for the WiFi network.

#### **`void sendMessage(String target, String message, String countryCode = "62")`**
Sends a WhatsApp message.
- `target`: Recipient's phone number.
- `message`: The message content.
- `countryCode` (optional): The recipient's country code (default is `"62"` for Indonesia).

#### **`void sendMessageWithDelay(String target, String message, unsigned long delayMs, String countryCode = "62")`**
Sends a WhatsApp message after a specified delay.
- `target`: Recipient's phone number.
- `message`: The message content.
- `delayMs`: The delay in milliseconds before the message is sent.
- `countryCode` (optional): The recipient's country code (default is `"62"`).

#### **`void setCountryCode(String countryCode)`**
Sets the country code for future messages.
- `countryCode`: The new default country code.

#### **`String getCountryCode()`**
Returns the current country code being used for messages.

## Contributing
Contributions are welcome! Please create a pull request or raise an issue for any bug fixes, improvements, or feature requests.

## License
This library is open-source and available under the **MIT License**.

## Author
- Ajang Rahmat
