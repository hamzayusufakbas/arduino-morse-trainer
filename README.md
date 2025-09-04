# Arduino Morse Trainer / Arduino Mors Alfabesi Öğretici

📟 This project is an Arduino-based Morse code trainer using a Nokia 5110 LCD, a buzzer, and two push buttons.  
📟 Bu proje, Nokia 5110 LCD, buzzer ve iki buton kullanarak mors alfabesini öğrenmeyi kolaylaştıran bir Arduino uygulamasıdır.

---

## Features / Özellikler
- **English**
  - D2: short/long press → dot and dash
  - D3: short press → delete code, long press → convert to letter, very long press → delete last letter
  - Startup animation + melody
  - Help screen (press both buttons)
  - Visual + sound feedback, mini animations when letters are added

- **Türkçe**
  - D2: kısa/uzun bas → nokta ve çizgi
  - D3: kısa bas → kod sil, uzun bas → harfe çevir, çok uzun bas → harf sil
  - Açılışta animasyon ve melodi
  - Yardım ekranı (iki tuşa basılı tut)
  - Görsel ve sesli geri bildirim, harf eklenince mini animasyon

---

## Hardware / Donanım
- Arduino UNO or Leonardo (clone compatible)  
- Nokia 5110 LCD  
- 2 push buttons  
- Buzzer  
- Jumper wires, breadboard  

---

## Usage / Kullanım
1. Upload `arduino-morse-trainer.ino` using Arduino IDE.  
2. On startup, a melody and animation play.  
3. Use D2 to input Morse code, D3 for control actions.  
4. Press both buttons → help screen.  

---

## License / Lisans
MIT License – free to use, modify, and share.  
MIT Lisansı – özgürce kullanabilir, değiştirebilir, paylaşabilirsiniz.
