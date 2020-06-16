const int echo=11;
const int trig=10;
void setup() {
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
Serial.begin(9600);
}
void loop() {
digitalWrite(trig,LOW);
delay(0.002);
digitalWrite(trig,HIGH);
delay(0.01);
digitalWrite(trig,LOW);
int duration = pulseIn(echo,HIGH);
Serial.println(duration);
}
