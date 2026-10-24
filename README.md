# Motion-detection-using-HC-SR501-PIR-Module
This is a simple motion detector project I made using an ESP32, an HC-SR501 PIR motion sensor, and a 0.92-inch OLED display.

The main idea is to detect motion and show an alert on the OLED screen whenever the sensor detects someone moving. If no motion is detected, it displays **SYSTEM OK**.

I'm building this project to learn more about ESP32, sensors, and how to connect different hardware components.

## Components Used

- ESP32 development board
- HC-SR501 PIR motion sensor
- 0.92-inch OLED display (I2C)
- Jumper wires
- USB cable

## Connections

### PIR Sensor

| PIR Pin | ESP32 Pin |
|---|---|
| VCC | VIN / 5V |
| GND | GND |
| OUT | GPIO 27 |

### OLED Display

| OLED Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## How It Works

The PIR sensor detects changes in infrared radiation caused by movement. The ESP32 reads the sensor output and updates the OLED display.

- When motion is detected, the display shows **ALERT - Motion Detected**.
- When there is no motion, it shows **SYSTEM OK**.

The sensor needs some time to warm up after powering on, so I wait before testing it.

## Arduino IDE Setup

I'm using Arduino IDE to write and upload the code.

Libraries required:

- Adafruit SSD1306
- Adafruit GFX Library

Install these libraries from the Arduino IDE Library Manager before uploading the code.

## Testing

1. Connect the PIR sensor and OLED to the ESP32.
2. Upload the code using Arduino IDE.
3. Wait for the PIR sensor to warm up.
4. Move your hand in front of the sensor.
5. Check whether the OLED displays the motion alert.
6. Stay still and check whether the display returns to SYSTEM OK.

## Problems I Faced

While testing, I noticed that the display sometimes switches between ALERT and SYSTEM OK even when nothing is moving.

I'm trying to fix this by checking the PIR wiring, adjusting the sensor sensitivity, and testing its output separately before connecting everything together.

## Future Plans

- Add temperature and humidity monitoring using a DHT22.
- Add an LDR sensor to check light levels.
- Improve the motion detection so the alert is more stable.
- Combine everything into my ESP32 fog-monitoring project.

## Final Note

This is a small learning project, and I'm still working on improving it. The aim is to understand how sensors work with ESP32 and build a simple system that can detect motion and display warnings.

Thanks for checking out my project! :)

