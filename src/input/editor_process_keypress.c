void editorProcessKeypress() {
  static int quit_times = KILO_QUIT_TIMES;
  int input = editorReadKey();

  switch(input) {
    case '\r':
      editorInsertNewline();
      break;

    case CTRL_KEY('q'):
      if (Editor.dirty && quit_times > 0) {
          editorSetStatusMessage("WARNING!!! File has unsaved changes. "
            "Press Ctrl-Q %d more times to quit.", quit_times);
          quit_times--;
          return;
      }
      clearScreenAndPositionCursor();
      exit(0);
      break;

    case CTRL_KEY('s'):
      editorSave();
    break;

    case HOME_KEY:
      Editor.char_position_x = 0;
      break;

    case END_KEY:
      if (Editor.char_position_y < Editor.numrows)
        Editor.char_position_x = Editor.row[Editor.char_position_y].size;
      break;

    case BACKSPACE:
    case CTRL_KEY('h'):
    case DEL_KEY:
      if (input == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
      editorDelChar();
      break;

    case PAGE_UP:
    case PAGE_DOWN:
      {
        if(input == PAGE_UP) {
          Editor.char_position_y = Editor.row_offset;
        } else if (input == PAGE_DOWN) {
          Editor.char_position_y = Editor.row_offset + Editor.screenrows - 1;
          if (Editor.char_position_y > Editor.numrows) Editor.char_position_y = Editor.numrows;
        }

        int times = Editor.screenrows;
        while (times--)
          editorMoveCursor( input == PAGE_UP ? ARROW_UP : ARROW_DOWN);
      }
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
      editorMoveCursor(input);
      break;

    case CTRL_KEY('l'):
    case '\x1b':
      break;

    default:
      editorInsertChar(input);
      break;
  }

  quit_times = KILO_QUIT_TIMES;
}
