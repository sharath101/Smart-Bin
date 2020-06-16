void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(fl,HIGH);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH); 

   //right
  digitalWrite(fl,LOW);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,HIGH);

  //left
  digitalWrite(fl,HIGH);
  digitalWrite(bl,LOW);

  digitalWrite(fr,LOW);
  digitalWrite(br,LOW);
}
