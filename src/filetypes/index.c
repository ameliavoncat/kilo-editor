char *C_HL_extensions[] = { ".c", ".h", ".cpp", NULL };

struct editorSyntax HLDB[] = {
  {
    "c",
    C_HL_extensions,
    HL_HIGHLIGHT_NUMBERS
  },
};

#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
