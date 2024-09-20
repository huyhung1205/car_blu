
//-----HC06---------ARDUINO--------L298N--------POWER 12V-5V--------MOTOR--
//-------------------------------- 12V ---------- 5V 12V ------------------
//----------------- VIN ---------- 5V -------------------------------------
//---- GND -------- GND ---------- GND ---------- 0V ----------------------
//---- VCC -------- 5V ----------------------------------------------------
//---- TX --------- RX ----------------------------------------------------
//---- RX --------- TX ----------------------------------------------------
//----------------- 9 ------------ ENA ------------------------------------
//----------------- 7 ------------ IN1 ------------------------------------
//----------------- 8 ------------ IN2 ------------------------------------
//----------------- 11 ----------- IN3 ------------------------------------
//----------------- 12 ----------- IN4 ------------------------------------
//----------------- 10 ----------- ENB ------------------------------------
//-------------------------------- OUT1 ----------------------------- A- --
//-------------------------------- OUT2 ----------------------------- A+ --
//-------------------------------- OUT3 ----------------------------- B- --
//-------------------------------- OUT4 ----------------------------- B+ --

#include <SoftwareSerial.h>

// Khai báo chân
// Motor Left
#define IN4 12  //L
#define IN3 11
#define ENB 10
// Motor Right
#define ENA 9
#define IN2 8  //R
#define IN1 7

// Tốc độ
#define speed_Coeff 3
#define SPEED 255

char command;

void setup() {
  Serial.begin(9600);

  pinMode(ENB, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  if (Serial.available() > 0)  // Nếu có dữ liệu nhận được từ mySerial
  {
    command = Serial.read();  // Đọc dữ liệu nhận được và lưu vào biến value
    Serial.println(command);  // In ra màn hình serial dữ liệu nhận được
  }

  if (command == "F") {
    Forward();
    Serial.println("go Forward");
  } else if (command == "G") {
    ForwardLeft();
    Serial.println("go ForwardLeft");
  } else if (command == "I") {
    ForwardRight();
    Serial.println("go ForwardRight");
  } else if (command == "B") {
    Backward();
    Serial.println("go Backward");
  } else if (command == "J") {
    BackwardRight();
    Serial.println("go BackwardRight");
  } else if (command == "H") {
    BackwardLeft();
    Serial.println("go BackwardLeft");
  } else if (command == "R") {
    TurnRight();
    Serial.println("TurnRight");
  } else if (command == "L") {
    TurnLeft();
    Serial.println("TurnLeft");
  } else {
    Stop();
    Serial.println("Stop");
  }
}

void Forward() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void Backward() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void TurnRight() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void TurnLeft() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void ForwardLeft() {
  analogWrite(ENB, SPEED / speed_Coeff);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void BackwardLeft() {
  analogWrite(ENB, SPEED / speed_Coeff);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, SPEED);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void ForwardRight() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  analogWrite(ENA, SPEED / speed_Coeff);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
void BackwardRight() {
  analogWrite(ENB, SPEED);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, SPEED / speed_Coeff);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void Stop() {
  analogWrite(ENB, 0);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
