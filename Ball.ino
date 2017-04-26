void findBall() {
    if(track(SIGNATURE_BALL)) {
      if(DEBUG)
        Serial.println(blob_y);
       
      if( blob_y > 100 ) {
        state = COLLECT;
        if(DEBUG)
          Serial.println("BALL >>> COLLECT"); 
      }  
    } else {
      //wait timeout and search for ball
      if(DEBUG)
        Serial.println("Searching balls");

      ScanForBlocks();
    }
}
