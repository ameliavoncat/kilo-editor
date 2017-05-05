void editorFind() {
  char *query = editorPrompt("Search: %s (ESC to cancel)", editorFindCallback);

  if (query) {
    free(query);
  }
}
