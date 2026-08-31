# Project Name: Basic Manipulator
Designed a basic manipulator with 3 degrees of freedom. Based on the joystick reading the values were mapped to the values accepted for the PWM range of values in Arduino, the PWM signal was then sent to the motor drivers controlling the speed. The motor drivers were supplied 12V and the power supply was set to CV mode. This project is the predecessor to project MRPP.

<img width="507" height="730" alt="image" src="https://github.com/user-attachments/assets/a4ab11ed-77ff-448e-9a11-8eb340f06221" />



## Firmware Architecture
<img width="572" height="772" alt="image" src="https://github.com/user-attachments/assets/c466da4d-0868-4a16-9206-47e801ce7835" />

---

## Hardware Architecture
<img width="1105" height="765" alt="image" src="https://github.com/user-attachments/assets/52fb1688-c0d3-453e-9b96-0f9f6461b79a" />

---

## CAD/3D Printing/Mechanical Specifications 

### CAD Files
* All CAD files can be found on under the cad-files folder in STL format.
### 3D Printing Specificatons
* The parts of this project were printed using a Creality Ender 3 Pro 3D printer
* 20% Infill
* Infill Pattern: Cubic
* Printing Temperature: 200C
* Build Plate Temperature: 60C
* Material: PLA
* Print Speed: 50 mm/s
Note: The rest of the settings were left as default as they come in the pre-set configuration for the Creality Ender 3 Pro Printer in Cura Slicer.
### Mechanical Specifications
* Motor Rated Torque: 0.4 Nm
* Gear Ratio: 1:3
Note: The same gear ratio and torque is present in all of the joints, with the exception of the shoulder which has double the torque rating because of the double motor.
Note: Further studies were planned to determine payload capabilities, rpm, experimental torque for all of the joints but the project has been abandoned.
---
## System Specifications

### Hardware
* Ball Bearings:
* **Board:** Arduino Uno R3
* **Motor Drivers:** L298N
* **Sensors:** KY-023
* **Battery:** Jesverty Power Supply (Model Number: ####)
Note: The power supply acted as the battery of the system.
* **Motors and Actuators:** Geartisan 12V DC Motor (Model: 100 rpm)
### Software & Dependencies
* **Development Environment:** Arduino IDE (v2.3.10)
* **3D Printer Slicer:** Ultimaker Cura Slicer (v5.8.1)
---

## Usage & Bringup

### Prerequisites

### 1. Hardware Cheklist
1. Connect the DC motors directly to the power supply and ensure they spin.
2. When the Arduino board is connected to your computer make sure the green LED is lit up.
3. When the power supply is connected to the two L298N drivers make sure the red LED is lit up on both drivers.
### 2. Execution
1. Open your file manager in and navigate to basic-maniplator/firmware/joystick_3axis_control.ino in this repository.
2. Open the ino file.
3. Select the board type (Arduino Uno R3) and COM port from the top left drop-down menu.
4. Click the Upload arrow button in the top toolbar.
