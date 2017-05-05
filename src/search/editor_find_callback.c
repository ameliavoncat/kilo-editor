void editorFindCallback(char *query, int key) {
  if (key == '\r' || key == '\x1b') {
    return;
  }

  int i;
  for (i = 0; i < Editor.numrows; i++) {
    erow *row = &Editor.row[i];
    char *match = strstr(row->render, query);
    if (match) {
      Editor.char_position_y = i;
      Editor.char_position_x = editorRowRxToCx(row, match - row->render);
      Editor.row_offset = Editor.numrows;
      break;
    }
  }
}
