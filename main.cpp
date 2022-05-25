using namespace std;
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <direct.h> //Thu vien tao FOLDER
#include <fstream>
#include <ctime>
#include <cmath>
#include <thread>

#include "define.h"
#include "struct.h"
#include "random.h"

#include "Button.h"
#include "EditText.h"
#include "RadioButon.h"
#include "Scan.h"
#include "local.h"

#include "cauhoi.h"
#include "diem.h"
#include "baithi.h"
#include "sinhvien.h"
#include "monhoc.h"
#include "lop.h"

#include "drawUI.h"
#include "displayHocSinh.h"
#include "displayGiaoVien.h"
#include "displayLogin.h"

//Bien dich thu cong bang tay qua lenh CMD
//g++ -std=c++17 main.cpp -o main -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

int main()
{
    //1600 * 900 la do phan giai man hinh 14 inch (Ti le 16/9)
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    mainWindow = initwindow(1600, 900, "THI TRAC NGHIEM", GetSystemMetrics(SM_CXSCREEN) /2 - 800);
    mkdir("DATA");
    mkdir("DATA\\FileDSDiem");
    mkdir("DATA\\FileDSSinhVien");

    srand((int)time(0));

    dslop DanhSachLop;
    docFileDsLop(DanhSachLop);

    ListMonHoc listMH;
    Doc_File_Mon_Hoc(listMH);

    IDRandom *listID = Tao_MIN_MAX(listID, MIN_ID, MAX_ID);
    NodeCauHoi *rootCayCauHoi = nullptr;
    Doc_File_Cau_Hoi(rootCayCauHoi, listID);

    mangCauHoi arrCauHoi;

    Diem_Thi gvThiThu;

    drawLogin();
    while (true)
    {
        GetAsyncKeyState(VK_RBUTTON);
        KbEvent();
        if (curMenu == DISPLAY_LOGIN)
        {
            displayLogin(listMH, DanhSachLop, listID, rootCayCauHoi, arrCauHoi);
        }
        else if (curMenu == DISPLAY_GIAOVIEN)
        {
            displayGV();
        }
        else if (curMenu == DISPLAY_DSMON)
        {
            DisplayMonHoc(rootCayCauHoi, listMH);
        }
        else if (curMenu == DISPLAY_DSLOP)
        {
            DisplayLop(DanhSachLop);
        }
        else if (curMenu == DISPLAY_DIEMMON || curMenu == LUACHON_MON)
        {
            //Lua chon 1 mon roi den tinh nang khac
            displayLuaChonMon(listMH);
        }
        else if (curMenu == LUACHON_LOP)
        {
            // xem diem theo mon cho ca 1 lop
            displayLuaChonLop1(DanhSachLop, listMH.monHoc[luaChonMon]->MAMH, listMH.monHoc[luaChonMon]->TENMH);
        }
        else if (curMenu == DISLPAY_DIEM_THEO_SV ) {
            // chon lop roi chon sv, roi xem toan bo DIEM cac mon da thi
            displayLuaChonLop2(DanhSachLop, listMH);
        }
        else if (curMenu == DISPLAY_DSDIEMGV)
        {
            diplayDsDiem(listMH.monHoc[luaChonMon]->MAMH, DanhSachLop.arrLop[luaChonLop]);
        }
        else if (curMenu == CHUCNANG_CAUHOI)
        {
            displayChucNangCauHoi(rootCayCauHoi, listID, listMH);
        }
        else if (curMenu == DISPLAY_THITHU)
        {
            displayThietLapThiThu(listMH, rootCayCauHoi, arrCauHoi, gvThiThu);
        }
        else if (curMenu == VAO_THITHU)
        {
            displayThiThu(gvThiThu);
        }
        else if (curMenu == XEMBAI_THUTHU)
        {
            displayXemBaiThiThu(gvThiThu);
        }
        
        if (preMenu == VAO_THITHU)
        {
            timer.join();
            chamBai(gvThiThu);
            preMenu = -1;
        }
        Sleep(75);
    }
}