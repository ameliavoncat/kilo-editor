void disableRawMode() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &Editor.orig_termios) == -1) die("tcgetattr");
}
