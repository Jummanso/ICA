// Definição dos pinos do Arduino conectados aos segmentos do display
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8}; 

// Matrizes representando cada número de 0 a 9 no display de 7 segmentos
const int digitPatterns[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};


void setup() {
  Serial.begin(9600);
  // Configuração dos pinos como saída
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void displayDigit(int number) {
  // Verifica se o número está no intervalo de 0 a 9
  if (number < 0 || number > 9) return;

  // Define os segmentos para o número específico
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[number][i]);
  }
}

void loop() {
  // Exibe números de 0 a 9 em sequência
  for (int number = 0; number < 10; number++) {
    Serial.println(number);
    displayDigit(number);  // Chama a função para mostrar o número atual
    delay(1000);  // Aguarda 1 segundo antes de exibir o próximo número
  }

}