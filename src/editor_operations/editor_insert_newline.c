void editorInsertNewline() {
  if (Editor.char_position_x == 0) {
    editorInsertRow(Editor.char_position_y, "", 0);
  } else {
    erow *row = &Editor.row[Editor.char_position_y];
    editorInsertRow(Editor.char_position_y + 1, &row->chars[Editor.char_position_x], row->size - Editor.char_position_x);
    row = &Editor.row[Editor.char_position_y];
    row-> size = Editor.char_position_x;
    row-> chars[row->size] = '\0';
    editorUpdateRow(row);
  }
  Editor.char_position_y++;
  Editor.char_position_x = 0;
}
