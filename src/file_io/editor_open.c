void editorOpen(char *filename) {
  free(Editor.filename);
  Editor.filename = strdup(filename);

  FILE *fp = fopen(filename, "r");
  if (!fp) die("fopen");

  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  while((linelen = getline(&line, &linecap, fp)) != -1) {
    while(linelen > 0 && (line[linelen - 1] == '\n' ||
                          line[linelen - 1] == '\r'))
      linelen --;
    editorInsertRow(Editor.numrows, line, linelen);
  }
  free(line);
  fclose(fp);
  Editor.dirty = 0;
}
