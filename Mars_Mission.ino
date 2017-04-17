#include <SPI.h>
#include <Pixy.h>
#include <Servo.h>
#include "Servoloop.h"

#define DEBUG true
#define TIMEOUT 40*1000
#define DELAY_DOOR 30
#define SIGNATURE_BALL 1
#define SIGNATURE_CONTAINER 2
#define THRESHOLD_BALL 300 
#define THRESHOLD_CONTAINER 300
#define DEFAULT_BLOB_SIZE 200


//All pins
const int motorL1 = 9;
const int motorL2 = 8;
const int motorLPWM = 6;

const int motorR1 = 12;
const int motorR2 = 13;
const int motorRPWM = 11;

const int motorP1 = 3;
const int motorP2 = 4;
const int motorPPWM = 2;
const int switchf = 40;
const int switchr = 41;

enum State {
    BALL,
    COLLECT,
    CONTAINER,
    EMPTY
  };

State state = BALL;
int ball = 0;

Servo doorservo;
Pixy pixy;
ServoLoop panLoop(200, 200, 0L, 1000L, 500L); //servoloop(kp, kd, min, max, center)
ServoLoop tiltLoop(150, 200, 0L, 400L, 200L); 

void setup()
{
  if(DEBUG) {
    Serial.begin(9600);
    Serial.print("Starting...\n");
  }
  
  pixy.init();
  doorservo.attach(10);
  pinMode(switchf, INPUT_PULLUP);
  pinMode(switchr, INPUT_PULLUP);
}

void loop()
{
  switch(state) {
    case BALL:
      findBall();
      break;
  
    case COLLECT:
      collect();
      break;
  
    case CONTAINER:
      findContainer();
      break;
  
    case EMPTY:
      empty();
      break;
  }
}
