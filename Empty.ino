void empty() {
  breakMove();
  
  openDoor();
  pushOut();
  moveMotor(-140, -140);
  delay(600);
  breakMove();
  
  closeDoor();
  moveMotor(200, 200);
  delay(500);
  breakMove();

  delay(2000);
  closeContainer();

  moveMotor(-140, -140);
  delay(600);
  breakMove();
  
  pushIn();
  state = HALT;
}

void pushOut() {
  digitalWrite(switchF, HIGH);
  while(digitalRead(switchF));
  stopPush();
}

void pushIn() {
  digitalWrite(switchR, HIGH);
  while(digitalRead(switchR));
  stopPush();
}

void stopPush() {
  digitalWrite(switchF, LOW);
  digitalWrite(switchR, LOW);
}




