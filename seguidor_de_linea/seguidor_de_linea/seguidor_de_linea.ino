int p1 = 0;
int p2 = 1;
int p3 = 2;
int p4 = 3;
int p5 = 4;
int E1 = 10;
int E2 = 11;
int I1 = 8; 
int I2 = 9; 
int I3 = 12;
int I4 = 13;
int Vel0 = 100;
int Vel1 = 155;
int Vel2 = 190; 
int Vel3 = 230;
int Vel = 255;
void setup(){
Serial.begin(9600);

pinMode( p1 , INPUT );
pinMode( p2 , INPUT );
pinMode( p3 , INPUT );
pinMode( p4 , INPUT );
pinMode( p5 , INPUT );
pinMode(E1, OUTPUT);
pinMode(E2, OUTPUT); 
pinMode(I1, OUTPUT);
pinMode(I2, OUTPUT);
pinMode(I3, OUTPUT);
pinMode(I4, OUTPUT);
}//setup

void loop(){ 
int h = analogRead(p1);
int h1 = analogRead(p2);
int h2 = analogRead(p3);
int h3 = analogRead(p4);
int h4 = analogRead(p5);
if((h2 < 180) && (h > 250) && (h1 > 250 ) && (h3 > 200) && (h4 < 10)){
    analogWrite(E1, 255);
    analogWrite(E2, 255);
 
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
}
else if((h1 < 250) && (h > 250) && (h2 > 180) && (h3 > 200) && (h4 < 10) ){
  analogWrite(E1, 123);
  analogWrite(E2, 255);
 
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);  
}
else if((h < 250) && (h1 > 250) && (h2 > 180) && (h3 > 200) && (h4 < 10)){
  analogWrite(E1, 0);
  analogWrite(E2, 255);
 
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);  
}
else if((h3 < 200) && (h > 250) && (h1 > 250) && (h2 > 180) && (h4 < 10)){
  analogWrite(E1, 255);
  analogWrite(E2, 123);
 
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);  
}
else if((h4 > 10) && (h3 > 200) && (h > 250) && (h1 > 250) && (h2 > 180)){
  analogWrite(E1, 255);
  analogWrite(E2, 0);
 
  digitalWrite(I1, HIGH);
  digitalWrite(I2, LOW);
  digitalWrite(I3, HIGH);
  digitalWrite(I4, LOW);  
}
delay(50);
Serial.print( analogRead ( p1 ) );
Serial.print( " " );
Serial.print( analogRead ( p2 ) );
Serial.print( " " ); 
Serial.print( analogRead ( p3 ) );
Serial.print( " " ); 
Serial.print( analogRead ( p4 ) );
Serial.print( " " ); 
Serial.print( analogRead ( p5 ) );
Serial.print( " " ); 
Serial.println();
Serial.flush(); 
delay(50);
}//loop
