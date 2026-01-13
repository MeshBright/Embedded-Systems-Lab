# ⚡ Embedded Systems Lab

![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![C++](https://img.shields.io/badge/-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Electronics](https://img.shields.io/badge/-Circuit_Prototyping-orange?style=for-the-badge)

### 🛠️ Firmware and Control Logic for Mechatronic Systems.

Welcome to my hardware laboratory. This repository documents my progression through the **Arduino RFID Master Roadmap**. It focuses on bridging physical components with digital logic, moving from basic circuit theory to advanced sensor integration and serial communication.

**Current Progress:** Segment 14/20 (Shift Registers & Advanced I/O).

---

## 🔌 Hardware Stack (The Setup)
All code in this repository has been rigorously tested on physical hardware. I do not just simulate; I build.

| Category | Specific Hardware Used |
| :--- | :--- |
| **Microcontroller** | Arduino Uno R3 (ATmega328P) |
| **Integrated Circuits** | **74HC595** (8-bit Shift Register for Pin Expansion) |
| **Env. Sensors** | DHT11 (Temp/Humidity), Water Level Sensor, Flame Sensor (IR) |
| **Distance/Light** | HC-SR04 (Ultrasonic Sonar), Photoresistor (LDR) |
| **Displays/Output** | 1-Digit 7-Segment Display, Active/Passive Buzzers, RGB LEDs |
| **Input Devices** | Potentiometers (Analog Control), Tactile Pushbuttons (Digital Logic) |

---

## 📂 Project Modules

My code is organized by **Engineering Concept**. Navigate to the folders to find specific firmware logic:

### 1️⃣ Advanced Digital Logic (The 74HC595)
* **`Shift-Register-Control/`**: Implementation of Serial-to-Parallel conversion using the 74HC595 IC.
    * *Engineering focus:* Controlling 8 outputs using only 3 Arduino pins (Data, Latch, Clock) via the `shiftOut()` function.
    * *Application:* Efficient resource management in pin-limited systems.

### 2️⃣ Environmental Sensing Systems
* **`Ultrasonic-Distance/`**: Active sensing logic using the HC-SR04 to trigger pulses and measure echo duration (`pulseIn`).
* **`Safety-Systems/`**: Logic for Water Level detection and IR Flame sensing for automated alarm systems.

### 3️⃣ Analog & Digital Interfacing
* **`Visual-Displays/`**: Logic for driving 7-Segment Displays and RGB Color Mixing (PWM).
* **`Auditory-Feedback/`**: Frequency generation using Passive Buzzers (`tone()`) vs. Active Buzzers.
* **`Input-Handling/`**: Solving "Floating Pin" issues with Pull-Up/Pull-Down resistors and reading Analog signals via Potentiometers.

---

## ⚙️ Key Technical Concepts Applied
In these projects, I focus on writing efficient, non-blocking code suitable for real-world deployment:
* **PWM (Pulse Width Modulation):** Simulating analog output for LED fading and color mixing.
* **One-Wire & Serial Protocols:** Communicating with digital sensors (DHT11) and Shift Registers.
* **Non-Blocking Logic:** Moving away from `delay()` to state-machine logic for multitasking.
* **Voltage Dividers:** Circuit theory applied to read resistive sensors (LDRs).

---

## ⚙️ How to Flash (Run the Code)
1. **Hardware Setup:** Connect the components according to the schematic notes in each folder.
2. **Software:** Open the file using the **Arduino IDE**.
3. **Select Board:** `Tools` > `Board` > `Arduino Uno`.
4. **Upload:** Connect via USB and hit `Ctrl + U`.

---

### 📫 Connect
If you have questions about the wiring logic (specifically the 74HC595 latching sequence) or need help troubleshooting, feel free to reach out via my Profile.
