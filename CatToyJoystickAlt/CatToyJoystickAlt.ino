#include<Servo.h>
#define SERVO_X 9
#define SERVO_Y 10
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_SWITCH 2

Servo servoX;
Servo servoY;

int joystickX = 0;
int joystickY = 0;
int x = 0;
int y = 0;
int _switch = 0;
int increment = 1;


void setup()
{

    //This enables the 20k pull up resistor on that pin. The input will no longer be floating when the button is not pressed.
    pinMode(JOYSTICK_SWITCH, INPUT_PULLUP);
    
    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);

    servoX.attach(SERVO_X);
    servoY.attach(SERVO_Y);
    servoX.write(0);
    servoY.write(0);
    Serial.begin(9600);
    Serial.setTimeout(10);
}


void loop()
{
    joystickX = analogRead(JOYSTICK_X);
    joystickY = analogRead(JOYSTICK_Y);

    _switch = digitalRead(JOYSTICK_SWITCH);
    Serial.println(_switch);
    if(_switch == 1)
    {
      incrementalMove();
    }
    else
    {
      relativeMove();
    }

    
    if (x > 180)
    {
      x = 180;
    }
    if (x < 0)
    {
      x = 0;
    }
    
    if (y > 180)
    {
      y = 180;
    }
    if (y < 0)
    {
      y = 0;
    }
    servoX.write(x);
    servoY.write(y);
    delay(50);
}

void relativeMove()
{
    x = joystickX / 5;
    y = joystickY / 5;
}

void incrementalMove()
{
   if (joystickX <= 100)
    {
      x = x + increment;
    }
    else if(joystickX >= 1000)
    {
      x = x - increment;
    }

    
    if (joystickY <= 100)
    {
      y = y - increment;
    }
    else if(joystickY >= 1000)
    {
      y = y + increment;
    }
}
