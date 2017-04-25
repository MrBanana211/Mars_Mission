void findContainer() {
  track(SIGNATURE_CONTAINER);
  if(blobSize > THRESHOLD_CONTAINER){
    openContainer();
    state = EMPTY;

    if(DEBUG)
      Serial.println("CONTAINER->EMPTY");
  }
}

void openContainer() {
  
}

void closeContainer() {
  
}
