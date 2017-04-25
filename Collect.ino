void collectBall() {
  if(track(SIGNATURE_BALL)) {
    Serial.println(blob_y); 
    openDoor();
  } else if(blob_y > 190){
      delay(500);
      if(closeDoor())
        ballCount++;
      if(ballCount == 3) {
        state = CONTAINER;
        Serial.println("COLLECT >>> CONTAINER");
      } else {
        state = BALL;
        Serial.println("COLLECT >>> BALL");
      }
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


bool openDoor() {
    if(doorClosed) {
      doorservo.write(50); //change number here
      Serial.println("Opened door.");
      doorClosed = false;
      return true;
    }
    return false;
}

bool closeDoor() {
    if(!doorClosed) {
      doorservo.write(110); //change number here
      Serial.println("Closed door.");
      doorClosed = true;
      return true;
    }
    return false;
}
