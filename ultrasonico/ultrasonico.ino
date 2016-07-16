int pingPin = 13; //Pin que emite los sonidos, Trig
int entradaPin = 12; //Pin que va a recibir de vuelta la onda
 
int ledRojo = 5; //LED rojo va en pin 5
int ledVerde = 7; //LED verde va en pin 7
 
/*Con esta variable podremos encender el LED rojo cuando
la distancia sea demasiado corta, puede ser
cambiada con solo cambiar el valor, ese valor esta en cm
*/
int zonaSegura = 10;
 
void setup(){
  
  //Inicializamos los pines como entradas y salidas
  pinMode(pingPin, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(entradaPin, INPUT);
  
  Serial.begin(9600); //Inicializamos la comunicacion serial
  
}
 
void loop(){
  
  //Creamos 2 variables, una para la duracion y otra para la distancia
  long duracion, distanciaEnCm;
  
  /*
  Hacemos un pulso bajo-alto-bajo para encender el sensor
  Al encender y apagar esperamos en microsegundos, de esta
  manera enviaremos nuestra primer onda
  */
  digitalWrite(pingPin, LOW); // Envía un pulso bajo
  delayMicroseconds(2);       // Espera dos microsegundos
  digitalWrite(pingPin, HIGH);// Envía un pulso alto
  delayMicroseconds(5);       // Espera 5 microsegundos
  digitalWrite(pingPin, LOW); // Se queda en espera
  
  /*Obtenemos la duracion de tiempo mientras
  el sensor este recibiendo la informacion
  */
  duracion = pulseIn(entradaPin, HIGH);
  
  /*
  Convertimos la duracion del tiempo a distancia
  La velocidad del sonido es de 340metros/segundo que 
  es igual a 29 microsegundos por centimetro es por es
  que vamos a dividir la duracion entre 29. 
  Despues se divide entre 2 porque es el tiempo que viaja
  el sonido de ida y de vuelta, solo queremos un valor pero
  ambos son iguales, es por eso que solo dividimos
  entre 2
  */
  distanciaEnCm = (duracion/29)/2;
  
  //Imprimimos la distancia en consola
  Serial.print(distanciaEnCm);
  Serial.print("cm");
  Serial.println();
  
  /*Prendemos los LED's, cuando la distancia es
  mayor a la zona segura se prende el LED verde y
  se apaga el rojo. Cuando la distancia es menor
  a la zona segura se prende el LED rojo y se apaga el LED
  verde
  */
  if(distanciaEnCm > zonaSegura){
  
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
      
  }
  else{
    
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
    
  }
  
  //Hacemos un delay antes de volver a sensar
  delay(100);
  
}
