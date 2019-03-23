#include <Servo.h>

// Initialize Servos
Servo servo_0;
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

// Declare Servo Pins
int servo_pin_0 = 2;
int servo_pin_1 = 3;
int servo_pin_2 = 4;
int servo_pin_3 = 5;
int servo_pin_4 = 6;
int servo_pin_5 = 7;

// Declare Joystick Input Pins
int x_key = A0;
int y_key = A1;
int grab;
int grab_key = 5;

// Declare positions
int x_pos;
int y_pos;
int pos = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_0.attach(servo_pin_0);
  servo_1.attach(servo_pin_1);
  servo_2.attach(servo_pin_2);
  servo_3.attach(servo_pin_3);
  servo_4.attach(servo_pin_4);
  servo_5.attach(servo_pin_5);
  
  servo_0.write(pos);
  pinMode(x_key, INPUT);
  pinMode(y_key, INPUT);
  pinMode(grab_key, INPUT);
  digitalWrite(grab_key, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  x_pos = analogRead(x_key);
  y_pos = analogRead(y_key);
  grab = digitalRead(grab_key);
//  Serial.println(digitalRead(grab_key));
  delay(10);

  if (grab == LOW) {
    Serial.println("clicked");
    if (servo_0.read() < 90) {
      servo_0.write(90);
      delay(100);
    } 
//    else {
//      servo_0.write(0);
//      delay(100);
//    }

  }
  
  if (x_pos < 300) {
    if (pos < 10) {
    }
    else {
      pos = pos - 5;
      servo_0.write(pos);
      delay(100);
    }
  }

  if (x_pos > 700) {
    if (pos > 180) {}
    else {
      pos = pos + 5;
      servo_0.write(pos);
      delay(100);
    }  
  }  
}
