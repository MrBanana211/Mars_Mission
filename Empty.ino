void empty() {
  openDoor();
  pushForward();
  pushBack();
}

void pushForward() {
  digitalWrite(motorP1, HIGH);
  digitalWrite(motorP2, LOW);
  analogWrite(motorPPWM, 255);

  while(digitalRead(switchf));
  stopPush();
}

void pushBack() {
  digitalWrite(motorP1, LOW);
  digitalWrite(motorP2, HIGH);
  analogWrite(motorPPWM, 255);

  while(digitalRead(switchr));
  stopPush();
}

void stopPush() {
  digitalWrite(motorP1, LOW);
  digitalWrite(motorP2, LOW);
  analogWrite(motorPPWM, 0);
}




