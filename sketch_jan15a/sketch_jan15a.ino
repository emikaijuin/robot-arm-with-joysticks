#include <Servo.h>

// Initialize Servos
Servo hand;
Servo base;
Servo extension_1;
Servo extension_2;
Servo extension_3;
Servo wrist;

// DECLARE SERVO PINS
int hand_pin = 2; // hand grab
int base_pin = 3;
int extension_1_pin = 4;
int extension_2_pin = 5;
int extension_3_pin = 6; // wrist extension
int wrist_pin = 7;       // wrist rotation

// DECLARE JOYSTICK PINS AND STATE
// right hand joystick
int y_key_0 = A0;
int x_key_0 = A1;
// lefthand joystick
// int y_key_0 = A2;
// int x_key_0 = A3;
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
  hand.attach(hand_pin);
  // extension_1.attach(base_pin);
  // extension_2.attach(extension_1_pin);
  // extension_3.attach(extension_2_pin);
  // base.attach(extension_3_pin);
  wrist.attach(wrist_pin);

  // hand.write(pos); // Don't override previous position on reboot
  pinMode(y_key_0, INPUT);
  pinMode(x_key_0, INPUT);
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, prevSwitchState);
  // pinMode(y_key_0, INPUT);
  // pinMode(x_key_0, INPUT);
}

void loop()
{
  // READ JOYSTICK INPUT

  switchState = digitalRead(switch_pin);
  x_pos_0 = analogRead(y_key_0);
  y_pos_0 = analogRead(x_key_0);

  // x_pos_1 = analogRead(y_key_0);
  // y_pos_1 = analogRead(x_key_0);

  // CONTROL HAND CLOSING AND OPENING
  // if (switchState == LOW && switchState != prevSwitchState)
  // {
  //   if (hand.read() < 90)
  //   {
  //     hand.write(170);
  //   }
  //   else
  //   {
  //     hand.write(0);
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
  // base.write(pos_1);
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
  // base.write(pos_1);
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
  //   wrist.write(pos_0);
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
  //   wrist.write(pos_0);
  //   delay(50);
  // }
}
