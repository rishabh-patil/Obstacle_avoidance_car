
//Servo
#include <Servo.h>
Servo myservo;
int pos = 90;  
int echoPin=13;
int trigPin=12; 
long duration; 
int distance; 
//bluetooth
word Incoming_value = 0; 
// Motors 
int right_motor_1 = 5;
int right_motor_2 = 4;
int left_motor_1 = 6;
int left_motor_2 = 7;
int enable_left = 3;
int enable_right = 9;
// Line Sensors
int ls_R = 0;
int ls_C = 1;
int ls_L = 2;

//

void setup() 
{
  Serial.begin(9600);        
  pinMode(right_motor_1, OUTPUT);
  pinMode(right_motor_2, OUTPUT);
  pinMode(left_motor_1, OUTPUT);
  pinMode(left_motor_2, OUTPUT);
  pinMode(enable_left,OUTPUT);
  pinMode(enable_right,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin, OUTPUT);
  
  
}


void loop()
{
  //Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
    //Serial.println(distance);
  //  Serial.println(Incoming_value);

   if (distance<50){
     Incoming_value = Serial.read();
          
    if(Incoming_value == 'b'){
     delay(500);
     backward();
    }
    else if(Incoming_value == 'r'){
      right();      
    }
    else if(Incoming_value == 'l'){
     left();
    }
    else {
     hold();
    }
    
        
      } 
  else {
//  if(Serial.available() > 0)  
//  { 
    Incoming_value = Serial.read(); 
       
//    Serial.print(Incoming_value);        
//    Serial.print("\n"); 
    
    if(Incoming_value == 'b'){
     backward();
    }
      
    else if(Incoming_value == 'f'){
      
        
      forward();
    }
    else if(Incoming_value == 'r'){
      right();      
    }
    else if(Incoming_value == 'l'){
     left();
    }
    else if(Incoming_value == 'h'){
     hold();
    }
      
                              
 
//  }
  } }   
void backward(){
   analogWrite(enable_left,120);
      analogWrite(enable_right,120);
      digitalWrite(right_motor_1, LOW);
      digitalWrite(right_motor_2, HIGH);
      digitalWrite(left_motor_1, LOW);
      digitalWrite(left_motor_2, HIGH);
  }
void forward(){
      analogWrite(enable_left,120);
      analogWrite(enable_right,120);
      digitalWrite(right_motor_1, HIGH);
      digitalWrite(left_motor_1, HIGH);
      digitalWrite(right_motor_2, LOW);
      digitalWrite(left_motor_2, LOW);
  }
void hold(){
      analogWrite(enable_left,0);
      analogWrite(enable_right,0);
      digitalWrite(right_motor_1, LOW);
      digitalWrite(left_motor_1, LOW);
      digitalWrite(right_motor_2, LOW);
      digitalWrite(left_motor_2, LOW);
  }  
void right(){
      analogWrite(enable_left,100);
      analogWrite(enable_right,100);
      digitalWrite(right_motor_1, HIGH);
      digitalWrite(right_motor_2, LOW);
      digitalWrite(left_motor_1, LOW);
      digitalWrite(left_motor_2, HIGH);
      delay(680);
      Incoming_value ='F';
      forward();
      
   
      
  } 
void left(){
      analogWrite(enable_left,100);
      analogWrite(enable_right,100);
      digitalWrite(right_motor_1, LOW);
      digitalWrite(right_motor_2, HIGH);
      digitalWrite(left_motor_1, HIGH);
      digitalWrite(left_motor_2, LOW);
      delay(680);
      Incoming_value = 'F';
      forward();
      
  
  }

          
