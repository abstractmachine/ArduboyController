void setupButtons() {
  
  // black background
  arduboy.clear();
  
  // draw all the buttons
  for (int i = 0; i < 6; i++) drawButton(i);

} // setupButtons

void updateButtons() {

  // cycle through all the buttons
  for (int i = 0; i < 6; i++) {

    // if we've just pressed a key that hasn't been registered yet as on
    if (arduboy.pressed(buttons[i].button) && !buttons[i].state) {
      // remember this state
      buttons[i].state = true;
      // press keyboard key
      Keyboard.press(buttons[i].key);
      // show result on Arduboy display
      drawButton(i);
      // or if we've just released a key that was registered as on
    } else if (!arduboy.pressed(buttons[i].button) && buttons[i].state) {
      // remember this state
      buttons[i].state = false;
      // release keyboard key
      Keyboard.release(buttons[i].key);
      // show result on Arduboy display
      drawButton(i);
    } // if

  } // for

} // updateButtons


void drawButton(int index) {

  // chose the foreground/background color depending on button state
  uint8_t color = buttons[index].state ? BLACK : WHITE;
  uint8_t background = buttons[index].state ? WHITE : BLACK;

  // the x,y position of the button
  uint8_t x = buttons[index].x;
  uint8_t y = buttons[index].y;

  // draw the button graphic

  if (buttons[index].button == A_BUTTON || buttons[index].button == B_BUTTON) { // round (circle) button
    arduboy.fillCircle(x-1, y-1, BUTTON_RADIUS, background);
    arduboy.drawCircle(x-1, y-1, BUTTON_RADIUS, WHITE);
  } else { // regular rounded square button
    arduboy.fillRoundRect(x - BUTTON_RADIUS, y - BUTTON_RADIUS, BUTTON_DIAMETER, BUTTON_DIAMETER, RECT_CORNER_SIZE, background);
    arduboy.drawRoundRect(x - BUTTON_RADIUS, y - BUTTON_RADIUS, BUTTON_DIAMETER, BUTTON_DIAMETER, RECT_CORNER_SIZE, WHITE);
  }

  // draw the button character ID
  arduboy.drawChar(x - CHAR_HALF_WIDTH, y - CHAR_HALF_HEIGHT, buttons[index].character, color, background, TEXT_SIZE);

  // update needs-display flag
  arduboy.display();

} // drawButtons

