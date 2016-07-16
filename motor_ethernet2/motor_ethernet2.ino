/*
  www.diymakers.es
  by A.García & M.García
  Crear servidor Web con Arduino
  Tutorial en: http://diymakers.es/crear-servidor-web-con-arduino/
*/
 
#include <SPI.h>  //Importamos librería comunicación SPI
#include <Ethernet.h>  //Importamos librería Ethernet
 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };//Ponemos la dirección MAC de la Ethernet Shield que está con una etiqueta debajo la placa
IPAddress ip(192,168,1,89); //Asingamos la IP al Arduino
EthernetServer server(80); //Creamos un servidor Web con el puerto 80 que es el puerto HTTP por defecto
 
int led=4; //Pin del led
int c1=13;
int c2=12;
int c3=11;
int c4=10;
int c5=9;
int c6=8;
int c7=7;
int c8=6;
int c9=5;
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
pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT);
  pinMode(c6, OUTPUT);
  pinMode(c7, OUTPUT);
  pinMode(c8, OUTPUT);
  
  digitalWrite(c1, HIGH);  
  digitalWrite(c4, HIGH);
  digitalWrite(c7, HIGH);
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
             digitalWrite(c2, LOW); 
 digitalWrite(c3, HIGH);
 
   digitalWrite(c4, LOW);
  digitalWrite(c7, LOW);
    digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
    digitalWrite(c8, LOW);
  digitalWrite(c9, LOW);
            estado="1";
          }
          if(cadena.substring(posicion)=="LED=2")//Si a la posición 'posicion' hay "LED=OFF"
          {
             digitalWrite(c3, HIGH);
 digitalWrite(c2, LOW);
 
    digitalWrite(c4, LOW);
  digitalWrite(c7, LOW);
    digitalWrite(c5, LOW);
  digitalWrite(c6, LOW);
    digitalWrite(c8, LOW);
  digitalWrite(c9, LOW);
            estado="2";
          }
          if(cadena.substring(posicion)=="LED=3")//Si a la posición 'posicion' hay "LED=OFF"
          {
           digitalWrite(c5, LOW);
 digitalWrite(c6, HIGH);
 
    digitalWrite(c1, LOW);
  digitalWrite(c7, LOW);
    digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
    digitalWrite(c8, LOW);
  digitalWrite(c9, LOW);
            estado="3";
          }
          if(cadena.substring(posicion)=="LED=4")//Si a la posición 'posicion' hay "LED=OFF"
          {
           digitalWrite(c6, HIGH);
 digitalWrite(c5, LOW);
 
 digitalWrite(c1, LOW);
  digitalWrite(c7, LOW);
    digitalWrite(c2, LOW);
  digitalWrite(c3, LOW);
    digitalWrite(c8, LOW);
  digitalWrite(c9, LOW);
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
            client.println("1");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=2\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("2");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=3\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("3");
            client.println("</button>");
            client.println("<button onClick=location.href='./?LED=4\' style='margin:auto;background-color: #84B1FF;color: snow;padding: 10px;border: 1px solid #3F7CFF;width:65px;'>");
            client.println("4");
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
