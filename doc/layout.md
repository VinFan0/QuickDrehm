# Pin layout for FieldMarker
## Author: Ryan Beck

## Peripherals to connect:
- 4x Motor
- 1x Servo (PWM, Pin 0)
- Down Prox Sensor (UART4)
- Forward Prox Sensor (UART3?)
- 1x GPS

## Pins
**Left Side**
- 0 Rx1 -> GPS Tx
- 1 Tx1 -> GPS Rx
- 2 Motor 2
- 3 UNUSED
- 4 Motor 0
- 5 Sprayer Servo
- 6 UNUSED SERVO
- 7 UNUSED
- 8 Motor 1
- 9 UNUSED MOTOR
- 10 UNUSED SERVO
- 11 UNUSED SERVO
- 12 UNUSED SERVO

**Right Side**
- 13 UNUSED
- 14 Forward Prox Sensor Tx
- 15 Forward Prox Sensor Rx
- 16 Down Prox Sensor Rx
- 17 Down Prox Sensor Tx
- 18 IMU SDA
- 19 IMU SCL
- 20 UNUSED
- 21 SBUS In
- 22 Motor 3
- 23 Motor 4


  **Bottom**
  - 24 Compass I2C SCL2
  - 24 Compass I2C SDA2
