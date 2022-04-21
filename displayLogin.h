// const int w  = 1600;
// const int h  = 900;

void displayLogin()
{
    dangnhap.ButtonEffect();
    if(GetAsyncKeyState(VK_LBUTTON)){

		if(dangnhap.isMouseHover()){
			if (taiKhoan.ToString() == "GV" && matKhau.content == "GV") {
                curMenu = DISPLAY_GIAOVIEN;
                drawGV();
                Edit = nullptr;
                // de nguoi dung nha chuot ra
                Sleep(500);
            }
            else if ( taiKhoan.ToString() == "SV" && matKhau.content == "SV") {
                curMenu = DISPLAY_HOCSINH;
                drawHocSinh();
                Edit = nullptr;

                // de nguoi dung nha chuot ra
                Sleep(500);
            }
            else {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Tai khoan hoac Mat khau khong chinh xac", "Thong bao", MB_ICONASTERISK | MB_OK);
            }
        }

        else if (taiKhoan.isMouseHover()) {
            Edit = &taiKhoan;
        }
        else if (matKhau.isMouseHover()) {
            Edit = &matKhau;
        }
    }           
}
