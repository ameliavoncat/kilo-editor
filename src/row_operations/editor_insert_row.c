void editorInsertRow(int y_index, char *s, size_t len) {
  if (y_index < 0 || y_index > Editor.numrows) return;

  Editor.row = realloc(Editor.row, sizeof(erow) * (Editor.numrows + 1));
  memmove(&Editor.row[y_index + 1], &Editor.row[y_index], sizeof(erow) * (Editor.numrows - y_index));

  Editor.row[y_index].size = len;
  Editor.row[y_index].chars = malloc(len + 1);
  memcpy(Editor.row[y_index].chars, s, len);
  Editor.row[y_index].chars[len] = '\0';

  Editor.row[y_index].rsize = 0;
  Editor.row[y_index].render = NULL;
  Editor.row[y_index].hl = NULL;
  editorUpdateRow(&Editor.row[y_index]);

  Editor.numrows++;
  Editor.dirty++;
}
