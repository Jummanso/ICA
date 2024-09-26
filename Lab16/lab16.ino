#include <Wire.h> // Biblioteca para I2C
#include <LiquidCrystal_I2C.h> // Biblioteca para LCD I2C

LiquidCrystal_I2C lcd1(0x27, 16, 2); // Primeiro LCD
LiquidCrystal_I2C lcd2(0x3F, 16, 2); // Segundo LCD (verifique o endereço)

const int pirPin = 2;   // Pino do sensor PIR
const int ledPin = 13;  // Pino do LED

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  lcd1.init();
  lcd1.backlight();
  lcd2.init();
  lcd2.backlight();
}

void loop() {
  int pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    Serial.println("Presença detectada!");
    digitalWrite(ledPin, HIGH);
    
    lcd1.clear();
    lcd1.print("Presença detectada!");
    lcd2.clear();
    lcd2.print("Alerta ativado!");

    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    lcd1.clear();
    lcd2.clear();
  }
}