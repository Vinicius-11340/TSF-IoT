#include <WiFi.h>
#include <PubSubClient.h>

WifiClient client;
PubSubClient mqtt(client);
const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";

const String brokerURL = "test.mosquitto.org";
const int brokerPort = ;

const String brokerUser = "";
const String brokerPass = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASS);
  Serial.println("WIFI Conecting...");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\nConection Succeed");
  mqtt.setServer(brokerURL.c_str(), brokerPort);
  Serial.println("\nConecting in Broker...");

  String boardID = "S1 - "
  boardID += String(random(0xffff),HEX)

  while(!mqtt.connect(boardID.c_str())){
    Serial.print(".");
    delay(200);
  }
  Serial.println("\nBroker Conection Succeed")
}

void loop() {

}
