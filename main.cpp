using namespace std;
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <direct.h> // thu vien tao folder
#include <fstream>

#include "struct.h"
#include "define.h"
#include "Button.h"
#include "EditText.h"
#include "Scan.h"
#include "local.h"
#include "sinhvien.h"
#include "monhoc.h"
#include "lop.h"

#include "drawUI.h"
#include "displayHocSinh.h"
#include "displayGiaoVien.h"
#include "displayLogin.h"
//AllocConsole();
//MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thong tin sinh vien thanh cong", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
int main()
{
    // 1600 * 900 la do phan giai man hinh 14 inch (ti le 16/9)
    initwindow(1600, 900, "THI TRAC NGHIEM");
    // Tao folder de luu du lieu
    mkdir("DATA") ;

    dslop DanhSachLop;
    docFileDsLop(DanhSachLop);

    ListMonHoc listMH;
    Doc_File_Mon_Hoc(listMH);
    
    drawLogin();
    while (true)
    {
        GetAsyncKeyState(VK_RBUTTON);
        KbEvent();
        if (curMenu == DISPLAY_LOGIN)
        {
            displayLogin();
        }
        else if (curMenu == DISPLAY_HOCSINH)
        {
            displayHocSinh();
        }
        else if (curMenu == DISPLAY_GIAOVIEN)
        {
            displayGV();
        }
        else if (curMenu == DISPLAY_DSMON)
        {
            DisplayMonHoc(listMH);
        }
        else if (curMenu == DISPLAY_DSLOP)
        {
            DisplayLop(DanhSachLop);
        }
        Sleep(75);
    }
}