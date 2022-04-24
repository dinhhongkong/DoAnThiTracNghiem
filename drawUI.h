// ve man hinh login
void drawLogin()
{
    cleardevice();
    taiKhoan.content = "";
    matKhau.content = "";
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    string nameApp = "PHAN MEM THI TRAC NGHIEM";
    outtextxy((w - textwidth(&nameApp[0])) / 2, 150, &nameApp[0]);
    taiKhoan.draw();
    matKhau.draw();
    dangnhap.draw();
    taiKhoan.setNext(&matKhau);
    matKhau.setPre(&taiKhoan);
    taiKhoan.setPre(&matKhau);
    matKhau.setNext(&taiKhoan);
}

// ve man hinh chuc nang giao vien
void drawGV()
{
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    outtextxy((w - textwidth("QUAN TRI VIEN HE THONG THI")) / 2, 100, "QUAN TRI VIEN HE THONG THI");
    btnMonHoc.draw();
    btnDsLop.draw();
    btnDiemThi.draw();
    btnCauHoiThi.draw();
    btnThiThu.draw();
    btnDangXuat.draw();
}

//---------------------------------------------CHUC NANG MON HOC-------------------------------------------------------

void DrawThemMonHoc()
{
    setfillstyle(WIDE_DOT_FILL, CYAN);
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
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
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
            listviewDS.size++;
            listviewDS.idItem[i] = i + (soTrangMon - 1) * 10;

            outtextxy(xDsMon[0] + 80, yDsMon[0] + 20 + i * 50, &listMH.monHoc[i + (soTrangMon - 1) * 10]->MAMH[0]);
            outtextxy(xDsMon[1] + 80, yDsMon[0] + 20 + i * 50, &listMH.monHoc[i + (soTrangMon - 1) * 10]->TENMH[0]);
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

void drawHieuChinhMonHoc() {
    setfillstyle(1, BLACK);
    bar(1005, 0, 1600, 765); // 75 tai y neu thay menu
    setfillstyle(WIDE_DOT_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);
    outtextxy(1080, 230, "HIEU CHINH MON HOC");
    line(1050, 300, 1550, 300);
    line(1050, 600, 1550, 600);
    themMaMon.draw();
    themTenMon.draw();
    btnHieuChinh.draw();
    btnXoaVinhVien.draw();
    btnThoat.draw();
}
//---------------------------------------------CHUC NANG LOP-------------------------------------------------------

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
    setfillstyle(WIDE_DOT_FILL, CYAN);
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
    bar(xDsLop[0] + 1, yDsLop[0] + 1, xDsLop[1] - 1, 760 - 1);
    bar(xDsLop[1] + 1, yDsLop[0] + 1, 950 - 1, 760 - 1);

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

void drawHieuChinhLop()
{
    setfillstyle(1, BLACK);
    bar(1005, 0, 1600, 765); // 75 tai y neu thay menu
    setfillstyle(WIDE_DOT_FILL, CYAN);
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

//------------------------------------------------------CHUC NANG SINH VIEN--------------------------------------------

void drawSinhVien()
{
    setbkcolor(BLACK);
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    outtextxy(250, 20, "DANH SACH SV");
    btnQuaylai.draw();
    edtimKiemSV.draw();
    btnMenuThemSV.click = true;
    btnMenuThemSV.draw();
    btnLui.draw();
    btnTien.draw();
    line(1000, 0, 1000, 900);
    rectangle(50, 200, 950, 760);
    // ve ma sv
    line(250, 200, 250, 760);
    // ve ho sv
    line(600, 200, 600, 760);
    // ve ten sv
    line(800, 200, 800, 760);
    // ve gach ngang
    line(50, 250, 950, 250);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    outtextxy(xDsSV[0] + 75, 215, "MSSV");
    outtextxy(xDsSV[1] + 165, 215, "HO");
    outtextxy(xDsSV[2] + 80, 215, "TEN");
    outtextxy(xDsSV[3] + 35, 215, "GIOI TINH");
}

void drawThemSinhVien()
{
    setfillstyle(1, BLACK);
    bar(1005, 75, 1600, 765);
    setfillstyle(WIDE_DOT_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);

    outtextxy(1140, 230, "THEM SINH VIEN");
    line(1050, 300, 1550, 300);
    line(1050, 600, 1550, 600);
    btnThem.draw();
    edMSSV.draw();
    edHoSV.draw();
    edTenSV.draw();
    setcolor(13);
    outtextxy(1075, 550, "Gioi tinh:");
    btnNam.draw();
    btnNu.draw();

    edMSSV.setNext(&edHoSV);
    edMSSV.setPre(&edTenSV);

    edHoSV.setNext(&edTenSV);
    edHoSV.setPre(&edMSSV);

    edTenSV.setNext(&edMSSV);
    edTenSV.setPre(&edHoSV);
}

int soTrangSV = 1;
void drawDsSinhVien(listSV &danhSachSV)
{
    setfillstyle(1, BLACK);
    int soLuongSV = SizeListSV(danhSachSV);

    static nodeSV *node = nullptr;

    if (listviewDS.click || btnThem.click || btnHieuChinh.click || btnXoaVinhVien.click)
    {
        node = danhSachSV.First;
        listviewDS.click = false;
        listviewDS.size = 0;
        btnHieuChinh.click = false;
        btnXoaVinhVien.click = false;
        btnThem.click = false;
        soTrangSV =1;
    }
    // if (btnThem.click == true) {
    //     btnThem.click = false;
    //     node = danhSachSV.First;
    //     soTrangSV =1;
    // }

    if (soLuongSV <= 10)
    {
        soTrangSV = 1;
    }
    else if (btnTien.click && soLuongSV > soTrangSV * 10 && edtimKiemSV.content.size() == 0 && node != nullptr)
    {
        soTrangSV++;
    }
    else if (btnLui.click && edtimKiemSV.content.size() == 0)
    {
        node = danhSachSV.First;
        if (soTrangSV > 1)
        {
            soTrangSV--;
            for (int i = 0; i < 10 * (soTrangSV - 1); i++)
            {
                node = node->pNext;
            }
        }
    }

    btnTien.click = false;
    btnLui.click = false;

    string textTrang = to_string(soTrangSV);

    textTrang += "/" + to_string((soLuongSV % 10 == 0) ? ((soLuongSV < 10) ? 1 : soLuongSV / 10) : (soLuongSV / 10 + 1));
    // thu nghiem xoa so trang:   setfillstyle(4, YELLOW);
    bar(425, 825, 500, 850);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    if (edtimKiemSV.content.size() == 0)
    {
        outtextxy(450, 825, &textTrang[0]);
    }

    if (edtimKiemSV.content.size() == 0 && node != nullptr)
    {
        bar(xDsSV[0] + 1, yDsSV[0] + 1, xDsSV[1] - 1, 760 - 1);
        bar(xDsSV[1] + 1, yDsSV[0] + 1, xDsSV[2] - 1, 760 - 1);
        bar(xDsSV[2] + 1, yDsSV[0] + 1, xDsSV[3] - 1, 760 - 1);
        bar(xDsSV[3] + 1, yDsSV[0] + 1, xDsSV[4] - 1, 760 - 1);
        listviewDS.size = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i + (soTrangSV - 1) * 10 >= soLuongSV || node == nullptr)
            {
                break;
            }

            listviewDS.size++;
            listviewDS.idItem[i] = i + (soTrangSV - 1) * 10;

            outtextxy(xDsSV[0] + 40, yDsSV[0] + 20 + i * 50, &node->info.mssv[0]);
            outtextxy(xDsSV[1] + 45, yDsSV[0] + 20 + i * 50, &node->info.Ho[0]);
            outtextxy(xDsSV[2] + 45, yDsSV[0] + 20 + i * 50, &node->info.Ten[0]);
            if (node->info.gioiTinh == 0)
            {
                outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + i * 50, "NAM");
            }
            else
            {
                outtextxy(xDsSV[3] + 40, yDsSV[0] + 20 + i * 50, "NU");
            }
            node = node->pNext;
        }
    }
    /*else if (edtimKiemSV.content.size() )
    {
        listviewDS.size = 0;
        int j = 0;
        // for (int i = 0; i < DanhSachLop.solop; i++)
        while (node != nullptr)
        {
            // if (j >= 10)
            // {
            //     break;
            // }

            // if (DanhSachLop.arrLop[i].MALOP.find(timKiemLop.content) != string::npos || DanhSachLop.arrLop[i].TENLOP.find(timKiemLop.content) != string::npos)
            // {
            //     listviewDS.size++;
            //     listviewDS.idItem[j] = i;

            //     outtextxy(xDsLop[0] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].MALOP[0]);
            //     outtextxy(xDsLop[1] + 80, yDsLop[0] + 20 + j * 50, &DanhSachLop.arrLop[i].TENLOP[0]);
            //     j++;
            // }
        }
    } */
}

void drawHieuChinhSV() {
    setfillstyle(1, BLACK);
    bar(1005, 0, 1600, 765); // 75 tai y neu thay menu
    setfillstyle(WIDE_DOT_FILL, CYAN);
    bar(1050, 200, 1550, 300);
    setcolor(YELLOW);
    rectangle(1050, 200, 1550, 700);
    settextstyle(0, 0, 3);
    outtextxy(1060, 230, "HIEU CHINH SINH VIEN");
    line(1050, 300, 1550, 300);
    line(1050, 600, 1550, 600);
    edMSSV.draw();
    edHoSV.draw();
    edTenSV.draw();
    btnHieuChinh.draw();
    btnXoaVinhVien.draw();
    btnThoat.draw();
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(13);
    outtextxy(1075, 550, "Gioi tinh:");
    btnNam.draw();
    btnNu.draw();
}