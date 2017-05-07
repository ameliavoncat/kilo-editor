struct editorConfig {
  int char_position_x, char_position_y;
  int render_position_x;
  int row_offset;
  int col_offset;
  int screenrows;
  int screencols;
  int numrows;
  erow *row;
  int dirty;
  char *filename;
  char statusmsg[80];
  time_t statusmsg_time;
  struct editorSyntax *syntax;
  struct termios orig_termios;
};
