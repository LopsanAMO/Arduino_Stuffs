#include <Servo.h>

Servo ServoPablo; //Declaramos que queremos controlar un Servo, al cual le vamos a poner un nombre cualquiera

int pot = 0; //El pin análogo donde va conectado el Potenciómetro
int val; //El valor a leer por el puerto análogo
int led1 = 13;
int led2 = 12;
int led3 = 11;
int boton1 = 2; //Encender
int boton2 = 4; //Apagar</code>
int boton3 = 7; //Encender
int servoval1=90;
void setup()
{
ServoPablo.attach(9); //El pin al cual conectaremos nuestro Servo
   Serial.begin(9600);
pinMode(led1, OUTPUT); 
pinMode(led2, OUTPUT); 
pinMode(led3, OUTPUT); 
pinMode(boton1, INPUT);
pinMode(boton2, INPUT);
pinMode(boton3, INPUT);
}

void loop()
{
val = analogRead(pot); //Aquí le decimos que lea el valor del potenciómetro, valor el cual oscila entre 0 y 1023
val = map(val, 0 ,1023, 0, 180); //Traduce la lectura análga (0, 1023) a grados (0°, 180°)
 //Mueve el Servo según la lectura análoga

if(digitalRead(boton2)==HIGH){
    //Si el boton de seleccion "Servo1" esta presionado
    if(digitalRead(boton1)==HIGH && digitalRead(boton3)==LOW){
      //Si al mismo tiempo está presionado el boton de direccion "Izquierda"
      val = val-60;
    }
    else if(digitalRead(boton1)==LOW && digitalRead(boton3)==HIGH){
      //Si al mismo tiempo está presionado el boton de direccion "Derecha"
      val = val+60;
    }
  }
  if(val > 0 && val < 60){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);  
    digitalWrite(led3, LOW);    
}
if(val > 60 && val < 120){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);  
    digitalWrite(led3, LOW);    
}
if(val > 120 && val < 181){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);  
    digitalWrite(led3, HIGH);    
}
 ServoPablo.write(val);
   Serial.println(val);
delay(15);

}
