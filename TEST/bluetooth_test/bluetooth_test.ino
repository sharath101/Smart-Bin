const int pin1=9;
const int pin2=6;
void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
Serial.begin(9600);
}
char x;
int f=100,r1=0,r2=0;
void loop() {
  // put your main code here, to run repeatedly:
 
 if(Serial.available()>0)
 { 
  x=Serial.read();
  if(x=='1')
    digitalWrite(pin1,HIGH);
  if(x=='2')
    digitalWrite(pin1,LOW);
  if(x=='3')
    digitalWrite(pin2,HIGH);
  if(x=='4')
    digitalWrite(pin2,LOW);
  }
  if(x=='1')
    r1=1;
  if(x=='2')
    r1=0;
  if(x=='3')
    r2=1;
  if(x=='4')
    r2=0;
  if(r1==1 && r2==1)
    Serial.println("1");
  if(r1==1 && r2==0)
    Serial.println("2");
  if(r1==0 && r2==1)
    Serial.println("3");
  if(r1==0 && r2==0)
    Serial.println("4");
   
  delay(50);
}
