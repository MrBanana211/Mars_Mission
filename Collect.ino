void collectBall() {
  if(track(SIGNATURE_BALL)) {
    openDoor();
  } else if(blob_y > 190){
      delay(500);
      if(closeDoor())
        ballCount++;
      if(ballCount >= 3) {
        state = CONTAINER;
        if(DEBUG) {
          Serial.println("COLLECT >>> CONTAINER");
        }
      } else {
        state = BALL;
        if(DEBUG) {
          Serial.println("COLLECT >>> BALL");
        }
      }
  }
}

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


bool openDoor() {
    if(doorClosed) {
      doorservo.write(SERVO_OPEN); //change number here
      
      if(DEBUG)
        Serial.println("Opened door.");

      doorClosed = false;
      return true;
    }
    return false;
}

bool closeDoor() {
    if(!doorClosed) {
      doorservo.write(SERVO_CLOSE); //change number here
      
      if(DEBUG) 
        Serial.println("Closed door.");
        
      doorClosed = true;
      return true;
    }
    return false;
}
