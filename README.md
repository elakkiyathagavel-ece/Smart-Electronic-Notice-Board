Smart Notice Board Using ESP32 and LCD

Project Description

The Smart Notice Board is an IoT-based digital notice display system developed using ESP32 and a 16x2 I2C LCD display. It allows users to send notices wirelessly through a mobile phone or laptop using Wi-Fi.

Features

- Wireless notice transmission using Wi-Fi.
- Mobile-friendly web interface.
- Send notices using a SEND button.
- Display notices on a 16x2 LCD.
- Simple and low-cost design.

Components Used

- ESP32
- 16x2 I2C LCD Display
- Jumper Wires
- USB Cable

Software Used

- Arduino IDE
- Embedded C++
- HTML
- Wi-Fi Web Server

Working Principle

1. ESP32 creates a Wi-Fi network named SmartNotice.
2. Connect a mobile phone or laptop to the network.
3. Open a browser and enter 192.168.4.1.
4. Type a notice and click SEND.
5. The ESP32 receives the notice and displays it on the LCD.

Hardware Connections

- LCD SDA – GPIO 21
- LCD SCL – GPIO 22
- LCD I2C Address – 0x27

Wi-Fi Details

- SSID: SmartNotice
- Password: 12345678
- IP Address: 192.168.4.1

Project Status

Working Prototype

