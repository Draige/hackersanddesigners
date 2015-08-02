int anPin0 = A0;
int sensorValue0 = 0;

//Sonar 1 
int echoPin1 =3; 
int trigPin1 =2; 
int distance1 =0; 

int thres0min = 900;
int thres0max = 1200;

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(anPin0, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

}


void loop() {
  readAnalog();
  delay(30000);
}

int getDistance (int trigPin1, int echoPin){  digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
unsigned long pulseTime = pulseIn(echoPin, HIGH);
int distance = pulseTime/58;
return distance;

}    


void printDistance(int id, int dist){
  Serial.print(id);
  if (dist >= 120 || dist <= 0 ){
    Serial.print(" Out of range ");
    Serial.flush(); 
  }else
    for (int i = 0; i <= dist; i++) {
    Serial.print("-");
  }
  Serial.print(dist);
  Serial.print(" cm  ");
  Serial.flush();  
}


void readAnalog() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(anPin0);
  
  if (sensorValue0 >= thres0min && sensorValue0 <= thres0max) {
    digitalWrite (ledPin, HIGH);
    distance1 = getDistance(trigPin1, echoPin1);
    printDistance(1, distance1);
//    connection0 = 1; 
//    Serial.print(" Hello Vince the Prince, you are a bit close ");
//    Serial.print(" Hello Vince the Prince ");
//    Serial.print(sensorValue0);
//    Serial.flush();
  } else {
    digitalWrite (ledPin, LOW);
  }
}
