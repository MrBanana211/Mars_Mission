#include <Pixy.h>

#define X_CENTER 160L
#define Y_CENTER 100L


class ServoLoop
{ 
  public:
    ServoLoop(int32_t , int32_t, int32_t, int32_t, int32_t);
    void update(int32_t);
    int32_t m_pos;
    int32_t m_prevError; 
    int32_t m_proportionalGain; 
    int32_t m_derivativeGain;
    int32_t m_minPos;
    int32_t m_maxPos;
    int32_t m_centerPos;
};
