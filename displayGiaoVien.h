//

void KhungMonHoc()
{
}

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
            curMenu = -1;
            drawMonHoc();
        }
    }
}

void DisplayMonHoc() {
    btnQuaylai.ButtonEffect();
    btnThemMon.ButtonEffect();
    btnTien.ButtonEffect();
    btnLui.ButtonEffect();    
    if (GetAsyncKeyState(VK_LBUTTON)) {
        if (btnQuaylai.isMouseHover()) {
            curMenu = DISPLAY_GIAOVIEN;
            drawGV();
        }
    }

}