#define WATER     A1
float water;
void setup() {
  // put your setup code here, to run once:
  pinMode(WATER, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  water = getWaterLevel();

  if (water >=500){
  Serial.print("Water Exist");
  Serial.println(water);
  delay(1000); 
  }
else{
  {
  Serial.print("Water Not Exist");
  Serial.println(water);
  delay(1000); 
  }
}
}

// Function used to get the water level
float getWaterLevel()
{
  return analogRead(WATER);
}
