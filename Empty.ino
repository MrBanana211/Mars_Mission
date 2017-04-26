void empty() {
  stopMove();
  openDoor();
  pushOut();
  moveMotor(-200, -200);
  delay(500);
  stopMove();
  closeDoor();
  moveMotor(200, 200);
  delay(500);
  stopMove();
  closeContainer();
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




