 int valor = 0;    // variable que contiene el valor a sacar por el terminal analógico 
 int motor = 10;  // motor conectado al PIN 10  
int potenciometro=0; // Se define la entrada analógica  
void setup() { } // No es necesario    
void loop() { 
  valor = analogRead(potenciometro); // se lee el valor de la entrada analógica y se asigna a val   
  analogWrite(motor, valor); // Se manda a la salida analógica 0 el valor leído   
  delay(30); // espera 30 ms para que el efecto sea visible   
}
