# esp32-beacon

A basic iBeacon implementation using an ESP32 and the standard Arduino framework.  _In particular_, I'm using an [Adafruit HUZZAH32 ESP32 Feather Board](https://www.adafruit.com/product/3405).

## Building and Running

This application uses [PlatformIO](https://platformio.org/) to build and upload, but you can use the commandline `platformio run`:

```
esp32-ibeacon % platformio run
Processing featheresp32 (platform: espressif32; board: featheresp32; framework: arduino)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/espressif32/featheresp32.html
PLATFORM: Espressif 32 (6.4.0) > Adafruit ESP32 Feather
HARDWARE: ESP32 240MHz, 320KB RAM, 4MB Flash
DEBUG: Current (cmsis-dap) External (cmsis-dap, esp-bridge, esp-prog, iot-bus-jtag, jlink, minimodule, olimex-arm-usb-ocd, olimex-arm-usb-ocd-h, olimex-arm-usb-tiny-h, olimex-jtag-tiny, tumpa)
PACKAGES:
 - framework-arduinoespressif32 @ 3.20011.230801 (2.0.11)
 - tool-esptoolpy @ 1.40501.0 (4.5.1)
 - toolchain-xtensa-esp32 @ 8.4.0+2021r2-patch5
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 33 compatible libraries
Scanning dependencies...
Dependency Graph
|-- ESP32 BLE Arduino @ 2.0.0
Building in release mode
Retrieving maximum program size .pio/build/featheresp32/firmware.elf
Checking size .pio/build/featheresp32/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]  11.5% (used 37668 bytes from 327680 bytes)
Flash: [========  ]  81.9% (used 1073901 bytes from 1310720 bytes)
================================================================== [SUCCESS] Took 0.68 seconds ==================================================================
```

Uploading with `platformio run --target upload`

```
esp32-ibeacon % platformio run --target upload
Processing featheresp32 (platform: espressif32; board: featheresp32; framework: arduino)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/espressif32/featheresp32.html
PLATFORM: Espressif 32 (6.4.0) > Adafruit ESP32 Feather
HARDWARE: ESP32 240MHz, 320KB RAM, 4MB Flash
DEBUG: Current (cmsis-dap) External (cmsis-dap, esp-bridge, esp-prog, iot-bus-jtag, jlink, minimodule, olimex-arm-usb-ocd, olimex-arm-usb-ocd-h, olimex-arm-usb-tiny-h, olimex-jtag-tiny, tumpa)
PACKAGES:
 - framework-arduinoespressif32 @ 3.20011.230801 (2.0.11)
 - tool-esptoolpy @ 1.40501.0 (4.5.1)
 - tool-mkfatfs @ 2.0.1
 - tool-mklittlefs @ 1.203.210628 (2.3)
 - tool-mkspiffs @ 2.230.0 (2.30)
 - toolchain-xtensa-esp32 @ 8.4.0+2021r2-patch5
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 33 compatible libraries
Scanning dependencies...
Dependency Graph
|-- ESP32 BLE Arduino @ 2.0.0
Building in release mode
Retrieving maximum program size .pio/build/featheresp32/firmware.elf
Checking size .pio/build/featheresp32/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]  11.5% (used 37668 bytes from 327680 bytes)
Flash: [========  ]  81.9% (used 1073901 bytes from 1310720 bytes)
Configuring upload protocol...
AVAILABLE: cmsis-dap, esp-bridge, esp-prog, espota, esptool, iot-bus-jtag, jlink, minimodule, olimex-arm-usb-ocd, olimex-arm-usb-ocd-h, olimex-arm-usb-tiny-h, olimex-jtag-tiny, tumpa
CURRENT: upload_protocol = esptool
Looking for upload port...
Auto-detected: /dev/cu.usbserial-02858CA9
Uploading .pio/build/featheresp32/firmware.bin
esptool.py v4.5.1
Serial port /dev/cu.usbserial-02858CA9
Connecting..........
Chip is ESP32-D0WD-V3 (revision v3.0)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 8c:4b:14:09:88:80
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 921600
Changed.
Configuring flash size...
Flash will be erased from 0x00001000 to 0x00005fff...
Flash will be erased from 0x00008000 to 0x00008fff...
Flash will be erased from 0x0000e000 to 0x0000ffff...
Flash will be erased from 0x00010000 to 0x00117fff...
Compressed 17568 bytes to 12204...
Writing at 0x00001000... (100 %)
Wrote 17568 bytes (12204 compressed) at 0x00001000 in 0.4 seconds (effective 331.3 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 146...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (146 compressed) at 0x00008000 in 0.1 seconds (effective 429.3 kbit/s)...
Hash of data verified.
Compressed 8192 bytes to 47...
Writing at 0x0000e000... (100 %)
Wrote 8192 bytes (47 compressed) at 0x0000e000 in 0.1 seconds (effective 669.3 kbit/s)...
Hash of data verified.
Compressed 1079648 bytes to 680754...
Writing at 0x00010000... (2 %)
Writing at 0x0001bac6... (4 %)
Writing at 0x0002744c... (7 %)
Writing at 0x00037a00... (9 %)
Writing at 0x0003cf4b... (11 %)
Writing at 0x0004281d... (14 %)
Writing at 0x00048074... (16 %)
Writing at 0x0004d749... (19 %)
Writing at 0x00052de7... (21 %)
Writing at 0x000587d6... (23 %)
Writing at 0x0005e1b9... (26 %)
Writing at 0x000637a0... (28 %)
Writing at 0x00068b31... (30 %)
Writing at 0x0006df7e... (33 %)
Writing at 0x000742fb... (35 %)
Writing at 0x00079ba2... (38 %)
Writing at 0x0007f786... (40 %)
Writing at 0x0008535d... (42 %)
Writing at 0x0008ac2f... (45 %)
Writing at 0x00090301... (47 %)
Writing at 0x00095e11... (50 %)
Writing at 0x0009b3d9... (52 %)
Writing at 0x000a0d8a... (54 %)
Writing at 0x000a6b31... (57 %)
Writing at 0x000acdd5... (59 %)
Writing at 0x000b38df... (61 %)
Writing at 0x000b9160... (64 %)
Writing at 0x000becd0... (66 %)
Writing at 0x000c4141... (69 %)
Writing at 0x000c98ef... (71 %)
Writing at 0x000cf41c... (73 %)
Writing at 0x000d5250... (76 %)
Writing at 0x000db5d7... (78 %)
Writing at 0x000e122e... (80 %)
Writing at 0x000e6c13... (83 %)
Writing at 0x000ec538... (85 %)
Writing at 0x000f29df... (88 %)
Writing at 0x000fabcc... (90 %)
Writing at 0x00103485... (92 %)
Writing at 0x0010936a... (95 %)
Writing at 0x0010ef07... (97 %)
Writing at 0x00114585... (100 %)
Wrote 1079648 bytes (680754 compressed) at 0x00010000 in 11.8 seconds (effective 734.6 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
================================================================= [SUCCESS] Took 29.44 seconds =================================================================
```
