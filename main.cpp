using namespace std;
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>

// #include "struct.h"
#include "define.h"
#include "Button.h"
#include "EditText.h"
#include "Scan.h"
#include "local.h"
#include "lop.h"
#include "sinhvien.h"


#include "displayHocSinh.h"
#include "displayGiaoVien.h"
#include "displayLogin.h"


void Event() {
    KbEvent();

    if ( curMenu == DISPLAY_LOGIN) {
        displayLogin();
    }
    else if ( curMenu == DISPLAY_HOCSINH) {
        displayHocSinh();
    }
    else if ( curMenu == DISPLAY_GIAOVIEN) {
        displayGV();
    }
    else if ( curGV == MON_HOC) {
        DisplayMonHoc();
    }


}

int main() {
    // 1600 * 900 la do phan giai man hinh 14 inch (ti le 16/9)
    initwindow(1600, 900, "THI TRAC NGHIEM");
    int i = 0;
    drawLogin();
    while (true)
    {
        Event();
        Sleep(50);
        cout << i++ << endl;
    }

    getch();
}