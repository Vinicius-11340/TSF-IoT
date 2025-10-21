#include <WiFi.h>
#include <PubSubClient.h>
#include "env.h"

void setup() {
  Serial.begin(115200);    //configura a placa pra mostrar na tela
  WiFi.begin(SSID, PASS);  //tenta conectar na rede
  Serial.println("Conectando ao Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.println("Conectado com Sucesso parceiro!");
  Serial.println("Conectando no Broker");
  mqtt.setServer(BROKER_URL, BROKER_PORT);
  String boardID = "S1-";
  userID += String(random(0xffff), HEX);

  while (!mqtt.connected()){
    mqttClient.connect(userID.c_str(),BROKER_USR_NAME, BROKER_USR_PASS); {
    Serial.print(".");
    delay(200);
  }
  mqtt.subscribe(TOPIC1);
  mqtt.setCallback(callback);
  Serial.println("\nConectado com sucesso ao broker!");
  pinMode(2, OUTPUT);
}

void loop() {
  String mensagem = "";
  if (Serial.available() > 0) {
    mensagem = Serial.readStringUntil('\n');
    Serial.print("Mensagem digitada: ");
    Serial.println(mensagem);
    mqtt.publish("StrogonoffcomBatataPalha", mensagem.c_str());
  }
  mqtt.loop();
  
}

void callback(char* topic, byte* payload, unsigned long length) {
  String mensagemRecebida = "";
  for (int i = 0; i < length; i++) {
    mensagemRecebida += (char)payload[i];
  }
  Serial.println(mensagemRecebida);
  if(mensagemRecebida == "on"){
    digitalWrite(2, 1);
  } else if(mensagemRecebida == "off"){
    digitalWrite(2, 0);
  }
}
