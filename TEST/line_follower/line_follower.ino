const int ls=7;
const int rs=6;
const int fl=5;
const int bl=4;
const int fr=3;
const int br=2;
void setup() {
  // put your setup code here, to run once:
pinMode(fl,OUTPUT);
  pinMode(bl,OUTPUT);
  pinMode(fr,OUTPUT);
  pinMode(br,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(ls);
  Serial.println(rs);
  delay(100);
if(digitalRead(ls)==0 && digitalRead(rs)==0)
 {
  digitalWrite(fl,LOW);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);  
 }
 else if(digitalRead(ls)==0 && digitalRead(rs)==1)
 {
  digitalWrite(fl,HIGH);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==0)
 {
  digitalWrite(fl,LOW);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,HIGH);
  digitalWrite(br,HIGH);
 }
 else if(digitalRead(ls)==1 && digitalRead(rs)==1)
 {
  digitalWrite(fl,HIGH);
  digitalWrite(bl,HIGH);

  digitalWrite(fr,HIGH);
  digitalWrite(fr,HIGH);
  
 }
}
