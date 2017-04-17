int track(int signature) {
  static unsigned long lastBlockTime = 0;
  uint16_t blocks;
  blocks = pixy.getBlocks();
  // If we have blocks in sight, track and follow them 
  if (blocks){
    int trackedBlock = TrackBlock(blocks, signature);
    FollowBlock(trackedBlock);
    lastBlockTime = millis();
    return pixy.blocks[trackedBlock].width * pixy.blocks[trackedBlock].height;
    
  }
  else if(millis() - lastBlockTime > 100) {

    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    analogWrite(motorLPWM, 0);

    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    analogWrite(motorRPWM, 0);
    ScanForBlocks();
  } 
  /*
  else if(millis() > TIMEOUT){ //no time state
    state = CONTAINER;
  }
  */
}
