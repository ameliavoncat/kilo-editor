void editorDrawRows(struct abuf *ab) {
  int y;
  for (y = 0; y < Editor.screenrows; y++) {
    int filerow = y + Editor.row_offset;
    if (filerow >= Editor.numrows) {
      if (Editor.numrows == 0 && y == Editor.screenrows / 3) {
        char welcome[80];
        int welcomelen = snprintf(
          welcome, sizeof(welcome), "Kilo editor -- version %s", KILO_VERSION
        );
        if(welcomelen > Editor.screencols) welcomelen = Editor.screencols;
        int padding = (Editor.screencols - welcomelen) / 2;
        if (padding) {
          abAppend(ab, "~", 1);
          padding--;
        }
        while (padding--) abAppend(ab, " ", 1);
        abAppend(ab, welcome, welcomelen);
      } else {
        abAppend(ab, "~", 1);
      }
    } else {
      int len = Editor.row[filerow].rsize - Editor.col_offset;
      if (len < 0) len = 0;
      if (len > Editor.screencols) len = Editor.screencols;
      abAppend(ab, &Editor.row[filerow].render[Editor.col_offset], len);
    }

    abAppend(ab, "\x1b[K", 3);
    abAppend(ab, "\r\n", 2);
  }
}
