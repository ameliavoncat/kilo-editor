void editorScroll() {
  Editor.render_position_x = 0;
  if (Editor.char_position_y < Editor.numrows) {
    Editor.render_position_x = editorRowCxToRx(&Editor.row[Editor.char_position_y], Editor.char_position_x);
  }

  if (Editor.char_position_y < Editor.row_offset) {
    Editor.row_offset = Editor.char_position_y;
  }
  if (Editor.char_position_y > Editor.row_offset + Editor.screenrows) {
    Editor.row_offset = Editor.char_position_y - Editor.screenrows + 1;
  }
  if (Editor.render_position_x < Editor.col_offset) {
    Editor.col_offset = Editor.render_position_x;
  }
  if (Editor.render_position_x >= Editor.col_offset + Editor.screencols) {
    Editor.col_offset = Editor.render_position_x - Editor.screencols + 1;
  }
}
