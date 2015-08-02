// Assign Arduino Pins
//Sonar Pins
int echoPin =3; 
int trigPin =4; 

// Assign varibles
int thresMax = 100;

int trigger = 0;

int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

}


void loop() {
  readSensor();
  //delay(30000);
  delay(500);
}


void readSensor() {
  distance = getDistance(trigPin, echoPin);
  // if the distance from the SonarSensor is bigger than "thresMin" AND (&&) smaller than "thresMax"
  if (distance <= thresMax && trigger == 0){

    // set LED (arduino pin 13) HIGH/ON
    digitalWrite (ledPin, HIGH);
    //Serial.print("Scott, Sit up right!!! ");
    Serial.print("Good posture prolongs your lifespan");
//    Serial.print("Your distance to the screen is: ");
//    Serial.print(distance);
//    Serial.print(" cm");
//    Serial.println("");
    Serial.flush(); 
    trigger = 1;
  }
  
  if (distance >= thresMax && trigger == 1){
    // set LED (arduino pin 13) LOW/OFF
    digitalWrite (ledPin, LOW);
    Serial.print("Sitting position neatly adapted, ");
    //Serial.println(distance);
    trigger = 0;

  }
}


int getDistance (int trigPin, int echoPin){  digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
unsigned long pulseTime = pulseIn(echoPin, HIGH);
int distance = pulseTime/58;
return distance;
} 

void Random_positive

//void printDistance(int id, int dist){
//  if (dist >= thresMin && dist <= thresMax){
//    // Print a "-" for every cm
//    for (int i = 0; i <= dist; i++) {
//    Serial.print("-");
//
//    // set LED (arduino pin 13) HIGH/ON
//    digitalWrite (ledPin, HIGH);
//    Serial.print("Scott, Sit up right!!! ");
//    Serial.print("Your distance to the screen is: ");
//    Serial.print(dist);
//    Serial.print(" cm");
//    Serial.println("");
//    Serial.flush(); 
//  } else {
//    // set LED (arduino pin 13) LOW/OFF
//    digitalWrite (ledPin, LOW);
//  }
//}
