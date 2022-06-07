#include "Arduino.h"
#include "Inkplate.h"

extern Inkplate display;
extern bool change_needed;
extern const char wday_name[7][10];
extern const char mon_name[12][4];

int widget0_h = 9;
int widget0_m = 41;
int widget0_center_x = 400;
int widget0_center_y = 260;
int widget0_size = 450;
int widget0_r0 = (double)widget0_size / 2 * 0.55;
int widget0_r1 = (double)widget0_size / 2 * 0.65;
int widget0_r2 = (double)widget0_size / 2 * 0.9;
int widget0_r3 = (double)widget0_size / 2 * 1.0;

char text1_content[32] = "Wednesday 22.03.2021.";
int text1_cursor_x = 220;
int text1_cursor_y = 550;
const GFXfont *text1_font = &Inter16pt7b;

int bitmap3_x = 340;
int bitmap3_y = 180;
const int bitmap3_w = 128;
const int bitmap3_h = 159;
const uint8_t bitmap3_content[] PROGMEM = {
0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x1f,0xff,0xff,0xfc,0x0,0x7,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x7f,0xff,0xff,0x80,0x0,0x0,0x0,
0x0,0x0,0x0,0xff,0xff,0xf8,0x0,0x0,0x0,0x3,0xff,0xff,0xe0,0x0,0x0,0x0,
0x0,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x0,0x0,0xff,0xff,0xf0,0x0,0x0,0x0,
0x0,0x0,0x3,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x3f,0xff,0xf8,0x0,0x0,0x0,
0x0,0x0,0x7,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xfc,0x0,0x0,0x0,
0x0,0x0,0x1f,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0x0,0x0,0x0,
0x0,0x0,0x3f,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0x80,0x0,0x0,
0x0,0x0,0x7f,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,0x0,
0x0,0x0,0x7f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xe0,0x0,0x0,
0x0,0x0,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xf0,0x0,0x0,
0x0,0x1,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xf8,0x0,0x0,
0x0,0x3,0xff,0xf0,0x0,0x0,0x0,0x3f,0x80,0x0,0x0,0x1,0xff,0xf8,0x0,0x0,
0x0,0x7,0xff,0xe0,0x0,0x0,0x3f,0xff,0xff,0x0,0x0,0x0,0xff,0xfe,0x0,0x0,
0x0,0xf,0xff,0xc0,0x0,0x0,0xff,0xff,0xff,0xe0,0x0,0x0,0x7f,0xff,0x0,0x0,
0x0,0xf,0xff,0x80,0x0,0x3,0xff,0xff,0xff,0xf8,0x0,0x0,0x3f,0xff,0x80,0x0,
0x0,0x1f,0xff,0x0,0x0,0x1f,0xff,0xff,0xff,0xfe,0x0,0x0,0x1f,0xff,0xc0,0x0,
0x0,0x3f,0xfe,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0x80,0x0,0xf,0xff,0xe0,0x0,
0x0,0x7f,0xfc,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x7,0xff,0xf0,0x0,
0x0,0x7f,0xf8,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,0xf8,0x0,
0x0,0xff,0xf8,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xfc,0x0,
0x0,0xff,0xf0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0xff,0xfe,0x0,
0x1,0xff,0xe0,0x0,0x1f,0xff,0xff,0xfb,0xff,0xff,0xff,0x0,0x0,0x7f,0xfe,0x0,
0x1,0xff,0xc0,0x0,0x3f,0xff,0xfc,0x0,0x7,0xff,0xff,0x80,0x0,0x3f,0xfe,0x0,
0x3,0xff,0xc0,0x0,0x7f,0xff,0xc0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x1f,0xff,0x0,
0x3,0xff,0x80,0x0,0xff,0xff,0x0,0x0,0x0,0x3f,0xff,0xe0,0x0,0x1f,0xff,0x0,
0x7,0xff,0x80,0x1,0xff,0xfe,0x0,0x0,0x0,0xf,0xff,0xf0,0x0,0x1f,0xff,0x0,
0x7,0xff,0x0,0x1,0xff,0xf8,0x0,0x0,0x0,0x3,0xff,0xf8,0x0,0x1f,0xff,0x0,
0x7,0xff,0x0,0x3,0xff,0xf0,0x0,0x0,0x0,0x1,0xff,0xfc,0x0,0x3f,0xfe,0x0,
0xf,0xfe,0x0,0x7,0xff,0xe0,0x0,0x0,0x0,0x0,0xff,0xfe,0x0,0x7f,0xfe,0x0,
0xf,0xfe,0x0,0x7,0xff,0xc0,0x0,0x0,0x0,0x0,0x7f,0xff,0x0,0xff,0xfe,0x0,
0x1f,0xfc,0x0,0xf,0xff,0x80,0x0,0x0,0x0,0x0,0x1f,0xff,0x81,0xff,0xfc,0x0,
0x1f,0xfc,0x0,0x1f,0xff,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xc3,0xff,0xf8,0x0,
0x1f,0xf8,0x0,0x1f,0xfe,0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xf0,0x0,
0x3f,0xf8,0x0,0x3f,0xfc,0x0,0x0,0xff,0xe0,0x0,0x3,0xff,0xff,0xff,0xe0,0x0,
0x3f,0xf8,0x0,0x3f,0xf8,0x0,0x1,0xff,0xf8,0x0,0x1,0xff,0xff,0xff,0xc0,0x0,
0x3f,0xf0,0x0,0x3f,0xf8,0x0,0x7,0xff,0xfc,0x0,0x1,0xff,0xff,0xff,0x80,0x0,
0x3f,0xf0,0x0,0x7f,0xf0,0x0,0xf,0xff,0xfe,0x0,0x0,0xff,0xff,0xff,0x0,0x0,
0x3f,0xf0,0x0,0x7f,0xf0,0x0,0x1f,0xff,0xff,0x0,0x0,0x3f,0xff,0xfe,0x0,0x0,
0x7f,0xf0,0x0,0xff,0xe0,0x0,0x3f,0xff,0xff,0x80,0x0,0x1f,0xff,0xfc,0x0,0x0,
0x7f,0xf0,0x0,0xff,0xe0,0x0,0x7f,0xff,0xff,0xc0,0x0,0x1f,0xff,0xf8,0x0,0x0,
0x7f,0xe0,0x0,0xff,0xc0,0x0,0xff,0xff,0xff,0xe0,0x0,0x7,0xff,0xf0,0x0,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x1,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,0xf0,0x0,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x3,0xff,0xff,0xff,0xf8,0x0,0x3,0xff,0xf8,0x0,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x3,0xff,0xff,0xff,0xfc,0x0,0x1,0xff,0xfc,0x0,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x7,0xff,0xc0,0x7f,0xfe,0x0,0x0,0x7f,0xfe,0x0,0x0,
0xff,0xe0,0x1,0xff,0x80,0x7,0xff,0x80,0x3f,0xff,0x0,0x0,0x3f,0xff,0x0,0x0,
0xff,0xe0,0x1,0xff,0x80,0x7,0xff,0x0,0x1f,0xff,0x80,0x0,0x3f,0xff,0x80,0x0,
0xff,0xe0,0x1,0xff,0x80,0xf,0xff,0x0,0xf,0xff,0xc0,0x0,0xf,0xff,0xc0,0x0,
0xff,0xc0,0x1,0xff,0x80,0xf,0xfe,0x0,0x7,0xff,0xe0,0x0,0x7,0xff,0xe0,0x0,
0xff,0xc0,0x1,0xff,0x80,0xf,0xfe,0x0,0x3,0xff,0xf0,0x0,0x3,0xff,0xe0,0x0,
0xff,0xc0,0x1,0xff,0x80,0xf,0xfe,0x0,0x1,0xff,0xf8,0x0,0x1,0xff,0xf0,0x0,
0xff,0xe0,0x1,0xff,0x80,0xf,0xfe,0x0,0x0,0xff,0xfc,0x0,0x0,0xff,0xf8,0x0,
0xff,0xe0,0x1,0xff,0x80,0xf,0xff,0x0,0x0,0x7f,0xfe,0x0,0x0,0x7f,0xf8,0x0,
0xff,0xe0,0x1,0xff,0x80,0x7,0xff,0x80,0x0,0x3f,0xff,0x0,0x0,0x7f,0xfc,0x0,
0xff,0xe0,0x1,0xff,0xc0,0x7,0xff,0x80,0x0,0x1f,0xff,0x80,0x0,0x3f,0xfe,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x7,0xff,0xc0,0x0,0xf,0xff,0xc0,0x0,0x1f,0xfe,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x3,0xff,0xe0,0x0,0x7,0xff,0xe0,0x0,0xf,0xff,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x1,0xff,0xf0,0x0,0x3,0xff,0xf0,0x0,0xf,0xff,0x0,
0x7f,0xe0,0x1,0xff,0xc0,0x1,0xff,0xfc,0x0,0x1,0xff,0xf8,0x0,0x7,0xff,0x80,
0x7f,0xf0,0x0,0xff,0xc0,0x0,0xff,0xfc,0x0,0x0,0xff,0xfc,0x0,0x3,0xff,0xc0,
0x7f,0xf0,0x0,0xff,0xe0,0x0,0x7f,0xfe,0x0,0x0,0x7f,0xfe,0x0,0x3,0xff,0xc0,
0x7f,0xf0,0x0,0xff,0xe0,0x0,0x3f,0xff,0x80,0x0,0x3f,0xff,0x0,0x1,0xff,0xe0,
0x3f,0xf0,0x0,0x7f,0xf0,0x0,0x1f,0xff,0xc0,0x0,0x1f,0xff,0x80,0x0,0xff,0xe0,
0x3f,0xf0,0x0,0x7f,0xf8,0x0,0xf,0xff,0xc0,0x0,0xf,0xff,0xc0,0x0,0xff,0xe0,
0x3f,0xf8,0x0,0x3f,0xf8,0x0,0x7,0xff,0xe0,0x0,0x7,0xff,0xe0,0x0,0xff,0xf0,
0x3f,0xf8,0x0,0x3f,0xfc,0x0,0x3,0xff,0xf8,0x0,0x3,0xff,0xe0,0x0,0x7f,0xf0,
0x3f,0xf8,0x0,0x1f,0xfc,0x0,0x1,0xff,0xfc,0x0,0x1,0xff,0xf0,0x0,0x7f,0xf0,
0x1f,0xfc,0x0,0x1f,0xfe,0x0,0x0,0xff,0xfe,0x0,0x0,0xff,0xf0,0x0,0x3f,0xf8,
0x1f,0xfc,0x0,0x1f,0xff,0x0,0x0,0x7f,0xff,0x0,0x0,0x7f,0xf8,0x0,0x3f,0xf8,
0x1f,0xfe,0x0,0xf,0xff,0x80,0x0,0x3f,0xff,0x80,0x0,0x3f,0xf8,0x0,0x1f,0xfc,
0xf,0xfe,0x0,0x7,0xff,0xc0,0x0,0x1f,0xff,0xc0,0x0,0x3f,0xfc,0x0,0x1f,0xfc,
0xf,0xfe,0x0,0x7,0xff,0xe0,0x0,0xf,0xff,0xe0,0x0,0x1f,0xfc,0x0,0x1f,0xfc,
0x7,0xff,0x0,0x3,0xff,0xf0,0x0,0x7,0xff,0xf0,0x0,0x1f,0xfe,0x0,0xf,0xfc,
0x7,0xff,0x0,0x1,0xff,0xf8,0x0,0x3,0xff,0xf8,0x0,0xf,0xfe,0x0,0xf,0xfc,
0x7,0xff,0x80,0x0,0xff,0xfc,0x0,0x1,0xff,0xfc,0x0,0x7,0xff,0x0,0xf,0xfe,
0x3,0xff,0xc0,0x0,0xff,0xfe,0x0,0x0,0xff,0xfe,0x0,0x7,0xff,0x0,0xf,0xfe,
0x3,0xff,0xc0,0x0,0x7f,0xff,0x0,0x0,0x7f,0xff,0x0,0x3,0xff,0x0,0xf,0xfe,
0x1,0xff,0xe0,0x0,0x3f,0xff,0x80,0x0,0x3f,0xff,0x0,0x3,0xff,0x80,0x7,0xfe,
0x1,0xff,0xf0,0x0,0x1f,0xff,0xc0,0x0,0x1f,0xff,0x80,0x3,0xff,0x80,0x7,0xfe,
0x0,0xff,0xf0,0x0,0xf,0xff,0xe0,0x0,0xf,0xff,0xc0,0x3,0xff,0x80,0x7,0xfe,
0x0,0x7f,0xf8,0x0,0x7,0xff,0xf0,0x0,0x7,0xff,0xe0,0x3,0xff,0x80,0x7,0xff,
0x0,0x7f,0xfc,0x0,0x3,0xff,0xf8,0x0,0x3,0xff,0xe0,0x1,0xff,0x80,0x7,0xff,
0x0,0x3f,0xfe,0x0,0x1,0xff,0xfc,0x0,0x1,0xff,0xe0,0x1,0xff,0x80,0x3,0xff,
0x0,0x3f,0xfe,0x0,0x0,0x7f,0xfe,0x0,0x0,0xff,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x1f,0xff,0x0,0x0,0x7f,0xff,0x0,0x0,0x7f,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0xf,0xff,0x80,0x0,0x3f,0xff,0x80,0x0,0x7f,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0xf,0xff,0xc0,0x0,0xf,0xff,0xc0,0x0,0x7f,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x7,0xff,0xe0,0x0,0x7,0xff,0xe0,0x0,0x7f,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x3,0xff,0xf0,0x0,0x7,0xff,0xf0,0x0,0x7f,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x1,0xff,0xf8,0x0,0x3,0xff,0xf8,0x0,0xff,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x0,0xff,0xfc,0x0,0x0,0xff,0xfc,0x1,0xff,0xf0,0x1,0xff,0x80,0x3,0xff,
0x0,0x0,0x7f,0xfe,0x0,0x0,0xff,0xfe,0x3,0xff,0xe0,0x1,0xff,0x80,0x7,0xff,
0x0,0x0,0x7f,0xff,0x0,0x0,0x7f,0xff,0x8f,0xff,0xe0,0x3,0xff,0x80,0x7,0xff,
0x0,0x0,0x1f,0xff,0x80,0x0,0x1f,0xff,0xff,0xff,0xc0,0x3,0xff,0x80,0x7,0xfe,
0x0,0x0,0x1f,0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0x80,0x3,0xff,0x80,0x7,0xfe,
0x0,0x0,0xf,0xff,0xe0,0x0,0xf,0xff,0xff,0xff,0x80,0x3,0xff,0x80,0x7,0xfe,
0x0,0x0,0xf,0xff,0xf0,0x0,0x7,0xff,0xff,0xff,0x0,0x3,0xff,0x0,0x7,0xfe,
0x0,0x0,0x1f,0xff,0xf8,0x0,0x1,0xff,0xff,0xfe,0x0,0x7,0xff,0x0,0xf,0xfe,
0x0,0x0,0x3f,0xff,0xfc,0x0,0x1,0xff,0xff,0xfc,0x0,0x7,0xff,0x0,0xf,0xfe,
0x0,0x0,0x7f,0xff,0xfe,0x0,0x0,0xff,0xff,0xf8,0x0,0xf,0xfe,0x0,0xf,0xfc,
0x0,0x0,0xff,0xff,0xff,0x0,0x0,0x3f,0xff,0xf0,0x0,0xf,0xfe,0x0,0xf,0xfc,
0x0,0x1,0xff,0xff,0xff,0x80,0x0,0x1f,0xff,0xc0,0x0,0x1f,0xfc,0x0,0xf,0xfc,
0x0,0x3,0xff,0xff,0xff,0xc0,0x0,0x7,0xff,0x80,0x0,0x3f,0xfc,0x0,0x1f,0xfc,
0x0,0x7,0xff,0xff,0xff,0xe0,0x0,0x0,0xf8,0x0,0x0,0x3f,0xfc,0x0,0x1f,0xfc,
0x0,0xf,0xff,0xe7,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x7f,0xf8,0x0,0x3f,0xf8,
0x0,0x1f,0xff,0x81,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0xff,0xf8,0x0,0x3f,0xf8,
0x0,0x3f,0xff,0x0,0xff,0xfc,0x0,0x0,0x0,0x0,0x1,0xff,0xf0,0x0,0x3f,0xf8,
0x0,0x7f,0xfe,0x0,0x7f,0xfe,0x0,0x0,0x0,0x0,0x3,0xff,0xe0,0x0,0x7f,0xf0,
0x0,0x7f,0xfc,0x0,0x3f,0xff,0x80,0x0,0x0,0x0,0x7,0xff,0xe0,0x0,0x7f,0xf0,
0x0,0x7f,0xfc,0x0,0x1f,0xff,0xc0,0x0,0x0,0x0,0x1f,0xff,0xc0,0x0,0xff,0xe0,
0x0,0xff,0xf8,0x0,0xf,0xff,0xe0,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,0xff,0xe0,
0x0,0xff,0xf8,0x0,0x7,0xff,0xfc,0x0,0x0,0x0,0xff,0xff,0x0,0x1,0xff,0xe0,
0x0,0xff,0xfc,0x0,0x3,0xff,0xfe,0x0,0x0,0x3,0xff,0xfe,0x0,0x1,0xff,0xc0,
0x0,0x7f,0xfc,0x0,0x1,0xff,0xff,0x80,0x0,0xf,0xff,0xfe,0x0,0x3,0xff,0xc0,
0x0,0x7f,0xfe,0x0,0x0,0xff,0xff,0xfe,0x1,0xff,0xff,0xfc,0x0,0x7,0xff,0x80,
0x0,0x7f,0xff,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7,0xff,0x80,
0x0,0x3f,0xff,0x80,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0xf,0xff,0x0,
0x0,0x1f,0xff,0xc0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x1f,0xfe,0x0,
0x0,0xf,0xff,0xe0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x3f,0xfe,0x0,
0x0,0x7,0xff,0xf0,0x0,0x3,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x7f,0xfc,0x0,
0x0,0x3,0xff,0xf8,0x0,0x0,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x7f,0xfc,0x0,
0x0,0x1,0xff,0xfc,0x0,0x0,0x3f,0xff,0xff,0xff,0xf0,0x0,0x0,0xff,0xf8,0x0,
0x0,0x0,0xff,0xfe,0x0,0x0,0x7,0xff,0xff,0xff,0x80,0x0,0x1,0xff,0xf0,0x0,
0x0,0x0,0x7f,0xff,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x3,0xff,0xf0,0x0,
0x0,0x0,0x3f,0xff,0x80,0x0,0x0,0x3f,0xff,0xe0,0x0,0x0,0x7,0xff,0xe0,0x0,
0x0,0x0,0x1f,0xff,0xc0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xc0,0x0,
0x0,0x0,0xf,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0x80,0x0,
0x0,0x0,0x7,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0x0,0x0,
0x0,0x0,0x3,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xfe,0x0,0x0,
0x0,0x0,0x1,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,0xfc,0x0,0x0,
0x0,0x0,0x0,0xff,0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xf8,0x0,0x0,
0x0,0x0,0x0,0x7f,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xf0,0x0,0x0,
0x0,0x0,0x0,0x3f,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xe0,0x0,0x0,
0x0,0x0,0x0,0x1f,0xff,0xfe,0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xc0,0x0,0x0,
0x0,0x0,0x0,0xf,0xff,0xff,0xc0,0x0,0x0,0x0,0xf,0xff,0xff,0x80,0x0,0x0,
0x0,0x0,0x0,0x3,0xff,0xff,0xf8,0x0,0x0,0x0,0x7f,0xff,0xfe,0x0,0x0,0x0,
0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xc0,0x0,0xf,0xff,0xff,0xfc,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
};
void mainDraw() {

    
   sprintf(text1_content, "%s %.3s%3d, %d\n",
                    wday_name[display.rtcGetWeekday()], mon_name[display.rtcGetMonth() - 1], display.rtcGetDay(), display.rtcGetYear());
   widget0_h = display.rtcGetHour();
   widget0_m = display.rtcGetMinute();
   for (int i = 0; i < 60; ++i) {
       if (i % 5 == 0)
           display.drawThickLine(widget0_center_x + widget0_r1 * cos((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_y + widget0_r1 * sin((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_x + widget0_r3 * cos((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_y + widget0_r3 * sin((double)i / 60.0 * 2.0 * 3.14159265), 0, 3);
       else if (widget0_size > 150)
               display.drawLine(widget0_center_x + widget0_r1 * cos((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_y + widget0_r1 * sin((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_x + widget0_r2 * cos((double)i / 60.0 * 2.0 * 3.14159265),
               widget0_center_y + widget0_r2 * sin((double)i / 60.0 * 2.0 * 3.14159265), 2);
   }
   display.drawThickLine(widget0_center_x,
   widget0_center_y,
    widget0_center_x + widget0_r0 * cos((double)(widget0_h - 3.0 + widget0_m / 60.0) / 12.0 * 2.0 * 3.14159265),
    widget0_center_y + widget0_r0 * sin((double)(widget0_h - 3.0 + widget0_m / 60.0) / 12.0 * 2.0 * 3.14159265), 2, 2);
 
   display.drawThickLine(widget0_center_x,
       widget0_center_y,
       widget0_center_x + widget0_r2 * cos((double)(widget0_m - 15.0) / 60.0 * 2.0 * 3.14159265),
       widget0_center_y + widget0_r2 * sin((double)(widget0_m - 15.0) / 60.0 * 2.0 * 3.14159265), 2, 2);

    display.setFont(text1_font);
    display.setTextColor(BLACK, WHITE);
    display.setTextSize(1);    
    display.setCursor(text1_cursor_x, text1_cursor_y);
    display.print(text1_content);

    display.drawBitmap(bitmap3_x, bitmap3_y, bitmap3_content, bitmap3_w, bitmap3_h, BLACK);
    change_needed = 1;
}