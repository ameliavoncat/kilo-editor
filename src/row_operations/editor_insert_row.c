void editorInsertRow(int y_index, char *s, size_t len) {
  if (y_index < 0 || y_index > E.numrows) return;

  E.row = realloc(E.row, sizeof(erow) * (E.numrows + 1));
  memmove(&E.row[y_index + 1], &E.row[y_index], sizeof(erow) * (E.numrows - y_index));

  E.row[y_index].size = len;
  E.row[y_index].chars = malloc(len + 1);
  memcpy(E.row[y_index].chars, s, len);
  E.row[y_index].chars[len] = '\0';

  E.row[y_index].rsize = 0;
  E.row[y_index].render = NULL;
  editorUpdateRow(&E.row[y_index]);

  E.numrows++;
  E.dirty++;
}
