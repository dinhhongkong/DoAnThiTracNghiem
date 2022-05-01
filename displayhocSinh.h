void drawHocSinh()
{
    cleardevice();
    btnThi.draw();
    btnXemDiemSV.draw();
    btnDoiMK.draw();
    btndangxuat.draw();
    setlinestyle(0, 0, 3);
    setcolor(WHITE);
    rectangle(325, 200, 1275,700);
    line(325, 325 , 1275, 325);
    setfillstyle(WIDE_DOT_FILL, LIGHTGREEN);
    bar(325, 200, 1275, 325);
    setcolor(YELLOW);
    settextstyle(0, 0, 5);
    outtextxy(430, 240,"THONG TIN SINH VIEN");
    //setlinestyle(, 0, 2);
}

void drawDoiMk()
{
    setbkcolor(BLACK);
    setfillstyle(1, BLACK);
    cleardevice();
    setfillstyle(WIDE_DOT_FILL, CYAN);
    bar(325, 100, 1275, 230);
    line(325,230,1275,230);
    rectangle(325, 100, 1275,700);
    setcolor(YELLOW);
    settextstyle(0,0,5);
    outtextxy(800 - textwidth("DOI MAT KHAU")/2 + 20,150,"DOI MAT KHAU");
    matKhauCu.draw();
    matKhauMoi.draw();
    nhapLaiMatKhau.draw();
    btnQuaylai.draw();
    btnDoiMKMoi.draw();
}

void displayHocSinh()
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
        }
        else if (btnDoiMK.isMouseHover())
        {
            curMenu = DISPLAY_DOIMK;
            drawDoiMk();
        }
        else if (btnThi.isMouseHover())
        {
            AllocConsole();
            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chua den gio thi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
        }
    }
}

void displayDoiMK()
{
    btnQuaylai.ButtonEffect();
    btnDoiMKMoi.ButtonEffect();

    if (GetAsyncKeyState(VK_LBUTTON)) {
        if ( matKhauCu.isMouseHover()) {
            Edit = &matKhauCu;
        }
        else if (matKhauMoi.isMouseHover()) {
            Edit = &matKhauMoi;
        }
        else if (nhapLaiMatKhau.isMouseHover()) {
            Edit = &nhapLaiMatKhau;
        }
        else if ( btnDoiMKMoi.isMouseHover() ){
            if ( matKhauCu.content == "") {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong duoc de trong mat khau cu", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else if ( matKhauMoi.content == "") {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long nhap mat khau moi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else if (nhapLaiMatKhau.content == "") {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Vui long nhap lai mat khau moi", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            }
            else {

            }
        }
    }
}