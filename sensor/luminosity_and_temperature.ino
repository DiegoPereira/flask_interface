#include <OneWire.h> // inclusão da biblioteca

int portaTemperatura = 7; // entrada de temperatura
int portaLuminosidade = A0; //Porta analógica utilizada pelo LDR  

float temperatura; // armazena a temperatura
float luminosidade; // armazena a temperatura

OneWire SensorTemperatura(portaTemperatura); // cria um objeto que representa o sensor ligado ao pino portaTemperatura

void setup() {
  Serial.begin(9600);

}

void loop() {
  luminosidade = analogRead(portaLuminosidade);  //Lê o valor fornecido pelo LDR
  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  temperatura = getTemp(); // obtem a temperatura como um numero real
  Serial.print("Temperatura: ");
  Serial.println (temperatura); // envia pela porta serial o valor a quem quiser saber

  Serial.println();
  
  delay(1000); // apenas um atraso entre execucoes do loop()
}

float getTemp() {   // se comunica com o sensor DS, obtem os bytes dele, processa-os e com isso calcula a temperatura em graus C

  byte dado[12]; // conjunto de variaveis
  byte endereco[8];  // conjunto de variaveis

  if (!SensorTemperatura.search(endereco)) {  //  nao ha mais sensores pendurados no pino 2 (dos DS)
    SensorTemperatura.reset_search();
    return -500; // se a programaçao der erro, esse sera o valor que ira aparecer
  }
  
  if (OneWire::crc8(endereco, 7) != endereco[7]) {
    Serial.println("Erro de leitura – CRC invalido!"); // se der erro na leitura, é mostrado “Erro de leitura – CRC invalido!”
    return -500;  // e mostrado um valor impossivel para representar o erro
  }
  
  if (endereco[0] != 0x10 && endereco[0] != 0x28) {
    Serial.print("Sensor nao reconhecido :("); // sensor não encontrado
    return -500; // é mostrado um valor impossivel para representar o erro
  }
  
  SensorTemperatura.reset();
  SensorTemperatura.select(endereco);
  SensorTemperatura.write(0x44,1); // inicia conversao
  
  byte present = SensorTemperatura.reset();
  SensorTemperatura.select(endereco);
  SensorTemperatura.write(0xBE);
  
  for (int i = 0; i < 9; i++) { // sao 9 bytes lidos
    dado[i] = SensorTemperatura.read();
  }
  
  SensorTemperatura.reset_search();
  
  byte MSB = dado[1];
  byte LSB = dado[0];
  
  float tempRead = ((MSB << 8) | LSB);
  float TemperatureSum = tempRead / 16;
  
  return TemperatureSum;

}
