//Rodrigo Queiroz de Francischi 

#include <Servo.h>  
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 9;
int led= 10;
long duration, distancia, average;   
long aver[3];  



void setup() {
  pinMode(13,OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  

         
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);        
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
distancia = (duration/2) / 29.1;   
}
void loop() { 
  digitalWrite(13,1);
  digitalWrite(12,0);
  digitalWrite(11,0);
  
  for (int i=0;i<=2;i++) { 
    measure();               
   aver[i]=distancia;            
    delay(10);              
  }
 distancia=(aver[0]+aver[1]+aver[2])/3;    

if ( distancia<20 ) {
  Serial.println("A lixeira foi aberta");
  delay(1000);
  digitalWrite(13,0);
  delay(1000);
  digitalWrite(12,1);
  delay(900);
  digitalWrite(12,0);
  digitalWrite(11,1);
 servo.attach(servoPin);
  delay(500);
 servo.write(0);  
 delay(10000);
 digitalWrite(11,1);   
 digitalWrite(11,0); 
 digitalWrite(12,1);
 delay(2000);
 digitalWrite(12,0);
 servo.write(150);    
 delay(10);
 Serial.println("A lixeira foi fechada");
 servo.detach();  
     
}


}
