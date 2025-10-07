#include <Wifi.h>
#include <PubSubClient.h>

WifiClient client; //cria objeto p/ wifi
PubSubClient mqtt(client);  //cria objeto p/ mqtt usando Wifi

const String SSID = "FIESC_IOT_EDU ";
const String PASS = "senha da rede "8120gv08";

const String brokerURL = "test.mosquitto.org";
const int brokerPort = 1883;

const String brokerUser = "";   // variável para o user do broker
const String brokerPass = "";   // variável para a senha do broker

void setup() {
  Serial.begin(115200); // configura a placa para mostrar na tela
  Wifi.begin(SSID, PASS); // tenta conectar na rede
  Serial.print("Conectado no Wifi");
  while(Wifi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);  

  }
  Serial.println("Conectado com sucesso!")
  
  mqtt.setServer(brokerURL.c_str(), brokerPort);
  Serial.println("Conectando no Broker");

  // cria um nome que começa com "s1-
  String boardID = "S1-";
  //junta o "s1-" com um número aleatório Hexadecimal
  boardID += String(random(0xffff),HEX);

   while(!mqtt.connect(     )){
    Serial.print(".");
    delay(200);  
  }
  Serial.println("\nConectado com sucesso ao broker!")

}

void loop() {
  String msg = "Eduardo: Oi"; // informação que será enviada para o broker
  String topico = "AulaIoT/msg";
  mqtt.publish(topico.c_str(),msg.c_str());
  delay(2000);
}
