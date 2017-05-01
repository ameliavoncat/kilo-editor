void editorSetStatusMessage(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(Editor.statusmsg, sizeof(Editor.statusmsg), fmt, ap);
  va_end(ap);
  Editor.statusmsg_time = time(NULL);
}
