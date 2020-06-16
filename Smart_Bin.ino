const int echo=11;
const int trig=10;
const int f0=9;
const int b0=8;
const int ls=7;
const int rs=6;
const int fl=5;
const int bl=4;
const int fr=3;
const int br=2;
const int x=A1;
const int y=A2;
const int z=A3;

void setup()
 {
  pinMode(fl,OUTPUT);
  pinMode(bl,OUTPUT);
  pinMode(fr,OUTPUT);
  pinMode(br,OUTPUT);
  pinMode(f0,OUTPUT);
  pinMode(b0,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(z,INPUT);
  pinMode(ls,INPUT);
  pinMode(rs,INPUT);
  Serial.begin(9600);
 }

int duration;
int distance=100;
int recieve;

int Acc()
 {
  int Xval = analogRead(x);
  int Yval = analogRead(y);
  int Zval = analogRead(z);
  
  return Yval;
 }
void lid()
  {
   digitalWrite(trig,LOW);
   delay(0.002);
  
  digitalWrite(trig,HIGH);
  delay(0.01);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=(0.034*duration)/2;
  Serial.println(distance);

  if(distance<9)
   {
    while(Acc()>320)
    {
    digitalWrite(f0,HIGH);
    digitalWrite(b0,LOW);
    }
    digitalWrite(f0,LOW);
    digitalWrite(b0,LOW);
    delay(4000);

    while(Acc()<370)
    {
    digitalWrite(f0,LOW);
    digitalWrite(b0,HIGH);
    }
    digitalWrite(f0,LOW);
    digitalWrite(b0,LOW);
   }
  else
  {
   digitalWrite(f0,HIGH);
   digitalWrite(b0,HIGH);
  }
 }
 void lidbt()
  {
   
    while(Acc()>295)
    {
    digitalWrite(f0,HIGH);
    digitalWrite(b0,LOW);
    }
    digitalWrite(f0,LOW);
    digitalWrite(b0,LOW);
    delay(4000);

    while(Acc()<345)
    {
    digitalWrite(f0,LOW);
    digitalWrite(b0,HIGH);
    }
    digitalWrite(f0,LOW);
    digitalWrite(b0,LOW);
 
 }
 void stop()
 {digitalWrite(fl,LOW);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(fr,LOW);
  delay(1000);
 }
void irs()
{ 
 
 if(digitalRead(ls)==0 && digitalRead(rs)==0)
 {
  digitalWrite(fl,LOW);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,HIGH);
  digitalWrite(br,LOW); 
   
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==0)
 {
  digitalWrite(fl,HIGH);
  digitalWrite(bl,LOW);

  digitalWrite(fr,HIGH);
  digitalWrite(br,LOW);
  
 }
 else if(digitalRead(ls)==0 && digitalRead(rs)==1)
 {
  digitalWrite(fl,LOW);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==1)
 {
  digitalWrite(fl,LOW);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(fr,LOW);
  lid();
 }
}
void back()
{
 if(digitalRead(ls)==0 && digitalRead(rs)==0)
 {
  digitalWrite(fl,HIGH);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);  
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==0)
 {stop();
 while(digitalRead(ls)!=0 && digitalRead(rs)!=0)
 { digitalWrite(fl,LOW);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);
 }
 }
 else if(digitalRead(ls)==0 && digitalRead(rs)==1)
 {stop();
 while(digitalRead(ls)!=0 && digitalRead(rs)!=0)
 {digitalWrite(fl,HIGH);
 
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,LOW);
 }
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==1)
 {
 
  digitalWrite(fl,LOW);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(fr,LOW);
  lid();
 } 
}
void loop() 
{
 if(Serial.available()>0)
  {
    recieve=Serial.read();
    
    if(recieve=='a')
     {
      digitalWrite(fl,LOW);
      digitalWrite(bl,HIGH);

      digitalWrite(fr,HIGH);
      digitalWrite(br,LOW);
      delay(1000);
      irs();
     } 

    else if(recieve=='b')
     lidbt();

    else if(recieve=='c')
     {
      digitalWrite(fl,HIGH);
      digitalWrite(bl,LOW);

      digitalWrite(fr,LOW);
      digitalWrite(br,HIGH);
      delay(1000);
      back();   
     } 
  }
  Serial.println(recieve);
  delay(50);
  lid();
  
  
  
  
}
