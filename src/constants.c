#define KILO_VERSION "0.0.1"
//ctrl key strips the 6th and 7th bits from the key pressed
#define CTRL_KEY(key) ((key) & 0x1f)

enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};