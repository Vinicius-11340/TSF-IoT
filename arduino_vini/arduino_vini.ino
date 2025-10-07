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
  Serial.begin(115200); //configura a placa pra mostrar na tela
  WiFi.begin(SSID, PASS); //tenta conectar na rede
  Serial.println("Conectando ao Wifi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
    Serial.println("Conectado com Sucesso parceiro!");

  mqtt.setServer(brokerURL.c_str(),brokerPort);
  Serial.println("Conectando no Broker");

  Serial boardID = "S1-conexão";
  boardID += String(random(0xffff), HEX); 

  while(!mqtt.connect(boardID.c_str( ))){
    Serial.print(".");
    delay(200);
  }
    mqttClient.subscribe("AulaIoT/msg");
  Serial.println("\nConectado com sucesso ao broker"!);
}

void loop() {
  String msg = "Vinicius: Oi";
  String topico = "AulaIoT/msg";
  mqtt.publish(topico.c_str(), msg.c_str());
  delay(2000); 
}
