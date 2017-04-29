void clearScreen() {
  //\x1b translates to 27 in decimal - the escape character
  //J is the Erase in Display command which clears the screen
  //4 bytes: [escape], [, 2, J
  write(STDOUT_FILENO, "\x1b[2J", 4);
}

void repositionCursor() {
  //3 bytes: [escape], [, H
  write(STDOUT_FILENO, "\x1b[H", 3);
}

void clearScreenAndPositionCursor() {
  clearScreen();
  repositionCursor();
}
