
int irPin = A0;
int sensorOut = 0;
void setup()
{
  
    pinMode(irPin, INPUT);
    Serial.begin(9600);
}

void loop() 
{
  
 sensorOut = analogRead(irPin);
 Serial.println(sensorOut);

}
