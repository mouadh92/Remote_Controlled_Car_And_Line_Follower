const int pin_1 = A0;
const int pin_2 = A1;
const int pin_3 = A2;
const int pin_4 = A3;
const int pin_5 = A4;
int DS_1 = 0;
int DS_2 = 0;
int DS_3 = 0;
int DS_4 = 0;
int DS_5 = 0;

void setup()
{  Serial.begin (9600);
   pinMode(pin_1, INPUT);
   pinMode(pin_2, INPUT);
   pinMode(pin_3, INPUT);
   pinMode(pin_4, INPUT);
   pinMode(pin_5, INPUT);
}

void loop()
{ DS_1 = digitalRead(pin_1);
  DS_2 = digitalRead(pin_2);
  DS_3 = digitalRead(pin_3);
  DS_4 = digitalRead(pin_4);
  DS_5 = digitalRead(pin_5);    //Declare variables equal to the reading of the sensors

  Serial.println ("Sensor Status: ");
  Serial.print (DS_1);
  Serial.print ("\t");
  Serial.print (DS_2);
  Serial.print ("\t");
  Serial.print (DS_3);
  Serial.print ("\t");
  Serial.print (DS_4);
  Serial.print ("\t");
  Serial.println (DS_5);        //Display reading of sensors at serial monitor
}
