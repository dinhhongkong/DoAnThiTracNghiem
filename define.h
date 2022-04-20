
const int w  = 1600;
const int h  = 900;

//      mau sac

//     0 = Black       8 = Gray
//     1 = Blue        9 = Light Blue
//     2 = Green       A = Light Green
//     3 = Aqua        B = Light Aqua
//     4 = Red         C = Light Red
//     5 = Purple      D = Light Purple
//     6 = Yellow      E = Light Yellow
//     7 = White       F = Bright White

// define button
#define BG_BUTTON_DEFAULT 				7
#define BG_BUTTON_SELECT 				1
#define BG_BUTTON_CLICK 				4
#define TEXT_BUTTON_SELECT 				15
#define TEXT_BUTTON_DEFAULT				0
#define BG_COLOR 						0

//define edittext
#define TEXT_EDIITEXT_TITLE_COLOR 13
#define BG_EDITTEXT_COLOR 2
#define TEXT_EDIITEXT_HINT_COLOR 7
#define TEXT_EDITTEXT_COLOR 4

#define DRAW_COLOR 15

// define ban phim
#define ENTER  13
#define BACKSPACE  8
#define SPACE  32
#define KEYUP 38
#define KEYDOWN 40

// Constants for closegraph
// #define CURRENT_WINDOW -1
// #define ALL_WINDOWS -2
// #define NO_CURRENT_WINDOW -3

enum ScanType{ ONLY_NUMBER, ONLY_TEXT, SPACE_TEXT, TEXT_NUMBER,TEXT_NUMBER_NO_SPACE, SCAN_MALOP};
enum Display{DISPLAY_LOGIN, DISPLAY_HOCSINH, DISPLAY_GIAOVIEN,DISPLAY_DSMON,DISPLAY_DSLOP,DISPLAY_DSSV};
// enum DisplayGV{MON_HOC,DS_LOP,DIEM_THI,CAU_HOI_THI,THI_THU};