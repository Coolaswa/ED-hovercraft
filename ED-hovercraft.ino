#include <Servo.h>

int thrust;
Servo liftMotor;
Servo thrustMotor;

void setup() {
  thrust = 0;
  liftMotor.attach(0, 1000, 2000);
  Serial.begin(9600);
  liftMotor.write(thrust);
}

void loop() {
    char input = Serial.read();
    switch(input){
      case 'w': 
        thrust += 5;
        liftMotor.write(thrust);
      break;
      case 's':
        thrust -= 5;
        liftMotor.write(thrust);
      break;
    }
}
