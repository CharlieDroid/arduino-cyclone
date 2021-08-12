#include "game.h"

void levelUp() {
  level++;
}

void waitUntilAnyButton() {
  while (digitalRead(leftButton) == LOW && digitalRead(rightButton) == LOW);
}

void waitUntilButtonMusic() {
  while (!buttonClicked) strangerThings();
}

void waitUntilRightButton() {
  while (digitalRead(rightButton) == LOW);
}

void blink_led(const uint8_t ledPin, int16_t delayTime){
  timeNow = millis();
  digitalWrite(ledPin, HIGH);
  while (millis() - timeNow <= delayTime and digitalRead(rightButton) == LOW);
  if (millis() - timeNow <= delayTime) buttonClicked = true;
  
  timeNow = millis();
  digitalWrite(ledPin, LOW);
  while (millis() - timeNow <= delayTime and digitalRead(rightButton) == LOW);
  if (millis() - timeNow <= delayTime) buttonClicked = true;
}

uint8_t randomStartLed() {
  uint8_t ledStart { random(5) };
  while (ledStart == 2) ledStart = random(5);
  bool goLeft {};
  if (ledStart == 4) goLeft = true;
  else if (ledStart == 0) goLeft = false;
  else bool goLeft { random(2) };
  
  if (goLeft) 
  {
    for (int8_t i { ledStart } ; i > 0 ; i--) {
      blink_led(ledPinArray[i], delayTime);
      if (buttonClicked == true) return ledPinArray[i];
    }
  } else 
  {
    for (uint8_t i { ledStart } ; i < 4 ; i++) {
      blink_led(ledPinArray[i], delayTime);
      if (buttonClicked == true) return ledPinArray[i];
    }
    for (int8_t i { 4 } ; i > 0 ; i--) {
      blink_led(ledPinArray[i], delayTime);
      if (buttonClicked == true) return ledPinArray[i];
    }
  }
}

uint8_t wave_led(int16_t delayTime){
  for (uint8_t i { 0 } ; i < 4 ; i++) {
    blink_led(ledPinArray[i], delayTime);
    if (buttonClicked == true) return ledPinArray[i];
  }
  for (int8_t i { 4 } ; i > 0 ; i--) {
    blink_led(ledPinArray[i], delayTime);
    if (buttonClicked == true) return ledPinArray[i];
  }
}

uint16_t delayTimeUpdate() {
  delayTime = (480 + (level * 20)) / level;
}
