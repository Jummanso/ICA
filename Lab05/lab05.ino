// Define os pinos dos LEDs e do botão
const int LED_VERMELHO = 2;
const int LED_AMARELO = 3;
const int LED_VERDE = 4;
const int BOTAO = 7; // Pino onde o botão está conectado

// Define os tempos de espera em milissegundos
const unsigned long TEMPO_VERDE = 2000; // Tempo para o LED verde
const unsigned long TEMPO_AMARELO = 2000; // Tempo para o LED amarelo
const unsigned long TEMPO_VERMELHO = 2000; // Tempo para o LED vermelho
const unsigned long TEMPO_VERMELHO_BOTAO = 5000; // Tempo para o LED vermelho quando o botão é pressionado

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

  if (botaoPressionado) {
    // Imprime mensagem no Serial Monitor se o botão estiver pressionado
    Serial.println("Botão pressionado!");
    
    // Mantém o semáforo no vermelho por TEMPO_VERMELHO_BOTAO e depois volta ao loop normal
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
    delay(TEMPO_VERMELHO_BOTAO); // Espera pelo tempo do botão

    // Retorna à sequência normal após o tempo de botão
    digitalWrite(LED_VERMELHO, LOW);
    delay(500); // Pequeno intervalo para garantir que o botão não mantenha o semáforo no vermelho por muito tempo
  }

  // Sequência normal do semáforo
  // Acende o LED verde e apaga os outros
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(TEMPO_VERDE); // Espera pelo tempo verde definido

  // Acende o LED amarelo e apaga os outros
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, HIGH);
  delay(TEMPO_AMARELO); // Espera pelo tempo amarelo definido

  // Acende o LED vermelho e apaga os outros
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
  delay(TEMPO_VERMELHO); // Espera pelo tempo vermelho definido
}