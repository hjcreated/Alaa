#include<AFMotor.h>
AF_DCMotor rightMotor(4); //create motor #1 using M3 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor(2); //create motor #2 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
char state = 0;
void setup() {
pinMode(50,OUTPUT);
pinMode(52,OUTPUT);

pinMode(52,OUTPUT);
digitalWrite(52,HIGH); 
digitalWrite(50,HIGH); 
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){

  state = Serial.read();
if(state == '1'){backward();}
if(state == '2'){forward();}
if(state == '3'){right();}
if(state == '4'){left();}
if(state == '0'){Stop();}
}






}//loop
void forward(){
   rightMotor.run(FORWARD);
   leftMotor.run(FORWARD);
   rightMotor.setSpeed(150);
   leftMotor.setSpeed(150);
       }
       
void backward(){
  rightMotor.run(BACKWARD);
   leftMotor.run(BACKWARD);
   rightMotor.setSpeed(150);
   leftMotor.setSpeed(150);
   
  }
void left(){
  rightMotor.run(FORWARD);
   leftMotor.run(BACKWARD);
   rightMotor.setSpeed(150);
   leftMotor.setSpeed(150);
}
void right(){
  rightMotor.run(BACKWARD);
   leftMotor.run(FORWARD);
   rightMotor.setSpeed(150);
   leftMotor.setSpeed(150);
   
  }
void Stop(){
   rightMotor.run(RELEASE);
   leftMotor.run(RELEASE);
   rightMotor.setSpeed(0);
   leftMotor.setSpeed(0);
   }

