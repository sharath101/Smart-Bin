const int trig=9;
const int echo=10; 
const int ledred=11;
const int ledgreen=3;
const int ledblue=5;

void setup()
 {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
 }

int duration;

void loop() 
 {
  digitalWrite(trig,LOW);
  delay(0.002);
  
  digitalWrite(trig,HIGH);
  delay(0.01);
  digitalWrite(trig,LOW);
  
  duration=pulseIn(echo,HIGH);
  
  Serial.println(duration);

  if(duration<)
   digitalWrite(ledred,HIGH);
  else
   digitalWrite(ledred,LOW);

  if(duration< && duration> );
   digitalWrite(ledblue,HIGH);
  else
   digitalWrite(ledblue,LOW);
 
  if(duration> );
   digitalWrite(ledgreen,HIGH);
  else
   digitalWrite(ledgreen,LOW);



}
