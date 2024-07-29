const int buzzer=6; //Initialize buzzer pin
const int led=5; //Initialize led pin
const int pir=7; //Initialize pir sensor pin
void setup() {
  // put your setup code here, to run once:
  //setup the connected digital pins
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Make the code if it is high turn on the LED and the BUZZER
if(digitalRead(pir)==HIGH)
{
  digitalWrite(buzzer,HIGH);
  digitalWrite(led,HIGH);
  delay(2000);
  Serial.println("Motion detected");
}
else
{
  digitalWrite(buzzer,LOW);
  digitalWrite(led,LOW);
  delay(1000);
  Serial.println("Motion not detected");
}
}
