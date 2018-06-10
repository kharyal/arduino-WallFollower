// defines pins numbers
const int trigPin1 = 6;
const int trigPin2 = 9;
const int echoPin1 = 10;
const int echoPin2 = 11;
const int op1=7;
const int op2=8;
int flag=0;
long dist1,dist2,duration1,duration2,def_dist=15;
void setup(){
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(op1,OUTPUT);
  pinMode(op2,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  dist1= duration1*0.034/2;
  dist2= duration2*0.034/2;
  if(dist1<def_dist and dist2<def_dist)
  {
    delay(250);
    digitalWrite(op1,HIGH);
    digitalWrite(op2,LOW);
    delay(1500);
    digitalWrite(op2,HIGH);
  }
  else if(dist2>def_dist){
    delay(750);
    digitalWrite(op2,HIGH);
    digitalWrite(op1,LOW);
    delay(1500);
    digitalWrite(op1,HIGH);
  }
  def_dist+=5;
  if(dist1>def_dist){
    digitalWrite(op1,HIGH);
    digitalWrite(op2,HIGH);
  }
  def_dist-=5;
  Serial.println(dist1);
  Serial.println(dist2);
  Serial.println(" ");
  }
  
