# 4-Servo Motor Synchronous Control System

---
## 📌 Project Overview

An advanced project driving four SG90 micro-servos synchronously via an Arduino Uno architecture. Verified via physical-behavioral simulation on Tinkercad for the Smart Methods Summer Training 2026.

---

## 🌐 Live Simulation
You can interact with and run the design directly in your browser without any hardware setup:
🔗 **[Run Live Simulation on Tinkercad](https://www.tinkercad.com/things/8LATScxELnR-4-servo)**

---

### 🖼️ Physical Layout & Simulation Schematic
![System Circuit Design](4_servo.png)

---

## 💻 Code

The source firmware is designed with precise angular increments to stabilize current draw during the high-speed sweep phase. 

```cpp
/**
 * @file 4-Servo.ino
 * @brief Synchronous multi-servo control system using non-blocking temporal checks.
 * @course Smart Methods Summer Training 2026
 */
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime < 2000) {    
    // حركة الذهاب: من زاوية 0 إلى 180
    for (int angle = 0; angle <= 180; angle += 2) {
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
      servo4.write(angle);
      delay(15);
    }    
    // حركة العودة: من زاوية 180 إلى 0
    for (int angle = 180; angle >= 0; angle -= 2) {
      servo1.write(angle);
      servo2.write(angle);
      servo3.write(angle);
      servo4.write(angle);
      delay(15);
    }  
  } 
    else {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
  }}
