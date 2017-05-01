void editorFreeRow(erow *row) {
  free(row->render);
  free(row->chars);
}
