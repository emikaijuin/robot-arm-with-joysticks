#include <Servo.h>

// Initialize Servos
Servo servo_0;
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;

// DECLARE SERVO PINS
int servo_pin_0 = 2; // hand grab
int servo_pin_1 = 3;
int servo_pin_2 = 4;
int servo_pin_3 = 5;
int servo_pin_4 = 6; // wrist extension
int servo_pin_5 = 7; // wrist rotation

// DECLARE JOYSTICK PINS AND STATE
// right hand joystick
int x_key_0 = A0;
int y_key_0 = A1;
// lefthand joystick
// int x_key_1 = A2;
// int y_key_1 = A3;
int switchState;
int switch_pin = 5;
int prevSwitchState = HIGH;

// Declare positions
int x_pos_0;
int y_pos_0;
int x_pos_1;
int y_pos_1;
int pos_0 = 0;
int pos_1 = 90;

// Declare increment angle to control speed of movement
int increment = 2;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo_0.attach(servo_pin_0);
  // servo_1.attach(servo_pin_1);
  // servo_2.attach(servo_pin_2);
  // servo_3.attach(servo_pin_3);
  // servo_4.attach(servo_pin_4);
  servo_5.attach(servo_pin_5);

  // servo_0.write(pos); // Don't override previous position on reboot
  pinMode(x_key_0, INPUT);
  pinMode(y_key_0, INPUT);
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, prevSwitchState);
  // pinMode(x_key_1, INPUT);
  // pinMode(y_key_1, INPUT);
}

void loop()
{
  // READ JOYSTICK INPUT

  switchState = digitalRead(switch_pin);
  x_pos_0 = analogRead(x_key_0);
  y_pos_0 = analogRead(y_key_0);

  // x_pos_1 = analogRead(x_key_1);
  // y_pos_1 = analogRead(y_key_1);

  // CONTROL HAND CLOSING AND OPENING
  // if (switchState == LOW && switchState != prevSwitchState)
  // {
  //   if (servo_0.read() < 90)
  //   {
  //     servo_0.write(170);
  //   }
  //   else
  //   {
  //     servo_0.write(0);
  //   }
  // }
  // prevSwitchState = switchState;

  Serial.println(y_pos_0);
  delay(100);
  // CONTROL WRIST EXTENSION
  // if (x_pos_1 < 300)
  // {
  // if (pos_1 >= increment)
  // {
  //   pos_1 = pos_1 - increment;
  // }
  // else
  // {
  //   pos_1 = 0;
  // }
  // servo_4.write(pos_1);
  // delay(50);
  // }
  // if (x_pos_1 > 700)
  // {
  // if (pos_1 <= 180 - increment)
  // {
  //   pos_1 = pos_1 + increment;
  // }
  // else
  // {
  //   pos_1 = 180;
  // }
  // servo_4.write(pos_1);
  // delay(50);
  // }

  // CONTROL WRIST ROTATION
  // if (x_pos_0 < 300)
  // {
  //   if (pos_0 >= increment)
  //   {
  //     pos_0 = pos_0 - increment;
  //   }
  //   else
  //   {
  //     pos_0 = 0;
  //   }
  //   servo_5.write(pos_0);
  //   delay(50);
  // }
  // if (x_pos_0 > 700)
  // {
  //   if (pos_0 <= 180 - increment)
  //   {
  //     pos_0 = pos_0 + increment;
  //   }
  //   else
  //   {
  //     pos_0 = 180;
  //   }
  //   servo_5.write(pos_0);
  //   delay(50);
  // }
}
