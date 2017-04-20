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
  
  int32_t panError = X_CENTER - pixy.blocks[trackedBlock].x; 
  int32_t tiltError = pixy.blocks[trackedBlock].y - Y_CENTER;
  if(maxblobSize > MIN_BLOB_SIZE) {
    panLoop.update(panError);
    tiltLoop.update(tiltError);
    
    pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);
  }
  return trackedBlock;
}



void FollowBlock(int trackedBlock) {
  int32_t panError = panLoop.m_pos - panLoop.m_centerPos; // How far off-center are we looking now?
  int32_t blobSize = pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height;
  int forwardSpeed = 140;

  if( blobSize >= THRESHOLD_BALL) {
    forwardSpeed = 0;
    Serial.println("Align.");
    
  }
    
    
  // Steering differential is proportional to the error times the forward speed 
  int32_t differential = (panError + (panError * forwardSpeed)) >> 8;
  //differential /= 2;
  
  // Adjust the left and right speeds by the steering differential.
  int leftSpeed = constrain(forwardSpeed + differential, -SPEED, SPEED); //forward + diff
  int rightSpeed = constrain(forwardSpeed - differential, -SPEED, SPEED); //forward - diff
  
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
  static int32_t delta_pan = 15L;
  static int32_t delta_tilt = 50L;
  static uint32_t lastMove = 0L;
  
  if (millis() - lastMove > 20) {
    lastMove = millis();
    panLoop.m_pos += delta_pan;
    
    if ((panLoop.m_pos >= panLoop.m_maxPos)||(panLoop.m_pos <= panLoop.m_minPos)) {
      delta_pan = -delta_pan;

      if ((tiltLoop.m_pos >= tiltLoop.m_maxPos)||(tiltLoop.m_pos <= tiltLoop.m_minPos)) {
        delta_tilt = -delta_tilt;
      }
      tiltLoop.m_pos += delta_tilt;
    }
      
    pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);
    
    Serial.print(panLoop.m_pos);
    Serial.print("\t");
    Serial.println(tiltLoop.m_pos);
    
  }
}

