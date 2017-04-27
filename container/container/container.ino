
const int switchU = 3;
const int switchD = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchU, OUTPUT);
  pinMode(switchU, OUTPUT);
  pushDown();
}

void loop() {
  // put your main code here, to run repeatedly:
  pushUp();
  pushDown();
}

void pushUp() {
  digitalWrite(switchU, HIGH);
  Serial.println("Push up.");
  while(digitalRead(switchU));
  stopPush();
}

void pushDown() {
  digitalWrite(switchD, HIGH);
  Serial.println("Push down");
  while(digitalRead(switchD));
  stopPush();
}

void stopPush() {
  digitalWrite(switchU, LOW);
  digitalWrite(switchD, LOW);
}
