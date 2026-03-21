# 🚀 GERO Launcher
> **ESP32-based Multi-Firmware Platform**
> A powerful firmware that turns your ESP32 Lolin32 into a versatile handheld multitool. Store multiple applications on a microSD card and flash them on the fly—no computer required.

[![Platform](https://img.shields.io/badge/Platform-ESP32-orange.svg)](https://www.espressif.com/en/products/socs/esp32)
[![License](https://img.shields.io/badge/License-Educational-blue.svg)](#-license--support)
[![Store](https://img.shields.io/badge/Tindie-Store-green.svg)](https://www.tindie.com)

---

## 🛠 Installation & Setup

### 1. Preparing the Hardware
Ensure your ESP32 is wired as follows:

| Component | Connection | ESP32 Pin |
| :--- | :--- | :--- |
| **OLED (SSD1306)** | SDA | **Pin 14** |
| | SCL | **Pin 15** |
| **SD Card (SPI)** | CS | **Pin 5** |
| **Buttons** | UP | **Pin 32** |
| | DOWN | **Pin 33** |
| | SELECT/EXIT | **Pin 25** |

### 2. Preparing the SD Card
1. **Format** your microSD card to **FAT32**.
2. **Copy** the `MASTER.bin` file to the root of the SD card.
3. **Copy** any other `.bin` apps you want to use.
   > 💡 **Note:** Keep names short and avoid spaces for better display.

---

## 📘 User Instructions

### 🕹 How to Use the Menu
1. Insert the microSD card into the slot.
2. Power on the device via the USB port or battery LiPo.
3. Use the **UP** and **DOWN** buttons to scroll through the list of available apps.
4. Press the **SELECT** button to flash the chosen app.
5. Wait a few seconds for the "Uploading" progress bar to finish. The device will reboot into your new app!

### 🔄 Returning to the Master Menu (With the Gero_App_Template)
GERO-compatible apps allow you to return to the main menu without a PC:
* **Action:** Press and hold the **SELECT** button (Pin 25) for 2 seconds (or more it's your choice).
* **Result:** The screen will display `RELOADING MASTER...` and the device will return to the original launcher menu.

---

## 💻 For Developers

### 📦 Installing the Library
To create your own apps for GERO:
1. Copy the `GeroLauncher` folder to your `Documents/Arduino/libraries/` path.
2. In your sketch, include the library: `#include <GeroLauncher.h>`

### 📝 Template Code & Export
Use the following structure in your Arduino IDE:

```cpp
#include <GeroLauncher.h>
#include <Adafruit_SSD1306.h>

void setup() {
  Gero.begin(25); // Set the exit button (Pin 25)
  // Your setup code...
}

void loop() {
  // Check if the user wants to go back to the Master Menu
  if (Gero.checkExit()) {
    Gero.backToMaster(display, 5); // 'display' is your OLED object, 5 is SD CS
  }
  // Your app logic...
}

![photo_2026-03-21_08-39-22 (7)](https://github.com/user-attachments/assets/1f139b10-bea5-4821-b94d-baa632918625)
![photo_2026-03-21_08-39-22 (3)](https://github.com/user-attachments/assets/9652f2e3-2fba-43bd-bba6-fc0718347ee6)


