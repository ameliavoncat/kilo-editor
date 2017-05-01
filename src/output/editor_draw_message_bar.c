void editorDrawMessageBar(struct abuf *ab) {
  abAppend(ab, "\x1b[K", 3);
  int msglen = strlen(Editor.statusmsg);
  if (msglen > Editor.screencols) msglen = Editor.screencols;
  if (msglen && time(NULL) - Editor.statusmsg_time < 5)
    abAppend(ab, Editor.statusmsg, msglen);
}
