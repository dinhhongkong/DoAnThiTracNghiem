// const int w  = 1600;
// const int h  = 900;

void displayLogin(ListMonHoc listMH ,dslop &DanhSachLop)
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
                                KbEvent();
                                if ( curMenu == DISPLAY_HOCSINH ) {
                                    displayHocSinh(listMH, DanhSachLop.arrLop[i].dsSinhVien,node->info,DanhSachLop.arrLop[i].MALOP );
                                }
                                else if ( curMenu == DISPLAY_DOIMK) {
                                    displayDoiMK(DanhSachLop.arrLop[i].dsSinhVien, node->info.mssv, DanhSachLop.arrLop[i].MALOP);
                                    if (btnQuaylai.click) {
                                        btnQuaylai.click = false;
                                        drawHocSinh(node->info);
                                    }
                                }
                                else if ( curMenu == LUACHON_THI_HS) {
                                    displayLuaChonMonThi(listMH, node->info, DanhSachLop.arrLop[i].MALOP);
                                }
                                else if ( curMenu == DISPLAY_HSTHI) {
                                    dipslayHocSinhThi();
                                }
                                else if ( curMenu == DISPLAY_DIEMSV) {
                                    displayDiemSV();
                                    if (btnQuaylai.click) {
                                        btnQuaylai.click = false;
                                        drawHocSinh(node->info);
                                    }
                                }
                                if ( btndangxuat.click == true) {
                                    btndangxuat.click = false;
                                    cout << curMenu << endl;
                                    return;
                                }
                                Sleep(75);
                            }
                            
                        }
                        else if (taiKhoan.ToString() == node->info.mssv && matKhau.content != node->info.Pass)
                        {
                            AllocConsole();
                            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Tai khoan hoac Mat khau khong chinh xac", "Thong bao", MB_ICONASTERISK | MB_OK);
                            checkThoat = false;
                            return;
                        }
                        // neu tim thay tai khoan, mat khau lai sai, thoat ra luon
                        if (checkThoat == false) {
                            break;
                        }
                        node = node->pNext;
                    }
                }
                AllocConsole();
                MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Tai khoan hoac Mat khau khong chinh xac", "Thong bao", MB_ICONASTERISK | MB_OK);
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
