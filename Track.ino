bool track(int signature) {
  static unsigned long lastBlockTime = 0;
  uint16_t blocks;
  blocks = pixy.getBlocks();
  
  // If we have blocks in sight, track and follow them 
  if (blocks){
    int trackedBlock = TrackBlock(blocks, signature);
    blobSize = pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height;
    blob_x = pixy.blocks[trackedBlock].x;
    blob_y = pixy.blocks[trackedBlock].y;
   
    if(blobSize > MIN_BLOB_SIZE) {
      FollowBlock(trackedBlock);
      lastBlockTime = millis();
      return true;
    }
  }
  return false;
  /*
  if(millis() - lastBlockTime > 100) {

    stopMove();

    digitalWrite(motorL1, LOW); //move backwoard for more space
    digitalWrite(motorL2, HIGH);
    analogWrite(motorLPWM, 200);

    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    analogWrite(motorRPWM, 200);

    delay(1000);
    
    ScanForBlocks();
  }
*/
}
