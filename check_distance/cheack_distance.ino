int E1 = 10;  // Enable Pin for motor 1
int E2 = 11;  // Enable Pin for motor 2
 
int I1 = 8;  // Control pin 1 for motor 1
int I2 = 9;  // Control pin 2 for motor 1
int I3 = 12; // Control pin 1 for motor 2
int I4 = 13;  // Control pin 2 for motor 2
int trigger=6;
int echo=7;
int dis;
float distance;
int ledr = 0;
int ledv = 1; 
void setup() {
  pinMode(trigger,OUTPUT);
    pinMode(echo,INPUT);
 pinMode(ledr, OUTPUT),
       pinMode(ledr, OUTPUT);
    pinMode(E1, OUTPUT);
    pinMode(E2, OUTPUT);
 
    pinMode(I1, OUTPUT);
    pinMode(I2, OUTPUT);
    pinMode(I3, OUTPUT);
    pinMode(I4, OUTPUT);
}
 
void loop() {
   
// Comenzamos las mediciones
// Enviamos una señal activando la salida trigger durante 10 microsegundos
  digitalWrite(trigger, LOW); // Envía un pulso bajo
  delayMicroseconds(2); 
  digitalWrite(trigger,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger,LOW);
// Adquirimos los datos y convertimos la medida a metros
 distance=pulseIn(echo,HIGH); // Medimos el ancho del pulso 
                              // (Cuando la lectura del pin sea HIGH medira 
                              // el tiempo que transcurre hasta que sea LOW
 //distance=distance*0.017;
  dis=(distance/29)/2; 
// Enviamos los datos medidos a traves del puerto serie y al display LCD
   if(dis >12){
    analogWrite(E1, 255); // Run in half speed
    analogWrite(E2, 255); // Run in full speed
 
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
 
    delay(10000);
 
    // change direction
 
    digitalWrite(E1, LOW);
    digitalWrite(E2, LOW);
 
    delay(200);
 
    analogWrite(E1, 255);  // Run in full speed
    analogWrite(E2, 255);  // Run in half speed
 
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
 
    delay(10000);
   }
   if(dis < 11){
       digitalWrite(ledr, LOW);
   digitalWrite(ledv, HIGH);    
    analogWrite(E1, 0);
    analogWrite(E2, 0); 
    digitalWrite(I1, LOW);
    digitalWrite(I2, LOW);
    digitalWrite(I3, LOW);
    digitalWrite(I4, LOW);
     delay(100);
   }
   delay(100);
}
