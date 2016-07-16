float temperatura;
int tempin = 0;
int led1 = 13;
int led2 = 12;
int led3 = 11;

void setup() {
  
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led2,OUTPUT);

}

void loop () {
  
  temperatura = analogRead(tempin);
  temperatura = temperatura * 0.48828125;
  Serial.print("Temperatura = ");
  Serial.print(temperatura);
  Serial.print(" C");
  Serial.println();
  delay(999);


  if(temperatura < 30 && temperatura > 27){
  digitalWrite(led1, HIGH); 
  }
  else if((temperatura < 27) && (temperatura > 24)){
  digitalWrite(led2, HIGH);
  }
  else if(temperatura > 0 ){
  digitalWrite(led1, HIGH);
  }
}

  
