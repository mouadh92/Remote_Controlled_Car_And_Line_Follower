#include <Servo.h>
Servo myservo;
int pos = 0;
  
const int pin1 = A0;
const int pin2 = A1;
const int pin3 = A2;
const int pin4 = A3;
const int pin5 = A4;

int DS1 = 0;
int DS2 = 0;
int DS3 = 0;
int DS4 = 0;
int DS5 = 0;

const int sensorPin = 2;
int pinstate;
int DIR1 = 4; //LEFTDIR
int PWM1 = 5; //LEFTSPD
int DIR2 = 7; //RIGHTDIR
int PWM2 = 6; //RIGHTSPD

int BT=2;
char state;
unsigned long Start;
int key=0;

void setup() 
{
  
  pinMode(sensorPin, INPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM2,OUTPUT);
   pinMode(pin1, INPUT);
   pinMode(pin2, INPUT);
   pinMode(pin3, INPUT);
   pinMode(pin4, INPUT);
   pinMode(pin5, INPUT);
   myservo.attach(9);
  Serial.begin(38400);
}

void loop()
{
  
  if(key == 1)
  {
  autonomous();
  state= Serial.read();
  if( state == 'O')
  key=0;
  }
  
  else
  {
    digitalWrite(BT,LOW);
    if(Serial.available()>0)
    {
      state = Serial.read();
      Start = millis();
      if(state == 'F')
      forward();
      else if(state == 'B')
      backward();
      else if(state == 'R')
      right();
      else if(state == 'L')
      left();
      else if(state == 'S')
      {
     myservo.write(180);
      }
      else if(state == 'K')
      {
        myservo.write(0);
      }
      else if(state == 'N')
      turboright();
      else if(state == 'M')
      turboleft();
      else if(state == 'A')
      key=1;
      
    }
   else if(millis()-Start >=500)
   {
    stopmove();
   }
    
  }
}
void autonomous()
{
  pinstate = digitalRead(sensorPin);
  if (pinstate==LOW)                //If there is obstacle, it will perform if operation
  {
    stopmove(); 
    avoid();
  }
  else
  {
    followline();
  }
}
void followline()
{
  DS1 = digitalRead(pin1);
  DS2 = digitalRead(pin2);
  DS3 = digitalRead(pin3);
  DS4 = digitalRead(pin4);
  DS5 = digitalRead(pin5);

  if (DS1 == 0 && DS2 == 0 && DS3 == 1 && DS4 == 1 && DS5 == 1)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,80);          //turn left
  analogWrite(PWM2,150);

  }
  else if (DS1 == 0 && DS2 == 1 && DS3 == 1 && DS4 == 1 && DS5 == 1)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,50);          //turn left more
  analogWrite(PWM2,150);

  }
  else if (DS1 == 1 && DS2 == 0 && DS3 == 0 && DS4 == 1 && DS5 == 1)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,150);          //go straight
  analogWrite(PWM2,150);

  }
  else if (DS1 == 1 && DS2 == 1 && DS3 == 0 && DS4 == 0 && DS5 == 1)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,150);          //go straight
  analogWrite(PWM2,150);

  }
  else if (DS1 == 1 && DS2 == 1 && DS3 == 1 && DS4 == 1 && DS5 == 0)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,150);          //turn right more
  analogWrite(PWM2,50);

  }
  else if (DS1 == 1 && DS2 == 1 && DS3 == 1 && DS4 == 0 && DS5 == 0)
  {
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,150);          //turn right
  analogWrite(PWM2,80);

 }
}

void forward()
{
    digitalWrite(DIR1,LOW);         //Low is forward, left wheel go fwd
    digitalWrite(DIR2,LOW);         //right wheel fwd
    analogWrite(PWM1,200);
    analogWrite(PWM2,245);
    
}
void stopmove()
{
    digitalWrite(DIR1,LOW); 
    analogWrite(PWM1,0);            //Left wheel stop
    digitalWrite(DIR2,LOW); 
    analogWrite(PWM2,0);             //Right wheel stop
    delay(1000);
    
}

void avoid()
{
    digitalWrite(DIR1,LOW);         //turn left
    analogWrite(PWM1,100);
    digitalWrite(DIR2,LOW);         
    analogWrite(PWM2,230);
    delay(1000);
    
    analogWrite(PWM1,180);          //turn right
    analogWrite(PWM2,0);
    delay(500);

    //analogWrite(PWM1,100);          //turn left again
    //analogWrite(PWM2,255);
    //delay(1000);
}
void right()
{
  digitalWrite(DIR1,LOW);         //turn left
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,100);          //turn right
  analogWrite(PWM2,20);
  
}
void backward()
{
    digitalWrite(DIR1,HIGH);         //Low is forward, left wheel go fwd
    digitalWrite(DIR2,HIGH);         //right wheel fwd
    analogWrite(PWM1,255);
    analogWrite(PWM2,245);
    
}
void left()
{
  digitalWrite(DIR1,LOW);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,20);          //turn left
  analogWrite(PWM2,100);
}
void turboright()
{
  digitalWrite(DIR1,LOW);         //turn left
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,255);          //turn right
  analogWrite(PWM2,0);
}
void turboleft()
{
  digitalWrite(DIR1,LOW);         //turn left
  digitalWrite(DIR2,LOW);
  analogWrite(PWM1,0);          //turn right
  analogWrite(PWM2,255);
}
