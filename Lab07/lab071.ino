int ldrPin = A0;  // Pino analógico onde o fotorresistor está conectado
int ledPin = 9;   // Pino digital onde o LED está conectado
int ldrValue;     // Variável para armazenar a leitura do fotorresistor

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
  Serial.begin(9600);       // Inicializa a comunicação serial para depuração
}

void loop() {
  ldrValue = analogRead(ldrPin); // Lê o valor do fotorresistor
  Serial.println(ldrValue);      // Imprime o valor lido para o monitor serial

  if (ldrValue < 500) {          // Se o valor lido for menor que 500 (ajuste conforme necessário)
    digitalWrite(ledPin, HIGH);  // Acende o LED
  } else {
    digitalWrite(ledPin, LOW);   // Apaga o LED
  }

  delay(100);  // Aguarda 100 ms antes de fazer a próxima leitura
}