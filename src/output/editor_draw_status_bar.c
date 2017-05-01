void editorDrawStatusBar(struct abuf *ab) {
  abAppend(ab, "\x1b[7m", 4);
  char status[80], rstatus[80];

  int len = snprintf(
    status,
    sizeof(status), "%.20s - %d lines %s",
    Editor.filename ? Editor.filename : "[No Name]",
    Editor.numrows,
    Editor.dirty ? "(modified)" : ""
  );

  int rlen = snprintf(rstatus, sizeof(rstatus), "%d/%d",
    Editor.char_position_y + 1, Editor.numrows);

  if (len > Editor.screencols) len = Editor.screencols;
  abAppend(ab, status, len);
  while (len < Editor.screencols) {
    if (Editor.screencols - len == rlen) {
      abAppend(ab, rstatus, rlen);
      break;
    } else {
      abAppend(ab, " ", 1);
      len++;
    }
  }
  abAppend(ab, "\x1b[m", 3);
  abAppend(ab, "\r\n", 2);
}
