// Definição dos pinos
const int tempPin = A0; // Pino onde o TMP36 está conectado
const int buzzerPin = 9; // Pino onde o buzzer está conectado

// Variáveis de temperatura
float temperatureC;
const float thresholdTempHigh = 30.0; // Temperatura para mensagem na serial
const float thresholdTempAlarm = 90.0; // Temperatura para acionar o alarme

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  int sensorValue = analogRead(tempPin); // Lê o valor do sensor TMP36
  
  // Converte a leitura do sensor para temperatura em Celsius
  temperatureC = (sensorValue * 5.0 / 1024.0 - 0.5) * 100.0;
  
  // Imprime a temperatura na serial
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  
  // Verifica se a temperatura é maior que 30°C
  if (temperatureC > thresholdTempHigh) {
    Serial.println("Alert: Temperature above 30°C!");
  }
  
  // Verifica se a temperatura é maior que 90°C
  if (temperatureC > thresholdTempAlarm) {
    tone(buzzerPin, 1000); // Toca o buzzer com frequência de 1000 Hz
  } else {
    noTone(buzzerPin); // Desliga o buzzer
  }
  
  delay(1000); // Aguarda 1 segundo antes da próxima leitura
}