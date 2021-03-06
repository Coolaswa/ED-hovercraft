#include <Servo.h>

int thrust;
int steer;
int lift;
int klap;
int grijp;
Servo liftMotor;
Servo thrustMotor;
Servo gimbleB;
Servo gimbleU;
Servo steering;
Servo optillen;
Servo grijpen;

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

  klap = 90;
  optillen.attach(3, 750, 2250);
  optillen.write(klap);

  grijp = 90;
  grijpen.attach(4, 800, 2200);
  grijpen.write(grijp);
  
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
        Serial.print("Thrust: ");
        Serial.println(thrust,DEC);
      break;
      case 's':
        thrust -= 5;
        thrustMotor.write(thrust);
        Serial.print("Thrust: ");
        Serial.println(thrust,DEC);
      break;
      case 'd':
        steer -= 5;
        steering.write(steer);
        Serial.print("Steer: ");
        Serial.println(steer,DEC);
      break;
      case 'a':
        steer += 5;
        steering.write(steer);
        Serial.print("Steer: ");
        Serial.println(steer,DEC);
      break;
      case 'q':
        lift += 5;
        liftMotor.write(lift);
        Serial.print("Lift: ");
        Serial.println(lift, DEC);
      break;
      case 'z':
        lift -= 5;
        liftMotor.write(lift);
        Serial.print("Lift: ");
        Serial.println(lift, DEC);
      break;
      case '8':
        klap += 5;
        optillen.write(klap);
      break;
      case '2':
        klap -= 5;
        optillen.write(klap);
      break;
      case '6':
        grijp += 5;
        grijpen.write(grijp);
        Serial.print("Grijp: ");
        Serial.println(grijp, DEC);
      break;
      case '4':
        grijp -= 5;
        grijpen.write(grijp);
        Serial.print("Grijp: ");
        Serial.println(grijp, DEC);
      break;
      case 'n':
        thrust = 0;
        lift = 0;
        liftMotor.write(lift);
        thrustMotor.write(thrust);
        Serial.println("Noodstop!");
  }
}
