const int motorPin = 9;   // Pino digital do Arduino conectado ao coletor do transistor
const int buttonPin = 2;  // Pino digital do Arduino conectado ao botão

void setup() {
  pinMode(motorPin, OUTPUT);  // Configura o pino do motor como saída
  pinMode(buttonPin, INPUT);  // Configura o pino do botão como entrada
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Lê o estado do botão
  
  if (buttonState == HIGH) {  // Se o botão estiver pressionado
    digitalWrite(motorPin, HIGH);  // Liga o motor
  } else {
    digitalWrite(motorPin, LOW);  // Desliga o motor
  }
}