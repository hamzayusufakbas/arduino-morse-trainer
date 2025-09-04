#include <LCD5110_Basic.h>
extern uint8_t SmallFont[];

LCD5110 lcd(8,9,10,11,12);

const int BUZZER = 7;
const int BTN_MORSE = 2;
const int BTN_CTRL  = 3;

String inputCode = "";
String decodedMsg = "";

unsigned long pressStartMorse = 0;
bool morsePressed = false;

unsigned long pressStartCtrl = 0;
bool ctrlPressed = false;

bool helpMode = false;

// ---------------- Mors Tablosu ----------------
char letters[] = {
  'A','B','C','D','E','F','G','H','I','J',
  'K','L','M','N','O','P','Q','R','S','T',
  'U','V','W','X','Y','Z'
};
String morse[] = {
  ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
  "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
  "..-","...-",".--","-..-","-.--","--.."
};

// ---------------- Ses Fonksiyonları ----------------
void beepDot(){ tone(BUZZER, 1000, 150); delay(200); noTone(BUZZER); }
void beepDash(){ tone(BUZZER, 1000, 400); delay(450); noTone(BUZZER); }

// D3 melodileri
void soundKodSil(){        // tek kısa
  tone(BUZZER, 800, 120); delay(150); noTone(BUZZER);
}

void soundHarfEkle(){      // iki notalık: do -> mi
  tone(BUZZER, 523, 150); delay(180); noTone(BUZZER);
  delay(50);
  tone(BUZZER, 659, 200); delay(220); noTone(BUZZER);
}

void soundHarfSil(){       // düşen ton: sol -> mi
  tone(BUZZER, 784, 300); delay(350); noTone(BUZZER);
  delay(50);
  tone(BUZZER, 659, 400); delay(450); noTone(BUZZER);
}

char decodeMorse(String code){
  for(int i=0;i<26;i++){
    if(morse[i] == code) return letters[i];
  }
  return '?';
}

// ---------------- LCD Fonksiyonları ----------------
void showLCD(String preview=""){
  lcd.clrScr();
  lcd.setFont(SmallFont);

  lcd.print("Kod:", CENTER, 0);
  if(inputCode != "") lcd.print(inputCode, CENTER, 10);
  else lcd.print("(bos)", CENTER, 10);

  if(preview != ""){
    lcd.print("-> " + preview, CENTER, 24);
  }

  lcd.print("Yazi:", CENTER, 34);
  if(decodedMsg != "") lcd.print(decodedMsg, CENTER, 44);
  else lcd.print("(bos)", CENTER, 44);
}

void showStartupAnim(){
  lcd.clrScr();
  lcd.setFont(SmallFont);
  lcd.print("TELGRAF v1.0", CENTER, 20);
  delay(1000);
  lcd.clrScr();

  for(int i=0;i<84;i+=4){
    lcd.print("TELGRAF", i-40, 20);
    delay(120);
    lcd.clrScr();
  }
}

void playStartupMelody(){
  int melody[] = { 262, 330, 392, 523 };
  int dur[]    = { 200, 200, 200, 400 };
  for(int i=0;i<4;i++){
    tone(BUZZER, melody[i], dur[i]);
    delay(dur[i]+80);
  }
  noTone(BUZZER);
}

void showHelpScreen(){
  String helpLines[] = {
    "NASIL KULLAN?",
    "D2 kisa = .",
    "D2 uzun = -",
    "D3 kisa = kod sil",
    "D3 uzun = harf ekle",
    "D3 cok uzun = harf sil"
  };
  int lines = 6;

  for(int i=0;i<lines;i++){
    lcd.clrScr();
    lcd.setFont(SmallFont);
    lcd.print(helpLines[i], CENTER, 20);
    delay(1500);
  }
}

// ---------------- Setup ----------------
void setup(){
  pinMode(BUZZER, OUTPUT);
  pinMode(BTN_MORSE, INPUT_PULLUP);
  pinMode(BTN_CTRL, INPUT_PULLUP);
  lcd.InitLCD();
  lcd.setContrast(70);

  playStartupMelody();
  showStartupAnim();
  showLCD();
}

// ---------------- Loop ----------------
void loop(){
  // İki tuş birlikte basılı → yardım ekranı
  if(digitalRead(BTN_MORSE)==LOW && digitalRead(BTN_CTRL)==LOW){
    helpMode = true;
    tone(BUZZER, 500, 400);
    showHelpScreen();
    while(digitalRead(BTN_MORSE)==LOW || digitalRead(BTN_CTRL)==LOW);
    delay(300);
    helpMode = false;
    showLCD();
  }

  if(helpMode) return;

  // --- Mors tuşu (D2) ---
  if (digitalRead(BTN_MORSE) == LOW && !morsePressed){
    morsePressed = true;
    pressStartMorse = millis();
  }
  if (digitalRead(BTN_MORSE) == LOW && morsePressed){
    unsigned long duration = millis() - pressStartMorse;
    if (duration < 300) showLCD("Nokta");
    else showLCD("Cizgi");
  }
  if (digitalRead(BTN_MORSE) == HIGH && morsePressed){
    unsigned long duration = millis() - pressStartMorse;
    morsePressed = false;

    if (duration < 300){
      inputCode += ".";
      beepDot();
    } else {
      inputCode += "-";
      beepDash();
    }
    showLCD();
  }

  // --- Kontrol tuşu (D3) ---
  if (digitalRead(BTN_CTRL) == LOW && !ctrlPressed){
    ctrlPressed = true;
    pressStartCtrl = millis();
  }
  if (digitalRead(BTN_CTRL) == LOW && ctrlPressed){
    unsigned long duration = millis() - pressStartCtrl;
    if (duration < 500) showLCD("Kod Sil");
    else if (duration < 1500) showLCD("Harf Ekle");
    else showLCD("Harf Sil");
  }
  if (digitalRead(BTN_CTRL) == HIGH && ctrlPressed){
    unsigned long duration = millis() - pressStartCtrl;
    ctrlPressed = false;

    if (duration < 500){
      if (inputCode.length() > 0){
        inputCode.remove(inputCode.length()-1);
      }
      soundKodSil();
    } else if (duration < 1500){
      if (inputCode.length() > 0){
        char d = decodeMorse(inputCode);
        decodedMsg += d;
        inputCode = "";
      }
      soundHarfEkle();
    } else {
      if (decodedMsg.length() > 0){
        decodedMsg.remove(decodedMsg.length()-1);
      }
      soundHarfSil();
    }
    showLCD();
  }
}
