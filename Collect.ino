void collect() {
  
  openDoor();
  stopMove();
  delay(3000);
  digitalWrite(motorL1, HIGH); //forward to eat the ball
  digitalWrite(motorL2, LOW);
  analogWrite(motorLPWM, 80);
  
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRPWM, 80);
  delay(800);
  stopMove();
  closeDoor();
  ball++;
  //state = HALT;
  delay(500);
  
  if (ball == 3){
    state = HALT;
  }
  else if (ball < 3){
    state = BALL;
  } 
  
}

void stopMove() {
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRPWM, 0);

  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  analogWrite(motorLPWM, 0);
}


void openDoor() {
    doorservo.write(0); //change number here
    delay(DELAY_DOOR);
}

void closeDoor() {
    doorservo.write(150); //change number here
    delay(DELAY_DOOR);
}
