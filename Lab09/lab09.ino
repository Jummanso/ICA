// Definição dos pinos
const int pirPin = 2;   // Pino onde o sensor PIR está conectado
const int ledPin = 13;  // Pino onde o LED está conectado

void setup() {
  pinMode(pirPin, INPUT);   // Configura o pino do sensor PIR como entrada
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
  Serial.begin(9600);       // Inicializa a comunicação serial
}

void loop() {
  int pirState = digitalRead(pirPin);  // Lê o estado do sensor PIR

  if (pirState == HIGH) {  // Se o sensor PIR detectar movimento
    Serial.println("Presença detectada!");  // Imprime mensagem na serial
    digitalWrite(ledPin, HIGH);  // Acende o LED
    delay(500);  // Aguarda 500 ms
    digitalWrite(ledPin, LOW);   // Apaga o LED
    delay(500);  // Aguarda 500 ms
  } else {
    digitalWrite(ledPin, LOW);   // Garante que o LED esteja apagado se não houver movimento
  }
}