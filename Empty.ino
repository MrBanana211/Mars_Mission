void empty() {
  openDoor();
  switch(PUSH){
    case PUSHF:
      digitalWrite(motorP1, HIGH);
      digitalWrite(motorP2, LOW);
      analogWrite(motorPPWM, 255);
  
      if (digitalRead(switchf == LOW)){
        PUSH = PUSHR;
        delay(20);
      }
    break;

    case PUSHR:
      digitalWrite(motorP1, LOW);
      digitalWrite(motorP2, HIGH);
      analogWrite(motorPPWM, 255);
  
      if (digitalRead(switchr == LOW)){
        PUSH = PUSHS;
        delay(20);
      }
    break;

    case PUSHS:
      digitalWrite(motorP1, LOW);
      digitalWrite(motorP2, LOW);
    break;
  }
}
