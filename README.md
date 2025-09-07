# Ultrasonic Distance Measurement Device  

This project is a simple distance measurement system built using **Arduino Uno**, **HC-SR04 ultrasonic sensor**, and an **OLED display**. It measures the distance of an object in real time and allows the user to switch between units (cm, inches, meters, feet) using a push button.  

---

🚀 Features  
- Real-time distance measurement  
- Supports 4 units: centimeters, inches, meters, feet  
- OLED display for clear output  
- Push button for easy unit switching  
- Beginner-friendly and compact design  

---

🧰 Components Used  
- Arduino Uno  
- HC-SR04 Ultrasonic Sensor  
- OLED Display (I2C – 128×64)  
- Push Button  
- Breadboard & Jumper Wires  

---

🔧 How to Build  
1. Connect components as per the circuit table:  

| Component       | Arduino Pin |
|-----------------|-------------|
| HC-SR04 VCC     | 5V          |
| HC-SR04 GND     | GND         |
| HC-SR04 Trigger | D9          |
| HC-SR04 Echo    | D10         |
| OLED VCC        | 5V          |
| OLED GND        | GND         |
| OLED SCL        | A5 (SCL)    |
| OLED SDA        | A4 (SDA)    |
| Push Button     | D2          |

2. Upload the Arduino code to the Uno.  
3. Power the device and observe distance readings on the OLED.  
4. Press the button to cycle between units (cm → in → m → ft).  

---

📂 Files Included  
File             | Description  
-----------------|----------------------------------------  
`Ultrasonic_Distance.ino` | Arduino code for distance measurement and unit conversion  
`README.md`      | Project documentation  
`/images`        | Circuit diagram & prototype images (optional)  

---

📝 Notes  
- Works best for distances between **2 cm and 400 cm** (HC-SR04 range).  
- Ensure the sensor is placed facing the object directly for accurate readings.  
- Can be extended for robotics, obstacle detection, and assistive devices.  

---

📄 License  
This project is open-source and free to use under the MIT License.  
