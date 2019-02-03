#include <dummy.h>


#include "SSD1306.h"

uint8_t ledPin = 16; // Onboard LED reference
SSD1306 display(0x3c, 5, 4); // instance for the OLED. Addr, SDA, SCL

void setup() {
    pinMode(ledPin, OUTPUT);

    Serial.begin(115200);

    // OLED SETUP
    display.init(); // initialise the OLED
    display.flipScreenVertically(); // does what is says
    display.setFont(ArialMT_Plain_10); // does what is says
    display.setTextAlignment(TEXT_ALIGN_LEFT); // Set the origin of text to top left
}

void loop() {
    Serial.println("Start Loop----------");

    digitalWrite(ledPin, LOW);
    delay(2000);
    digitalWrite(ledPin, HIGH);
    delay(2000);

    display.clear(); 
    display.drawString(0, 0, "Hello World! \nBy Billy Park");
    display.display(); 
}
