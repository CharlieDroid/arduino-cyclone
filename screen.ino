#include "screen.h"

static const unsigned char PROGMEM bulb_off[] = {
  B00000011, B11100000, B00000000, B00000000,
  B00000100, B00010000, B00000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B00000100, B00010000, B00000000, B00000000,
  B00000100, B00010000, B00000000, B00000000,
  B00000010, B00100000, B00000000, B00000000,
  B00000010, B00100000, B00000000, B00000000,
  B00000001, B11000000, B00000000, B00000000,
  B00000001, B11000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000
};
static const unsigned char PROGMEM bulb_on[] = {
  B00010011, B11100100, B00000000, B00000000,
  B10000100, B00010000, B10000000, B00000000,
  B01101000, B00001011, B00000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B11101000, B00001011, B11000000, B00000000,
  B00001000, B00001000, B00000000, B00000000,
  B01100100, B00010011, B00000000, B00000000,
  B10000100, B00010000, B10000000, B00000000,
  B00010010, B00100100, B00000000, B00000000,
  B00000010, B00100000, B00000000, B00000000,
  B00000001, B11000000, B00000000, B00000000,
  B00000001, B11000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000, B00000000
};
static const unsigned char PROGMEM copyright[] = {
  B00011110, B00000000,
  B01100001, B10000000,
  B10011110, B01000000,
  B10100000, B01000000,
  B10100000, B01000000,
  B10011110, B01000000,
  B01100001, B10000000,
  B00011110, B00000000,
};
static const unsigned char PROGMEM heart[] = {
 B01101100,
 B11111110,
 B11111110,
 B11111110,
 B01111100,
 B00111000,
 B00010000,
};
static const unsigned char PROGMEM cyclone[] = {
  B00000000, B00011111, B11111111, B11111000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B11111111, B11100000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000011, B11111110, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000001, B11100000, 
  B00000111, B11111000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B01111100, B00000000, B00000000, B00000000, B00000000, B00000000, B00011111, B11110000, 
  B00111111, B10000000, B00000000, B00000000, B00000000, B00000000, B00111000, B00000000, B11111000, B00000000, B00000000, B00000000, B01100000, B00000000, B01111110, B00010000, 
  B01111110, B00000000, B00000000, B00000000, B00000000, B00000000, B11000000, B00000001, B11110000, B00111111, B11110000, B00000000, B11100000, B00000001, B11110000, B00110000, 
  B01111110, B00000000, B00000000, B00000000, B00000000, B00000011, B10000000, B00000011, B11100000, B11111111, B11110000, B00000001, B11000000, B00000011, B11000000, B11110000, 
  B01111110, B00000000, B00000011, B11100000, B00001111, B10000111, B10000000, B00000111, B11000001, B11100000, B00011100, B00000011, B11111100, B00000011, B10000111, B11100000, 
  B01111110, B00000000, B00000001, B11110000, B00111111, B00001111, B00000000, B00001111, B10000111, B10000000, B00001110, B00000111, B11111111, B00000011, B00011111, B00000000, 
  B01111110, B00000000, B00000000, B11111000, B01111100, B00011110, B00000000, B00011111, B00000110, B00000000, B00000110, B00001111, B00000111, B10000011, B11111100, B00000000, 
  B00111111, B00000000, B00000000, B00111111, B11110000, B00011111, B10000000, B00111110, B00000110, B00000000, B00000110, B00011110, B00000011, B11000011, B11100000, B00100000, 
  B00011111, B11000000, B00000000, B00011111, B11100000, B00001111, B11110000, B11111100, B00000111, B10000000, B00001110, B00111100, B00000001, B11100001, B11100001, B11100000, 
  B00000111, B11111111, B11100000, B00011111, B10000000, B00000001, B11110000, B11111000, B00000001, B11000000, B01111100, B01111000, B00000000, B11110000, B11111111, B11100000, 
  B00000000, B11111111, B11100000, B00111110, B00000000, B00000000, B00000000, B01110000, B00000000, B11111111, B11110000, B00000000, B00000000, B00000000, B00011111, B00000000, 
  B00000000, B00011111, B11100000, B11111000, B00000000, B00000000, B00000000, B00000000, B00000000, B00111111, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000, 
  B00000000, B00000000, B00100001, B11110000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000
};

String instructions[] { "HIT THE RIGHT BUTTON", "WHEN THE CENTER LED", "TURNS ON!" };
String win_words[] = { "Good Job!", "Nice", "Fast Hands", "Keep Going", "Godlike!", "Good Game Well Played", "Fantastic"};
String lose_words[]= { "Almost", "Oops", "Try Again", "Aja! Fighting.", "Don't Give Up", "Play To Win"};

int16_t wordLocationCompute(String words) {
  int16_t location = words.length() * 6;
  if (location > 128) return 0;
  else return (128 - location) / 2;
}

void drawCyclone() {
  display.drawBitmap(0, 8, cyclone, CYCLONE_WIDTH, CYCLONE_HEIGHT, WHITE);
}
void drawCopyright() {
  display.drawBitmap(COPYRIGHT_LOCATION, 24, copyright, COPYRIGHT_WIDTH, COPYRIGHT_HEIGHT, WHITE);
}
void drawHeart() {
  for (int i { 0 } ; i < lives ; i++) {
    display.drawBitmap(95 + (i * 8), 0, heart, HEART_WIDTH, HEART_HEIGHT, WHITE);
  }
}

void levelUpdate() {
  display.setCursor(53, 0);
  if (level < 10) display.print("LEVEL ");
  else display.print("LEVEL");
  display.print(level);
}

void scoreUpdate() {
  display.setCursor(0, 0);
  display.print("SCORE ");
  display.print(String(score));
}

void drawBulbOff() {
  for (uint8_t i { 0 } ; i < 5 ; i++) display.drawBitmap(5 + (i * 25), 8, bulb_off, BULB_WIDTH, BULB_HEIGHT, WHITE);
}

void drawBulbOn() {
  drawBulbOff();
  display.drawBitmap(55, 8, bulb_on, BULB_WIDTH, BULB_HEIGHT, WHITE);
}

void textBottom(String words) {
  display.setCursor(wordLocationCompute(words), 24);
  display.print(words);
}

void screenUpdate(bool isScore) {
  display.clearDisplay();
  scoreUpdate();
  levelUpdate();
  drawHeart();
  drawCyclone();
  if (isScore) textBottom(win_words[random(WIN_WORDS)]);
  else textBottom(lose_words[random(LOSE_WORDS)]);
  display.display();
}

void instructionsBoot() {
  for (int8_t i { 0 } ; i < 3 ; i++) {
    display.clearDisplay();
    scoreUpdate();
    levelUpdate();
    drawHeart();
    if (i != 2) drawBulbOff();
    else drawBulbOn();
    textBottom(instructions[i]);
    display.display();
    delay(500);
    waitUntilAnyButton();
  }
  display.clearDisplay();
  scoreUpdate();
  levelUp();
  levelUpdate();
  drawHeart();
  drawCyclone();
  display.setCursor(wordLocationCompute("  START  "), 24);
  display.write(14);
  display.print(" START ");
  display.write(14);
  display.display();
  delay(300);
  start_sound();
  buttonClicked = false;
  delay(300);
}

void screenBoot() {
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("PRESS ANY BUTTON");
  drawCyclone();
  drawCopyright();
  display.setCursor(COPYRIGHT_LOCATION, 24);
  display.print("  CHARLES 2021");
}