void findContainer() {
  bool found = track(SIGNATURE_CONTAINER);
  
  if(found){
    if(!foundBlob)
      breakMove();
    foundBlob = true;
          
    FollowBlock(trackedBlock);
    
    if(DEBUG)
      Serial.println(blobSize);
      
    if(blobSize > THRESHOLD_CONTAINER){
      //openContainer();
      state = EMPTY;
      if(DEBUG)
        Serial.println("CONTAINER->EMPTY");
    }
  } else if(!foundBlob) {
      ScanForBlocks();
  }
}

void openContainer() {
  
}

void closeContainer() {
  
}
