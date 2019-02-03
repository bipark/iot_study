
#include "SSD1306.h"
#include "WiFi.h"

uint8_t ledPin = 16; // Onboard LED reference
SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

const char* ssid = "KT_GiGA_2G_Wave2_0514";
const char* password =  "ddb39dc829";

void setup() {
    pinMode(ledPin, OUTPUT);

    Serial.begin(115200);

    // OLED SETUP
    display.init(); // initialise the OLED
    display.flipScreenVertically(); // does what is says
    display.setFont(ArialMT_Plain_10); // does what is says
    display.setTextAlignment(TEXT_ALIGN_LEFT); // Set the origin of text to top left

    // Wifi Setup
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network");
    Serial.println(WiFi.localIP());    
}

void loop() {
//    Serial.println("Start Loop----------");

//    digitalWrite(ledPin, LOW);
//    delay(2000);
//    digitalWrite(ledPin, HIGH);
//    delay(2000);


    display.clear(); 
    display.drawString(0, 0, "IP : ");
    display.display(); 
}
