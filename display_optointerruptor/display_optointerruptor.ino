int a = 2;
int b = 3;
int c = 6;
int d = 5;
int e = 4;
int f = 1;
int g = 0;

//Contador que llevara el registro de las veces que se interrumpe
int Cont = 0;
int tiempo = 300;
int pinSensor = 12; //Pin de entrada que se utilizara
int estadoSensor = 0; //Variable que indica si el optointerruptor envia un 1 o un 0

void setup(){ //Se configuran todos los pines del display como salidas
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(pinSensor, INPUT); //Se configura el pin del optointerruptor como entrada
}


void loop(){
  estadoSensor = digitalRead(pinSensor); //lee el estado del sensor
  if (estadoSensor == HIGH) //Si el sensor es interrumpido entra al proceso
  {
    Cont += 1; //Aumenta el contador para indicar en que numero va
    if (Cont == 0) //Dependiendo del valor del contador entrara a la condicion para escribir en el display
    {
      //Cero
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,HIGH); 
      delay(tiempo);
    }
    if (Cont == 1)
    {
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH); 
      delay(tiempo);
    }
    if (Cont == 2)
    {
      //Dos
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,HIGH);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 3)
    {
      //Tres
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 4)
    {
      //Cuatro
      digitalWrite(a,HIGH);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 5)
    {
      //Cinco
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 6)
    {
      //Seis
      digitalWrite(a,LOW);
      digitalWrite(b,HIGH);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 7)
    {
      //Siete
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,HIGH);
      digitalWrite(g,HIGH);
      delay(tiempo);
    }
    if (Cont == 8)
    {
      //Ocho
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,LOW);
      digitalWrite(e,LOW);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(tiempo);
    }
    if (Cont == 9)
    {
      //Nueve
      digitalWrite(a,LOW);
      digitalWrite(b,LOW);
      digitalWrite(c,LOW);
      digitalWrite(d,HIGH);
      digitalWrite(e,HIGH);
      digitalWrite(f,LOW);
      digitalWrite(g,LOW);
      delay(tiempo);
      Cont = -1;
    }
  } 
}

