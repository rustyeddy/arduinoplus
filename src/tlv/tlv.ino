//www.elegoo.com
//2016.12.09

class Joystick {
public:
  int pinX, pinY, pinSW;
  int x, y, sw;

  Joystick(int px, int py, int psw);
  void Report();
  
};

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int x, y, sw;
  sw = digitalRead(SW_pin);
  x = analogRead(X_pin);
  y = analogRead(Y_pin);

  Serial.print("j:"); Serial.print(sw);
  Serial.print(":"); Serial.print(x);
  Serial.print(":"); Serial.println(y);
  delay(100);
}
