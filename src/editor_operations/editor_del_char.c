void editorDelChar() {
  if (Editor.char_position_y == Editor.numrows) return;
  if (Editor.char_position_x == 0 && Editor.char_position_y == 0) return;

  erow *row = &Editor.row[Editor.char_position_y];
  if (Editor.char_position_x > 0) {
    editorRowDelChar(row, Editor.char_position_x - 1);
    Editor.char_position_x --;
  } else {
    Editor.char_position_x = Editor.row[Editor.char_position_y - 1].size;
    editorRowAppendString(&Editor.row[Editor.char_position_y - 1], row->chars, row->size);
    editorDelRow(Editor.char_position_y);
    Editor.char_position_y--;
  }
}
