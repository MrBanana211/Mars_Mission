void findContainer() {
  if( track(SIGNATURE_CONTAINER) > THRESHOLD_CONTAINER){
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
