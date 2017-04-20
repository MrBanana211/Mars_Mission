int track(int signature) {
  static unsigned long lastBlockTime = 0;
  uint16_t blocks;
  blocks = pixy.getBlocks();
  int blobSize = 0;
  
  // If we have blocks in sight, track and follow them 
  if (blocks){
    int trackedBlock = TrackBlock(blocks, signature);
    blobSize = pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height; 
    if(blobSize > MIN_BLOB_SIZE) {
      FollowBlock(trackedBlock);
      lastBlockTime = millis();
    }
  }
  if(millis() - lastBlockTime > 100) {

    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    analogWrite(motorLPWM, 0);

    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    analogWrite(motorRPWM, 0);
    ScanForBlocks();
  }

   return blobSize;
}
