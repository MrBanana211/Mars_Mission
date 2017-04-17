int TrackBlock(int blockCount, int targetSignature)
{
  static int oldX, oldY;
  int trackedBlock = 0;
  long maxSize = 0;
  
  for (int i = 0; i < blockCount; i++) {
    if (pixy.blocks[i].signature == targetSignature) {
      long newSize = pixy.blocks[i].height * pixy.blocks[i].width;
      if (newSize > maxSize){
        trackedBlock = i;
        maxSize = newSize; 
      }
    }
  }
  
  int32_t panError = X_CENTER - pixy.blocks[trackedBlock].x; 
  int32_t tiltError = pixy.blocks[trackedBlock].y - Y_CENTER;
  
  panLoop.update(panError);
  tiltLoop.update(tiltError);
  
  pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);
  
  oldX = pixy.blocks[trackedBlock].x;
  oldY = pixy.blocks[trackedBlock].y;

  return trackedBlock;
}



void FollowBlock(int trackedBlock) {
  static int32_t size = 200;
  int32_t followError = panLoop.m_pos - panLoop.m_centerPos; // How far off-center are we looking now?
  // Size is the area of the object.
  // We keep a running average of the last 8.
  size += pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height; 
  size -= size >> 3;
  
  // Forward speed decreases as we approach the object (size is larger) 
  int forwardSpeed = constrain(200 - (size/256), -100, 200);
  
  // Steering differential is proportional to the error times the forward speed 
  int32_t differential = (followError + (followError * forwardSpeed)) >> 8;
  differential /= 2;
  
  // Adjust the left and right speeds by the steering differential.
  int leftSpeed = constrain(forwardSpeed + differential, -180, 180); //forward + diff
  int rightSpeed = constrain(forwardSpeed - differential, -180, 180); //forward - diff
  
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

//---------------------------------------
// Random search for blocks
//
// This code pans back and forth at random until a block is detected //---------------------------------------
int scanIncrement = (panLoop.m_maxPos - panLoop.m_minPos) / 150;
uint32_t lastMove = 0;

void ScanForBlocks() {
if (millis() - lastMove > 20) {
  lastMove = millis();
  panLoop.m_pos += scanIncrement;
    if ((panLoop.m_pos >= panLoop.m_maxPos)||(panLoop.m_pos <= panLoop.m_minPos)) {
      tiltLoop.m_pos = random(tiltLoop.m_maxPos * 0.5, tiltLoop.m_maxPos); 
      scanIncrement = -scanIncrement;
      }
  pixy.setServos(panLoop.m_pos, tiltLoop.m_pos);
  }
}

