# Ultrasonic Distance Measurement Device  

This project is a **distance measurement device** built using an **Arduino Uno**, **HC-SR04 Ultrasonic Sensor**, and an **OLED display**. It can measure the distance of objects in real-time and display the values on the OLED screen. A push button allows users to switch between different distance units (**centimeters, inches, meters, and feet**).  

---

## 📌 Features  
- Real-time distance measurement  
- Unit conversion: cm, inches, meters, feet  
- Compact OLED display interface  
- Easy to build and beginner-friendly  
- Suitable for robotics, obstacle detection, and educational projects  

---

## 🛠️ Components Required  
- Arduino Uno  
- HC-SR04 Ultrasonic Sensor  
- OLED Display (I2C – GND, VCC, SCL, SDA)  
- Push Button  
- Jumper Wires  
- Breadboard or PCB  

---

## ⚡ Circuit Connections  

| Component             | Arduino Uno Pin |
|------------------------|-----------------|
| HC-SR04 VCC           | 5V              |
| HC-SR04 GND           | GND             |
| HC-SR04 Trigger       | D9              |
| HC-SR04 Echo          | D10             |
| OLED VCC              | 5V              |
| OLED GND              | GND             |
| OLED SCL              | A5 (SCL)        |
| OLED SDA              | A4 (SDA)        |
| Push Button           | D2              |

---

## 🔧 Working Principle  
1. The **HC-SR04 ultrasonic sensor** sends ultrasonic pulses.  
2. The pulses reflect back from an object and are received by the sensor.  
3. Arduino calculates the distance using the **time of flight** of the pulse.  
4. The calculated distance is displayed on the **OLED screen**.  
5. The **push button** cycles through different units of measurement.  

---

## 📜 Formula Used  
Distance is calculated using the speed of sound:  

\[
\text{Distance (cm)} = \frac{\text{Time (µs)} \times 0.034}{2}
\]

---

## 🚀 Applications  
- Obstacle detection in robotics  
- Smart assistance for visually impaired persons  
- Parking assistance systems  
- Distance monitoring in automation systems  
- Educational electronics projects  

---

## 📷 Images / Circuit Diagram  
(Add images of your circuit and setup here once available)  

---

## 📂 Repository Contents  
- `README.md` → Documentation  
- `/images` → Circuit diagram, prototype pictures (optional)  

---

## 🏆 Author  
Developed by **Nagarajan** ✨  
Diploma in Electronics & Communication Engineering 

---
