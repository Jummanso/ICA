// Define os pinos dos LEDs
const int LED_VERMELHO = 2;
const int LED_AMARELO = 3;
const int LED_VERDE = 4;

void setup() {
  // Define os pinos dos LEDs como saídas
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  // Acende o LED verde e apaga os outros
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(2000); // Espera por 2 segundos

  // Acende o LED amarelo e apaga os outros
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  delay(2000); // Espera por 2 segundos

  // Acende o LED vermelho e apaga os outros
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(2000); // Espera por 2 segundos

  // Retorna ao LED verde
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(2000); // Espera por 2 segundos
}