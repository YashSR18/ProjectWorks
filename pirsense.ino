#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
//Define the ESP pins to which the display is connected
#define OLED_SDA 21
#define OLED_SCL 22
Adafruit_SH1106 display(21, 22);
//Define the ESP pin to which DH11 is connected
#define DHTPIN 15
// Pins for the L298N motor driver
#define ENA 13   // PWM pin for speed control
#define IN1 16  // Control pin 1
#define IN2 2  // Control pin 2

// Constants for motor speed levels
#define SPEED_LOW 35   // ~33% of max speed
#define SPEED_MEDIUM 100 // ~66% of max speed
#define SPEED_HIGH 255  // 100% of max speed



//Select the type of sensor used (DHT11)
#define DHTTYPE    DHT11
DHT dht(DHTPIN, DHTTYPE);
int pirSensor1 = 19;
int pirSensor2 = 18;
int pirSensor3 = 17;
int pirSensor4 = 26;
int pirSensor5 = 25;
int pirSensor6 = 32;
int seat1;
int seat2;
int seat3;
int seat4;
int seat5;
int seat6;
void setup() {

  // Set motor driver pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Initialize motor in forward direction
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);


  pinMode(pirSensor1, INPUT);
  pinMode(pirSensor2, INPUT);
  pinMode(pirSensor3, INPUT);
  pinMode(pirSensor4, INPUT);
  pinMode(pirSensor5, INPUT);
  pinMode(pirSensor6, INPUT);
  Serial.begin(115200); // Change baud rate for ESP32
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  dht.begin();
  Serial.println("Waiting For Power On Warm Up");
  delay(20000); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}

void loop() {
  int pirValue1 = digitalRead(pirSensor1);
  int pirValue2 = digitalRead(pirSensor2);
  int pirValue3 = digitalRead(pirSensor3);
  int pirValue4 = digitalRead(pirSensor4);
  int pirValue5 = digitalRead(pirSensor5);
  int pirValue6 = digitalRead(pirSensor6);

  if (pirValue1 == HIGH) {
    seat1 = 0;
    Serial.println("S1 occupied");
  } 
  else {
    seat1 = 1;
    Serial.println("S1 empty");
  }
  if (pirValue2 == HIGH) {
    seat2 = 0;
    Serial.println("S2 occupied");
  } 
  else {
    seat2 = 1;
    Serial.println("S2 empty");
  }
  if (pirValue3 == HIGH) {
    seat3 = 0;
    Serial.println("S3 occupied");
  } 
  else {
    seat3 = 1;
    Serial.println("S3 empty");
  }
  if (pirValue4 == HIGH) {
    seat4 = 0;
    Serial.println("S4 occupied");
  } 
  else {
    seat4 = 1;
    Serial.println("S4 empty");
  }
  if (pirValue5 == HIGH) {
    seat5 = 0;
    Serial.println("S5 occupied");
  } 
  else {
    seat5 = 1;
    Serial.println("S5 empty");
  }
  if (pirValue6 == HIGH) {
    seat6 = 0;
    Serial.println("S6 occupied");
  } 
  else {
    seat6 = 1;
    Serial.println("S6 empty");
  }
  int totalseat = seat1+seat2+seat3+seat4+seat5+seat6;
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("Temperature");
  display.print(t);
  display.cp437(true);
  display.write(167);
  display.println("C");
  display.display();
  display.setCursor(0, 20);
  display.setTextSize(1);
  display.println("Humidity");
  display.setTextSize(1);
  display.print(h);
  display.println("%");
  display.display();
  display.setCursor(0, 40);
  display.setTextSize(1);
  display.println("Empty Seats");
  display.print(totalseat);
  Serial.println(totalseat);
  display.display();

    switch (totalseat) {
    case 1:
      analogWrite(ENA, SPEED_HIGH);
      Serial.println("A/C INCREASED");
      break;
    case 2:
      analogWrite(ENA, SPEED_HIGH);
      Serial.println("A/C INCREASED");
      break;
    case 3:
      analogWrite(ENA, SPEED_MEDIUM);
      Serial.println("A/C MEDIUM");
      break;
    case 4:
      analogWrite(ENA, SPEED_MEDIUM);
      Serial.println("A/C MEDIUM");
      break;
    case 5:
      analogWrite(ENA, SPEED_LOW);
      Serial.println("POWER SAVING");
      break;  
    case 6:
      analogWrite(ENA, SPEED_LOW);
      Serial.println("POWER SAVING");
      break;
  }

  // Delay for stability (optional, as speed changes every 3 seconds)
  delay(100);
  delay(5000);


}