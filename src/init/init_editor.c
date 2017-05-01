void initEditor() {
  Editor.char_position_x = 0;
  Editor.char_position_y = 0;
  Editor.render_position_x = 0;
  Editor.row_offset = 0;
  Editor.col_offset = 0;
  Editor.numrows = 0;
  Editor.row = NULL;
  Editor.dirty = 0;
  Editor.filename = NULL;
  Editor.statusmsg[0] = '\0';
  Editor.statusmsg_time = 0;

  if (getWindowSize(&Editor.screenrows, &Editor.screencols) == -1) die("getWindowSize");
  Editor.screenrows -= 2;
}
