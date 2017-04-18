void findBall() {
    int ballSize = track(SIGNATURE_BALL);
    Serial.println(ballSize);
    if( ballSize > THRESHOLD_BALL){ //next state
      state = COLLECT;
      if(DEBUG)
        Serial.println("Ball->COLLECT");
    }
}
