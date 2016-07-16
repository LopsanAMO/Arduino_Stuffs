int boton = 7;
int boton2 = 6;
int valor2 = 0;
int valor = 0;
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(boton,INPUT);
     pinMode(boton2,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  valor = digitalRead(boton);
  valor2 = digitalRead(boton2);
   if(valor==1){
  digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
  if(valor2 == 1){
  digitalWrite(13,HIGH);
  }
  else{
  digitalWrite(13,LOW);

  } 
 
              // wait for a second
}
