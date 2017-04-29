void die(const char *s) {
  clearScreenAndPositionCursor();

  perror(s);
  exit(1);
}
