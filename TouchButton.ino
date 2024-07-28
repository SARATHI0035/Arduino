//Initialize pins 
const int touch=2;
const int led=6;
const int buzz=9;
void setup() {
  // put your setup code here, to run once:
 pinMode(led,OUTPUT);
 pinMode(buzz,OUTPUT);
 pinMode(touch,INPUT);
 Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //if touch button get touched it will send high signal to turn on the buzzer and led 
  if(digitalRead(touch)==HIGH)
  {
    digitalWrite(led,HIGH);
    //tone is used to change sound frequency
    tone(buzz,500);
    Serial.println("Turn on");
    delay(2000);
    
  }
  else
  {
    digitalWrite(led,LOW);
    noTone(buzz);
    Serial.println("Turned off");
    delay(1000);
    
  }
}
