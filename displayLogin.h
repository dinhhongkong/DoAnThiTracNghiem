// const int w  = 1600;
// const int h  = 900;

void displayLogin(dslop &DanhSachLop)
{
    dangnhap.ButtonEffect();
    if (GetAsyncKeyState(VK_LBUTTON))
    {

        if (dangnhap.isMouseHover())
        {
            if (taiKhoan.ToString() == "GV" || matKhau.content == "GV")
            {
                curMenu = DISPLAY_GIAOVIEN;
                drawGV();
                Edit = nullptr;
                // de nguoi dung nha chuot ra
                Sleep(500);
            }
            else if (taiKhoan.content.size() && matKhau.content.size() )
            {
                nodeSV *node = nullptr;
                bool checkThoat = true;
                for (int i = 0; i < DanhSachLop.solop; i++)
                {
                    node = DanhSachLop.arrLop[i].dsSinhVien.First;
                    while (node != nullptr)
                    {
                        if (taiKhoan.ToString() == node->info.mssv && matKhau.content == node->info.Pass)
                        {
                            curMenu = DISPLAY_HOCSINH;
                            drawHocSinh(node->info, DanhSachLop.arrLop[i].TENLOP);
                            Edit = nullptr;
                            while (true)
                            {
                                displayHocSinh(node->info);
                                if ( btndangxuat.click == true) {
                                    btndangxuat.click = false;
                                    checkThoat == false;
                                    cout << curMenu << endl;
                                    break;
                                }
                                Sleep(75);
                            }
                            
                        }
                        else if (taiKhoan.ToString() == node->info.mssv && matKhau.content != node->info.Pass)
                        {
                            AllocConsole();
                            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Tai khoan hoac Mat khau khong chinh xac", "Thong bao", MB_ICONASTERISK | MB_OK);
                            checkThoat = false;
                            break;
                        }
                        // neu tim thay tai khoan, mat khau lai sai, thoat ra luon
                        if (checkThoat == false) {
                            break;
                        }
                        node = node->pNext;
                    }
                }
                Sleep(500);
            }
            else
            {
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Tai khoan hoac Mat khau khong chinh xac", "Thong bao", MB_ICONASTERISK | MB_OK);
            }
        }

        else if (taiKhoan.isMouseHover())
        {
            Edit = &taiKhoan;
        }
        else if (matKhau.isMouseHover())
        {
            Edit = &matKhau;
        }
    }
}
