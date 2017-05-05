void editorFind() {
  char *query = editorPrompt("Search: %s (ESC to cancel)", NULL);
  if (query == NULL) return;

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

  free(query);
}
