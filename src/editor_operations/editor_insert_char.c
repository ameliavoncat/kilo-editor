void editorInsertChar(int character) {
  if (Editor.char_position_y == Editor.numrows) {
    editorInsertRow(Editor.numrows, "", 0);
  }
  editorRowInsertChar(&Editor.row[Editor.char_position_y], Editor.char_position_x, character);
  Editor.char_position_x++;
}
