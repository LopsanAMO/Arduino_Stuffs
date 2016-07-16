/*
  www.diymakers.es
  by A.García & M.García
  Crear servidor Web con Arduino
  Tutorial en: http://diymakers.es/crear-servidor-web-con-arduino/
*/
 
#include <SPI.h>  //Importamos librería comunicación SPI
#include <Ethernet.h>  //Importamos librería Ethernet
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//Ponemos la dirección MAC de la Ethernet Shield que está con una etiqueta debajo la placa
IPAddress ip(192,168,0,45); //Asingamos la IP al Arduino
EthernetServer server(80); //Creamos un servidor Web con el puerto 80 que es el puerto HTTP por defecto
 
int led=6; //Pin del led
int led1 =5;
int led2 =4;
int led3 =3;
String estado="OFF"; //Estado del Led inicialmente "OFF"
 
void setup()
{
  Serial.begin(9600);
 
  // Inicializamos la comunicación Ethernet y el servidor
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
 
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}
 
void loop()
{
  EthernetClient client = server.available(); //Creamos un cliente Web
  //Cuando detecte un cliente a través de una petición HTTP
  if (client) {
    Serial.println("new client");
    boolean currentLineIsBlank = true; //Una petición HTTP acaba con una línea en blanco
    String cadena=""; //Creamos una cadena de caracteres vacía
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();//Leemos la petición HTTP carácter por carácter
        Serial.write(c);//Visualizamos la petición HTTP por el Monitor Serial
        cadena.concat(c);//Unimos el String 'cadena' con la petición HTTP (c). De esta manera convertimos la petición HTTP a un String
 
         //Ya que hemos convertido la petición HTTP a una cadena de caracteres, ahora podremos buscar partes del texto.
         int posicion=cadena.indexOf("LED="); //Guardamos la posición de la instancia "LED=" a la variable 'posicion'
 
          if(cadena.substring(posicion)=="LED=1")//Si a la posición 'posicion' hay "LED=ON"
          {
            digitalWrite(led,HIGH);
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led3,LOW);
            estado="1";
          }
          if(cadena.substring(posicion)=="LED=2")//Si a la posición 'posicion' hay "LED=OFF"
          {
            digitalWrite(led,LOW);
            digitalWrite(led1,HIGH);
            digitalWrite(led2,LOW);
            digitalWrite(led3,LOW);           
            estado="2";
          }
          if(cadena.substring(posicion)=="LED=3")//Si a la posición 'posicion' hay "LED=OFF"
          {
               digitalWrite(led,LOW);
            digitalWrite(led1,LOW);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,LOW);;
            estado="3";
          }
          if(cadena.substring(posicion)=="LED=4")//Si a la posición 'posicion' hay "LED=OFF"
          {
               digitalWrite(led,LOW);
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led3,HIGH);
            estado="4";
          }
           if(cadena.substring(posicion)=="LED=5")//Si a la posición 'posicion' hay "LED=OFF"
          {
               digitalWrite(led,HIGH);
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,HIGH);
            estado="4";
          }
 
        //Cuando reciba una línea en blanco, quiere decir que la petición HTTP ha acabado y el servidor Web está listo para enviar una respuesta
        if (c == '\n' && currentLineIsBlank) {
 
            // Enviamos al cliente una respuesta HTTP
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println();
 
            //Página web en formato HTML
            client.println("<html>");
            client.println("<head>");
            client.println("</head>");
            client.println("<body>");
            client.println("<h1 align='center'>DIYMakers</h1><h3 align='center'>LED controlado por Servidor Web con Arduino</h3>");
            //Creamos los botones. Para enviar parametres a través de HTML se utiliza el metodo URL encode. Los parámetros se envian a través del símbolo '?'
            client.println("<div style='text-align:center;'>");
            client.println("<button onClick=location.href='./?LED=1\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("BAÑO");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=2\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("RECAMARA");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=3\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("CONCINA");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=4\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("SALA");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=5\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("PARTY");
            client.println("</button>");
            client.println("<br /><br />");
            client.println("<b>LED = ");
            client.print(estado);
            client.println("</b><br />");
            client.println("</b></body>");
            client.println("</html>");
            break;
        }
        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    //Dar tiempo al navegador para recibir los datos
    delay(1);
    client.stop();// Cierra la conexión
  }
}
