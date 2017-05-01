void editorRowInsertChar(erow *row, int index, int input) {
  if (index < 0 || index > row->size) index = row->size;
  row->chars = realloc(row->chars, row->size + 2);
  memmove(&row->chars[index + 1], &row->chars[index], row->size - index + 1);
  row->size++;
  row->chars[index] = input;
  editorUpdateRow(row);
  E.dirty++;
}
