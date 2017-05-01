char *editorRowsToString(int *buflen) {
  int totlen = 0;
  int j;
  for (j = 0; j < Editor.numrows; j++)
    totlen += Editor.row[j].size + 1;
  *buflen = totlen;

  char *buf = malloc(totlen);
  char *p = buf;
  for (j = 0; j < Editor.numrows; j++){
    memcpy(p, Editor.row[j].chars, Editor.row[j].size);
    p+= Editor.row[j].size;
    *p = '\n';
    p++;
  }

  return buf;
}
