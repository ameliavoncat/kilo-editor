void editorMoveCursor(int key) {
  erow *row = (Editor.char_position_y >= Editor.numrows) ? NULL : &Editor.row[Editor.char_position_y];

  switch (key) {
    case ARROW_LEFT:
      if (Editor.char_position_x != 0) {
        Editor.char_position_x--;
      } else if (Editor.char_position_y > 0) {
        Editor.char_position_y --;
        Editor.char_position_x = Editor.row[Editor.char_position_y].size;
      }
      break;
    case ARROW_RIGHT:
      if (row && Editor.char_position_x < row->size) {
        Editor.char_position_x++;
      } else if (row && Editor.char_position_x == row->size) {
        Editor.char_position_y++;
        Editor.char_position_x = 0;
      }
      break;
    case ARROW_UP:
      if (Editor.char_position_y != 0) {
        Editor.char_position_y--;
      }
      break;
    case ARROW_DOWN:
      if (Editor.char_position_y < Editor.numrows) {
        Editor.char_position_y++;
      }
      break;
  }

  row = (Editor.char_position_y >= Editor.numrows) ? NULL : &Editor.row[Editor.char_position_y];
  int rowlen = row ? row->size : 0;
  if (Editor.char_position_x > rowlen) {
    Editor.char_position_x = rowlen;
  }
}
