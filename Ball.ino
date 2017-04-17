void findBall() {
    if( track(SIGNATURE_BALL) > THRESHOLD_BALL){ //next state
      state = COLLECT;

      if(DEBUG)
        Serial.println("Ball->COLLECT");
    }
}
