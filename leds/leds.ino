int led1 = 11; /*PROGRAMA QUE ACTIVA CADA 500ms LOS PINES 6, 16 Y 26*/
int led2 = 12; // Se definen nombre de las constantes
int led3 = 13;
//Configuracion de los pines.
void setup() {
 pinMode(led1, OUTPUT); 
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 digitalWrite(led1, LOW); 
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW); }
void loop() {
 digitalWrite(led1, HIGH); 
 delay(50); 
 digitalWrite(led1, LOW); 
 delay(50);
 digitalWrite(led2, HIGH);
 delay(50);
 digitalWrite(led2, LOW);
 delay(50);
 digitalWrite(led3, HIGH);
 delay(50);
 digitalWrite(led3,LOW);
 delay(50); 
 }
