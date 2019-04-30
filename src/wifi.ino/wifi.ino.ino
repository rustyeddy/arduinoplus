// put your setup code here, to run once:
// Import required libraries
#include "ESP8266WiFi.h"

// WiFi parameters
const char* ssid = "SnotGobbler";
const char* password = "123454321";

void setup(void)
{ 
  // Start Serial
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {
  // put your main code here, to run repeatedly:

}
