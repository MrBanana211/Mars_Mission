void findBall() {
    int ballSize = track(SIGNATURE_BALL);
    //Serial.println(ballSize);
    if( ballSize > THRESHOLD_BALL && abs(panLoop.m_pos - panLoop.m_centerPos) < 10) { //next state
      state = COLLECT;
      if(DEBUG)
        Serial.println("Ball->COLLECT");
    }
}
