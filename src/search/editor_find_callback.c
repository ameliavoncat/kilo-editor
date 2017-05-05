void editorFindCallback(char *query, int key) {
  static int last_match = -1;
  static int direction = 1;

  if (key == '\r' || key == '\x1b') {
    last_match = -1;
    direction = 1;
    return;
  } else if (key == ARROW_RIGHT || key == ARROW_DOWN) {
    direction = 1;
  } else if (key == ARROW_LEFT || key == ARROW_UP) {
    direction = -1;
  } else {
    last_match = -1;
    direction = 1;
  }

  if (last_match == -1) direction = 1;
  int current = last_match;
  int i;
  for (i = 0; i < Editor.numrows; i++) {
    current += direction;
    if(current == -1) current = Editor.numrows - 1;
    else if (current == Editor.numrows) current = 0;

    erow *row = &Editor.row[current];
    char *match = strstr(row->render, query);
    if (match) {
      last_match = current;
      Editor.char_position_y = current;
      Editor.char_position_x = editorRowRxToCx(row, match - row->render);
      Editor.row_offset = Editor.numrows;
      break;
    }
  }
}
