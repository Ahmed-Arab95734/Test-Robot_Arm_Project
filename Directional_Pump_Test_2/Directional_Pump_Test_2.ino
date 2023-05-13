
# define Pump_pin A2
# define In1 1
# define In2 0

void setup() {
 
  pinMode(Pump_pin, OUTPUT);
  
    pinMode(In1, OUTPUT);
    pinMode(In2, OUTPUT);
      
   digitalWrite(Pump_pin, HIGH);   // The Pump off
   
  digitalWrite(In1, LOW); 
  digitalWrite(In2, LOW);
//Gate motor off
   
   delay(1000);  //to charge the capacitores and the power become stable 
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(In1, LOW); 
  digitalWrite(In2, HIGH); 
    // Gate close to proceed Suction
    
  delay(16000);
    delay (5000);
  //Waite motor to close the gate
    //Note : delay function canot take argumetns more than 16 second so in done by 2 lines 

  
   digitalWrite(Pump_pin, LOW);// The Pump on
   delay(5000);//waite the pump to complete the suction
   
   digitalWrite(Pump_pin,HIGH);     // The Pump off

     digitalWrite(In1, HIGH); 
     digitalWrite(In2, LOW); 
         // Gate close to proceed Pumping
     
  delay(16000);  
  delay (5000);
  //Waite motor to close the gate 
  //Note : delay function canot take argumetns more than 16 second so in done by 2 lines 

     digitalWrite(Pump_pin, LOW);// The Pump on
   delay(10000);//waite the pump to complete the Pumping
   digitalWrite(Pump_pin,HIGH);// The Pump off
  
}
