void editorScroll() {
  if (E.cy < E.rowoff) {
    E.rowoff = E.cy;
  }
  if (E.cy > E.rowoff + E.screenrows) {
    E.rowoff = E.cy - E.screenrows + 1;
  }
}
