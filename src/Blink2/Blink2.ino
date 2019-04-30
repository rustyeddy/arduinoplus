
#define BUZZER_PIN 3
#define BUTTON_PIN 2
#define LED_PIN 4

#define NOTE_C6 1047
#define NOTE_D6 1157

int pin_state = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {

    int button = digitalRead(BUTTON_PIN);
  if (button == LOW) {
    pin_state = HIGH;
    tone(BUZZER_PIN, NOTE_D6, 500);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  } 
  
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
