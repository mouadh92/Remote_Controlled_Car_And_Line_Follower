const int sensorPin = 2;
int pinstate;
int DIR1 = 4; //LEFTDIR
int PWM1 = 5; //LEFTSPD
int DIR2 = 7; //RIGHTDIR
int PWM2 = 6; //RIGHTSPD

void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(DIR1,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM2,OUTPUT);
}

void loop()
{
  pinstate = digitalRead(sensorPin);
  if (pinstate==LOW)                //If there is obstacle, it will perform if operation
  {
    Serial.println("Blocked!");
    stopmove();                         //call stop fucntion to stop wheel
 
    
  }
  
  else
  {
    Serial.println("Unblock!");
    forward();
    
  }
}

void forward()
{
    digitalWrite(DIR1,LOW);         //Low is forward, left wheel go fwd
    analogWrite(PWM1,255);
    digitalWrite(DIR2,LOW);         //right wheel fwd
    analogWrite(PWM2,255);
}
void stopmove()
{
    digitalWrite(DIR1,LOW); 
    analogWrite(PWM1,0);            //Left wheel stop
    digitalWrite(DIR2,LOW); 
    analogWrite(PWM2,0);             //Right wheel stop
    delay(1000);
    avoid();
}

void avoid()
{
    digitalWrite(DIR1,LOW);         //turn left
    analogWrite(PWM1,100);
    digitalWrite(DIR2,LOW);         
    analogWrite(PWM2,255);
    delay(2000);
    
    analogWrite(PWM1,255);          //turn right
    analogWrite(PWM2,100);
    delay(2000);

    analogWrite(PWM1,100);          //turn left again
    analogWrite(PWM2,255);
    delay(2000);
}
