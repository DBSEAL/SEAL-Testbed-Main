//H-Bride pins 1 and 2 are always front motors and 3 and 4 are always rear motors
//No speed control currently available
String command = "";
//Declare control pins
//RIGHT FRONT
int IN1R = 11;
int IN2R = 10;

//RIGHT REAR
int IN3R = 7;
int IN4R = 6;

//LEFT FRONT=how+to+op
int IN1L = 9;
int IN2L = 8;

//LEFT REAR
int IN3L = 4;
int IN4L = 5;


void setup() {

  //CONFIGURE THE SERIAL INPUT
  Serial.begin(9600);

  pinMode(IN1R, OUTPUT);
  pinMode(IN2R, OUTPUT);
  pinMode(IN3R, OUTPUT);
  pinMode(IN4R, OUTPUT);
  
  pinMode(IN1L, OUTPUT);
  pinMode(IN2L, OUTPUT);
  pinMode(IN3L, OUTPUT);
  pinMode(IN4L, OUTPUT);

  digitalWrite(IN1R, LOW);
  digitalWrite(IN2R, LOW);
  
  allSTOP();
}

void MoveForward(){
  digitalWrite(IN1R, HIGH);
  digitalWrite(IN2R, LOW);
  digitalWrite(IN3R, HIGH);
  digitalWrite(IN4R, LOW);
  digitalWrite(IN1L, HIGH);
  digitalWrite(IN2L, LOW);
  digitalWrite(IN3L, HIGH);
  digitalWrite(IN4L, LOW); 
}

void MoveBackward(){
  digitalWrite(IN1R, LOW);
  digitalWrite(IN2R, HIGH);
  digitalWrite(IN3R, LOW);
  digitalWrite(IN4R, HIGH);
  digitalWrite(IN1L, LOW);
  digitalWrite(IN2L, HIGH);
  digitalWrite(IN3L, LOW);
  digitalWrite(IN4L, HIGH); 
}

void TurnRight(){
  digitalWrite(IN1R, LOW);
  digitalWrite(IN2R, HIGH);
  digitalWrite(IN3R, LOW);
  digitalWrite(IN4R, HIGH);
  digitalWrite(IN1L, HIGH);
  digitalWrite(IN2L, LOW);
  digitalWrite(IN3L, HIGH);
  digitalWrite(IN4L, LOW);
}

void TurnLeft(){
  digitalWrite(IN1R, HIGH);
  digitalWrite(IN2R, LOW);
  digitalWrite(IN3R, HIGH);
  digitalWrite(IN4R, LOW);
  digitalWrite(IN1L, LOW);
  digitalWrite(IN2L, HIGH);
  digitalWrite(IN3L, LOW);
  digitalWrite(IN4L, HIGH);
}

void allSTOP(){
  digitalWrite(IN1R, LOW);
  digitalWrite(IN2R, LOW);
  digitalWrite(IN3R, LOW);
  digitalWrite(IN4R, LOW);
  digitalWrite(IN1L, LOW);
  digitalWrite(IN2L, LOW);
  digitalWrite(IN3L, LOW);
  digitalWrite(IN4L, LOW);
}

void loop() {
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim();

    Serial.print("SEALReceived: ");
    Serial.println(command);

    if (command == "forward") {
      MoveForward();
    } 
    else if (command == "backward") {
      MoveBackward();
    } 
    else if (command == "left") {
      TurnLeft();
    } 
    else if (command == "right") {
      TurnRight();
    } 
    else if (command == "stop") {
      allSTOP();
    } 
  }
}
