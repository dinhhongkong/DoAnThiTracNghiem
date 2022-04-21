//

// void DrawThemMonHoc();
// void drawMonHoc();
// void drawLop();

void displaySinhVien(listSV &danhSachSV, string maLop);

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
            curMenu = DISPLAY_DSMON;
            drawList = true;
            drawMonHoc();
        }
        if (btnDsLop.isMouseHover())
        {
            curMenu = DISPLAY_DSLOP;
            drawList = true;
            drawLop();
        }
    }
}

//------------------------------------------------CHUC NANG QUAN LI MON HOC----------------------------------------

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
            }
            else if (themTenMon.isMouseHover())
            {
                Edit = &themTenMon;
            }
            else if (btnThem.isMouseHover())
            {
                if (themMaMon.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong MA MON HOC", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themMaMon;
                }
                else if (themTenMon.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong TEN MON HOC", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themTenMon;
                }
                else
                {
                    // Them mon hoc
                    Mon_Hoc mh;
                    mh.MAMH = themMaMon.ToString();
                    mh.TENMH = themTenMon.ToString();

                    Them_Mon_Hoc(listMH, mh);
                    Luu_File_Mon_Hoc(listMH);
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

        // bat su kien khi click vao item khi click chuot tra hoac chuot phai
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
                        AllocConsole();
                        if ( MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ban chac chan muon XOA", "Thong bao", MB_ICONQUESTION | MB_OKCANCEL) == IDOK) {
                            xoaLop(DanhSachLop, listviewDS.idItem[LuaChon]);
                            drawDSLop(DanhSachLop);

                            btnMenuThemLop.click = true;
                            setfillstyle(1, BLACK);
                            bar(1005, 0, 1600, 765);
                            themMaLop.content = "";
                            themTenLop.content = "";
                            btnMenuThemLop.draw();
                            drawThemLop();
                            break;
                        }
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
                        chinhSuaLop(DanhSachLop,(DanhSachLop.arrLop[listviewDS.idItem[LuaChon]]), themMaLop.ToString(), themTenLop.ToString());
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
        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size)
        {
            btnMenuThemLop.click = false;
            drawSinhVien();
            curMenu = DISPLAY_DSSV;
            drawThemSinhVien();
            while (true)
            {
                KbEvent();
                displaySinhVien(DanhSachLop.arrLop[LuaChon].dsSinhVien,DanhSachLop.arrLop[LuaChon].MALOP);
                if ( btnQuaylai.click) {
                    btnQuaylai.click = false;
                    break;
                }
                Sleep(75);
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

    // Bat su kien khi click item trong cai listView
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
            }
            else if (themTenLop.isMouseHover())
            {
                Edit = &themTenLop;
            }

            else if (btnThem.isMouseHover())
            {

                if (themMaLop.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong MA LOP", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themMaLop;
                }
                else if (themTenLop.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong TEN LOP", "Thong bao", MB_ICONASTERISK | MB_OK);
                    Edit = &themTenLop;
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


//---------------------------------------------------CHUC NANG SINH VIEN--------------------------------------

void displaySinhVien(listSV &danhSachSV, string maLop)
{
    btnQuaylai.ButtonEffect();
    btnLui.ButtonEffect();
    btnTien.ButtonEffect();
    btnMenuThemSV.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            curMenu = DISPLAY_DSLOP;
            drawLop();
            Sleep(200);
            drawList = true;
            Edit = nullptr;
            edMSSV.content = "";
            edHoSV.content = "";
            edTenSV.content = "";
            edtimKiemSV.content = "";
            btnNam.click = false;
            btnNu.click = false;
            btnQuaylai.click = true;
        }
        else if (edtimKiemSV.isMouseHover())
        {
            Edit = &edtimKiemSV;
        }
    }
    if (btnMenuThemSV.click)
    {
        btnNam.ButtonEffect();
        btnNu.ButtonEffect();
        btnThem.ButtonEffect();
        if (GetAsyncKeyState(VK_LBUTTON))
        {
            if (edMSSV.isMouseHover())
            {
                Edit = &edMSSV;
            }
            else if (edHoSV.isMouseHover())
            {
                Edit = &edHoSV;
            }
            else if (edTenSV.isMouseHover())
            {
                Edit = &edTenSV;
            }
            else if ( btnNam.isMouseHover() ) {
                btnNam.click = true;
                btnNu.click = false;
                btnNam.draw();
                btnNu.draw();
                
            }
            else if ( btnNu.isMouseHover()) {
                btnNam.click = false;
                btnNu.click = true;
                btnNam.draw();
                btnNu.draw();
            }
            else if ( btnThem.isMouseHover()) {
                if ( edMSSV.content.size() == 0) {

                }
                else if ( edHoSV.content.size() == 0) {

                }
                else if ( edTenSV.content.size() == 0) {

                }
                else if (!btnNam.click && !btnNu.click) {

                }
                else {
                    sinhVien sv;
                    sv.mssv = edMSSV.ToString();
                    sv.Ho = edHoSV.ToString();
                    sv.Ten = edTenSV.ToString();
                    sv.gioiTinh = (btnNam.click ? 0 : 1);
                    // pass mac dinh la mssv;
                    // sv.Pass = sv.mssv;
                    sv.Pass = "mk";
                    InsertNodeSV(danhSachSV,sv);
                    ghiFileDsSinhVien(danhSachSV,maLop);
                    
                }

            }
        }
    }
}