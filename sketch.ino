//#include <EnableInterrupt.h>
#include <LiquidCrystal_I2C.h>
//#include <Wire.h>
//#include <HardwareSerial.h>
#include <nanoFORTH.h>
#include <string.h>

#define LABEL_COUNT 16

const char* labels[] = {
  "PORTAL  My",
  "ATLETAS  ",
  "REGIST.  ",
  "COMUNICANDO ",
  "LEITOR ",
  "LTE/4G: ",
  "WIFI: ",
  "IP: ",
  "LOCAL: ",
  "PROVA: ",
  "PING: ",
  "HORA: ",
  "USB: ",
  "AGUARDE...",
  "ERRO, TENTAR",
  "  NOVAMENTE"
};
const int labels_len[LABEL_COUNT] = {
  10,9,9,12,7,8,6,4,7,7,6,6,5,10,12,11
};

#define VALUE_COUNT 9

const char* values[] = {
  "WEB",
  "CONECTAD",
  "DESLIGAD",
  "AUTOMATIC",
  "OK",
  "X",
  "  ",
  "A",
  ": "
};

const char code[] PROGMEM =
#define NL "\n"
/*
  -------------------------------------

  Intro:

    (EXP): Exported variable, means it
    will be used outside of this code,
    probably in the Go part of the
    source, which mainly deals with
    ACtions.

    Such variables follow the go
    convention for exported symbols,
    starting with a capital letter.
  
  ----------CAPITALIZATION-------------

    Xxx: (EXP) Variables. They can
    (and will), still have prefixes
    though it will take some
    imagination.

    XXX: Forth primitives or consts
    (VALs).

  -------------------------------------

    xXX: Variables with the first
    letter left uncapitalized, and
    the rest capitalized, are prefix
    variables, akin to namespaces or
    objects (read them like: x.XX).

    They are used to specify that a
    variable refers to some entity,
    for example, the MAIN button, in
    'mAC'.
  
  -------------------------------------

    xXx: These are functions, they are
    capitalized this way to help with
    identification, since we have no
    syntax highlighting and are limited
    to 3 chars.

    This also enables us to name
    functions after certain variables,
    although it is not recommended.

  -------------------------------------
*/

// Const.fth
  "501 VAL VER"     NL // version

// Button.fth

  // Generic button interface definition
  //  "IFC b HAS AC ST RL Pr IN\n"
  //  "b m, b a\n"

  // Class consts ( they use property capitalization )
  "6 VAL mIN"       NL
  "7 VAL aIN"       NL

  // Properties                 CLASS  PROP     DESC
  "VAR mRL"         NL // m ->  MAIN , m.RL, MAIN RELEASE
  "VAR Mac"         NL // (EXP) MAIN , M.ac, MAIN ACTION
  "VAR mST"         NL //       MAIN , m.ST, MAIN STATE

  "VAR aAC"         NL // a ->  ALT  , a.AC, ALT  ACTION
  "VAR aST"         NL //       ALT  , a.ST, ALT  STATE

  // Methods                    CLASS  METHOD   DESC
  ": mPr"              // M.PR(--)
    " mIN IN 0 = ;" NL //       MAIN , m.Pr, MAIN PRESSED
  ": aPr "             // A.PR(--)
    " aIN IN 0 = ;" NL //       ALT  , a.Pr, ALT  PRESSED

  ": cAl"              // CAL ( b.Pr b.ST -- b.RL b.ST' )
    " DUP ROT SWP"     // Desc: "CALculates" the truth
    " NOT AND ;"    NL // value of b.RL, i.e. checks if
  //                      the button has been PR + RL
  //                      (RELEASED), from the current
  //                      state vs the previous one, i.e.
  //                      b.Pr vs b.ST.
  //                        - Also returns the new value
  //                      for b.ST, which is the return
  //                      from b.PR.

  ": sWi"              // SWI ( m.RL -- )
    " IF"              // Desc: Switches screens if
      " Scr @ 1 +"     // m.RL is set.
      " 7 MOD THN ;"NL

  ": mUp"
    " mST @ mPR"
    " cAl DUP"
    " sWi bAc"
    " Mac !"
    " mST ! ;"      NL

  ": aUp"
    " aST @ aPR"
    " cAl DUP"
    " bAc"
    " Aac !"
    " aST ! ;"      NL

  ": bUp"              // b::Up(--)
    " Mac @ NOT IF mUp THN"
    " Aac @ NOT IF aUp THN"
  " ;"              NL

// Screen.fth
  ": lBl  5   API ;"NL
  ": fWd  2   API ;"NL
  ": fNm  1   API ;"NL
  ": nUm  4   API ;"NL
  ": vAl  6   API ;"NL
  ": iP   7   API ;"NL
  ": mS   3   API ;"NL
  ": hMs  256 iP  ;"NL
  //": uSb  12  lBl ;"NL
  //": tIm  11  lBl ;"NL
  
  // Text Decorations
  ": a    7 6 API ;"NL
  ": sPc  6 6 API ;"NL
  ": sEp  8 6 API ;"NL

  // Antenna Data
  ": atn" // ( N Mag N Mag N Mag N Mag -- )
    " a 1 nUm sEp fNm sPc a 2 nUm sEp fNm fWd"
    " a 3 nUm sEp fNm sPc a 4 nUm sEp fNm fWd"
  " ;"               NL

  // Display memory
  ": Dis"

    // Data: 8 bytes
    " NOP NOP"
    " NOP NOP"
    " NOP NOP"
    " NOP NOP"       NL

    // Heading: 9 bytes
    " 0 lBl VER nUm fWd"

    // +0x11 (dec 17)
    " NOP NOP NOP NOP NOP fWd"
    " NOP NOP NOP NOP NOP fWd"

    // Heading: 8 bytes
    " 3 lBl 0 vAl fWd"

    " 0 API"
  " ;"               NL

// Timers.fth
  "500 DLY"          NL // Wait until everything is loaded
  "10 0 TMI bUp"     NL // Init button checking
  "50 1 TMI Dis"     NL // Init display
  "1 TME"            NL // Init timers
;

#define VIRT_SCR_COLS 20
#define VIRT_SCR_ROWS 4

uint8_t g_x, g_y;
char g_virt_scr[VIRT_SCR_ROWS][VIRT_SCR_COLS];

#define virt_scr_sprintf(fmt, ...) \
  snprintf(g_virt_scr[g_y] + g_x, ((VIRT_SCR_COLS + 1) - g_x), fmt, __VA_ARGS__);

LiquidCrystal_I2C lcd(0x27, VIRT_SCR_COLS, VIRT_SCR_ROWS);

void
setup()
{
  lcd.init();      // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
  
  memset(g_virt_scr, '\0', sizeof(g_virt_scr));

  Serial.begin(115200);
  while(!Serial);

  n4_setup(code);

  n4_api(0, draw);
  n4_api(1, print_forthNumber);
  n4_api(2, forth_line_feed);
  n4_api(3, forth_millis);

  n4_api(4, forth_number);
  n4_api(5, forth_label);
  n4_api(6, forth_value);
  n4_api(7, forth_ip);

  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void
forth_millis()
{
  int v;

  if ((v = n4_pop()) < 1000) {
    g_x += virt_scr_sprintf("%dms", v);
    return;
  }

  v /= 1000;
  g_x += virt_scr_sprintf("%ds", v);
}

void
forth_value()
{
  int v;

  if ((v = n4_pop()) > VALUE_COUNT || v < 0) return;

  g_x += virt_scr_sprintf("%s", values[v]);
}

void
print_forthNumber()
{
  int mag, v;
  char postfix;

  mag = n4_pop();
  v = n4_pop();

  postfix = (mag == 0) ?
      ' ' :
      (mag >= 3 && mag < 6 ? 'K' : 'M');

  // 'X'  if Magnitude = 0, 'XK' if 6 > Magnitude >= 3
  // 'XM' if Magnitude >= 6

  g_x += virt_scr_sprintf("%d%c", v, postfix);
}

void
forth_ip()
{
  int f;

  if ((f = n4_pop()) >= 256) {
    g_x += virt_scr_sprintf("%02d:%02d:%02d", n4_pop(), n4_pop(), n4_pop());
  } else {
    g_x += virt_scr_sprintf("%d.%d.%d.%d", n4_pop(), n4_pop(), n4_pop(), f);
  }
}

void
forth_number()
{
  g_x += virt_scr_sprintf("%d", n4_pop());
}

void
forth_label()
{
  char* buf;
  int v;

  if ((v = n4_pop()) >= LABEL_COUNT || v < 0) return;

  g_x = labels_len[v];

  memcpy(g_virt_scr[g_y], labels[v], labels_len[v]);
}

void
forth_line_feed()
{
  for (; g_x < VIRT_SCR_COLS - 1; g_x++)
    g_virt_scr[g_y][g_x] = ' ';

  g_x++;
  g_virt_scr[g_y][g_x] = '\0';

  g_x = 0;
  if (g_y++ >= (VIRT_SCR_ROWS - 1)) g_y = VIRT_SCR_ROWS - 1;
}

void
draw()
{
  // resetting
  g_y = 0;
  g_x = 0;

  for (int i = 0; i < VIRT_SCR_ROWS; i++){

    lcd.setCursor(0, i);

    for (char* c = g_virt_scr[i], i = 0; *c != '\0' && i < VIRT_SCR_COLS; c++, i++)
      lcd.write(*c);
  }
}

void
loop()
{
  n4_run();
}
