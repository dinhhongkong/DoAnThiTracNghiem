using namespace std;
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <direct.h> // thu vien tao folder
#include <fstream>
#include <ctime>
#include <cmath>
#include <thread>

#include "struct.h"
#include "define.h"
#include "random.h"

#include "Button.h"
#include "EditText.h"
#include "RadioButon.h"
#include "Scan.h"
#include "local.h"

#include "cauhoi.h"
#include "baithi.h"
#include "sinhvien.h"
#include "monhoc.h"
#include "lop.h"

#include "drawUI.h"
#include "displayHocSinh.h"
#include "displayGiaoVien.h"
#include "displayLogin.h"

// Bien dich thu cong bang tay qua lenh CMD
// g++ -std=c++17 main.cpp -o main -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
//AllocConsole();
//MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thong tin sinh vien thanh cong", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
int main()
{
    // 1600 * 900 la do phan giai man hinh 14 inch (ti le 16/9)
    initwindow(1600, 900, "THI TRAC NGHIEM");
    // Tao folder de luu du lieu
    mkdir("DATA") ;
    mkdir("DATA\\bai thi") ;
    srand((int)time(0));

    dslop DanhSachLop;
    docFileDsLop(DanhSachLop);

    ListMonHoc listMH;
    Doc_File_Mon_Hoc(listMH);

    int arrID[MAX_RANDOM];
    docFileRandom(arrID);

    NodeCauHoi *rootCayCauHoi;
    drawLogin();
    while (true)
    {
        GetAsyncKeyState(VK_RBUTTON);
        KbEvent();
        if (curMenu == DISPLAY_LOGIN)   
        {
            displayLogin(listMH, DanhSachLop, arrID);
        }
        else if (curMenu == DISPLAY_GIAOVIEN)
        {
            displayGV();
        }
        else if (curMenu == DISPLAY_DSMON)
        {
            DisplayMonHoc(rootCayCauHoi ,listMH);
        }
        else if (curMenu == DISPLAY_DSLOP)
        {
            DisplayLop(DanhSachLop);
        }
        else if ( curMenu == DISPLAY_DIEMMON || curMenu == LUACHON_MON ) {
            // Lua chon 1 mon roi den tinh nang khac
            displayLuaChonMon(listMH);
        }
        else if ( curMenu == LUACHON_LOP) {
            displayLuaChonLop(DanhSachLop, listMH.monHoc[luaChonMon]->MAMH ,listMH.monHoc[luaChonMon]->TENMH);
        }
        else if ( curMenu == DISPLAY_DSDIEMGV) {
            diplayDsDiem(listMH.monHoc[luaChonMon]->MAMH, DanhSachLop.arrLop[luaChonLop]);
        }
        else if ( curMenu == CHUCNANG_CAUHOI) {
            displayChucNangCauHoi(rootCayCauHoi ,arrID);
        }
        else if ( curMenu == DISPLAY_THITHU) {
            displayThietLapThiThu(listMH);
        }
        else if ( curMenu == VAO_THITHU) {
            displayThiThu();
        }
        if ( preMenu == VAO_THITHU) {
            timer.join();
            preMenu = -1;
        }
        Sleep(75);
    }
}