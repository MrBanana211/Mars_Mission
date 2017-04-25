void findBall() {
    if(track(SIGNATURE_BALL)) {
      Serial.println(blob_y); 
      if( blob_y > 100 ) {
        state = COLLECT;
        Serial.println("BALL >>> COLLECT");    
      }  
    } else {
      //wait timeout and search for ball
      Serial.println("Searching balls");
      ScanForBlocks();
    }
}
