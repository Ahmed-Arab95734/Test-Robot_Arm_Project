// Ultrasonic sensor pins
#define trigPin 5
#define echoPin 6

// Water level sensor pins
#define waterPin A0

// Motor driver pins
#define IN1 2
#define IN2 4
#define ENA 3

// Servo motor pins
#define SERVO_1_PIN 9
#define SERVO_2_PIN 10

// Constants used in kinematic calculations
const float L1 = 30.4;
const float L2 = 20.3;
const float L3 = 10.0;
const float H = 9.1;
const float r = 3.5;
const float P1 = 0.0;
const float P2 = 0.0;
const float P = 18.0;
const float h = 4.0 + 2.5;

// Variables used in the program
long duration;
float distance, Y, R, Theta1, Theta2, pos;
float d = 0.0; // distance variable
int Final_Move;
int waterLevel;

// Servo objects
Servo Servo1;
Servo Servo2;

// Function prototypes
void initializePins();
void moveArm(float distance);
void pourWater();
void refillContainer();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Starts the serial communication

  initializePins(); // Initialize pins used in the program

  moveArm(90); // Move the arm to its initial position

  delay(2000); // Wait for the arm to reach the initial position
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read the distance detected by the ultrasonic sensor
  distance = getDistance();

  // Check if the distance is within a certain range
  if (distance >= 13 && distance <= 29) {
    // Move the arm to pour water into the container
    moveArm(distance);

    // Check if the water level is low
    waterLevel = getWaterLevel();
    if (waterLevel <= 300) {
      // Refill the container
      refillContainer();
    } else {
      // Pour water into the container
      pourWater();
    }

    // Move the arm back to its initial position
    moveArm(90);
  } else {
    // Distance is not within the desired range, do nothing
  }
}

// Function to initialize pins used in the program
void initializePins() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(waterPin, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(7, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  Servo1.attach(SERVO_1_PIN);
  Servo2.attach(SERVO_2_PIN);
}

// Function to move the arm to pour water into the container
void moveArm(float distance) {
  // Calculate the angles required to move the arm
  Theta1 = atan((L3 - H + h) / (distance + P + r)) +
           acos((pow(distance + P + r, 2.0) + pow(L3 - H + h, 2.0) + pow(L1, 2.0) - pow(L2, 2.0)) /
                (2 * L1 * sqrt(pow(distance + P + r, 2.0) + pow(L3 - H + h, 2.0))));
  Theta2 = acos((pow(distance + P + r, 2.0) + pow(L3 - H + h, 2.0) - pow(L1, 2.0) - pow(L2, 2.0)) /
                (2 * L1 * L2));

  Theta1 = Theta1 * 180.0 / PI;
  Theta2 = Theta2 * 180.0 / PI;

  // Move the servos to the calculated angles
  float Theta1_R = Theta1 + 9;
  float Theta1_L = 180 - Theta1 + 9;
  float Theta2_R = 90 + Theta2 - 9;
  float Theta2_L = 90 - Theta2 - 9;

  if (Theta1_R <= 90) {
    if (Theta2_R >= 90) {
      for (pos = 90; pos <= Theta2_R; pos += 1) {
        Servo2.write(pos);
        delay(30);
      }

      for (pos = 90; pos >= Theta1_R; pos -= 1) {
        Servo1.write(pos);
        delay(50);
      }
    } else if (Theta2_R < 90) {
      for (pos = 90; pos >= Theta2_R; pos -= 1) {
        Servo2.write(pos);
        delay(30);
      }

      for (pos = 90; pos >= Theta1_R; pos -= 1) {
        Servo1.write(pos);
        delay(50);
      }
    }
  }
}

// Function to pour water into the container
void pourWater() {
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH); // turn the LED off by making the voltage LOW
  delay(18000);
  digitalWrite(7, LOW);
  delay(6000);
  digitalWrite(7, HIGH);
  digitalWrite(13, LOW);
  delay(3000);
}

// Function to refill the container
void refillContainer() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 250);
  delay(10000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

// Function to get the distance detected by the ultrasonic sensor
float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

// Function to get the water level in the container
int getWaterLevel() {
  int sensorValue = analogRead(waterPin);
  return map(sensorValue, 0, 1023, 0, 500);
}
