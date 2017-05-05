void editorUpdateSyntax(erow *row) {
  row->hl = realloc(row->hl, row->rsize);
  memset(row->hl, HL_NORMAL, row->rsize);

  int i;
  for (i = 0; i < row->rsize; i++) {
    if (isdigit(row->render[i])) {
      row->hl[i] = HL_NUMBER;
    }
  }
}
