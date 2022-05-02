// void drawHocSinh(sinhVien sv, string tenlop = "")
// {
//     cleardevice();
//     btnThi.draw();
//     btnXemDiemSV.draw();
//     btnDoiMK.draw();
//     btndangxuat.draw();
//     setlinestyle(0, 0, 3);
//     setcolor(WHITE);
//     rectangle(325, 200, 1275,700);
//     line(325, 325 , 1275, 325);
//     setfillstyle(WIDE_DOT_FILL, CYAN);
//     bar(325, 200, 1275, 325);
//     setcolor(YELLOW);
//     settextstyle(0, 0, 5);
//     outtextxy(430, 240,"THONG TIN SINH VIEN");
//     string hoTen = "Ho va Ten: "+ sv.Ho + " " + sv.Ten;
//     string mssv = "Mssv: " + sv.mssv;
//     static string tenLop;
//     if ( tenlop.size()) {
//         tenLop = "Lop: " + tenlop;
//     }
//     string temp = (sv.gioiTinh) ? ("NU") : ("NAM");
//     string gioiTinh = "Gioi tinh: " + temp ;
//     settextstyle(10, 0, 4);
//     setcolor(LIGHTRED);
//     outtextxy(430,400, &hoTen[0]);
//     outtextxy(430,475, &mssv[0]);
//     outtextxy(430,550, &tenLop[0]);
//     outtextxy(430, 625, &gioiTinh[0]);

//     //setlinestyle(, 0, 2);
// }

// void drawDoiMk()
// {
//     setbkcolor(BLACK);
//     setfillstyle(1, BLACK);
//     cleardevice();
//     setfillstyle(WIDE_DOT_FILL, CYAN);
//     bar(325, 100, 1275, 230);
//     line(325,230,1275,230);
//     rectangle(325, 100, 1275,700);
//     setcolor(YELLOW);
//     settextstyle(0,0,5);
//     outtextxy(800 - textwidth("DOI MAT KHAU")/2 + 20,150,"DOI MAT KHAU");
//     matKhauCu.draw();
//     matKhauMoi.draw();
//     nhapLaiMatKhau.draw();
//     btnQuaylai.draw();
//     btnDoiMKMoi.draw();

//     matKhauCu.setNext(&matKhauMoi);
//     matKhauMoi.setNext(&nhapLaiMatKhau);
//     nhapLaiMatKhau.setNext(&matKhauCu);

//     matKhauCu.setPre(&nhapLaiMatKhau);
//     matKhauMoi.setPre(&matKhauCu);
//     nhapLaiMatKhau.setPre(&matKhauMoi);
// }

void displayDoiMK(listSV &dsSinhVien, string &mk, string maLop);

void displayHocSinh(listSV &dsSinhVien ,sinhVien &sv, string maLop)
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
            while (true)
            {
                KbEvent();
                displayDoiMK(dsSinhVien,sv.Pass,maLop);
                if (btnQuaylai.click)
                {
                    btnQuaylai.click = false;
                    curMenu = DISPLAY_HOCSINH;
                    drawHocSinh(sv);
                    break;
                }
                Sleep(75);
            }
        }
        else if (btnThi.isMouseHover())
        {
            AllocConsole();
            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chua den gio thi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
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
                else if ( mk == matKhauMoi.content ) {
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
        }
    }
}