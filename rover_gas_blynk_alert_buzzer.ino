#define BLYNK_TEMPLATE_ID "TMPL34LqBD9LD"
#define BLYNK_TEMPLATE_NAME "Gas rover"
#define BLYNK_AUTH_TOKEN "G_v7vGdE-E_LywpdSQrZJsbR29Q__L-E"
#define buzzerPin  33   // Buzzer connected to GPIO 33


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

bool alertSent = false;  // Keeps track of whether alert is already sent


// Blynk Auth & WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "myfi";           // Your WiFi name
char pass[] = "123123123";      // Your WiFi password

// Motor control pins
int ENA = 13;
int IN1 = 12;
int IN2 = 14;
int ENB = 25;
int IN3 = 27;
int IN4 = 26;

// MQ-2 Gas Sensor
int gasSensorPin = 35; // Analog pin

// PWM channels
const int freq = 1000;
const int resolution = 8;
const int channelA = 0;
const int channelB = 1;

// Rover Movement Functions
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  ledcWrite(channelA, 255);
  ledcWrite(channelB, 255);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  ledcWrite(channelA, 255);
  ledcWrite(channelB, 255);
}

void moveLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  ledcWrite(channelA, 255);
  ledcWrite(channelB, 255);
}

void moveRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  ledcWrite(channelA, 255);
  ledcWrite(channelB, 255);
}

void stopMoving() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  ledcWrite(channelA, 0);
  ledcWrite(channelB, 0);
}

// Blynk Button Control Handlers
BLYNK_WRITE(V1) {
  int state = param.asInt();
  if (state == 1) moveForward();
  else stopMoving();
}

BLYNK_WRITE(V2) {
  int state = param.asInt();
  if (state == 1) moveBackward();
  else stopMoving();
}

BLYNK_WRITE(V3) {
  int state = param.asInt();
  if (state == 1) moveLeft();
  else stopMoving();
}

BLYNK_WRITE(V4) {
  int state = param.asInt();
  if (state == 1) moveRight();
  else stopMoving();
}

void setup() {
  Serial.begin(9600);
  
  Serial.println("Connecting to WiFi...");
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println("\n✅ WiFi Connected!");
Serial.print("IP Address: ");
Serial.println(WiFi.localIP());

Serial.println("Connecting to Blynk...");
Blynk.begin(auth, ssid, pass);
Serial.println("✅ Blynk Init Done");

  Blynk.begin(auth, ssid, pass);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(buzzerPin, OUTPUT);
digitalWrite(buzzerPin, LOW);  // Make sure buzzer is OFF at start


  // PWM Setup
  ledcSetup(channelA, freq, resolution);
  ledcAttachPin(ENA, channelA);

  ledcSetup(channelB, freq, resolution);
  ledcAttachPin(ENB, channelB);
}

void loop() {
  Blynk.run();

  // Read and send gas level
  // int gasValue = analogRead(gasSensorPin);
  // Serial.print("Gas Level: ");
  // Serial.println(gasValue);
  // Blynk.virtualWrite(V5, gasValue);
int gasValue = analogRead(gasSensorPin);
Serial.print("Gas Level: ");
Serial.println(gasValue);

// Send to Blynk app
Blynk.virtualWrite(V5, gasValue);

// Check gas threshold and send alert once
if (gasValue > 100 && !alertSent) {
  Blynk.logEvent("gas_alert", "⚠️ Gas level is dangerously high!");
  alertSent = true;
  digitalWrite(buzzerPin, HIGH);  // Turn ON buzzer when gas is high


}
else if (gasValue <= 100) {
  alertSent = false; // Reset flag when gas drops back to safe level
  digitalWrite(buzzerPin, LOW);   // Turn OFF buzzer when gas is normal

}


  // Send to both Gauge & Chart (same virtual pin V5)
  Blynk.virtualWrite(V5, gasValue);

  

  delay(500); // Update every 0.5 sec
}
