int E1 = 10; // Enable Pin for motor 1
int E2 = 11;  // Enable Pin for motor 2
int I1 = 8;  // Control pin 1 for motor 1
int I2 = 9;  // Control pin 2 for motor 1
int I3 = 12; // Control pin 1 for motor 2
int I4 = 13;  // Control pin 2 for motor 2
int E3 = 4;
int E4 = 5;
int k40 = 2;
int k41 = 3;
int k42 = 6;
int k43 = 7;
void setup() {
 
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
    pinMode(E3, OUTPUT);
    pinMode(E4, OUTPUT);
    
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
    pinMode(k40, OUTPUT);
    pinMode(k41, OUTPUT);
    pinMode(k42, OUTPUT);
    pinMode(k43, OUTPUT);
}
 
void loop() {
 
    analogWrite(E1, 153); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
    analogWrite(E3, 153);
    analogWrite(E4, 255);
    
    
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
    digitalWrite(k40, HIGH);
    digitalWrite(k41, LOW);
    digitalWrite(k42, HIGH);
    digitalWrite(k43, LOW);    
 
 
    delay(10000);
 
    // change direction
 
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
    digitalWrite(E3, LOW);
    digitalWrite(E4, LOW);    
    
 
    delay(200);
 
    analogWrite(E1, 255);  // Run in full speed
    analogWrite(E2, 153);  // Run in half speed
    analogWrite(E3, 255);  // Run in full speed
    analogWrite(E4, 153);
   
    
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
    digitalWrite(k40, LOW);
    digitalWrite(k41, HIGH);
    digitalWrite(k42, LOW);
    digitalWrite(k43, HIGH);    
 
    delay(10000);
}
