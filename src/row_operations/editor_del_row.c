void editorDelRow(int index) {
  if (index < 0 || index >= Editor.numrows) return;
  editorFreeRow(&Editor.row[index]);
  memmove(&Editor.row[index], &Editor.row[index + 1], sizeof(erow) * (Editor.numrows - index - 1));
  Editor.numrows --;
  Editor.dirty ++;
}
