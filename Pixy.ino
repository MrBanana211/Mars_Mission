int TrackBlock(int blockCount, int targetSignature)
{
  int trackedBlock = -1;
  long maxblobSize = -1;
  
  for (int i = 0; i < blockCount; i++) {
    if (pixy.blocks[i].signature == targetSignature) {
      long newblobSize = pixy.blocks[i].height * pixy.blocks[i].width;
      if (newblobSize > maxblobSize){
        trackedBlock = i;
        maxblobSize = newblobSize; 
      }
    }
  }

  return trackedBlock;
}



void FollowBlock(int trackedBlock) {
  int forwardSpeed = 140;
    
  // Steering differential is proportional to the off center value
  int differential = 160 - pixy.blocks[trackedBlock].x;
  
  // Adjust the left and right speeds by the steering differential.
  int leftSpeed = constrain(forwardSpeed - 0.8*differential, -SPEED, SPEED);
  int rightSpeed = constrain(forwardSpeed + 0.8*differential, -SPEED, SPEED);

  if (leftSpeed >= 0){
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    analogWrite(motorLPWM, leftSpeed);
  }
  else if (leftSpeed < 0){
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    analogWrite(motorLPWM, -leftSpeed);
  }
  if (rightSpeed >= 0){
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    analogWrite(motorRPWM, rightSpeed);
  }
  else if (rightSpeed < 0){
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    analogWrite(motorRPWM, -rightSpeed);
  }
}




void ScanForBlocks() {

    static uint32_t lastMove = 0L;

  if (millis() - lastMove > 20) {
    lastMove = millis();
    
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    analogWrite(motorRPWM, 100);

    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    analogWrite(motorLPWM, 100
    );
  }
}

