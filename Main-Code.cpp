#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
void setup(void) {
  Serial.begin(115200);
  // initialize
  if (!mpu.begin()) {
    Serial.println("Try to connect a MPU6050");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  // set A. range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  // set G. range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // set bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);
}
void loop() {
  // Get new events
  sensors_event_t a, g;
  mpu.getEvent(&a, &g);
  // Print 
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");
  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  Serial.println("<----------------------------------------->");
  delay(1000);
}
