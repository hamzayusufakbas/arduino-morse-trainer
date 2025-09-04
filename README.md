# Arduino Morse Trainer / Arduino Mors Alfabesi Öğretici

📟 This project is an Arduino-based Morse code trainer using a Nokia
5110 LCD, a buzzer, and two push buttons.\
📟 Bu proje, Nokia 5110 LCD, buzzer ve iki buton kullanarak mors
alfabesini öğrenmeyi kolaylaştıran bir Arduino uygulamasıdır.

------------------------------------------------------------------------

## Features / Özellikler

-   **English**
    -   D2: short/long press → dot and dash
    -   D3: short press → delete code, long press → convert to letter,
        very long press → delete last letter
    -   Startup animation + melody
    -   Help screen (press both buttons)
    -   Visual + sound feedback, mini animations when letters are added
-   **Türkçe**
    -   D2: kısa/uzun bas → nokta ve çizgi
    -   D3: kısa bas → kod sil, uzun bas → harfe çevir, çok uzun bas →
        harf sil
    -   Açılışta animasyon ve melodi
    -   Yardım ekranı (iki tuşa basılı tut)
    -   Görsel ve sesli geri bildirim, harf eklenince mini animasyon

------------------------------------------------------------------------

## Components / Parçalar

-   Arduino UNO or Leonardo (clone compatible) / Arduino UNO veya
    Leonardo (klon uyumlu)
-   Nokia 5110 LCD (3.3V)
-   2 push buttons / 2 buton
-   Buzzer
-   330--1kΩ resistor (for LCD backlight) / 330--1kΩ direnç (LCD arka
    ışık için)
-   Jumper wires, breadboard / Jumper kablolar, breadboard

------------------------------------------------------------------------

## Circuit Diagram (ASCII - English)

              Nokia 5110 LCD
          ┌─────────────────────┐
          │ RST  ─────────→ D11 │
          │ CE   ─────────→ D12 │
          │ DC   ─────────→ D10 │
          │ DIN  ─────────→ D9  │
          │ CLK  ─────────→ D8  │
          │ VCC  ─────────→ 3.3V│
          │ BL   ──330Ω───→ 3.3V│ (Backlight, optional)
          │ GND  ─────────→ GND │
          └─────────────────────┘

            Arduino UNO
       ┌───────────────────────┐
       │ BTN_MORSE: D2 ↔ GND   │
       │ BTN_CTRL : D3 ↔ GND   │
       │ Buzzer +  → D7        │
       │ Buzzer −  → GND       │
       │ LCD pins: D8–D12      │
       │ 3.3V, GND to LCD      │
       └───────────────────────┘

------------------------------------------------------------------------

## Devre Şeması (ASCII - Türkçe)

              Nokia 5110 LCD
          ┌─────────────────────┐
          │ RST  ─────────→ D11 │
          │ CE   ─────────→ D12 │
          │ DC   ─────────→ D10 │
          │ DIN  ─────────→ D9  │
          │ CLK  ─────────→ D8  │
          │ VCC  ─────────→ 3.3V│
          │ BL   ──330Ω───→ 3.3V│ (Arka ışık, opsiyonel)
          │ GND  ─────────→ GND │
          └─────────────────────┘

            Arduino UNO
       ┌───────────────────────┐
       │ BTN_MORSE: D2 ↔ GND   │
       │ BTN_CTRL : D3 ↔ GND   │
       │ Buzzer +  → D7        │
       │ Buzzer −  → GND       │
       │ LCD pinleri: D8–D12   │
       │ 3.3V, GND LCD’ye      │
       └───────────────────────┘

------------------------------------------------------------------------

## Usage / Kullanım

-   **English**
    1.  Upload `arduino-morse-trainer.ino` using Arduino IDE.
    2.  On startup, a melody and animation play.
    3.  Use D2 to input Morse code, D3 for control actions.
    4.  Press both buttons → help screen.
-   **Türkçe**
    1.  `arduino-morse-trainer.ino` dosyasını Arduino IDE ile yükle.
    2.  Açılışta melodi ve animasyon çalar.
    3.  D2 ile mors kodunu gir, D3 ile işlemleri yap.
    4.  İki tuşa basılı tut → yardım ekranı.

------------------------------------------------------------------------

## License / Lisans

MIT License -- free to use, modify, and share.\
MIT Lisansı -- özgürce kullanabilir, değiştirebilir, paylaşabilirsiniz.
