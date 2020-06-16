const int pin1=9;
const int pin2=6;
void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
Serial.begin(9600);
}
char x;
int r1=0,r2=0;
void loop() {
 if(Serial.available()){ 
    x=Serial.read();
    if(x=='1')
      digitalWrite(pin1,HIGH);
    else if(x=='2')
      digitalWrite(pin1,LOW);
    else if(x=='3')
      digitalWrite(pin2,HIGH);
    else if(x=='4')
      digitalWrite(pin2,LOW);
  }
  
  if(x=='1')
    r1=1;
  else if(x=='2')
    r1=0;
  else if(x=='3')
    r2=1;
  else if(x=='4')
    r2=0;
  if(r1==0 && r2==0)
    Serial.println("Light 1:OFF & Light 2:OFF");
  else if(r1==1 && r2==0)
    Serial.println("Light 1:ON & Light 2:OFF");
  else if(r1==0 && r2==1)
    Serial.println("Light 1:OFF & Light 2:ON");
  else if(r1==1 && r2==1)
    Serial.println("Light 1:ON & Light 2:ON");
  delay(50);
}
