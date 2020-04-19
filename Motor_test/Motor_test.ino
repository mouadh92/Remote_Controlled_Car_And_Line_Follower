int DIR1 = 4; //LEFTDIR
int PWM1 = 5; //LEFTSPD
int DIR2 = 7; //RIGHTDIR
int PWM2 = 6; //RIGHTSPD
void setup() {
  pinMode(DIR1,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(PWM2,OUTPUT);

}

void loop() {
  digitalWrite(DIR1,HIGH);  //Low=forward High=backward
  analogWrite(PWM1,255);
  digitalWrite(DIR2,HIGH);
  analogWrite(PWM2,255);

  delay(3000);

  analogWrite(PWM1,0);
  analogWrite(PWM2,0);

  delay(1000);
   
  digitalWrite(DIR1,LOW); 
  analogWrite(PWM1,255);
  digitalWrite(DIR2,LOW);
  analogWrite(PWM2,255);
  delay(3000);
}
