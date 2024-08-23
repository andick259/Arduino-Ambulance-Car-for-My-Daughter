#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);//SDA A4. SCL A5
Servo servoBuka;
int pos=0;

#define led_pin 7
int buzzerAgust = 13;
int buttonAgust = 9;
int buttonBuka = 10;
int buttonTutup = 11;
int buttonAmbulance = 5;
int buttonStop = 4;
int buttonStateAmbulance;
int lastButtonStateAmbulance = HIGH;  // Initialize to HIGH for INPUT_PULLUP
int delayTime = 280;
bool ambulancePlaying = false;

void setup() {
  //////////LCD/////////////
  lcd.init();
  lcd.backlight();

  // First line text
  String text1 = "Good Day";
  int text1Length = text1.length();
  int text1Position = (16 - text1Length) / 2;

  // Display first line centered
  lcd.setCursor(text1Position, 0);
  lcd.print(text1);

  // Second line text (if any)
  String text2 = "dr. Aisyah, Sp.A"; // Replace with actual text if needed
  int text2Length = text2.length();
  int text2Position = (16 - text2Length) / 2;

  // Display second line centered
  lcd.setCursor(text2Position, 1);
  lcd.print(text2);
  ///////////////////////////////////////

  servoBuka.attach(12);
  servoBuka.write(0);

  pinMode(led_pin, OUTPUT);
  pinMode(buzzerAgust, OUTPUT);
  pinMode(buttonAgust, INPUT_PULLUP);
  pinMode(buttonBuka, INPUT_PULLUP);
  pinMode(buttonTutup, INPUT_PULLUP);
  pinMode(buttonAmbulance, INPUT_PULLUP);
  pinMode(buttonStop, INPUT_PULLUP);
}

void loop() {
  // Blink LED
  digitalWrite(led_pin, HIGH); // Turn the LED on
  delay(500); // wait a second
  digitalWrite(led_pin, LOW); // Turn the LED off
  delay(500); // wait a second

   //Button Ambulance Automatic RePlay Non Stop
   buttonStateAmbulance = digitalRead(buttonAmbulance);
   if (lastButtonStateAmbulance == HIGH && buttonStateAmbulance == LOW) {
    ambulancePlaying = true;
  }
  lastButtonStateAmbulance = buttonStateAmbulance;
  if (ambulancePlaying) {
   ambulance();
  }

  Btn_17Agustus();
  Servo_Buka();
  Servo_Tutup();
}

//void Servo_Buka(){
 // if (digitalRead(buttonBuka)==LOW){
  //servoBuka.write(90);  }
//}

void Servo_Buka(){
  if (digitalRead(buttonBuka)==LOW){
  
  for(pos = 0; pos <= 40; pos +=1){
  servoBuka.write(pos);
  delay(25);
  }
  }
}

void Servo_Tutup(){
  if (digitalRead(buttonTutup)==LOW){
  servoBuka.write(0);
  }
}


//Function AutoReplay NonStop Ambulance Sirine
void ambulance(){
  while (ambulancePlaying){
    tone(buzzerAgust, 800);
    digitalWrite(led_pin, HIGH);
    delay(500);
    tone(buzzerAgust, 900);
    digitalWrite(led_pin, LOW);
    delay(500);
  }
}

void Btn_17Agustus() {
  if (digitalRead(buttonAgust)==LOW){
    //tujuh belas agustus tahun 45
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(600);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 196);
    delay(400);
    digitalWrite(led_pin, HIGH);

    //itulah hari kemerdekaan kita
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 440);
    delay(300);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(300);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(700);
    digitalWrite(led_pin, HIGH);

    //hari merdeka nusa dan bangsa, 
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 440);
    delay(400);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 440);
    delay(600);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 440);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(400);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(800);
    digitalWrite(led_pin, HIGH);
    
    //hari lahirnya bangsa indonesia
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(400);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Merdeka
    tone(buzzerAgust, 392);
    delay(1000);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(1000);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(1000);
    digitalWrite(led_pin, LOW);

    //Sekali merdeka tetap merdeka
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(400);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(700);
    digitalWrite(led_pin, HIGH);

    //Selama hayat masih dikandung badan
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 440);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Kita Tetap setia
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 220);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 247);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(800);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Tetap Sedia
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(800);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Mempertahankan Indonesia
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(500);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(500);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(500);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 329);
    delay(500);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Kita Tetap setia
    tone(buzzerAgust, 196);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 220);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 247);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(800);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 293);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Tetap Sedia
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(800);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 349);
    delay(800);
    digitalWrite(led_pin, HIGH);

    //Membela negara kita
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 261);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 392);
    delay(delayTime);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 349);
    delay(delayTime);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 329);
    delay(500);
    digitalWrite(led_pin, HIGH);
    tone(buzzerAgust, 293);
    delay(500);
    digitalWrite(led_pin, LOW);
    tone(buzzerAgust, 261);
    delay(800);
    digitalWrite(led_pin, HIGH);
    noTone(buzzerAgust);
    delay(1000);
    digitalWrite(led_pin, LOW);
  }
}
