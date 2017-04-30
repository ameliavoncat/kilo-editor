void editorProcessKeypress() {
  int input = editorReadKey();

  switch(input) {
    case '\r':
      /* TODO */
      break;

    case CTRL_KEY('q'):
      clearScreenAndPositionCursor();
      exit(0);
      break;

    case HOME_KEY:
      E.cx = 0;
      break;

    case END_KEY:
      if (E.cy < E.numrows)
        E.cx = E.row[E.cy].size;
      break;

    case BACKSPACE:
    case CTRL_KEY('h'):
    case DEL_KEY:
      /* TODO */
      break;

    case PAGE_UP:
    case PAGE_DOWN:
      {
        if(input == PAGE_UP) {
          E.cy = E.rowoff;
        } else if (input == PAGE_DOWN) {
          E.cy = E.rowoff + E.screenrows - 1;
          if (E.cy > E.numrows) E.cy = E.numrows;
        }

        int times = E.screenrows;
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
}
