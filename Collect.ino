void collect() {
  
  openDoor();
  stopMove();
  delay(200);
  digitalWrite(motorL1, HIGH); //forward to eat the ball
  digitalWrite(motorL2, LOW);
  analogWrite(motorLPWM, 100);
  
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRPWM, 100);
  delay(500);
  stopMove();
  closeDoor();
  ball++;
  state = HALT;
  /*
  if (ball == 3){
    state = CONTAINER;
  }
  else if (ball < 3){
    state = BALL;
  } 
  */
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
    doorservo.write(90); //change number here
    delay(DELAY_DOOR);
}

void closeDoor() {
    doorservo.write(90); //change number here
    delay(DELAY_DOOR);
}
