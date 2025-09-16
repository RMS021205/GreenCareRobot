#include <Servo.h> 
Servo myservo; 
 
void setup() { 
 myservo.attach(8); 
 
} 
 
void loop() {             
  myservo.write(0);         //0도 회전해라 
  delay(2000);             //2초 쉬어라 
  myservo.write(180);     //180도 회전해라 
  delay(2000);    //2초 쉬어라 
}