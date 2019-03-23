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

// Declare Joystick Input Pins and State
int x_key = A0;
int y_key = A1;
int switchState;
int switch_pin = 5;
int prevSwitchState = HIGH;

// Declare positions
int x_pos;
int y_pos;
int pos = 0;

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
  pinMode(x_key, INPUT);
  pinMode(y_key, INPUT);
  pinMode(switch_pin, INPUT);
  digitalWrite(switch_pin, prevSwitchState);
}

void loop()
{
  // READ JOYSTICK INPUT
  switchState = digitalRead(switch_pin);
  x_pos = analogRead(x_key);
  y_pos = analogRead(y_key);

  // CONTROL HAND CLOSING AND OPENING

  if (switchState == LOW && switchState != prevSwitchState)
  {
    if (servo_0.read() < 90)
    {
      servo_0.write(170);
    }
    else
    {
      servo_0.write(0);
    }
  }

  prevSwitchState = switchState;

  // Wrist servo can continuously rotate, do not need to set constraints on max angles
  // if (x_pos < 300)
  // {
  //   if (pos >= 10)
  //   {
  //     pos = pos - 5;
  //     servo_5.write(pos);
  //   }
  // }

  // if (x_pos > 700)
  // {
  //   if (pos <= 180)
  //   {
  //     pos = pos + 5;
  //     servo_5.write(pos);
  //   }
  // }

  // CONTROL WRIST ROTATION
  if (x_pos < 300)
  {
    if (pos >= increment)
    {
      pos = pos - increment;
    }
    else
    {
      pos = 0;
    }
    servo_5.write(pos);
    delay(50);
  }
  if (x_pos > 700)
  {
    if (pos <= 180 - increment)
    {
      pos = pos + increment;
    }
    else
    {
      pos = 180;
    }
    servo_5.write(pos);
    delay(50);
  }
}
