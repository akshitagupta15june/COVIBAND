const int pingTrigPin = A4;
const int pingEchoPin = A5;
int led=13; //Buzzer to PIN 4
int buz1=9;
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(buz1, OUTPUT);
}
void loop()
{
long duration, cm;
pinMode(pingTrigPin, OUTPUT);
digitalWrite(pingTrigPin, LOW);
delayMicroseconds(2);
digitalWrite(pingTrigPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingTrigPin, LOW);
pinMode(pingEchoPin, INPUT);
duration = pulseIn(pingEchoPin, HIGH);
cm = microsecondsToCentimeters(duration);
if(cm<=100 && cm>0)
{

int d= map(cm, 1, 300, 10, 1000);
digitalWrite(led, HIGH);
digitalWrite(buz1, HIGH);
delay(50);
digitalWrite(led, LOW);
digitalWrite(buz1, LOW);
delay(d);
}
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(40);
}
long microsecondsToCentimeters(long microseconds)
{
return microseconds / 29 / 2;
}
