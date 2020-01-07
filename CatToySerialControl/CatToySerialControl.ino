#include<Servo.h>
#define SERVO_X 9
#define SERVO_Y 10

Servo servoX;
Servo servoY;

String serialData;

void setup()
{
    servoX.attach(SERVO_X);
    servoY.attach(SERVO_Y);
    Serial.begin(9600);
    Serial.setTimeout(10);
}

void loop()
{

}

void serialEvent()
{
    serialData = Serial.readString();
    servoX.write(parseDataX(serialData));
    servoY.write(parseDataY(serialData));
}

int parseDataX(String data)
{
    data.remove(data.indexOf(":"));
    return data.toInt();
}

int parseDataY(String data)
{
    data.remove(0, data.indexOf(":") + 1);
    return data.toInt();
}
