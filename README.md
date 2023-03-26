# MPU6050-Usage-for-Arduino
An Arduino code for detect and explain movements with vectors.

This code detects movements with vectors for 3-dimensional space, you can change the dimension by erasing Y and Z vector codes.

Disclaimer: MPU6050 can measure temperature but this code not for that. If you want to measure temperature with MPU6050 sensor, you can add this code after reading event of radians (rad/s):
  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
