// Define os pinos dos LEDs e do botão
const int LED_VERMELHO = 2;
const int LED_AMARELO = 3;
const int LED_VERDE = 4;
const int BOTAO = 7; // Pino onde o botão está conectado

// Define os tempos de espera em milissegundos
const unsigned long TEMPO_VERDE_PADRAO = 2000; // Tempo padrão para o LED verde
const unsigned long TEMPO_VERDE_AUMENTADO = 5000; // Tempo aumentado para o LED verde

void setup() {
  // Define os pinos dos LEDs como saídas
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  // Define o pino do botão como entrada
  pinMode(BOTAO, INPUT_PULLUP);

  // Inicia a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Verifica se o botão está pressionado
  bool botaoPressionado = digitalRead(BOTAO) == LOW; // Botão pressionado lê LOW devido ao resistor pull-up

  // Imprime mensagem no Serial Monitor se o botão estiver pressionado
  if (botaoPressionado) {
    Serial.println("Botão pressionado!");
  }

  // Determina o tempo de espera com base no estado do botão
  unsigned long tempoVerde = botaoPressionado ? TEMPO_VERDE_AUMENTADO : TEMPO_VERDE_PADRAO;

  // Acende o LED verde e apaga os outros
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(tempoVerde); // Espera pelo tempo verde definido

  // Acende o LED vermelho e apaga os outros
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, LOW);
  delay(2000); // Espera por 2 segundos

  // Acende o LED amarelo e apaga os outros
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERDE, LOW);
  delay(2000); // Espera por 2 segundos

  // Retorna ao LED verde
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(tempoVerde); // Espera pelo tempo verde definido
}
