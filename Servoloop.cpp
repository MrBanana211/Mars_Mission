#include "Servoloop.h"


ServoLoop::ServoLoop(int32_t proportionalGain, int32_t derivativeGain, int32_t minPos, int32_t maxPos, int32_t centerPos) {
  m_proportionalGain = -proportionalGain;
  m_derivativeGain = -derivativeGain; 
  m_prevError = 0x80000000L;
  m_minPos = minPos;
  m_maxPos = maxPos;
  m_centerPos = centerPos;
  m_pos = centerPos;
}

void ServoLoop::update(int32_t error) {
  long int velocity;
  char buf[32];
  if (m_prevError!=0x80000000) {
    velocity = (error * m_proportionalGain + (error - m_prevError)*m_derivativeGain)>>10;
    m_pos += velocity;
    if (m_pos > m_maxPos) {
      m_pos = m_maxPos; 
    }
    else if (m_pos < m_minPos) {
      m_pos = m_minPos; 
    }
  }
  m_prevError = error; 
}
