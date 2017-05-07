void editorSelectSyntaxHighlight() {
  Editor.syntax = NULL;
  if (Editor.filename == NULL) return;

  char *ext = strrchr(Editor.filename, '.');

  for (unsigned int j = 0; j< HLDB_ENTRIES; j++) {
    struct editorSyntax *s = &HLDB[j];
    unsigned int i = 0;
    while (s->filematch[i]) {
      int is_ext = (s->filematch[i][0] == '.');
      if ((is_ext && ext && !strcmp(ext, s->filematch[i])) ||
          (!is_ext && strstr(Editor.filename, s->filematch[i]))) {
        Editor.syntax = s;

        int filerow;
        for (filerow = 0; filerow < Editor.numrows; filerow++) {
          editorUpdateSyntax(&Editor.row[filerow]);
        }
        return;
      }
      i++;
    }
  }
}
