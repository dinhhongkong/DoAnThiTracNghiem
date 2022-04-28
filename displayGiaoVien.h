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
    btnCaiDatThi.ButtonEffect();
    btnDangXuat.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnDangXuat.isMouseHover())
        {
            curMenu = DISPLAY_LOGIN;
            drawLogin();
        }
        else if (btnMonHoc.isMouseHover())
        {
            curMenu = DISPLAY_DSMON;
            drawList = true;
            drawMonHoc();
        }
        else if (btnDsLop.isMouseHover())
        {
            curMenu = DISPLAY_DSLOP;
            drawList = true;
            drawLop();
            Sleep(100);
        }
        else if ( btnDiemThi.isMouseHover()) {
            curMenu = DISPLAY_DIEMMON;
            drawMonHoc();
        }
        else if (btnCauHoiThi.isMouseHover()) {
            curMenu = DISPLAY_CAUHOIMON;
            drawMonHoc();
        }
        else if ( btnCaiDatThi.isMouseHover()) {
            curMenu = DISPLAY_CAIDATTHI;
            drawCaiDatThi();
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
        if (PreLuaChon != -1 && PreLuaChon != LuaChon && PreLuaChon < listviewDS.size)
        {
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            bar(xDsMon[0] + 5, yDsMon[0] + 20 + PreLuaChon * 50 - 10, xDsMon[2] - 5, yDsMon[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsMon[0] + 80, yDsMon[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->MAMH[0]);
            outtextxy(xDsMon[1] + 80, yDsMon[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->TENMH[0]);
        }

        PreLuaChon = LuaChon;
        // ve item hien tai
        if (PreLuaChon != -1 && LuaChon < listviewDS.size)
        {
            setcolor(LIGHTGREEN);
            setfillstyle(1, RED);
            setbkcolor(RED);
            bar(xDsMon[0] + 5, yDsMon[0] + 20 + PreLuaChon * 50 - 10, xDsMon[2] - 5, yDsMon[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsMon[0] + 80, yDsMon[0] + 20 + LuaChon * 50, &listMH.monHoc[listviewDS.idItem[LuaChon]]->MAMH[0]);
            outtextxy(xDsMon[1] + 80, yDsMon[0] + 20 + LuaChon * 50, &listMH.monHoc[listviewDS.idItem[LuaChon]]->TENMH[0]);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(300, 200, 300, 760);

        // bat su kien khi o man hinh danh sach mon ( co the them, hieu chinh)
        if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_DSMON)
        {
            Sleep(20);
            themMaMon.content = listMH.monHoc[listviewDS.idItem[LuaChon]]->MAMH;
            themTenMon.content = listMH.monHoc[listviewDS.idItem[LuaChon]]->TENMH;
            drawHieuChinhMonHoc();
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
                    else if (btnHieuChinh.isMouseHover())
                    {
                        if (Hieu_Chinh_Mon_Hoc(listMH, listviewDS.idItem[LuaChon], themMaMon.ToString(), themTenMon.ToString()))
                        {
                            Luu_File_Mon_Hoc(listMH);
                            AllocConsole();
                            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua mon hoc thanh cong", "Thong bao", MB_OK);
                            drawDSMonHoc(listMH);
                            themMaMon.content = "";
                            themTenMon.content = "";
                            btnMenuThemMon.click = true;
                            DrawThemMonHoc();
                            break;
                        }
                        else
                        {
                            AllocConsole();
                            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ma mon hoc hoac Ten mon hoc da ton tai", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                        }
                    }
                    else if (btnThoat.isMouseHover())
                    {
                        btnMenuThemLop.click = true;
                        setfillstyle(1, BLACK);
                        bar(1005, 0, 1600, 765);
                        themMaMon.content = "";
                        themTenMon.content = "";
                        btnMenuThemMon.draw();
                        Sleep(100);
                        DrawThemMonHoc();
                        break;
                    }
                    else if (themMaMon.isMouseHover())
                    {
                        Edit = &themMaMon;
                    }
                    else if (themTenMon.isMouseHover())
                    {
                        Edit = &themTenMon;
                    }
                    else if (btnQuaylai.isMouseHover())
                    {
                        curMenu = DISPLAY_GIAOVIEN;
                        drawGV();
                        Edit = nullptr;
                        themMaMon.content = "";
                        themTenMon.content = "";
                        timKiemMon.content = "";
                        soTrangMon = 1;
                        break;
                    }
                }
                Sleep(75);
            }
        }

        else if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_LICHTHI) {

        }
        else if ( GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_DIEMMON) {
            curMenu = LUACHON_LOP;
            drawList = true;
            drawLop();
            return listviewDS.idItem[LuaChon];

        }
        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_CAUHOIMON) {
            curMenu = CHUCNANG_CAUHOI;
            drawCauHoi(listMH.monHoc[listviewDS.idItem[LuaChon]]->MAMH,listMH.monHoc[listviewDS.idItem[LuaChon]]->TENMH );
            drawXemCauHoi();
            return listviewDS.idItem[LuaChon];
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
            bar(xDsMon[0] + 5, yDsMon[0] + 20 + PreLuaChon * 50 - 10, xDsMon[2] - 5, yDsMon[0] + 20 + PreLuaChon * 50 + 30);
            outtextxy(xDsMon[0] + 80, yDsMon[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->MAMH[0]);
            outtextxy(xDsMon[1] + 80, yDsMon[0] + 20 + PreLuaChon * 50, &listMH.monHoc[listviewDS.idItem[PreLuaChon]]->TENMH[0]);
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
    if (timKiemMon.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (timKiemMon.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (timKiemMon.content.size() < checkTimKiem)
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
            soTrangMon = 1;
        }
        else if (btnMenuThemMon.isMouseHover())
        {
            DrawThemMonHoc();
            btnMenuThemMon.click = true;
        }
        else if (timKiemMon.isMouseHover())
        {
            Edit = &timKiemMon;
        }
        else if (btnTien.isMouseHover()) {
            drawList = true;
            btnTien.click = true;
            btnLui.click = false;
        }
        else if (btnLui.isMouseHover()) {
            drawList = true;
            btnTien.click = false;
            btnLui.click = true;
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

void ClickItemLop(dslop &DanhSachLop, string tenMon = "")
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
        if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_DSLOP)
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
                        if (MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ban chac chan muon XOA", "Thong bao", MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
                        {
                            xoaLop(DanhSachLop, listviewDS.idItem[LuaChon]);
                            ghiFileDSlop(DanhSachLop);
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
                        if (chinhSuaLop(DanhSachLop, listviewDS.idItem[LuaChon], themMaLop.ToString(), themTenLop.ToString()))
                        {
                            ghiFileDSlop(DanhSachLop);
                            drawDSLop(DanhSachLop);
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
        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size && curMenu == DISPLAY_DSLOP)
        {
            btnMenuThemLop.click = false;
            drawSinhVien(DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].TENLOP);
            curMenu = DISPLAY_DSSV;
            drawThemSinhVien();
            listviewDS.click = true;
            drawList = true;
            int viTri = listviewDS.idItem[LuaChon];
            while (true)
            {
                KbEvent();
                displaySinhVien(DanhSachLop.arrLop[viTri].dsSinhVien, DanhSachLop.arrLop[viTri].MALOP);
                if (btnQuaylai.click)
                {
                    btnQuaylai.click = false;
                    break;
                }
                Sleep(75);
            }
        }

        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size && curMenu == LUACHON_LOP) {
            drawBangDiem(tenMon, DanhSachLop.arrLop[listviewDS.idItem[LuaChon]].TENLOP);
            Sleep(1000);
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
    return;
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
            drawList = true;
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

void ClickItemSinhVien(listSV &danhSachSV, string maLop)
{
    int x = -1, y = -1;
    x = mousex();
    y = mousey();
    static int LuaChon = -1; // cai thanh sang khi di chuot qua item
    static int PreLuaChon = -1;
    int soLuongSV = SizeListSV(danhSachSV);

    LuaChon = (y - yDsSV[0]) / 50;
    nodeSV *node = danhSachSV.First;

    if (x > xDsSV[0] && x < xDsSV[4] && y > yDsSV[0] && y < yDsSV[1])
    {
        // khoi phuc item
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        if (PreLuaChon != -1 && PreLuaChon != LuaChon && PreLuaChon < listviewDS.size)
        {
            setcolor(WHITE);
            setfillstyle(1, BLACK);
            setbkcolor(BLACK);
            node = danhSachSV.First;
            // for (int i = 0; i < PreLuaChon + (soTrangSV - 1) * 10; i++)
            for (int i = 0; i < listviewDS.idItem[PreLuaChon]; i++)
            {
                if (node == nullptr)
                {
                    break;
                }
                node = node->pNext;
            }

            if (node != nullptr)
            {
                bar(xDsSV[0] + 5, yDsSV[0] + 20 + PreLuaChon * 50 - 10, xDsSV[4] - 5, yDsSV[0] + 20 + PreLuaChon * 50 + 30);
                outtextxy(xDsSV[0] + 40, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.mssv[0]);
                outtextxy(xDsSV[1] + 45, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.Ho[0]);
                outtextxy(xDsSV[2] + 45, yDsSV[0] + 20 + +PreLuaChon * 50, &node->info.Ten[0]);
                if (node->info.gioiTinh == 0)
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NAM");
                }
                else
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NU");
                }
            }
        }

        PreLuaChon = LuaChon;
        // ve item hien tai
        if (PreLuaChon != -1 && LuaChon < listviewDS.size)
        {
            setcolor(LIGHTGREEN);
            setfillstyle(1, RED);
            setbkcolor(RED);
            bar(xDsSV[0] + 5, yDsSV[0] + 20 + PreLuaChon * 50 - 10, xDsSV[4] - 5, yDsSV[0] + 20 + PreLuaChon * 50 + 30);
            node = danhSachSV.First;
            for (int i = 0; i < listviewDS.idItem[LuaChon] ; i++)
            {
                if (node == nullptr)
                {
                    break;
                }
                node = node->pNext;
            }
            if (node != nullptr)
            {
                outtextxy(xDsSV[0] + 40, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.mssv[0]);
                outtextxy(xDsSV[1] + 45, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.Ho[0]);
                outtextxy(xDsSV[2] + 45, yDsSV[0] + 20 + +PreLuaChon * 50, &node->info.Ten[0]);
                if (node->info.gioiTinh == 0)
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NAM");
                }
                else
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NU");
                }
            }
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        line(250, 200, 250, 760);
        // ve ho sv
        line(600, 200, 600, 760);
        // ve ten sv
        line(800, 200, 800, 760);
        // bat su kien khi click vao item khi click chuot tra hoac chuot phai
        if (GetAsyncKeyState(VK_RBUTTON) && LuaChon < listviewDS.size)
        {
            Sleep(20);
            // node = danhSachSV.First;
            // for (int i = 0; i < PreLuaChon + (soTrangSV - 1) * 10; i++)
            // for (int i = 0; i < listviewDS.idItem[PreLuaChon]; i++)
            // {
            //     if (node == nullptr)
            //     {
            //         break;
            //     }
            //     node = node->pNext;
            // }
            edMSSV.content = node->info.mssv;
            edHoSV.content = node->info.Ho;
            edTenSV.content = node->info.Ten;
            if (node->info.gioiTinh == 0)
            {
                btnNam.click = true;
                btnNu.click = false;
            }
            else
            {
                btnNam.click = false;
                btnNu.click = true;
            }

            drawHieuChinhSV();
            while (node != nullptr)
            {
                KbEvent();
                btnHieuChinh.ButtonEffect();
                btnXoaVinhVien.ButtonEffect();
                btnThoat.ButtonEffect();
                // btnQuaylai.ButtonEffect();
                btnNam.ButtonEffect();
                btnNu.ButtonEffect();
                btnResetMK.ButtonEffect();
                GetAsyncKeyState(VK_RBUTTON); // xoa bo nho dem chuot trai
                if (GetAsyncKeyState(VK_LBUTTON))
                {
                    if (btnXoaVinhVien.isMouseHover())
                    {
                        cout << danhSachSV.First->info.mssv << endl;
                        cout << danhSachSV.Last->info.mssv << endl
                             << endl;
                        // AllocConsole();
                        // if (MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ban chac chan muon XOA", "Thong bao", MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
                        // {
                        // xoaLop(DanhSachLop, listviewDS.idItem[LuaChon]);
                        // ghiFileDSlop(DanhSachLop);
                        // drawDSLop(DanhSachLop);

                        // btnMenuThemLop.click = true;
                        // setfillstyle(1, BLACK);
                        // bar(1005, 0, 1600, 765);
                        // themMaLop.content = "";
                        // themTenLop.content = "";
                        // btnMenuThemLop.draw();
                        // drawThemLop();
                        // break;
                        // }
                    }
                    else if (btnHieuChinh.isMouseHover())
                    {
                        if (ChinhSuaSinhVien(danhSachSV, node, edMSSV.ToString(), edHoSV.ToString(), edTenSV.ToString(), btnNam.click ? 0 : 1))
                        {
                            ghiFileDsSinhVien(danhSachSV, maLop);
                            btnHieuChinh.click = true;
                            drawDsSinhVien(danhSachSV);
                            btnMenuThemSV.click = true;
                            setfillstyle(1, BLACK);
                            bar(1005, 0, 1600, 765);
                            edMSSV.content = "";
                            edHoSV.content = "";
                            edTenSV.content = "";
                            btnNam.click = false;
                            btnNu.click = false;
                            btnMenuThemSV.draw();
                            Sleep(100);
                            drawThemSinhVien();
                            break;
                        }
                    }
                    else if (btnThoat.isMouseHover())
                    {
                        btnMenuThemSV.click = true;
                        setfillstyle(1, BLACK);
                        bar(1005, 0, 1600, 765);
                        edMSSV.content = "";
                        edHoSV.content = "";
                        edTenSV.content = "";
                        btnNam.click = false;
                        btnNu.click = false;
                        btnMenuThemSV.draw();
                        Sleep(100);
                        drawThemSinhVien();
                        break;
                    }
                    else if (edMSSV.isMouseHover())
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
                    else if (btnNam.isMouseHover())
                    {
                        btnNam.click = true;
                        btnNu.click = false;
                        btnNam.draw();
                        btnNu.draw();
                    }
                    else if (btnNu.isMouseHover())
                    {
                        btnNam.click = false;
                        btnNu.click = true;
                        btnNam.draw();
                        btnNu.draw();
                    }
                    else if (btnResetMK.isMouseHover())
                    {
                        AllocConsole();
                        if (MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chuc nang nay de cap lai MK mac dinh cho sinh vien. Ban muon tiep tuc?", "Thong bao", MB_ICONQUESTION | MB_OKCANCEL) == IDOK)
                        {
                            thayDoiMK(node, "mk");
                            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Reset Mat khau thanh cong", "Thong bao", MB_OK);
                        }
                    }
                }
                Sleep(75);
            }
        }
        else if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size)
        {
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
            node = danhSachSV.First;
            // for (int i = 0; i < PreLuaChon + (soTrangSV - 1) * 10; i++)
            for (int i = 0; i < listviewDS.idItem[PreLuaChon]; i++)
            {
                if (node == nullptr)
                {
                    break;
                }
                node = node->pNext;
            }
            if (node != nullptr)
            {
                bar(xDsSV[0] + 5, yDsSV[0] + 20 + PreLuaChon * 50 - 10, xDsSV[4] - 5, yDsSV[0] + 20 + PreLuaChon * 50 + 30);
                outtextxy(xDsSV[0] + 40, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.mssv[0]);
                outtextxy(xDsSV[1] + 45, yDsSV[0] + 20 + PreLuaChon * 50, &node->info.Ho[0]);
                outtextxy(xDsSV[2] + 45, yDsSV[0] + 20 + +PreLuaChon * 50, &node->info.Ten[0]);
                if (node->info.gioiTinh == 0)
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NAM");
                }
                else
                {
                    outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + PreLuaChon * 50, "NU");
                }
            }
        }
        LuaChon = -1;
        PreLuaChon = -1;
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        // ve ma sv
        line(250, 200, 250, 760);
        // ve ho sv
        line(600, 200, 600, 760);
        // ve ten sv
        line(800, 200, 800, 760);
    }
}

void displaySinhVien(listSV &danhSachSV, string maLop)
{
    static int checkTimKiem = 0;
    if (drawList == true)
    {
        // listviewDS.size = 0;
        drawDsSinhVien(danhSachSV);
        drawList = false;
        if (checkTimKiem < 0)
        {
            checkTimKiem = 0;
        }
    }
    if (edtimKiemSV.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (edtimKiemSV.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (edtimKiemSV.content.size() < checkTimKiem)
    {
        checkTimKiem -= 2;
        drawList = true;
    }

    btnQuaylai.ButtonEffect();
    btnLui.ButtonEffect();
    btnTien.ButtonEffect();
    btnMenuThemSV.ButtonEffect();

    ClickItemSinhVien(danhSachSV, maLop);
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
            listviewDS.click = false;
        }
        else if (edtimKiemSV.isMouseHover())
        {
            Edit = &edtimKiemSV;
        }
        else if (btnTien.isMouseHover())
        {
            drawList = true;
            btnTien.click = true;
        }
        else if (btnLui.isMouseHover())
        {
            drawList = true;
            btnLui.click = true;
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
            else if (btnNam.isMouseHover())
            {
                btnNam.click = true;
                btnNu.click = false;
                btnNam.draw();
                btnNu.draw();
            }
            else if (btnNu.isMouseHover())
            {
                btnNam.click = false;
                btnNu.click = true;
                btnNam.draw();
                btnNu.draw();
            }
            else if (btnThem.isMouseHover())
            {
                if (edMSSV.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long dien MSSV", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else if (edHoSV.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long dien Ho vs Ten dem", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else if (edTenSV.content.size() == 0)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long dien Ten", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else if (!btnNam.click && !btnNu.click)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long lua chon gioi tinh", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else
                {
                    sinhVien sv;
                    sv.mssv = edMSSV.ToString();
                    sv.Ho = edHoSV.ToString();
                    sv.Ten = edTenSV.ToString();
                    sv.gioiTinh = (btnNam.click ? 0 : 1);
                    // pass mac dinh la mssv;
                    // sv.Pass = sv.mssv;
                    sv.Pass = "mk";
                    if (InsertNodeSV(danhSachSV, sv))
                    {
                        ghiFileDsSinhVien(danhSachSV, maLop);
                        edMSSV.content = "";
                        edHoSV.content = "";
                        edTenSV.content = "";
                        btnNam.click = false;
                        btnNu.click = false;
                        btnThem.click = true;
                        drawDsSinhVien(danhSachSV);
                        drawThemSinhVien();
                        Sleep(100);
                    }
                }
            }
            if ( btnMenuThemSV.isMouseHover()) {
                nodeSV *node = danhSachSV.First;
                
                while (node != nullptr) {
                    cout << node->info.mssv << endl;
                    node = node->pNext;
                }
            }
        }
    }
}

//------------------------------------------CHON 1 MON HOAC 1 LOP KHI THUC HIEN CHUC NANG KHAC------------------------------------------

int displayLuaChonMon(ListMonHoc listMH) {
    btnQuaylai.ButtonEffect();
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();
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
    if (timKiemMon.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (timKiemMon.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (timKiemMon.content.size() < checkTimKiem)
    {
        checkTimKiem -= 2;
        drawList = true;
    }
    int MonLuaChon = ClickItemMonHoc(listMH);
    if (GetAsyncKeyState(VK_LBUTTON)) {
        if ( btnQuaylai.isMouseHover() ) {
            Edit = nullptr;
            drawList = true;
            curMenu = DISPLAY_GIAOVIEN;
            drawGV();
            soTrangMon = 1;
            Sleep(200);
        }
        else if ( btnTien.isMouseHover()) {
            drawList = true;
            btnTien.click = true;
        }
        else if ( btnLui.isMouseHover()) {
            drawList = true;
            btnLui.click = true;
        }
        else if ( timKiemMon.isMouseHover()) {
            Edit = &timKiemMon;
        }
    }
    return MonLuaChon;

}

void displayLuaChonLop(dslop &DanhSachLop,string maMon ,string tenMon)  {
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
    ClickItemLop(DanhSachLop, tenMon);

    setfillstyle(1, LIGHTGRAY);
    btnQuaylai.ButtonEffect();
    btnLui.ButtonEffect();
    btnTien.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            curMenu = DISPLAY_DIEMMON;
            btnMenuThemLop.click = false;
            drawMonHoc();
            Edit = nullptr;

            timKiemLop.content = "";
            soTrangLop = 1;
            drawList = true;
            Sleep(200);
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

}

//---------------------------------------------------TUY CHINH CAU HOI THI------------------------------------------

void displayChucNangCauHoi() {
    btnQuaylai.ButtonEffect();
    btnTien_L.ButtonEffect();
    btnLui.ButtonEffect();
    btnDapAnA.ButtonEffect();
    btnDapAnB.ButtonEffect();
    btnDapAnC.ButtonEffect();
    btnDapAnD.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON)) {
        if ( btnQuaylai.isMouseHover()) {
            curMenu = DISPLAY_CAUHOIMON;
            drawList = true;
            drawMonHoc();
            Sleep(100);
        }
    }
}

//------------------------------------------------------CAI DAT THI ----------------------------------------------
void displayCaiDatThi(ListMonHoc listMH) {
    btnThietLapThi.ButtonEffect();
    btnQuaylai.ButtonEffect();
    btnThiThu.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON)) {
        if ( btnQuaylai.isMouseHover()) {
            curMenu = DISPLAY_GIAOVIEN;
            drawGV();
            drawList = true;
        }
        else if ( btnThietLapThi.isMouseHover()) {
            curMenu = DISPLAY_LICHTHI;
            drawMonHoc();
            // setfillstyle(1,BLACK);
            // bar(1175,20,1175+250,70);
            drawDSMonHoc(listMH);
            drawLichThi();
        }
        else if ( btnThiThu.isMouseHover()) {

        }
    }

}

//---------------------------------------------------CAI DAT GIO THI----------------------------------------------------

void displayThietLapLichThi(ListMonHoc listMH) {
    btnQuaylai.ButtonEffect();
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();
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
    if (timKiemMon.content.size() > checkTimKiem)
    {
        checkTimKiem++;
        drawList = true;
    }
    else if (timKiemMon.content.size() == checkTimKiem)
    {
        drawList = false;
    }
    else if (timKiemMon.content.size() < checkTimKiem)
    {
        checkTimKiem -= 2;
        drawList = true;
    }

    ClickItemMonHoc(listMH);
    if (GetAsyncKeyState(VK_LBUTTON)) {
        if ( btnQuaylai.isMouseHover()) {
            curMenu = DISPLAY_CAIDATTHI;
            drawCaiDatThi();
            Sleep(100);
        }
        else if ( timKiemMon.isMouseHover()) {
            Edit = &timKiemMon;
        }
    }
}