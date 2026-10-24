#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIR_PIN 27
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

int lastMotion = -1;

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (true) {
      delay(100);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(10, 20);
  display.println("Motion Detector");
  display.setCursor(20, 35);
  display.println("Starting...");
  display.display();

  // Allow PIR sensor to stabilize
  delay(30000);
}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion != lastMotion) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    if (motion == HIGH) {
      Serial.println("WARNING: Motion Detected!");

      display.setTextSize(2);
      display.setCursor(5, 0);
      display.println("!!ALERT!!");

      display.setTextSize(1);
      display.setCursor(5, 25);
      display.println("Motion Detected");
      display.setCursor(5, 45);
      display.println("Check Surroundings");
    } 
    
    else {
      Serial.println("No Motion");

      display.setTextSize(2);
      display.setCursor(10, 20);
      display.println("SYSTEM OK");

      display.setTextSize(1);
      display.setCursor(10, 50);
      display.println("No Motion Detected");
    }

    display.display();
    lastMotion = motion;
  }

  delay(10);
}
