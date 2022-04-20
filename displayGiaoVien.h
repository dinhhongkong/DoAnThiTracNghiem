//

void DrawThemMonHoc();
void drawMonHoc();
void drawLop();

void displayGV()
{
    btnMonHoc.ButtonEffect();
    btnDsLop.ButtonEffect();
    btnDiemThi.ButtonEffect();
    btnCauHoiThi.ButtonEffect();
    btnThiThu.ButtonEffect();
    btnDangXuat.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnDangXuat.isMouseHover())
        {
            curMenu = DISPLAY_LOGIN;
            drawLogin();
        }
        if (btnMonHoc.isMouseHover())
        {
            curMenu = btnMenuThemMon.id;
            drawList = true;
            drawMonHoc();
        }
        if (btnDsLop.isMouseHover())
        {
            curMenu = btnDsLop.id;
            drawList = true;
            drawLop();
        }
    }
}

//------------------------------------------------CHUC NANG QUAN LI MON HOC----------------------------------------
void DrawThemMonHoc()
{
    setfillstyle(LTSLASH_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);
    outtextxy(1170, 230, "THEM MON HOC");
    line(1050, 300, 1550, 300);

    line(1050, 600, 1550, 600);
    btnThem.draw();
    themMaMon.draw();
    themTenMon.draw();

    themMaMon.setNext(&themTenMon);
    themTenMon.setNext(&themMaMon);
    themMaMon.setPre(&themTenMon);
    themTenMon.setPre(&themMaMon);
}

void drawMonHoc()
{
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    string nameApp = "DANH SACH MON HOC";
    outtextxy(200, 20, &nameApp[0]);
    btnQuaylai.draw();
    timKiemMon.draw();
    btnMenuThemMon.draw();
    btnLui.draw();
    btnTien.draw();
    line(1000, 0, 1000, 900);
    line(300, 200, 300, 760);
    rectangle(50, 200, 950, 760);
    // ve gach ngang
    line(50, 250, 950, 250);
    outtextxy(xDsMon[0] + 85, 210, "MA MON");
    outtextxy(550, 210, "TEN MON HOC");
}

int soTrangMon = 0;
void drawDSMonHoc(ListMonHoc listMH)
{
    setfillstyle(1, BLACK);
    // setfillstyle(2, WHITE);
    bar(xDsMon[0] + 5, yDsMon[0] + 5, xDsMon[1] - 5, 760 - 5);
    bar(xDsMon[1] + 5, yDsMon[0] + 5, 950 - 5 - 5, 760 - 5);
    if (listMH.slmh <= 10)
    {
        soTrangMon = 1;
    }
    else if (btnTien.click && listMH.slmh > soTrangMon * 10 && timKiemMon.content.size() == 0)
    {
        soTrangMon++;
        btnTien.click = false;
    }
    else if (btnLui.click && soTrangMon > 1 && timKiemLop.content.size() == 0)
    {
        soTrangMon--;
    }
    btnTien.click = false;
    btnLui.click = false;

    string textTrang = to_string(soTrangMon);
    textTrang += "/" + to_string((listMH.slmh % 10 == 0) ? ((listMH.slmh < 10) ? 1 : listMH.slmh / 10) : (listMH.slmh / 10 + 1));
    // thu nghiem xoa so trang:   setfillstyle(4, YELLOW);
    bar(425, 825, 500, 850);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    listviewDS.size = 0;

    if (timKiemMon.content.size() == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i + (soTrangMon - 1) * 10 >= listMH.slmh)
            {
                break;
            }
            // CHINH SUA LAI
            listviewDS.size++;
            listviewDS.idItem[i] = i + (soTrangMon - 1) * 10;

            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + i * 50, &listMH.monHoc[i + (soTrangMon - 1) * 10]->MAMH[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + i * 50, &listMH.monHoc[i + (soTrangMon - 1) * 10]->TENMH[0]);
        }
        outtextxy(450, 825, &textTrang[0]);
    }
    else
    {
        int j = 0;
        for (int i = 0; i < listMH.slmh; i++)
        {
            if (j >= 10)
            {
                break;
            }

            // if (DanhSachLop.arrLop[i].MALOP.find(timKiemLop.content) != string::npos || DanhSachLop.arrLop[i].TENLOP.find(timKiemLop.content) != string::npos)
            // {
            //     listviewDS.size++;
            //     listviewDS.idItem[j] = i;

            //     outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].MALOP[0]);
            //     outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].TENLOP[0]);
            //     j++;
            // }
        }
    }
}

int ClickItemMonHoc(ListMonHoc &listMH)
{
    int x = -1, y = -1;
    x = mousex();
    y = mousey();
    static int LuaChon = -1; // cai thanh sang khi di chuot qua item
    static int PreLuaChon = -1;

    LuaChon = (y - yDsMon[0]) / 50;

    if (x > xDsMon[0] && x < xDsMon[2] && y > yDsMon[0] && y < yDsMon[1])
    {
        // khoi phuc item
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        //                                                              can chinh sua|
        if (PreLuaChon != -1 && PreLuaChon != LuaChon && PreLuaChon < listviewDS.size)
        {
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            bar(xDsMon[0] + 5, yDsMon[0] + 20 + PreLuaChon * 50 - 10, xDsMon[2] - 5, yDsMon[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->MAMH[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->TENMH[0]);
        }

        PreLuaChon = LuaChon;
        // ve item hien tai
        if (PreLuaChon != -1 && LuaChon < listviewDS.size)
        {
            setcolor(LIGHTGREEN);
            setfillstyle(1, RED);
            setbkcolor(RED);
            bar(xDsMon[0] + 5, yDsMon[0] + 20 + PreLuaChon * 50 - 10, xDsMon[2] - 5, yDsMon[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + LuaChon * 50, &listMH.monHoc[listviewDS.idItem[LuaChon]]->MAMH[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + LuaChon * 50, &listMH.monHoc[listviewDS.idItem[LuaChon]]->TENMH[0]);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(300, 200, 300, 760);

        // if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size)
        // {
        //     Sleep(20);
        //     themMaLop.content = DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].MALOP;
        //     themTenLop.content = DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].TENLOP;
        //     drawHieuChinhLop();
        //     while (true)
        //     {
        //         KbEvent();
        //         btnHieuChinh.ButtonEffect();
        //         btnXoaVinhVien.ButtonEffect();
        //         btnThoat.ButtonEffect();
        //         GetAsyncKeyState(VK_RBUTTON); // xoa bo nho dem chuot trai
        //         if (GetAsyncKeyState(VK_LBUTTON))
        //         {
        //             if (btnXoaVinhVien.isMouseHover())
        //             {
        //             }
        //             else if (btnHieuChinh.isMouseHover())
        //             {
        //                 // chua bat truong hop
        //                 chinhSuaLop( (DanhSachLop.arrLop[listviewDS.idItem[LuaChon]]), themMaLop.ToString(), themTenLop.ToString());
        //                 drawDSLop(DanhSachLop);
        //             }
        //             else if (btnThoat.isMouseHover())
        //             {
        //                 btnMenuThemLop.click = true;
        //                 setfillstyle(1, BLACK);
        //                 bar(1005, 0, 1600, 765);
        //                 themMaLop.content = "";
        //                 themTenLop.content = "";
        //                 btnMenuThemLop.draw();
        //                 Sleep(100);
        //                 drawThemLop();
        //                 break;
        //             }
        //             else if (themMaLop.isMouseHover())
        //             {
        //                 Edit = &themMaLop;
        //             }
        //             else if (themTenLop.isMouseHover())
        //             {
        //                 Edit = &themTenLop;
        //             }
        //         }
        //         Sleep(75);
        //     }
        // }
    }
    else
    {
        // khoi phuc item
        if (PreLuaChon != -1 && PreLuaChon < listviewDS.size)
        {
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            bar(xDsLop[0] + 5, yDsLop[0] + 20 + PreLuaChon * 50 - 10, xDsLop[2] - 5, yDsLop[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->MAMH[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->TENMH[0]);
        }
        LuaChon = -1;
        PreLuaChon = -1;
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(300, 200, 300, 760);
    }
    return -1;
}

void DisplayMonHoc(ListMonHoc &listMH)
{
    // tim kiem theo nhap tu ban phim, xuat ra man hinh luon
    static int checkTimKiem = 0;
    if (drawList == true)
    {
        drawDSMonHoc(listMH);
        drawList = false;
        if (checkTimKiem < 0)
        {
            checkTimKiem = 0;
        }
    }
    if (timKiemLop.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (timKiemLop.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (timKiemLop.content.size() < checkTimKiem)
    {
        checkTimKiem -= 2;
        drawList = true;
    }

    ClickItemMonHoc(listMH);

    btnQuaylai.ButtonEffect();
    btnMenuThemMon.ButtonEffect();
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            curMenu = DISPLAY_GIAOVIEN;
            drawGV();
            btnMenuThemMon.click = false;
            Edit = nullptr;
            themMaMon.content = "";
            themTenMon.content = "";
            timKiemMon.content = "";
            drawList = true;
        }
        if (btnMenuThemMon.isMouseHover())
        {
            DrawThemMonHoc();
            btnMenuThemMon.click = true;
        }
    }

    if (btnMenuThemMon.click)
    {
        btnThem.ButtonEffect();
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (themMaMon.isMouseHover())
            {
                Edit = &themMaMon;
                themTenMon.isChoose = false;
                themTenMon.draw();
            }
            else if (themTenMon.isMouseHover())
            {
                Edit = &themTenMon;
                themMaMon.isChoose = false;
                themMaMon.draw();
            }
            else if (btnThem.isMouseHover())
            {
                if (themMaMon.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong MA MON HOC", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themMaMon;
                    themTenMon.isChoose = false;
                }
                else if (themTenMon.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong TEN MON HOC", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themTenMon;
                    themMaMon.isChoose = false;
                }
                else
                {
                    // Them mon hoc
                    Mon_Hoc mh;
                    mh.MAMH = themMaMon.ToString();
                    mh.TENMH = themTenMon.ToString();

                    Them_Mon_Hoc(listMH, mh);
                    // Luu_File_Mon_Hoc(listMH);
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_ICONASTERISK | MB_OK);
                    drawList = true;
                    themMaMon.content = "";
                    themTenMon.content = "";
                    themMaMon.draw();
                    themTenMon.draw();
                }
            }
        }
    }
}

//--------------------------------------------------CHUC NANG QUAN LY LOP---------------------------------------

void drawLop()
{
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    outtextxy(250, 20, "DANH SACH LOP");
    btnQuaylai.draw();
    // timKiemMon.draw();
    btnMenuThemLop.draw();
    btnLui.draw();
    btnTien.draw();
    timKiemLop.draw();
    line(1000, 0, 1000, 900);

    rectangle(50, 200, 950, 760);
    // ve ma lop
    line(350, 200, 350, 760);
    // ve gach ngang
    line(50, 250, 950, 250);
    outtextxy(xDsLop[0] + 80, 215, "MA LOP");
    outtextxy(xDsLop[1] + 225, 215, "TEN LOP");
}

void drawThemLop()
{
    setfillstyle(1, BLACK);
    bar(1005, 75, 1600, 765);
    setfillstyle(LTSLASH_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);

    outtextxy(1170, 230, "THEM LOP HOC");
    line(1050, 300, 1550, 300);
    line(1050, 600, 1550, 600);
    btnThem.draw();
    themMaLop.draw();
    themTenLop.draw();

    themMaLop.setNext(&themTenLop);
    themTenLop.setNext(&themMaLop);
    themMaLop.setPre(&themTenLop);
    themTenLop.setPre(&themMaLop);
}

int soTrangLop = 1;
void drawDSLop(dslop DanhSachLop)
{
    setfillstyle(1, BLACK);
    bar(xDsLop[0] + 5, yDsLop[0] + 5, xDsLop[1] - 5, 760 - 5);
    bar(xDsLop[1] + 5, yDsLop[0] + 5, 950 - 5 - 5, 760 - 5);

    if (DanhSachLop.solop <= 10)
    {
        soTrangLop = 1;
    }
    else if (btnTien.click && DanhSachLop.solop > soTrangLop * 10 && timKiemLop.content.size() == 0)
    {
        soTrangLop++;
        btnTien.click = false;
    }
    else if (btnLui.click && soTrangLop > 1 && timKiemLop.content.size() == 0)
    {
        soTrangLop--;
    }
    btnTien.click = false;
    btnLui.click = false;

    string textTrang = to_string(soTrangLop);
    textTrang += "/" + to_string((DanhSachLop.solop % 10 == 0) ? ((DanhSachLop.solop < 10) ? 1 : DanhSachLop.solop / 10) : (DanhSachLop.solop / 10 + 1));
    // thu nghiem xoa so trang:   setfillstyle(4, YELLOW);
    bar(425, 825, 500, 850);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    listviewDS.size = 0;

    if (timKiemLop.content.size() == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i + (soTrangLop - 1) * 10 >= DanhSachLop.solop)
            {
                break;
            }
            listviewDS.size++;
            listviewDS.idItem[i] = i + (soTrangLop - 1) * 10;

            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + i * 50, &DanhSachLop.arrLop[i + (soTrangLop - 1) * 10].MALOP[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + i * 50, &DanhSachLop.arrLop[i + (soTrangLop - 1) * 10].TENLOP[0]);
        }
        outtextxy(450, 825, &textTrang[0]);
    }
    else
    {
        int j = 0;
        for (int i = 0; i < DanhSachLop.solop; i++)
        {
            if (j >= 10)
            {
                break;
            }

            if (DanhSachLop.arrLop[i].MALOP.find(timKiemLop.content) != string::npos || DanhSachLop.arrLop[i].TENLOP.find(timKiemLop.content) != string::npos)
            {
                listviewDS.size++;
                listviewDS.idItem[j] = i;

                outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].MALOP[0]);
                outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].TENLOP[0]);
                j++;
            }
        }
    }
}

void drawSinhVien() {
    setbkcolor(BLACK);
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    outtextxy(250, 20, "DANH SACH SV");
    btnQuaylai.draw();
    timKiemSV.draw();
    btnMenuThemSV.draw();
    btnLui.draw();
    btnTien.draw();
    line(1000, 0, 1000, 900);
    rectangle(50, 200, 950, 760);
    // ve ma sv
    line(200, 200, 200, 760);
    // ve ho sv
    line(500, 200, 500, 760);
    // ve ten sv
    line(650, 200, 650, 760);
    // ve gach ngang
    line(50, 250, 950, 250);
    outtextxy(xDsSV[0] + 50, 215, "MSSV");
    outtextxy(xDsSV[1] + 130, 215, "HO");
    outtextxy(xDsSV[2] + 55, 215, "TEN");


}

void drawHieuChinhLop()
{
    setfillstyle(1, BLACK);
    bar(1005, 0, 1600, 765); // 75 tai y neu thay menu
    setfillstyle(LTSLASH_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);
    outtextxy(1080, 230, "HIEU CHINH LOP HOC");
    line(1050, 300, 1550, 300);
    line(1050, 600, 1550, 600);
    themMaLop.draw();
    themTenLop.draw();
    btnHieuChinh.draw();
    btnXoaVinhVien.draw();
    btnThoat.draw();
}

int ClickItemLop(dslop &DanhSachLop)
{
    int x = -1, y = -1;
    x = mousex();
    y = mousey();
    static int LuaChon = -1; // cai thanh sang khi di chuot qua item
    static int PreLuaChon = -1;

    LuaChon = (y - yDsLop[0]) / 50;

    if (x > xDsLop[0] && x < xDsLop[2] && y > yDsLop[0] && y < yDsLop[1])
    {
        // khoi phuc item
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        if (PreLuaChon != -1 && PreLuaChon != LuaChon && PreLuaChon < listviewDS.size)
        {
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            bar(xDsLop[0] + 5, yDsLop[0] + 20 + PreLuaChon * 50 - 10, xDsLop[2] - 5, yDsLop[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[PreLuaChon]].MALOP[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[PreLuaChon]].TENLOP[0]);
        }

        PreLuaChon = LuaChon;
        // ve item hien tai
        if (PreLuaChon != -1 && LuaChon < listviewDS.size)
        {
            setcolor(LIGHTGREEN);
            setfillstyle(1, RED);
            setbkcolor(RED);
            bar(xDsLop[0] + 5, yDsLop[0] + 20 + PreLuaChon * 50 - 10, xDsLop[2] - 5, yDsLop[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + LuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].MALOP[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + LuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].TENLOP[0]);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(350, 200, 350, 760);

        if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size)
        {
            Sleep(20);
            themMaLop.content = DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].MALOP;
            themTenLop.content = DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].TENLOP;
            drawHieuChinhLop();
            while (true)
            {
                KbEvent();
                btnHieuChinh.ButtonEffect();
                btnXoaVinhVien.ButtonEffect();
                btnThoat.ButtonEffect();
                btnQuaylai.ButtonEffect();
                GetAsyncKeyState(VK_RBUTTON); // xoa bo nho dem chuot trai
                if (GetAsyncKeyState(VK_LBUTTON))
                {
                    if (btnXoaVinhVien.isMouseHover())
                    {
                    }
                    else if (btnQuaylai.isMouseHover())
                    {
                        curMenu = DISPLAY_GIAOVIEN;
                        btnMenuThemLop.click = false;
                        drawGV();
                        Edit = nullptr;
                        themMaLop.content = "";
                        themTenLop.content = "";
                        timKiemLop.content = "";
                        soTrangLop = 1;
                        break;
                    }
                    else if (btnHieuChinh.isMouseHover())
                    {
                        // chua bat truong hop
                        chinhSuaLop((DanhSachLop.arrLop[listviewDS.idItem[LuaChon]]), themMaLop.ToString(), themTenLop.ToString());
                        drawDSLop(DanhSachLop);
                    }
                    else if (btnThoat.isMouseHover())
                    {
                        btnMenuThemLop.click = true;
                        setfillstyle(1, BLACK);
                        bar(1005, 0, 1600, 765);
                        themMaLop.content = "";
                        themTenLop.content = "";
                        btnMenuThemLop.draw();
                        Sleep(100);
                        drawThemLop();
                        break;
                    }
                    else if (themMaLop.isMouseHover())
                    {
                        Edit = &themMaLop;
                    }
                    else if (themTenLop.isMouseHover())
                    {
                        Edit = &themTenLop;
                    }
                }
                Sleep(75);
            }
        }
        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size) {
            drawSinhVien();
            while (true)
            {
                btnQuaylai.ButtonEffect();
                btnLui.ButtonEffect();
                btnTien.ButtonEffect();
                if (GetAsyncKeyState(VK_LBUTTON)) {
                    if ( btnQuaylai.isMouseHover()) {
                        drawLop();
                        Sleep(200);
                        drawList = true;
                        break;
                    }
                }
            }
            

        }
    }
    else
    {
        // khoi phuc item
        if (PreLuaChon != -1 && PreLuaChon < listviewDS.size)
        {
            settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            bar(xDsLop[0] + 5, yDsLop[0] + 20 + PreLuaChon * 50 - 10, xDsLop[2] - 5, yDsLop[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[PreLuaChon]].MALOP[0]);
            outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + PreLuaChon * 50, &DanhSachLop.arrLop[listviewDS.idItem[PreLuaChon]].TENLOP[0]);
        }
        LuaChon = -1;
        PreLuaChon = -1;
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(350, 200, 350, 760);
    }
    return -1;
}

void DisplayLop(dslop &DanhSachLop)
{
    // tim kiem theo nhap tu ban phim, xuat ra man hinh luon
    static int checkTimKiem = 0;
    if (drawList == true)
    {
        drawDSLop(DanhSachLop);
        drawList = false;
        if (checkTimKiem < 0)
        {
            checkTimKiem = 0;
        }
    }
    if (timKiemLop.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (timKiemLop.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (timKiemLop.content.size() < checkTimKiem)
    {
        checkTimKiem -= 2;
        drawList = true;
    }

    ClickItemLop(DanhSachLop);

    setfillstyle(1, LIGHTGRAY);
    btnQuaylai.ButtonEffect();
    btnLui.ButtonEffect();
    btnTien.ButtonEffect();
    btnMenuThemLop.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            curMenu = DISPLAY_GIAOVIEN;
            btnMenuThemLop.click = false;
            drawGV();
            Edit = nullptr;
            themMaLop.content = "";
            themTenLop.content = "";
            timKiemLop.content = "";
            soTrangLop = 1;
        }
        else if (btnMenuThemLop.isMouseHover())
        {
            drawThemLop();
            btnMenuThemLop.click = true;
        }
        else if (timKiemLop.isMouseHover())
        {
            timKiemLop.isChoose = true;
            timKiemLop.draw();
            Edit = &timKiemLop;
        }
        else if (btnTien.isMouseHover())
        {
            drawList = true;
            btnTien.click = true;
            btnLui.click = false;
        }
        else if (btnLui.isMouseHover())
        {
            drawList = true;
            btnLui.click = true;
            btnTien.click = false;
        }
    }

    if (btnMenuThemLop.click)
    {
        btnThem.ButtonEffect();
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (themMaLop.isMouseHover())
            {
                Edit = &themMaLop;
                themMaLop.isChoose = false;
                themMaLop.draw();
            }
            else if (themTenLop.isMouseHover())
            {
                Edit = &themTenLop;
                themTenLop.isChoose = false;
                themTenLop.draw();
            }

            else if (btnThem.isMouseHover())
            {

                if (themMaLop.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong MA LOP", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themMaLop;
                    themTenLop.isChoose = false;
                }
                else if (themTenLop.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong TEN LOP", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themTenLop;
                    themMaLop.isChoose = false;
                }
                else if (ThemVaoDanhSach(DanhSachLop, themMaLop.ToString(), themTenLop.ToString()))
                {
                    ghiFileDSlop(DanhSachLop); // ghi vao file

                    themTenLop.content = "";
                    themMaLop.content = "";
                    themMaLop.draw();
                    themTenLop.draw();
                    drawList = true;
                }
            }
        }
    }
}