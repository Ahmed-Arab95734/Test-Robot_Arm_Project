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
