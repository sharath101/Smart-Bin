const int x=A1;
const int y=A2;
const int z=A3;
void setup() {
  // put your setup code here, to run once:
pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(z,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int Xval = analogRead(x);
  int Yval = analogRead(y);
  int Zval = analogRead(z);
  Serial.print("X=");
  Serial.print(Xval);
  Serial.print("  Y=");
  Serial.print(Yval);
  Serial.print("  Z=");
  Serial.println(Zval);
  delay(200);
}
