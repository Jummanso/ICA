// Define os pinos
const int POT_PIN = A0; // Pino analógico onde o potenciômetro está conectado
const int LED_PIN = 9;  // Pino PWM onde o LED está conectado

void setup() {
  // Inicializa o pino do LED como saída
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Lê o valor do potenciômetro (0 a 1023)
  int valorPot = analogRead(POT_PIN);

  // Mapeia o valor do potenciômetro para o intervalo de 0 a 255
  int valorLED = map(valorPot, 0, 1023, 0, 255);

  // Ajusta a luminosidade do LED com base no valor mapeado
  analogWrite(LED_PIN, valorLED);

  // Pequena pausa para estabilizar a leitura
  delay(10);
}