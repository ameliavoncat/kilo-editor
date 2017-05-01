char *editorPrompt(char *prompt) {
  size_t bufsize = 128;
  char *buf = malloc(bufsize);

  size_t buflen = 0;
  buf[0] = '\0';

  while (1) {
    editorSetStatusMessage(prompt, buf);
    editorRefreshScreen();

    int input = editorReadKey();
    if (input == DEL_KEY || input == CTRL_KEY('h') || input == BACKSPACE) {
      if (buflen !=0) buf[--buflen] = '\0';
    } else if (input == '\x1b') {
      editorSetStatusMessage("");
      free(buf);
      return NULL;
    } else if (input == '\r') {
      if (buflen != 0) {
        editorSetStatusMessage("");
        return buf;
      }
    } else if (!iscntrl(input) && input < 128) {
      if (buflen == bufsize - 1) {
        bufsize *= 2;
        buf = realloc(buf, bufsize);
      }
      buf[buflen++] = input;
      buf[buflen] = '\0';
    }
  }
}
