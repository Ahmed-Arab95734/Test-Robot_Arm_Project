#define WATER A0
float water;
const int THRESHOLD = 500; // set your threshold value

void setup() {
  // put your setup code here, to run once:
  pinMode(WATER, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  water = getWaterLevel();
  Serial.print("water level = ");
  Serial.println(water);
  delay(1000); 
}

// Function used to get the water level
bool getWaterLevel()
{
  int waterValue = analogRead(WATER);
  if (waterValue > THRESHOLD) {
    return true;
  } else {
    return false;
  }
}
