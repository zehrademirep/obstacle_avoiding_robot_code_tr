const int trigPin = 1;
const int echoPin = A5;
int sagyon1 = A1;
int sagyon2 = A2;
int solyon1 = A4;
int solyon2 = A3;
int sagpwm = 10;
int solpwm = 9;
int led = 11;
int ds1 = 4;
int ds2 = 3;
int ds3 = 2;
int i = 9;
int buton = A0;
int buzzer = 8;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(sagyon1, OUTPUT);
  pinMode(sagyon2, OUTPUT);
  pinMode(solyon1, OUTPUT);
  pinMode(solyon2, OUTPUT);
  pinMode(sagpwm, OUTPUT);
  pinMode(solpwm, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ds1, INPUT);
  pinMode(ds2, INPUT);
  pinMode(ds3, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buton, INPUT);
  Serial.begin(9600); 
  digitalWrite(ds1, HIGH);
  digitalWrite(ds2, HIGH);
  digitalWrite(ds3, HIGH);
  analogWrite(9, 0);
  analogWrite(10, 0);

}
void loop() {
  if (digitalRead(ds1) == 0 && digitalRead(ds2) == 0 && digitalRead(ds3) == 0 && digitalRead(buton) == 1 ) {
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(1000);
devam:
if (i ==1) {
    analogWrite(9, 0);
    analogWrite(10, 0);
    delay(100);
}
   
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
   
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 25) {

          analogWrite(9, 200);
    analogWrite(10, 200);
    
      digitalWrite(buzzer, HIGH);
      digitalWrite(solyon1, HIGH);
      digitalWrite(solyon2, LOW);
      
      digitalWrite(sagyon1, HIGH);
      digitalWrite(sagyon2, LOW);
      
      delay(250);
      i =1;

    } else {

       analogWrite(9, 200);
    analogWrite(10, 200);
      digitalWrite(buzzer, LOW);
      digitalWrite(solyon2, HIGH);
      digitalWrite(solyon1, LOW);
      digitalWrite(sagyon1, HIGH);
      digitalWrite(sagyon2, LOW);
     // delay(50);
     i=3;
    }
 
    goto devam;
  } else if (digitalRead(ds1) == 1 && digitalRead(ds2) == 1 && digitalRead(ds3) == 1 && digitalRead(buton) == 1 ) {
    digitalWrite(buzzer, HIGH);
    delay(600);
    digitalWrite(buzzer, LOW);
    delay(1000);
takip:
    analogWrite(9, 160);
    analogWrite(10, 160);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);
    if (distance < 30) {
      digitalWrite(buzzer, HIGH);
      
      digitalWrite(solyon1, HIGH);
      digitalWrite(solyon2, LOW);
      
      digitalWrite(sagyon2, HIGH);
      digitalWrite(sagyon1, LOW);
    } else if (distance >= 30 && distance <= 50) {
      analogWrite(9,0);
      analogWrite(10,0);

      digitalWrite(buzzer, LOW);
      digitalWrite(solyon1, LOW);
      digitalWrite(solyon2, LOW);
      digitalWrite(sagyon2, LOW);
      digitalWrite(sagyon1, LOW);
    } else if (distance > 50) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(solyon2, HIGH);
      digitalWrite(solyon1, LOW);
      
      digitalWrite(sagyon1, HIGH);
      digitalWrite(sagyon2, LOW);
    }
    goto takip;
  }
}
