void drawHocSinh() {
    cleardevice();
    btnThi.draw();
    btnXemLai.draw();
    btnDoiMK.draw();
    btndangxuat.draw();
    setlinestyle(0,0,2);
    line(1000,0,1000,900);
    line(1000, 450, 1600, 450);
}

void displayHocSinh()
{
    btnThi.ButtonEffect();
    btnXemLai.ButtonEffect();
    btnDoiMK.ButtonEffect();
    btndangxuat.ButtonEffect();

    if(GetAsyncKeyState(VK_LBUTTON)) {
        if (btndangxuat.isMouseHover()) {
            drawLogin();
            curMenu = DISPLAY_LOGIN;
        }
    }

    
}