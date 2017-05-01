void editorDelRow(int index) {
  if (index < 0 || index >= E.numrows) return;
  editorFreeRow(&E.row[index]);
  memmove(&E.row[index], &E.row[index + 1], sizeof(erow) * (E.numrows - index - 1));
  E.numrows --;
  E.dirty ++;
}
