int editorSyntaxToColor(int hl) {
  switch(hl) {
    case HL_STRING: return 35;
    case HL_NUMBER: return 31;
    case HL_MATCH: return 34;
    default: return 37;
  }
}
