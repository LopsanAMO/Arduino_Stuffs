#include <Bridge.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

int led = 11;
int boton = 12;
int valor = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(boton,INPUT);
pinMode(led,OUTPUT);
digitalWrite(led,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor = digitalRead(boton);
  if(valor==1){
  digitalWrite(led,HIGH);
  Serial.write(valor);
  }
  else{
    digitalWrite(led,LOW);
    Serial.write(valor);
  }
  delay(100);
}
