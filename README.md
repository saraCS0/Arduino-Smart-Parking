# Arduino Smart Parking

## Description
Arduino Smart Parking is an automated system designed to optimize parking management by using sensors, motors, and real-time displays. It reduces the time drivers spend searching for parking spots and enhances efficiency in parking lots.

## Features
- **Vehicle Detection:** Detects vehicles entering and exiting using ultrasonic and IR sensors.
- **Gate Automation:** Automatically opens and closes the gate based on parking availability.
- **Real-Time Display:** Shows the number of available parking spots on an LCD.

## Requirements
### Hardware:
- Arduino UNO
- 16×2 LCD Display
- I2C Module for the LCD
- Ultrasonic Sensors (2x)
- Mini Servo Motor (SG-90)
- IR Sensors
- Power Adapter (5V, 2A)

### Software:
- Arduino IDE (C++)

## How to Use
1. Clone the repository:
   ```bash
   https://github.com/saraCS0/Arduino-Smart-Parking/blob/main/README.md#requirements
   ```
2. Open the `.ino` file in Arduino IDE.
3. Connect the hardware components based on the system diagram.
4. Upload the code to the Arduino board.
5. Power the system and watch the parking system in action!

## System Design
1. **Vehicle Detection:** Ultrasonic sensors detect cars approaching the gate.
2. **Gate Control:** Servo motors open/close the gate based on availability.
3. **Display:** LCD shows real-time parking availability.

## File Structure
- `/code/`: Contains Arduino code.
- `/diagrams/`: Includes system and hardware connection diagrams.
- `/documentation/`: Contains the project report and supplementary files.

## Task Management
The progress and task breakdown for this project are managed using a Trello board.  
You can view the board here: [Trello Board](https://trello.com/b/wxy8h6PE/arduino-smart-parking)


## Authors
- [Sarah Khalid Alsaedi]
- [Jana Abusoudah]
- [Lana Alamer]

## License
This project is licensed under the MIT License.
