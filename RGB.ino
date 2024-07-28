//Initialize pins 
const int red=2;
const int green=3;
const int blue=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red,HIGH);
  delay(100);
  digitalWrite(red,LOW);
  delay(100);
  digitalWrite(green,HIGH);
  delay(100);
  digitalWrite(green,LOW);
  delay(100);
  digitalWrite(blue,HIGH);
  delay(100);
  digitalWrite(blue,LOW);
  delay(100);

}
