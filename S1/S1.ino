#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure>
#include "env.h"

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wificlient);

const String SSID = "FIESC_IOT_EDU";
const String PASS = "8120gv08";
const String topico = "StrogonoffcomBatataPalha";

const String brokerURL = "test.mosquitto.org";
const int brokerPort = 1883;

const String brokerUser = "";
const String brokerPass = "";

void setup() {
  Serial.begin(115200);
  wifiClient.setInsecure();
  connectToWiFi();
  connectToBroker();
}

void loop() {
  // String mensagem = "";
  // if (Serial.available() > 0) {
  //   mensagem = Serial.readStringUntil('\n');
  //   Serial.print("Mensagem digitada: ");
  //   Serial.println(mensagem);
  //   mqtt.publish("TopicoVini", mensagem.c_str());
  // }
  // mqtt.loop();
}

void callback(char* topic, byte* payload, unsigned long length) {
  // String mensagemRecebida = "";
  // for (int i = 0; i < length; i++) {
  //   mensagemRecebida += (char)payload[i];
  // }
  // Serial.println(mensagemRecebida);
  // if(mensagemRecebida == "on"){
  //   digitalWrite(2, 1);
  // } else if(mensagemRecebida == "off"){
  //   digitalWrite(2, 0);
  // }
}