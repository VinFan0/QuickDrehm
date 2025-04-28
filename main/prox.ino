// Proximity Sensor
// Teensy Flight Controller - QuickDrehm
// Author: Ryan Beck

void proxInit() {
  // pinMode(FRONT_TX_PIN, OUTPUT);
  // pinMode(FRONT_RX_PIN, INPUT);
  // digitalWrite(FRONT_TX_PIN, LOW);
  altSerial.begin(9600);


  // pinMode(ALT_TX_PIN, OUTPUT);
  // pinMode(ALT_RX_PIN, INPUT);
  // digitalWrite(ALT_TX_PIN, LOW);
  delayMicroseconds(20);
}

void getProxMeasurement(proxReadings_t *prox_readings, bool sensor) {
  if (sensor == 1) {
    prox_readings->altitude = measureAlt();
  }
  // else {
  //   prox_readings->obstacle = measureObstacle();
  // }
}

float measureAlt() {
  uint16_t measurement_mm;
  static float measurement_in;
  Serial4.write(0x55);
  delay(5);

  if (Serial4.available() >= 2) {
    uint8_t highByte = Serial4.read();
    uint8_t lowByte = Serial4.read();

    measurement_mm = (highByte << 8) | lowByte;
    measurement_in = measurement_mm * 0.0393701;
  } else {
    Serial.println("Failed to read");
  }
  return measurement_in;
  
  // float duration, inches;

  // digitalWrite(ALT_TX_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(ALT_TX_PIN, LOW);

  // duration = pulseIn(ALT_RX_PIN, HIGH);

  // inches = microsecondsToInches(duration);
  // return inches;
}

float measureObstacle() {
  // float duration, inches;

  // digitalWrite(FRONT_TX_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(FRONT_TX_PIN, LOW);

  // duration = pulseIn(FRONT_RX_PIN, HIGH);

  // inches = microsecondsToInches(duration);
  return 0.0f;
}

float microsecondsToInches(float microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}	
