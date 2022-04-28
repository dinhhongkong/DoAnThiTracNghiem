void drawHocSinh()
{
    cleardevice();
    btnThi.draw();
    btnXemDiemSV.draw();
    btnDoiMK.draw();
    btndangxuat.draw();
    setlinestyle(0, 0, 2);
    rectangle(325, 200, 1275,700);
}

void drawDoiMk()
{
    setbkcolor(BLACK);
    setfillstyle(1, BLACK);
    cleardevice();
    matKhauCu.draw();
    matKhauMoi.draw();
    nhapLaiMatKhau.draw();
    btnQuaylai.draw();
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
}