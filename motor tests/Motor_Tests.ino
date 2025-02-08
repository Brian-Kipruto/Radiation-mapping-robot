
/*This code tests each of the  motors on the 6WD chassis keeping in mind that each L298N controls 2 motors.*/
#include <Arduino.h>

//L298N Pin definitions
//for L298N #1 controls front left and front right motors

const int ENA1 = 3; // front left PWM
const int IN1 = 7;
const int IN2 = 8;
const int ENB1 = 5; //front right PWM
const int IN3 = 4;
const int IN4 = 2;

// for L298N #2 controls middle left and back left motors

const int ENA2 = 6; // middle left PWM
const int IN1b = 12;
const int IN2b = 13;
const int ENB2 = 9; //back left PWM
const int IN3b = A0;
const int IN4b = A3;

// for l298n #3. controls middle right and back right motors.

const int ENA3 = 10; //middle right PWM
const int IN1c = A1;
const int IN2c = A2;
const int ENB3 = 11; //back right PWM
const int IN3c = A4;
const int IN4c = A5;

// motor arrangements: 0-front left, 1-middle left, 2-back left, 3-front right, 4-middle right, 5-back right

const int motors = 6;
int currentMotor = 0;

void setup(){
  pinMode (ENA1, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENB1, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);

  pinMode (ENA2, OUTPUT);
  pinMode (IN1b, OUTPUT);
  pinMode (IN2b, OUTPUT);
  pinMode (ENB2, OUTPUT);
  pinMode (IN3b, OUTPUT);
  pinMode (IN4b, OUTPUT);

  pinMode (ENA3, OUTPUT);
  pinMode (IN1c, OUTPUT);
  pinMode (IN2c, OUTPUT);
  pinMode (ENB3, OUTPUT);
  pinMode (IN3c, OUTPUT);
  pinMode (IN4c, OUTPUT);

  Serial.begin (9600);
  
  }

  void loop (){
    Serial.print ("Testing motor: ");
    Serial.println(currentMotor);

    motorTesting(currentMotor);
    delay(2000);

    currentMotor++;
    if (currentMotor >= motors){
      currentMotor=0;
      }

  }

  void motorTesting (int motorNumber){
    
    analogWrite (ENA1,0);
    analogWrite (ENB1,0);
    analogWrite (ENA2,0);
    analogWrite (ENB2,0);
    analogWrite (ENA3,0);
    analogWrite (ENB3,0);

    switch (motorNumber){
       case 0://l298N#1
           Serial.println ("Frontleft motor:foward");
           digitalWrite(IN1, LOW);
           digitalWrite (IN2, HIGH);
           analogWrite (ENA1, 255);
           break;

       case 1: //L298N #2
           Serial.println ("middle left motor: Foward");
           digitalWrite (IN1b, LOW);
           digitalWrite (IN2b, HIGH);
           analogWrite (ENA2, 240);
           break;

       case 2: //L298N #2
           Serial.println ("back left motor: Foward");
           digitalWrite (IN3b, LOW);
           digitalWrite (IN4b, HIGH);
           analogWrite (ENB2, 240);
           break;

       case 3://l298N#1
           Serial.println ("front right motor: Foward");
           digitalWrite (IN3, LOW);
           digitalWrite (IN4, HIGH);
           analogWrite (ENB1, 240);
           break;

       case 4: //l298N #3
           Serial.println ("middle right motor: Foward");
           digitalWrite (IN1c, LOW);
           digitalWrite (IN2c, HIGH);
           analogWrite (ENA3, 240);
           break;

       case 5: // l298N #3
           Serial.println (" back right motor: Foward");
           digitalWrite (IN3c, LOW);
           digitalWrite (IN4c, HIGH);
           analogWrite (ENB3, 240);
           break;
    }

       delay (4000);

    analogWrite (ENA1,0);
    analogWrite (ENB1,0);
    analogWrite (ENA2,0);
    analogWrite (ENB2,0);
    analogWrite (ENA3,0);
    analogWrite (ENB3,0);

    delay (1000);
  

     switch (motorNumber){
       case 0: //l298N#1
           Serial.println ("Frontleft motor:Backward");
           digitalWrite(IN1, HIGH);
           digitalWrite (IN2, LOW);
           analogWrite (ENA1, 240);
           break;

       case 1: //L298N #2
           Serial.println ("middle left motor: Backward");
           digitalWrite (IN1b, HIGH);
           digitalWrite (IN2b, LOW);
           analogWrite (ENA2, 240);
           break;

       case 2: //L298N #2
           Serial.println ("back left motor: Backward");
           digitalWrite (IN3b, HIGH);
           digitalWrite (IN4b, LOW);
           analogWrite (ENB2, 240);
           break;

       case 3://l298N#1
           Serial.println ("front right motor: Backward");
           digitalWrite (IN3, HIGH);
           digitalWrite (IN4, LOW);
           analogWrite (ENB1, 240);
           break;

       case 4: //l298N #3
           Serial.println ("middle right motor: Backward");
           digitalWrite (IN1c, HIGH);
           digitalWrite (IN2c, LOW);
           analogWrite (ENA3, 240);
           break;

       case 5: // l298N #3
           Serial.println (" back right motor: Backward");
           digitalWrite (IN3c, HIGH);
           digitalWrite (IN4c, LOW);
           analogWrite (ENB3, 240);
           break;
     }

       delay (4000);
       
    analogWrite (ENA1,0);
    analogWrite (ENB1,0);
    analogWrite (ENA2,0);
    analogWrite (ENB2,0);
    analogWrite (ENA3,0);
    analogWrite (ENB3,0);
  
  }
