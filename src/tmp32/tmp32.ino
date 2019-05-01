void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = analogRead(A1);

  float voltage = temp * 5.0;
  voltage /= 1024.0;

  char buffer[80];
  char *p = buffer;
  
  //Serial.print(voltage);
  //Serial.println(" volts");
  Serial.print("temp:");

  float tempC = (voltage - 0.5) * 100;
  //Serial.print(tempC); Serial.println(" C");
  Serial.print(tempC); Serial.print("C:");
  
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  Serial.print(tempF); Serial.println("F");

  delay(1000);
}
