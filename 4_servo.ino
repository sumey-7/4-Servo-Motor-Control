#include <Servo.h>

// تعريف المحركات الأربعة
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  // ربط المحركات بالدبابيس (Pins) المخصصة
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  // قراءة الوقت الحالي بالمللي ثانية
  unsigned long currentTime = millis();

  // إذا كان الوقت أقل من ثانيتين (2000 مللي ثانية)
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
  // إذا مرّت الثانيتين، يثبت للأبد
  else {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
  }
}