//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

This program will test the LCD panel and the buttons
Mark Bramwell, July 2010

********************************************************/

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// define some values used by the panel and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
const int trigger=6;
const int echo=7;
float distance;
int led = 0; //Pin del led
int led1 = 1;
int led2 = 30;
int led3 = 31;
int led4 = 32;
int led5 = 33;
int led6 = 34;
int led7 = 35;
int led8 = 36;
int led9 = 37;
// read the buttons

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Distancia: "); // print a simple message
 Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}
 
void loop()
{
  
  delayMicroseconds(5);
// Comenzamos las mediciones
// Enviamos una señal activando la salida trigger durante 10 microsegundos
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
// Adquirimos los datos y convertimos la medida a metros
 distance=pulseIn(echo,HIGH); // Medimos el ancho del pulso 
                              // (Cuando la lectura del pin sea HIGH medira 
                              // el tiempo que transcurre hasta que sea LOW
 distance=distance*0.017;
 int dis = distance;
// Enviamos los datos medidos a traves del puerto serie y al display LCD
  Serial.write(dis  );
 


 lcd.setCursor(0,1);            // move to the begining of the second line
  lcd.print(distance);
  
   if (distance < 101) //Si a la posición 'posicion' hay "LED=ON"
        {
          
              digitalWrite(led, HIGH);
          digitalWrite(led1, LOW);   
        }
        if (distance < 91) //Si a la posición 'posicion' hay "LED=OFF"
        {
          digitalWrite(led, LOW);
          digitalWrite(led1, HIGH);
                }
      
  
 delay(100);

}
