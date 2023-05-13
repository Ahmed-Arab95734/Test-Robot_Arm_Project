const int trigPin = 10;
const int echoPin = 13;

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;
  
  if (distance >= 40 || distance <= 2) {
    return -1; // Out of range
  } else {
    return distance;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float distance = getDistance(trigPin, echoPin);
  
  if (distance == -1) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  delay(100);
}
