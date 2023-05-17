
#include<Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo3;


int pos = 0;  

     float Theta1;
    float Theta2;
    float Theta3;

    float initial_1 = 99;
    float initial_2 = 90;
    float initial_3 = 90;

    float Theta1_R = Theta1+9;
    float Theta1_L =180- Theta1-9;

    
    float Theta2_R = 90+Theta2;
    float Theta2_L = 90-Theta2;
    
    float Theta3_R = 90+Theta3;
    float Theta3_L = 90-Theta3;
void setup() {

  delay(3000); 
  
  Servo1.attach(6);  
  Servo2.attach(10);  
  Servo3.attach(11);  




    for (pos =0; pos <= initial_1; pos += 1) {
      Servo1.write(pos);             
      delay(50); 
    }

    Servo2.write(initial_2); 
    Servo3.write(initial_3);

}


void loop() {

  
    Theta1=50;
    Theta2=50;
    Theta3=80;

  
    Theta1_R = Theta1+9;
    Theta1_L =180- Theta1;

    
    Theta2_R = 90+Theta2;
    Theta2_L = 90-Theta2;
    
    Theta3_R = 90-Theta3;
    Theta3_L = 90+Theta3;

  for (pos =initial_3; pos >= Theta3_R; pos -= 1) { 
   
     Servo3.write(pos);             
     delay(10);  }


  for (pos =initial_2; pos <= Theta2_R; pos += 1) { 
     Servo2.write(pos);             
     delay(30);  }


  for (pos =initial_1; pos >= Theta1_R; pos -= 1) {

     Servo1.write(pos);             
     delay(50);  }



   delay(3000); 


   for (pos =Theta1_R; pos <= initial_1; pos += 1) {

      Servo1.write(pos);             
      delay(50);  }

  for (pos = Theta2_R; pos >=initial_2; pos -= 1) { 
     Servo2.write(pos);             
     delay(30);  }
     
  for (pos =Theta3_R; pos <= initial_3; pos += 1) { 
   
     Servo3.write(pos);             
     delay(10);  }


   delay(3000);




   
  for (pos =initial_3; pos <= Theta3_L; pos += 1) { 
   
     Servo3.write(pos);             
     delay(10);  }


  for (pos =initial_2; pos >= Theta2_L; pos -= 1) { 
     Servo2.write(pos);             
     delay(30);  }


  for (pos =initial_1; pos <= Theta1_L; pos += 1) {

     Servo1.write(pos);             
     delay(50);  }



   delay(3000); 


   for (pos =Theta1_L; pos >= initial_1; pos -= 1) {

      Servo1.write(pos);             
      delay(50);  }

  for (pos = Theta2_L; pos <=initial_2; pos += 1) { 
     Servo2.write(pos);             
     delay(30);  }
     
  for (pos =Theta3_L; pos >= initial_3; pos -= 1) { 
   
     Servo3.write(pos);             
     delay(10);  }


   delay(3000);

   
}
