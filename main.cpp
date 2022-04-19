using namespace std;
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>

#include "struct.h"
#include "define.h"
#include "Button.h"
#include "EditText.h"
#include "Scan.h"
#include "local.h"
#include "lop.h"
#include "sinhvien.h"
#include "monhoc.h"

#include "displayHocSinh.h"
#include "displayGiaoVien.h"
#include "displayLogin.h"


int main()
{
    // 1600 * 900 la do phan giai man hinh 14 inch (ti le 16/9)
    initwindow(1600, 900, "THI TRAC NGHIEM");
    
    dslop DanhSachLop;
    docFileDsLop(DanhSachLop);


    ListMonHoc listMH;
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
        else if (curMenu == btnMenuThemMon.id)
        {
            DisplayMonHoc(listMH);
        }
        else if (curMenu == btnDsLop.id)
        {
            DisplayLop(DanhSachLop);
        }
        Sleep(75);
    }
}