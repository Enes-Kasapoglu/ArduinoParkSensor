#define echoPin 6
#define trigPin 7
#define buzzerPin 8

#define startPin 12
#define noproblemPin 2
#define stoponePin 3
#define stoptwoPin 4
#define stopthreePin 9
#define stopfourPin 10
#define stopfivePin 11

int maximumRange =50;
int minimumRange = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
    
  pinMode(startPin, OUTPUT);
  pinMode(noproblemPin, OUTPUT);
  pinMode(stoponePin, OUTPUT);
  pinMode(stoptwoPin, OUTPUT);
  pinMode(stopthreePin, OUTPUT);
  pinMode(stopfourPin, OUTPUT);
  pinMode(stopfivePin, OUTPUT);  


}

void loop() {
  // put your main code here, to run repeatedly:

  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum*10);

  digitalWrite(startPin, HIGH);
 // delay(300);
  digitalWrite(startPin, LOW);
  delay(100);
  //digitalWrite(noproblemPin, HIGH);

  digitalWrite(stoponePin, LOW);
  digitalWrite(stoptwoPin, LOW);
  digitalWrite(stopthreePin, LOW);
  digitalWrite(stopfourPin, LOW);
  digitalWrite(stopfivePin, LOW);
}

int mesafe(int maxrange, int minrange){

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  delay(50);

  Serial.println(distance);

  if(distance <= 20){
  digitalWrite(noproblemPin, LOW);
  digitalWrite(stoponePin, HIGH);
  digitalWrite(stoptwoPin, HIGH);
  digitalWrite(stopthreePin, HIGH);
  digitalWrite(stopfourPin, HIGH);
  digitalWrite(stopfivePin, HIGH);
  //digitalWrite(motorPin, HIGH);
  
  }
  else{
  digitalWrite(noproblemPin, HIGH);
    
  }

  
  if(distance >= maxrange || distance <= minrange)
  return 0;
  return distance;


}

int melodi(int dly){
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
