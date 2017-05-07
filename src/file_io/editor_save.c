void editorSave() {
  if (Editor.filename == NULL) {
    Editor.filename = editorPrompt("Save as: %s (ESC to cancel)", NULL);
    if (Editor.filename == NULL) {
      editorSetStatusMessage("Save aborted!");
      return;
    }
    editorSelectSyntaxHighlight();
  }

  int len;
  char *buf = editorRowsToString(&len);

  int fd = open(Editor.filename, O_RDWR | O_CREAT, 0644);
  if (fd != -1) {
    if (ftruncate(fd, len) != -1) {
      if (write(fd, buf, len) == len) {
        close(fd);
        free(buf);
        Editor.dirty = 0;
        editorSetStatusMessage("%d bytes written to disk.", len);
        return;
      }
    }
    close(fd);
  }
  free(buf);
  editorSetStatusMessage("Can't save! I/O error: %s", strerror(errno));
}
