void findContainer() {
  if(track(SIGNATURE_CONTAINER)){
    if(DEBUG)
      Serial.println(blobSize);
      
    if(blobSize > THRESHOLD_CONTAINER){
      //openContainer();
      state = EMPTY;
      if(DEBUG)
        Serial.println("CONTAINER->EMPTY");
    }
  } else {
    ScanForBlocks();
  }
}

void openContainer() {
  
}

void closeContainer() {
  
}
