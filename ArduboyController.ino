 /*
  Arduboy Controller
  http://github.com/abstractmachine/
  (c) 2016 Douglas Edric Stanley
  This code is provided under the MIT License.
 */
 
#include <Keyboard.h>
#include "Arduboy.h"

Arduboy arduboy;

// Change the following two defines if you want to map A & B buttons to different keys

#define A_BUTTON_KEY          KEY_LEFT_CTRL   // what key is pressed with A button
#define B_BUTTON_KEY          KEY_LEFT_ALT    // what key is pressed with B button

//#define A_BUTTON_KEY          ' '             // map A button to the 'space bar'
//#define B_BUTTON_KEY          KEY_LEFT_SHIFT  // map B button to 'left shift'

// Change these four defines if you want to map the direction buttons to different keys

#define LEFT_BUTTON_KEY       KEY_LEFT_ARROW  // what key is pressed with LEFT button
#define RIGHT_BUTTON_KEY      KEY_RIGHT_ARROW // what key is pressed with RIGHT button
#define UP_BUTTON_KEY         KEY_UP_ARROW    // what key is pressed with UP button
#define DOWN_BUTTON_KEY       KEY_DOWN_ARROW  // what key is pressed with DOWN button

//#define UP_BUTTON_KEY         'e'             // alphanumerical keyboard configuration
//#define LEFT_BUTTON_KEY       's'             // alphanumerical keyboard configuration
//#define DOWN_BUTTON_KEY       'd'             // alphanumerical keyboard configuration
//#define RIGHT_BUTTON_KEY      'f'             // alphanumerical keyboard configuration

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
  {false, LEFT_BUTTON_KEY,  LEFT_BUTTON,  '<', 14, 32}, // LEFT button
  {false, RIGHT_BUTTON_KEY, RIGHT_BUTTON, '>', 54, 32}, // RIGHT button
  {false, UP_BUTTON_KEY,    UP_BUTTON,    '^', 34, 16}, // UP button
  {false, DOWN_BUTTON_KEY,  DOWN_BUTTON,  'v', 34, 48}, // DOWN button
  {false, A_BUTTON_KEY,     A_BUTTON,     'A', 94, 36}, // A button
  {false, B_BUTTON_KEY,     B_BUTTON,     'B', 114,28}  // B button
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
