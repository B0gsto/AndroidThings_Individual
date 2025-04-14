#define BLYNK_TEMPLATE_ID "TMPL4be3ffKyk"
#define BLYNK_TEMPLATE_NAME "Android Things Single"
#define BLYNK_AUTH_TOKEN "***************"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "*********";       // 🔁 schimbă cu WiFi-ul tău
char pass[] = "**************";        // 🔁 schimbă cu parola ta

BlynkTimer timer;

#define GREEN_LED 2   // D4 = GPIO2
#define RED_LED   14  // D5 = GPIO14

void sendSensorAndControlLEDs() {
  int value = analogRead(A0);
  Serial.println(value);

  Blynk.virtualWrite(V0, value);  // trimitem valoarea în aplicație

  if (value > 300) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    // Trimitere notificare o singură dată
    
  } else {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Se conectează la WiFi...");
    delay(500);
  }

  // Rulează funcția o dată la 1 sec
  timer.setInterval(5000L, sendSensorAndControlLEDs);
}

void loop() {
  Blynk.run();
  timer.run();
}