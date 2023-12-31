int trigPin = 12; 
int echoPin = 11; 
int trigPin1 = 9; 
int echoPin1 = 10; 
int gate1 = 8;
int gate2 = 7;
long timeperiod, cm, c1, c2, lane; 


void setup()
{
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);  
  pinMode(gate1,INPUT);
  pinMode(gate2,INPUT);
}

void loop()
{
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin,LOW);
  duration= pulseIn(echopin,HIGH);
  distance=(duration/2)/29.1;
  digitalWrite(trigpin1,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigpin1,LOW);
  duration= pulseIn(echopin1,HIGH);
  distance1=(duration/2)/29.1;
  if(distance <= 30){c1=c1+1;}
  if(distance1 <= 30){c2=c2+1;}
  if(digitalRead(gate1) == HIGH){c1=c1-1;}
  if(digitalRead(gate2) == HIGH){c2=c2-1;}
  lane = (c1>c2)?c2:c1;
}
