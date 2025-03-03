// Proximity Sensor
// Teensy Flight Controller - QuickDrehm
// Author: Ryan Beck

void proxInit() {
  pinMode(FRONT_TX_PIN, OUTPUT);
  pinMode(FRONT_RX_PIN, INPUT);
  digitalWrite(FRONT_TX_PIN, LOW);

  pinMode(ALT_TX_PIN, OUTPUT);
  pinMode(ALT_RX_PIN, INPUT);
  digitalWrite(ALT_TX_PIN, LOW);
  delayMicroseconds(20);
}

float measureAlt() {
  float duration, inches;

  digitalWrite(ALT_TX_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ALT_TX_PIN, LOW);

  duration = pulseIn(ALT_RX_PIN, HIGH);

  inches = microsecondsToInches(duration);
  return inches;
}

float microsecondsToInches(float microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}	
