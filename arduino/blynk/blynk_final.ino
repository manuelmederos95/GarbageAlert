#define BLYNK_PRINT Serial
#define maxBlockedTime 3000
#define nomPoubelle "Poubelle1"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
char auth[] = "9965480b40994ffbb077346f70c5e632";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ESGI";
char pass[] = "Reseau-GES";
int pinValue; //reset pinValue
int pinRead0; //photoreceptor read value
int counter = 0; //timer counter
WidgetLED led1(V0); //warning led in application

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  pinMode(D7, OUTPUT);
  pinMode(D8, INPUT);
  digitalWrite(D7, 1);
  //led1.off();
}


// This function will be called in loop
// Every time Reset button is pushed it will reset counter and turn off warning led in app
BLYNK_WRITE(V1)
{
  pinValue = param.asInt();
  if (pinValue == 1) {
    counter = 0;
    led1.off();
  }
}

void loop()
{
  Blynk.run();
  int pinRead0 = analogRead(D8) * (3.3 / 1023.0);
  Serial.print(pinRead0);
  if (pinRead0 == 0) {
    counter++;
    Serial.print(" Blocked ");
    Serial.println(counter);
    digitalWrite(LED_BUILTIN, 1);
    if (counter == maxBlockedTime) {
      Serial.println("EVENT DECLANCHER");
      Blynk.notify("GARBAGE IS FULLL");
      Blynk.virtualWrite(V0, 0);
      led1.on();
    }
  } else {
    Serial.print(" Pass ");
    Serial.println(counter);
    counter = 0;
  }
}
