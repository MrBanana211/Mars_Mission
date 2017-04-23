int TrackBlock(int blockCount, int targetSignature)
{
  int trackedBlock = 0;
  long maxblobSize = 0;
  
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
  int32_t blobSize = pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height;
  int forwardSpeed = 140;
    
  // Steering differential is proportional to the off center value
  int32_t differential = 160 - pixy.blocks[trackedBlock].x;
  //differential /= 2;
  
  // Adjust the left and right speeds by the steering differential.
  int leftSpeed = constrain(forwardSpeed - differential, -SPEED, SPEED);
  int rightSpeed = constrain(forwardSpeed + differential, -SPEED, SPEED);
  
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

}

