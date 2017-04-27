void left(int PWM) {
  int pin1 = LOW;
  int pin2 = LOW;
  
  if(PWM > 0) {
    pin1 = HIGH;
  } else if(PWM < 0){
    PWM = -PWM;
    pin2 = HIGH;
  }
  PWM = constrain(PWM, 0, 255);
  
  digitalWrite(motorL1, pin1);
  digitalWrite(motorL2, pin2);
  analogWrite(motorLPWM, PWM);
}

void right(int PWM) {
  int pin1 = LOW;
  int pin2 = LOW;
  
  if(PWM > 0) {
    pin1 = HIGH;
  } else if(PWM < 0){
    PWM = -PWM;
    pin2 = HIGH;
  }
  PWM = constrain(PWM, 0, 255);
  
  digitalWrite(motorR1, pin1);
  digitalWrite(motorR2, pin2);
  analogWrite(motorRPWM, PWM);
}

void moveMotor(int leftPWM, int rightPWM) {
  left(leftPWM);
  right(rightPWM);
}


void stopMove() {
  moveMotor(0, 0);
}

void breakMove() {
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLPWM, 255);
  
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRPWM, 255);

  delay(200);
  stopMove();
}


void FollowBlock(int trackedBlock) {
  int forwardSpeed = 140;
    
  // Steering differential is proportional to the off center value
  int differential = 160 - pixy.blocks[trackedBlock].x;
  
  // Adjust the left and right speeds by the steering differential.
  int leftSpeed = constrain(forwardSpeed - 0.8*differential, -SPEED, SPEED);
  int rightSpeed = constrain(forwardSpeed + 0.8*differential, -SPEED, SPEED);

  moveMotor(leftSpeed, rightSpeed);
}


void ScanForBlocks() {
  static uint32_t lastMove = 0L;

  if (millis() - lastMove > 20) {
    lastMove = millis();
    moveMotor(100, -100);
  }
}
