
// header files
#include <NewPing.h>
#include<Servo.h>
#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 100
Servo servo_1;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

// variable declaration
long duration;
int distance;
const int buzzer = 5;
const int LM_35 = A0;
int input_val = 0;
float temp = 0;

// function declaration - setting for initial setup
void setup() 
{
  pinMode(buzzer,OUTPUT);
  servo_1.attach(3);
  pinMode(6,OUTPUT); 
  pinMode(TRIGGER_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  Serial.begin(9600); 
  Serial.println("Temperature ,Distance ");
}

// function declaration - setting for again conditions
void loop() 
{
  input_val = analogRead(LM_35);
  temp = (5.0 * input_val * 100)/1024;
  servo_1.write(60);
  delay(1000);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance= duration*0.034/2;
  if(distance<30)
  {
    digitalWrite(buzzer,HIGH);
    analogWrite(6,1000);
    delay(200);
  }
  if(distance>=30)
  {
    digitalWrite(buzzer,LOW);
    analogWrite(6,0);
    delay(200);
  }
  servo_1.write(120);
  delay(1000);
  Serial.print("The Temperature is ");
  Serial.print(temp);
  Serial.print(",and the distance is ");
  Serial.println(distance);
}

