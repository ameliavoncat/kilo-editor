void repositionCursor() {
  //3 bytes: [escape], [, H
  write(STDOUT_FILENO, "\x1b[H", 3);
}
