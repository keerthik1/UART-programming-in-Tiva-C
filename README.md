# UART Programming on TIVA C LaunchPad

## Overview
This project demonstrates UART (Universal Asynchronous Receiver/Transmitter) programming on the TIVA C LaunchPad (EK-TM4C123GXL, TM4C123GH6PM microcontroller). It implements serial communication using UART0 to send and receive data between the LaunchPad and a PC terminal (e.g., PuTTY, Tera Term). The project includes echoing received characters by switching on led based on character input showcasing embedded systems skills such as UART configuration, interrupt-driven communication, and system clock setup.

### Features
- Configures UART0 for serial communication at 9600 baud rate.
- Echoes received characters by switching on led based on character input.
- Uses interrupt-driven UART communication for efficient data handling.
- Sets the system clock to 16 MHz for accurate timing.

## Hardware Requirements
- **TIVA C LaunchPad**: EK-TM4C123GXL with TM4C123GH6PM microcontroller.
- **USB-to-Serial Connection**: The LaunchPad’s USB interface (via ICDI) for UART communication with a PC.
- **Connections**:
  - UART0 TX (PA1) → Used for serial transmission (via LaunchPad USB to PC).
  - UART0 RX (PA0) → Used for serial reception (via LaunchPad USB to PC).
  - Note: The LaunchPad’s USB connection handles UART communication; no additional hardware is required.

## Software Requirements
- **Code Composer Studio (CCS)**: Version 12.4.0 or later.
- **TivaWare**: Optional (this project uses direct register access for educational purposes).
- **Compiler**: TI ARM Compiler (included with CCS).
- **Terminal Software**: PuTTY, Tera Term, or CCS Terminal for viewing UART output.

## Setup Instructions
1. **Hardware Setup**:
   - Connect the TIVA C LaunchPad to your PC via USB (this enables UART communication through the ICDI interface).
2. **Software Setup**:
   - Clone or download this repository.
