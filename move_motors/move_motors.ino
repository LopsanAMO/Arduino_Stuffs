int c1=13;
int c2=12;
int c3=11;
int c4=10;
int c5=9;
int c6=8;
int c7=7;
int c8=6;
int c9=5;

void setup(){

  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT);
  pinMode(c6, OUTPUT);
  pinMode(c7, OUTPUT);
  pinMode(c8, OUTPUT);
  
  digitalWrite(c1, HIGH);  
  digitalWrite(c4, HIGH);
  digitalWrite(c7, HIGH);
}

void loop(){
 
 digitalWrite(c2, LOW); 
 digitalWrite(c3, HIGH);
 delay(2000);
 digitalWrite(c2, HIGH);
 digitalWrite(c3, LOW);
 delay(2000);
 digitalWrite(c5, LOW);
 digitalWrite(c6, HIGH);
 delay(2000);
 digitalWrite(c5, HIGH);
 digitalWrite(c6, LOW);
 delay(2000);
 digitalWrite(c8, LOW);
 digitalWrite(c9, HIGH);
 delay(2000);
 digitalWrite(c8, HIGH);
 digitalWrite(c9, LOW);
 delay(2000);
 
}

