void displayHocSinh(ListMonHoc listMH, listSV &dsSinhVien, sinhVien &sv, string maLop)
{
    btnThi.ButtonEffect();
    btnXemDiemSV.ButtonEffect();
    btnDoiMK.ButtonEffect();
    btndangxuat.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btndangxuat.isMouseHover())
        {
            drawLogin();
            curMenu = DISPLAY_LOGIN;
            btndangxuat.click = true;
        }
        else if (btnDoiMK.isMouseHover())
        {
            curMenu = DISPLAY_DOIMK;
            drawDoiMk();
        }
        else if (btnThi.isMouseHover())
        {
            curMenu = LUACHON_THI_HS;
            drawMonHoc();
            drawThietLapThi();
            MenuThemMon = false;
        }
        else if (btnXemDiemSV.isMouseHover())
        {
            curMenu = DISPLAY_DIEMSV;
            drawDiemSV();
        }
    }
}

void displayDoiMK(listSV &dsSinhVien, string &mk, string maLop)
{
    btnQuaylai.ButtonEffect();
    btnDoiMKMoi.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (matKhauCu.isMouseHover())
        {
            Edit = &matKhauCu;
        }
        else if (matKhauMoi.isMouseHover())
        {
            Edit = &matKhauMoi;
        }
        else if (nhapLaiMatKhau.isMouseHover())
        {
            Edit = &nhapLaiMatKhau;
        }
        else if (btnDoiMKMoi.isMouseHover())
        {
            if (matKhauCu.content == "")
            {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong mat khau cu", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else if (matKhauMoi.content == "")
            {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long nhap mat khau moi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else if (nhapLaiMatKhau.content == "")
            {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long nhap lai mat khau moi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else
            {
                if (mk != matKhauCu.content)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Mat khau cu khong chinh xac", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else if (matKhauMoi.content != nhapLaiMatKhau.content)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Mat khau moi khong trung nhau", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else if (mk == matKhauMoi.content)
                {
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Mat khau moi trung voi mat khau cu", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                }
                else
                {
                    mk = matKhauMoi.content;
                    ghiFileDsSinhVien(dsSinhVien, maLop);
                    AllocConsole();
                    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Doi mat khau thanh cong", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
                    matKhauCu.content = "";
                    matKhauMoi.content = "";
                    nhapLaiMatKhau.content = "";
                    btnQuaylai.click = true;
                }
            }
        }
        else if (btnQuaylai.isMouseHover())
        {
            matKhauCu.content = "";
            matKhauMoi.content = "";
            nhapLaiMatKhau.content = "";
            btnQuaylai.click = true;
            curMenu = DISPLAY_HOCSINH;
        }
    }
}

void ClickItemMonThi(ListMonHoc &listMH)
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

        // bat su kien khi o man hinh danh sach mon thi
        if (GetAsyncKeyState(VK_LBUTTON) && LuaChon < listviewDS.size && curMenu == LUACHON_THI_HS)
        {
            edChonMonThi.content = listMH.monHoc[listviewDS.idItem[LuaChon]]->MAMH;
            edChonMonThi.draw();
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
}

void displayLuaChonMonThi(ListMonHoc listMH, sinhVien sv, string maLOP)
{
    btnQuaylai.ButtonEffect();
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();
    btnVaoThi.ButtonEffect();
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
    ClickItemMonThi(listMH);
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            Edit = nullptr;
            drawList = true;
            curMenu = DISPLAY_HOCSINH;
            preMenu = -1;
            MenuThemMon = true;
            MenuThemLop = true;
            edChonMonThi.content = "";
            edTimeThi.content = "";
            edsoCau.content = "";
            timKiemMon.content = "";
            drawHocSinh();
            soTrangMon = 1;
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
        else if (timKiemMon.isMouseHover())
        {
            Edit = &timKiemMon;
        }
        else if (edTimeThi.isMouseHover())
        {
            Edit = &edTimeThi;
        }
        else if (edsoCau.isMouseHover())
        {
            Edit = &edsoCau;
        }
        else if (btnVaoThi.isMouseHover())
        {
            Edit = nullptr;
            curMenu = DISPLAY_HSTHI;
            drawThi(sv.Ho, sv.Ten, sv.mssv, maLOP, "");
            int giay = edTimeThi.toInt() * 60;
            timer = thread(drawThoiGian, giay);
            // timer.join();
            timKiemMon.content = "";
            edChonMonThi.content = "";
            edTimeThi.content = "";
            edsoCau.content = "";
        }
    }
}

void displayDiemSV()
{
    btnQuaylai.ButtonEffect();
    btnTien_L1.ButtonEffect();
    btnLui_L.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        if (btnQuaylai.isMouseHover())
        {
            curMenu = DISPLAY_HOCSINH;
            btnQuaylai.click = true;

            drawList = true;
            soTrangSV = 1;
            edtimKiemSV_R.content = "";
            luaChonLop = -1;
            Edit = nullptr;
        }
    }
}

void dipslayHocSinhThi()
{
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();
    rdChonA.RadioEffect();
    rdChonB.RadioEffect();
    rdChonC.RadioEffect();
    rdChonD.RadioEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {
        // if (btnQuaylai.isMouseHover())
        // {
        //     timer.join();
        //     // if (timer.join()) {

        //     // }
        //     curMenu = DISPLAY_GIAOVIEN;
        //     drawList = true;
        //     drawGV();
        // }
        if (rdChonA.isMouseHover())
        {
            rdChonA.click = true;
            rdChonB.click = false;
            rdChonC.click = false;
            rdChonD.click = false;

            rdChonA.drawEffect();
            rdChonB.drawEffect();
            rdChonC.drawEffect();
            rdChonD.drawEffect();
        }
        else if (rdChonB.isMouseHover())
        {
            rdChonA.click = false;
            rdChonB.click = true;
            rdChonC.click = false;
            rdChonD.click = false;

            rdChonA.drawEffect();
            rdChonB.drawEffect();
            rdChonC.drawEffect();
            rdChonD.drawEffect();
        }
        else if (rdChonC.isMouseHover())
        {
            rdChonA.click = false;
            rdChonB.click = false;
            rdChonC.click = true;
            rdChonD.click = false;

            rdChonA.drawEffect();
            rdChonB.drawEffect();
            rdChonC.drawEffect();
            rdChonD.drawEffect();
        }
        else if (rdChonD.isMouseHover())
        {
            rdChonA.click = false;
            rdChonB.click = false;
            rdChonC.click = false;
            rdChonD.click = true;

            rdChonA.drawEffect();
            rdChonB.drawEffect();
            rdChonC.drawEffect();
            rdChonD.drawEffect();
        }
    }
}