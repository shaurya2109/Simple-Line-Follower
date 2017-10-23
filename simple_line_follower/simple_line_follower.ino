/*
Arduino Simple Line Follower Program for 2 Light sensor confirguration.
Owner: Shaurya Jain.
*/

int leftSensor = 3;
int rightSensor = 4;
int leftMotorf = 5;
int leftMotorb = 6;
int rightMotorf = 9;
int rightMotorb = 10;
int leftSensorValue ; 
int rightSensorValue ;

void setup() {
  // put your setup code here, to run once:
pinMode(leftSensor, INPUT);
pinMode(rightSensor, INPUT);
pinMode(leftMotorf, OUTPUT);
pinMode(leftMotorb, OUTPUT);
pinMode(rightMotorf, OUTPUT);
pinMode(rightMotorb, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
leftSensorValue = digitalRead(leftSensor);
rightSensor = digitalRead(rightSensor);

if (leftSensorValue == HIGH && rightSensorValue == HIGH) //forward if both sensors are on white
{
  analogWrite(leftMotorf, 140);
  analogWrite(leftMotorb, 0);
  analogWrite(rightMotorf, 140);
  analogWrite(rightMotorb, 0);
}

if (leftSensorValue == LOW && rightSensorValue == HIGH) //right if only right sensor is on white
{
  analogWrite(leftMotorf, 140);
  analogWrite(leftMotorb, 0);
  analogWrite(rightMotorf, 0);
  analogWrite(rightMotorb, 140);
}

if (leftSensorValue == HIGH && rightSensorValue == LOW) //left if only left sensor is on white
{
  analogWrite(leftMotorf, 0);
  analogWrite(leftMotorb, 140);
  analogWrite(rightMotorf, 140);
  analogWrite(rightMotorb, 0);
}

if (leftSensorValue == LOW && rightSensorValue == LOW) 
{
  analogWrite(leftMotorf, 0);
  analogWrite(leftMotorb, 0);
  analogWrite(rightMotorf, 0);
  analogWrite(rightMotorb, 0);

  delay (500);

  analogWrite(leftMotorf, 0);
  analogWrite(leftMotorb, 140);
  analogWrite(rightMotorf, 140);
  analogWrite(rightMotorb, 0);

  delay(2000);
}

}
