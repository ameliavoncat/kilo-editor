void editorDelChar() {
  if (E.cy == E.numrows) return;

  erow *row = &E.row[E.cy];
  if (E.cx > 0) {
    editorRowDelChar(row, E.cx - 1);
    E.cx --;
  }
}
