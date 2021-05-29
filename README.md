# Accident-Detection-System

Accident Detection System Using IOT

## Pre-requisites:

Make sure the drivers are installed. Use this article for reference=> https://seeeddoc.github.io/Download_Arduino_and_install_Arduino_driver/

## Installation Instructions:

1. Install Arduino.
2. http://arduino.esp8266.com/stable/package_esp8266com_index.json=> Paste the given URL in the additional boards manager
   urls field in File->Preferences.
3. Open Tools->Boards->Boards Manager and search and instal esp8266
4. Connect Arduino and Node MCU to PC
5. Open transmitter file in one window of Arduino IDE
6. Open receiver file in another window of Arduino IDE
7. Choose respective port numbers in both windows in Tools->port.
8. In receiver window,select board as node mcu esp12 and in sender, select arduino uno.
9. Make sure hardware is connected properly(except serial ports of both arduino and node mcu whic have to be disconnected), upload
   the respective codes in both devices.
10. Connect serial ports, and check output in Serial Monitor.
