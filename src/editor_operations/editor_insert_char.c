void editorInsertChar(int character) {
  if (E.cy == E.numrows) {
    editorAppendRow("", 0);
  }
  editorRowInsertChar(&E.row[E.cy], E.cx, character);
  E.cx++;
}
