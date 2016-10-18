#include <Servo.h>

int thrust;
Servo liftMotor;
Servo thrustMotor;
Servo gimbleB;
Servo gimbleU;

int gimbleUPosX = 90;
int gimbleUPosY = 90;
int currentsystem = 0;
//1 = gimble (g)
//2 = hand (h)

void setup() {
  thrust = 0;
  liftMotor.attach(0, 1000, 2000);
  liftMotor.write(thrust);
  
  //servoX.attach(servoPinX, 1000, 2000);
  //servoY.attach(servoPinY, 750, 2250);
  //Gimble
  gimbleB.attach(6);
  gimbleU.attach(5);

  gimbleB.write(gimbleUPosX);
  gimbleU.write(gimbleUPosY);

    Serial1.begin(9600);
}

void loop() {
    char input = Serial1.read();
    switch(input){
      case 'w': 
        thrust += 5;
        liftMotor.write(thrust);
          Serial1.println(thrust,DEC);

      break;
      case 's':
        thrust -= 5;
        liftMotor.write(thrust);
          Serial1.println(thrust,DEC);

      break;
  }
}
