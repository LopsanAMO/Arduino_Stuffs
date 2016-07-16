int led = 13;
int b1 = 0;
int b2 = 1;
int c1 = 2;
int c2 = 3;
int c3 = 4;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  digitalWrite(c3, HIGH);
  digitalWrite(led,LOW);
}
void loop() {
if(digitalRead(b1) == HIGH){
  digitalWrite(led,HIGH);
}
else{
  digitalWrite(led,LOW);
}
if(digitalRead(b2) == HIGH){
   digitalWrite(c1,LOW);
   digitalWrite(c2,HIGH);
}
else{
    digitalWrite(c1,HIGH);
   digitalWrite(c2,LOW);  
}
}
