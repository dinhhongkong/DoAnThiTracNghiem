// const int w  = 1600;
// const int h  = 900;

bool CheckTkMk(dslop DanhSachLop, string TaiKhoan, string MatKhau) {
    nodeSV *node = nullptr;
    for ( int i = 0 ; i < DanhSachLop.solop; i++) {
        node = DanhSachLop.arrLop[i].dsSinhVien.First;
        while (node != nullptr)
        {
            if ( TaiKhoan == node->info.mssv && MatKhau == node->info.Pass) {
                return true;
            }
            else if ( TaiKhoan == node->info.mssv && MatKhau != node->info.Pass) {
                return false;
            }
            node = node->pNext;
        }   
    }
    return false;
}

void displayLogin(dslop DanhSachLop)
{
    dangnhap.ButtonEffect();
    if(GetAsyncKeyState(VK_LBUTTON)){

		if(dangnhap.isMouseHover()){
			if (taiKhoan.ToString() == "GV" || matKhau.content == "GV") {
                curMenu = DISPLAY_GIAOVIEN;
                drawGV();
                Edit = nullptr;
                // de nguoi dung nha chuot ra
                Sleep(500);
            }
            else if ( CheckTkMk(DanhSachLop, taiKhoan.ToString(), matKhau.content)) {
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
