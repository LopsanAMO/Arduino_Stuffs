int c1=13;
int c2=12;
int c3=11;
int c4=10;
int c5=9;
int c6=8;
void setup() {
  // put your setup code here, to run once:
pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT);
  pinMode(c6, OUTPUT);
  digitalWrite(c1, HIGH);  
  digitalWrite(c4, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(c2, LOW); 
 digitalWrite(c3, HIGH);
 delay(2000);
 digitalWrite(c2, HIGH); 
 digitalWrite(c3, LOW);
 delay(2000);
 digitalWrite(c5, HIGH); 
 digitalWrite(c6, LOW);
 delay(2000);
 digitalWrite(c5, HIGH); 
 digitalWrite(c6, LOW);
 delay(2000);
}
