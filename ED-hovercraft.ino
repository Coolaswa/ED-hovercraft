#include <Servo.h>

int thrust;
int steer;
int lift;
Servo liftMotor;
Servo thrustMotor;
Servo gimbleB;
Servo gimbleU;
Servo steering;

int gimbleUPosX = 90;
int gimbleUPosY = 90;
int currentsystem = 0;
//1 = gimble (g)
//2 = hand (h)

void setup() {
  thrust = 0;
  thrustMotor.attach(0, 1000, 2000);
  thrustMotor.write(thrust);

  steer = 90;
  steering.attach(1, 750, 2250);
  steering.write(90);

  lift = 0;
  liftMotor.attach(2, 1000, 2000);
  liftMotor.write(lift);
  
  //servoX.attach(servoPinX, 1000, 2000);
  //servoY.attach(servoPinY, 750, 2250);
  //Gimble
  gimbleB.attach(6);
  gimbleU.attach(5);

  gimbleB.write(gimbleUPosX);
  gimbleU.write(gimbleUPosY);

    Serial.begin(9600);
}

void loop() {
    char input = Serial.read();
    switch(input){
      case 'w': 
        thrust += 5;
        thrustMotor.write(thrust);
        Serial.println(thrust,DEC);
      break;
      case 's':
        thrust -= 5;
        thrustMotor.write(thrust);
        Serial.println(thrust,DEC);
      break;
      case 'd':
        steer -= 5;
        steering.write(steer);
      break;
      case 'a':
        steer += 5;
        steering.write(steer);
      break;
      case 'q':
        lift += 5;
        liftMotor.write(lift);
      break;
      case 'z':
        lift -= 5;
        liftMotor.write(lift);
      break;
  }
}
