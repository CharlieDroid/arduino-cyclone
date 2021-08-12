#include "screen.h"
#include "game.h"
#include "music.h"

const uint8_t speakerPin { A0 };
const uint8_t ledPinArray[] { 5, 6, 7, 8, 9 };
const uint8_t leftButton { 2 };
const uint8_t rightButton { 3 };

int8_t level { 0 };
int8_t lives { 4 };
uint8_t ledPinLast { 0 };
int16_t score { 0 };
int16_t delayTime { 600 };
uint32_t timeNow { 0 };
bool buttonClicked { false };
bool isWin { true };

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(speakerPin, OUTPUT);
  for (int i { 0 } ; i < 5 ; i++) pinMode(ledPinArray[i], OUTPUT);

  // Press Any Button Screen
  screenBoot();
  display.display();
  // the screen is divided by 8 (memory map), scroll from 0 to 1 to the right
  display.startscrollright(0x00, 0x00);
  // time to press before the music stops
  delay(500);
  waitUntilButtonMusic();
  display.stopscroll();

  // Show instructions
  instructionsBoot();
}

void loop() {
  theGame();
}

void theGame() {
  ledPinLast = randomStartLed();
  while (buttonClicked == false) ledPinLast = wave_led(delayTime);
  digitalWrite(ledPinLast, HIGH);
  if (ledPinLast == ledPinArray[2]) {
    score_sound();
    isWin = true;
    levelUp();
    if (level <= 27) score += level;
    else score += 27;
    delayTimeUpdate();
  } else {
    miss_sound();
    isWin = false;
    lives--;
    score *= 0.95;
  }
  if (lives > 0) {
    buttonClicked = false;
    digitalWrite(ledPinLast, LOW);
    screenUpdate(isWin);
  } else gameOver();
}

void (* resetGame) (void) = 0;

void gameOver() {
  display.clearDisplay();
  digitalWrite(ledPinLast, LOW);
  display.setCursor(0, 13);
  display.setTextSize(2);
  display.print("GAME OVER");
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("SCORE " );
  display.print(String(score));
  display.setCursor(80, 0);
  display.print("LEVEL ");
  display.print(String(level));
  display.display();
  display.startscrollright(0x01, 0x07);
  game_over_sound();
  waitUntilAnyButton();
  resetGame();
}
