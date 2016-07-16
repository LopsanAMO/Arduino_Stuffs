#include <Bridge.h>
#include <Temboo.h>
#include "TembooAccount.h"
 
const String GMAIL_USER_NAME = "makiko787@gmail.com";
const String GMAIL_PASSWORD = "vzgvufggvrznabbd";
const String TO_EMAIL_ADDRESS = "masterofhalo9000@hotmail.com";
int led = 11;
int boton = 12;
int valor = 0; 
boolean action = true; 
 
/**
  * Funcion que manda un correo haciendo uso de Temboo.
  */
void mandarCorreo() {
    // Creacion de un objeto para mandar el correo.
    TembooChoreo SendEmail;
    SendEmail.begin();
    
    // Credenciales de la cuenta Temboo (las coge de TembooAccount.h)
    SendEmail.setAccountName(TEMBOO_ACCOUNT);
    SendEmail.setAppKeyName(TEMBOO_APP_KEY_NAME);
    SendEmail.setAppKey(TEMBOO_APP_KEY);
    // Ruta de la libreria que hemos linstalado (Google > Gmail > SendEmail)
    SendEmail.setChoreo("/Library/Google/Gmail/SendEmail");
 
    // Configuracion de parametros: usuario, contraseña y destinatario 
    SendEmail.addInput("Username", GMAIL_USER_NAME);
    SendEmail.addInput("Password", GMAIL_PASSWORD);
    SendEmail.addInput("ToAddress", TO_EMAIL_ADDRESS);
    // Asunto del correo
    SendEmail.addInput("Subject", "Este es un mensaje enviado desde una arduino YUN");
    // Cuerpo del correo   
    SendEmail.addInput("MessageBody", "Que chinge a su madre el america");
 
    // Cuando ejecutemos el metodo run() devolvera un valor:
    //     0 -> exito en el envio.
    //     1 -> error en el envio.
    unsigned int returnCode = SendEmail.run();
 
    if (returnCode == 0) {
        Serial.println("Success! Email sent!");
    } else {
      // Mostramos el error por monitor serial.
      while (SendEmail.available()) {
        char c = SendEmail.read();
        Serial.print(c);
      }
    } 
    SendEmail.close();
}
 
void setup() {
  Serial.begin(9600);
  Bridge.begin();
  pinMode(boton,INPUT);
pinMode(led,OUTPUT);
digitalWrite(led,HIGH);
}
 
void loop() {
  // Mandar el correo electronico si ha ocurrido alguna accion
  
  // como pulsar un boton, leer un valor de un sensor, etc.
  valor = digitalRead(boton);
 
   if(action){
      digitalWrite(led,HIGH);
 mandarCorreo();
       action = false;
  }
  else{
    digitalWrite(led,LOW);
  }
  
}
