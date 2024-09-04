const int motorPin = 9;   // Pino PWM do Arduino conectado à base do transistor
const int potPin = A0;    // Pino analógico do Arduino conectado ao potenciômetro

void setup() {
  pinMode(motorPin, OUTPUT);  // Configura o pino do motor como saída
}

void loop() {
  int potValue = analogRead(potPin);         // Lê o valor do potenciômetro
  
  // Mapeia o valor do potenciômetro para o intervalo de 0 a 255
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  analogWrite(motorPin, motorSpeed);  // Ajusta a velocidade do motor
}