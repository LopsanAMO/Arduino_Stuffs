int lightPin = 0;

int ledPin1 = 7;
int ledPin2 = 6;
int ledPin3 = 5;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
}
void loop (){
Serial.println(analogRead(lightPin));

// Ahora cogemos la lectura de la fotoresistencia, la
// dividimos por 4 y la mandamos como salida analogica
// al LED
int hola = analogRead(lightPin);
analogWrite(ledPin1, analogRead(lightPin)/4);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
if(hola > 966){
digitalWrite(ledPin3, LOW);
}
// Hacemos una pequeña pausa para que el baile de
// numeros en el puerto serie no sea mareante
delay(100);
}

