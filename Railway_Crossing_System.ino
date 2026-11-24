#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd1(0x27, 16, 2);

Servo gate1;
Servo gate2;


int trigL = 2;
int echoL = 3;
int trigR = 4;
int echoR = 5;
int redPin = 6;
int greenPin = 7;
int buzzer = 8;
bool trainDetected = false;
unsigned long previousBeepTime = 0;
bool buzzerState = false;
const int beepInterval = 400;


// Function to measure distance
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  gate1.attach(9);
  gate2.attach(10);

  pinMode(trigL, OUTPUT);
  pinMode(echoL, INPUT);
  pinMode(trigR, OUTPUT);
  pinMode(echoR, INPUT);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // LCD start
  lcd1.init();
  lcd1.backlight();

  // Initial state
  gate1.write(0);
  gate2.write(0);

  lcd1.setCursor(0, 0);
  lcd1.print("WELCOME");
  lcd1.setCursor(0, 1);
  lcd1.print("C++ RAILWAY GATE");
  
  digitalWrite(greenPin, HIGH);
}

void loop() {
  long distL = getDistance(trigL, echoL);
  long distR = getDistance(trigR, echoR);
  
  bool currentTrainState = (distL < 15 || distR < 15);

  if (currentTrainState && !trainDetected) {
    trainDetected = true;
    
    gate1.write(90);
    gate2.write(90);

    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    

    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("TRAIN COMING");
    lcd1.setCursor(0, 1);
    lcd1.print("GATE CLOSED");
  } 
  else if(!currentTrainState && trainDetected){
    trainDetected = false;
    
    gate1.write(0);
    gate2.write(0);
    
 	digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);

    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("SAFE TO GO");
    lcd1.setCursor(0, 1);
    lcd1.print("GATE OPEN");
  }

  delay(300);
  if (trainDetected) {
  	unsigned long currentTime = millis();
  
    if(currentTime - previousBeepTime >= beepInterval) {
    	previousBeepTime = currentTime;
    	buzzerState = !buzzerState;
    
      if(buzzerState) {
      	tone(buzzer, 1000);
      }
      else {
      	noTone(buzzer);
      }
    }
  }
  else {
  	noTone(buzzer);
  }
}