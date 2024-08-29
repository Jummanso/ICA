// Definição dos pinos
const int pirPin = 2;   // Pino onde o sensor PIR está conectado
const int relayPin = 3; // Pino onde o relé está conectado

void setup() {
  pinMode(pirPin, INPUT);   // Configura o pino do sensor PIR como entrada
  pinMode(relayPin, OUTPUT);  // Configura o pino do relé como saída
  Serial.begin(9600);       // Inicializa a comunicação serial
  Serial.println("Sistema de Iluminação Residencial iniciado"); // Mensagem de inicialização
}

void loop() {
  int pirState = digitalRead(pirPin);  // Lê o estado do sensor PIR

  if (pirState == HIGH) {  // Se o sensor PIR detectar movimento
    Serial.println("Movimento detectado!");  // Imprime mensagem na serial
    digitalWrite(relayPin, HIGH);  // Ativa o relé para acender a lâmpada
  } else {
    Serial.println("Nenhum movimento detectado."); // Mensagem de ausência de movimento
    digitalWrite(relayPin, LOW);   // Desativa o relé para apagar a lâmpada
  }
}