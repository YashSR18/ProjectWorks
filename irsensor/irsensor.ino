#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc; // Create an instance of the RTC_DS3231 class

// create simple variables to map to the arduino pins
int IRsensor1 = 13;
int IRsensor2 = 4;
int IRsensor3 = 5;
int IRsensor4 = 8;
int IRsensor5 = 6;
int IRsensor6 = 3;
int IRsensor7 = 11;
int IRsensor8 = 12;
int IRsensor9 = 7;
//create variables to store the in time and out time
char buf1[20];
char buf2[20];

//CONNECT THE RTC MODULE AS FOLLOWING
// SDA TO ANALOG PIN 4
// SCL TO ANALOG PIN 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //set baud rate for communication to arduino
  //Serial.begin(115200);
  Wire.begin();
  //Check if RTC is working
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  // set the pins to which IR sensors are connected as input pins
  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);
  pinMode(IRsensor3, INPUT);
  pinMode(IRsensor4, INPUT);
  pinMode(IRsensor5, INPUT);
  pinMode(IRsensor6, INPUT);
  pinMode(IRsensor7, INPUT);
  pinMode(IRsensor8, INPUT);
  pinMode(IRsensor9, INPUT);

}

void loop() {
  
  // assign variables to read the input from sensors
  int IRvalue1 = digitalRead(IRsensor1);
  int IRvalue2 = digitalRead(IRsensor2);
  int IRvalue3 = digitalRead(IRsensor3);
  int IRvalue4 = digitalRead(IRsensor4);
  int IRvalue5 = digitalRead(IRsensor5);
  int IRvalue6 = digitalRead(IRsensor6);
  int IRvalue7 = digitalRead(IRsensor7);
  int IRvalue8 = digitalRead(IRsensor8);
  int IRvalue9 = digitalRead(IRsensor9);
  // Read the current date and time from the DS3231

  DateTime now = rtc.now(); 

  if (IRvalue1 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  
  if (IRvalue2 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue3 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue4 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue5 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue6 == 0) 
 {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue7 == 0) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue8 == 1) 
  {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  if (IRvalue9 == 1) 
 {  
    sprintf(buf2, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Coil present"); Serial.print(",");
  } 
  else 
  { 
    sprintf(buf1, "%02d:%02d:%02d% 02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year()); 
    Serial.print(buf1); Serial.print("#"); Serial.print(buf2); Serial.print("#"); Serial.print("Space Available"); Serial.print(",");
  }
  Serial.println();

  delay(2000); //run loop after 10 seconds
}

/* void printTwoDigits(int number) {
  if (number < 10) {
    Serial.print("0"); // Print a leading zero for single-digit numbers
  }
  Serial.print(number);
}*/