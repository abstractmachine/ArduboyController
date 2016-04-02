 /*
  Arduboy Controller
  http://github.com/abstractmachine/
  (c) 2016 Douglas Edric Stanley
  This code is provided under the MIT License.
 */
 
#include <Keyboard.h>
#include "Arduboy.h"

Arduboy arduboy;

// Change the following two defines if you want to map to different keys
// for example, to map the A key to 'space bar' and the B key to 'left shift' try:
// #define A_BUTTON_KEY ' '
// #define B_BUTTON_KEY KEY_LEFT_SHIFT

#define A_BUTTON_KEY          KEY_LEFT_CTRL   // what key is pressed with A button
#define B_BUTTON_KEY          KEY_LEFT_ALT    // what key is pressed with B button

#define BUTTON_COUNT  6

struct Button {
  bool    state;      // current button state
  uint8_t key;        // Arduino key
  uint8_t button;     // Arduboy button
  char    character;  // ASCII character
  uint8_t x;          // x coordinate on display (MAX:128)
  uint8_t y;          // y coordinate on display (MAX:64)
};

// configure the buttons
Button buttons[] = {
  {false, KEY_LEFT_ARROW, LEFT_BUTTON,  '<', 14, 32}, // LEFT button
  {false, KEY_RIGHT_ARROW,RIGHT_BUTTON, '>', 54, 32}, // RIGHT button
  {false, KEY_UP_ARROW,   UP_BUTTON,    '^', 34, 16}, // UP button
  {false, KEY_DOWN_ARROW, DOWN_BUTTON,  'v', 34, 48}, // DOWN button
  {false, A_BUTTON_KEY,   A_BUTTON,     'A', 94, 36}, // A button
  {false, B_BUTTON_KEY,   B_BUTTON,     'B', 114,28}  // B button
};

#define TEXT_SIZE             1
#define CHAR_WIDTH            6 * TEXT_SIZE
#define CHAR_HALF_WIDTH       CHAR_WIDTH / 2
#define CHAR_HEIGHT           8 * TEXT_SIZE
#define CHAR_HALF_HEIGHT      CHAR_HEIGHT / 2
#define BUTTON_DIAMETER       18
#define BUTTON_RADIUS         BUTTON_DIAMETER / 2
#define RECT_CORNER_SIZE      3

void setup() {
  
  arduboy.begin();
  arduboy.setTextSize(TEXT_SIZE);

  setupButtons();

  Keyboard.begin();

}


void loop() {

  updateButtons();

}
