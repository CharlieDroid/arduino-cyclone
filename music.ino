#include "pitches.h"
#include "music.h"

void score_sound() {
  uint16_t score[] { 1325, 1550, 2600, 2060, 2360, 3090 };
  for (uint8_t i { 0 } ; i < 6 ; i++) {
    tone(speakerPin, score[i]);
    delay(125);
    noTone(speakerPin);
  }
}

void miss_sound() {
  for (uint8_t i { 0 } ; i < 100 ; i++) {
    tone(speakerPin, 3200 / (i + 1));
    delay(10 * 1.10);
    noTone(speakerPin);
  }
}

void start_sound() {
  uint16_t start[] { 
    800, 1050, 1180, 1450, 1350, 1050, 1180, 
    1780, 1610, 1050, 1200, 1450, 1350, 1380, 
    1610, 2010, 2125, 1925, 1700, 1610, 1440, 
    900, 1180, 900, 1900, 1850, 1900, 1590, 
    1180, 1600, 1200
  };
  uint16_t duration[] { 300, 100 };
  uint16_t noteDuration { 0 };
  for (uint8_t i { 0 } ; i < 35 ; i++) {
    timeNow = millis();
    tone(speakerPin, start[i]);
    noteDuration = duration[i % 2] * 1.10;
    while (millis() - timeNow < noteDuration && digitalRead(leftButton) == LOW && digitalRead(rightButton) == LOW);
    if (millis() - timeNow < noteDuration) buttonClicked = true;
    noTone(speakerPin);
  }
}

void game_over_sound() {
  uint16_t freq { 3450 };
  for (uint8_t i { 0 } ; i < 110 ; i++) {
    tone(speakerPin, freq);
    delay(30);
    freq -= 32;
    noTone(speakerPin);
  }
}

const uint16_t stranger_things[] {
  NOTE_A4, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_A5,
  NOTE_E2, NOTE_A5,
  NOTE_B2, NOTE_G4,
  NOTE_A4, NOTE_D2,
  NOTE_D2, NOTE_C5, NOTE_E5, NOTE_B1, NOTE_A4,
  NOTE_G5, NOTE_E5, NOTE_B1, NOTE_C5,
  NOTE_B1, NOTE_A5
};
const uint16_t noteDuration { (1000 / 8) * 1.30 };

void sound(uint8_t index) {
  timeNow = millis();
  tone(speakerPin, stranger_things[index]);
  while (millis() - timeNow <= noteDuration && digitalRead(2) == LOW && digitalRead(3) == LOW);
  if (millis() - timeNow <= noteDuration) buttonClicked = true;
  noTone(speakerPin);
}

void ascendSmall() {
  for (uint8_t i { 1 } ; i < 4 ; i++) sound(i);
}

void ascend() {
  for (uint8_t i { 0 } ; i < 5 ; i++) sound(i);
}

void descend() {
  for (uint8_t i { 3 } ; i > 0 ; i--) sound(i);
}

void ascendDescend() {
  ascend();
  descend();
}

void doubleAscendDescend() {
  for (uint8_t i { 0 } ; i < 2 ; i++) ascendDescend();
}

void first() {
  sound(5);
  ascendSmall();
  sound(6);
  descend();
}

void second() {
  sound(7);
  ascendSmall();
  sound(8);
  descend();
}

void third() {
  sound(9);
  ascendSmall();
  sound(10);
  descend();
}

void fourth() {
  first();
}

void fifth() {
  third();
}

void sixth() {
  fourth();
}

void seventh() {
  for (uint8_t i { 11 } ; i < 16 ; i++) sound(i);
}

void eighth() {
  for (uint8_t i { 16 } ; i < 20 ; i++) sound(i);
}

void ninth() {
  sound(20);
  ascendSmall();
  sound(21);
  descend();
}

void strangerThings() {
  doubleAscendDescend();
  doubleAscendDescend();
  first();
  doubleAscendDescend();
  ascendDescend();
  second();
  doubleAscendDescend();
  third();
  fourth();
  doubleAscendDescend();
  fifth();
  sixth();
  doubleAscendDescend();
  seventh();
  eighth();
  ninth();
  doubleAscendDescend();
}
