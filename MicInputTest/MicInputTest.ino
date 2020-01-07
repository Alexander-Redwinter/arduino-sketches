
int x = 0;
int xPin = A0;

void setup() {
    
    pinMode(xPin, INPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  x = analogRead(A0);
   Serial.println(x);
   if (x > 200){
    Serial.println("wow loud mate");
    delay(2000);
   }
}
