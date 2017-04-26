#include <SPI.h>
#include <Pixy.h>
#include <Servo.h>

#define DEBUG false
#define TIMEOUT 40*1000
#define DELAY_DOOR 30
#define SERVO_CLOSE 100
#define SERVO_OPEN 0
#define SIGNATURE_BALL 1
#define SIGNATURE_CONTAINER 2
#define THRESHOLD_Y 180 
#define THRESHOLD_CONTAINER 24000
#define DEFAULT_BLOB_SIZE 200
#define MIN_BLOB_SIZE 10
#define SPEED 140

//All pins
const int motorL1 = 7;
const int motorL2 = 8;
const int motorLPWM = 6;

const int motorR1 = 12;
const int motorR2 = 13;
const int motorRPWM = 11;

const int switchF = 3;
const int switchR = 4;

int blob_x;
int blob_y;
int blobSize;
int ballCount = 0;

bool doorClosed;

enum State {
    BALL,
    COLLECT,
    CONTAINER,
    EMPTY,
    HALT
  };
 // add a comment
State state;

Servo doorservo;
Pixy pixy;

void setup()
{
  
  if(DEBUG) {
    Serial.begin(9600);
    Serial.print("Starting...\n");
  }
  pixy.init();
  doorservo.attach(10);
  
  pinMode(switchF, OUTPUT);
  pinMode(switchR, OUTPUT);

  doorClosed = false;
  state = BALL;
  
  closeDoor();
  pushIn();
  stopMove();
  stopPush();

  if(DEBUG)
    Serial.print("Ready\n");
}

void loop()
{
    switch(state) {
      case BALL:
        findBall();
        break;
  
      case HALT:
        stopMove();
        break;
    
      case COLLECT:
        collectBall();
        break;
    
      case CONTAINER:
        findContainer();
        break;
    
      case EMPTY:
        empty();
        break;
    }
}
