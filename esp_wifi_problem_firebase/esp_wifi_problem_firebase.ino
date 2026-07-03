#include <WiFi.h>
#include <Firebase_ESP_Client.h>

#define FIREBASE_HOST "    " // Firebase project name address
#define FIREBASE_AUTH "  " // Firebase secret key
#define WIFI_SSID "  " // Your WiFi name
#define WIFI_PASSWORD "  " // WiFi password
#define TRIG_PIN 33 // Replace with your TRIG pin number
#define ECHO_PIN 25 // Replace with your ECHO pin number

FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);   // Connect to WiFi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);

  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  // Connect to Firebase
}

void loop() {
  // Read distance from ultrasonic sensor
  long duration, distance;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2;

  // Send ultrasonic sensor data to Firebase
  if (Firebase.setFloat(firebaseData, "ULTRASONIC_DISTANCE", distance)) {
    Serial.println("Distance sent to Firebase: " + String(distance));
  } else {
    Serial.println("Failed to send distance to Firebase");
    Serial.println("Error: " + firebaseData.errorReason());
  }

  delay(1000);
}
