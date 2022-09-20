int LevelSensorVal = 0;

int echoPin = 0;

int triggerPin = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  echoPin = 3;
  triggerPin = 2;
  LevelSensorVal = 0.01723 * readUltrasonicDistance(2, 3);
  Serial.println("Level Control System");
  Serial.println(LevelSensorVal);
  if (LevelSensorVal <= 40) {
    Serial.println("Tank is FULL");
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    tone(5, 19, 1000); 
  }
  if (LevelSensorVal >= 300) {
    Serial.println("Tank is EMPTY");
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  delay(10); 
}