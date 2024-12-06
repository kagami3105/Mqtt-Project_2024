#include <Arduino.h>

#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>


char ssid[] = "UNIFI_IDO1";    // your network SSID (name)
char pass[] = "41Bidules!";    // your network password (use for WPA, or use as key for WEP)

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
void onMqttMessage(int);

const char broker[]    = "192.168.10.122";
int        port        = 1883;

const char topic_A1[]  = "amine/Touche_Sensor";
const char topic_A2[]  = "amine/Distance";
const char topic_A3[]  = "amine/ledState";
const char topic_A4[]  = "amine/Sound_Sensor";


const long interval = 1000;
unsigned long previousMillis = 0;


#define toucheSensorPin 8
#define ultraSonicPin A6
#define ledPin 6
#define soundSensorPin A1


String toucheSensor;
String ledState;
int distance;

/*void setup() {

   Serial.begin(9600);

  pinMode(toucheSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

// ___________________________________________________ Connect to Newtork ____________________________________________
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to WiFi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();
  // ____________________________________________________________________________________________________________________

  // ___________________________________________________ Connect to Broker ______________________________________________

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
  Serial.println();
  // ____________________________________________________________________________________________________________________
}

void loop() {

  mqttClient.poll();

  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {

// _________________________ Touche Sensor ______________________________

    if(digitalRead(toucheSensorPin) == HIGH)
        toucheSensor = "ON";
    else 
        toucheSensor = "OFF";

    mqttClient.beginMessage(topic_A1);
    mqttClient.print(toucheSensor);
    mqttClient.endMessage();
// _________________________________________________________________________

// _________________________ ultraSonic Sensor _____________________________

    mqttClient.beginMessage(topic_A2);
    int distance = analogRead(ultraSonicPin) * 520 / 1023;
    mqttClient.print(distance);
    mqttClient.endMessage();
// ________________________________________________________________________

// _______________________________ led ____________________________________
    Serial.println(distance);

    if(distance < 50) {
      digitalWrite(ledPin, HIGH);
      ledState = "ON";
    }
    else {
      digitalWrite(ledPin, LOW);
      ledState = "OFF";
    }
    
    mqttClient.beginMessage(topic_A3);
    mqttClient.print(ledState);
    mqttClient.endMessage();

// ________________________________________________________________________

// _____________________________ Sound Sensor _____________________________

    int val;
    val = analogRead(soundSensorPin);   //connect sensor to Analog 0
    Serial.println(val);//print the sound value to serial

    mqttClient.beginMessage(topic_A4);
    mqttClient.print(val);
    mqttClient.endMessage();

    // save the last time a message was sent
    previousMillis = currentMillis;

  }
// ________________________________________________________________________

}*/

