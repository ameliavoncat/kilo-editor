void editorFind() {
  int saved_cx = Editor.char_position_x;
  int saved_cy = Editor.char_position_y;
  int saved_coloff = Editor.col_offset;
  int saved_rowoff = Editor.row_offset;

  char *query = editorPrompt("Search: %s (ESC to cancel)", editorFindCallback);

  if (query) {
    free(query);
  } else {
    Editor.char_position_x = saved_cx;
    Editor.char_position_y = saved_cy;
    Editor.col_offset = saved_coloff;
    Editor.row_offset = saved_rowoff;
  }
}
