void collect() {
  
  openDoor();
  
  digitalWrite(motorL1, HIGH); //forward to eat the ball
  digitalWrite(motorL2, LOW);
  analogWrite(motorLPWM, 255);
  
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  analogWrite(motorRPWM, 255);
  delay(700);
  
  closeDoor();
  ball++;

  if (ball == 3){
    state = CONTAINER;
  }
  else if (ball < 3){
    state = BALL;
  } 
}

void openDoor() {
    doorservo.write(90); //change number here
    delay(DELAY_DOOR);
}

void closeDoor() {
    doorservo.write(90); //change number here
    delay(DELAY_DOOR);
}
