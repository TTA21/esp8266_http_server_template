# esp8266_http_server_template
A messy template for an http server that can be hosted in an esp8266 without any external hardware (except for a host computer to compile and flash the device)
This template is a more thoughtful version of the original "http_server/simple" template featured in the freeRTOS examples folder. It contains a mutable size vector library, a json builder and parser, aswell as a sqlite3 database library for data persistency.

Note: The template uses SPIFFS for its file handlers and sqlite connetion, so before flashig your device remember to check the partition table and menuconfig, remember aswell to change the SSID and password values to connect to your WIFI.

*Libraries used:
1.json-parser: https://github.com/json-parser/json-parser
2.json-builder: https://github.com/json-parser/json-builder
3.c-vector: https://github.com/Mashpoe/c-vector
4.esp32-idf-sqlite3: https://github.com/siara-cc/esp32-idf-sqlite3
