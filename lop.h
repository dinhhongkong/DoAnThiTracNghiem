bool CheckMaLopTenLop(dslop ds, string maLop, string tenlop)
{
    for (int i = 0; i < ds.solop; i++)
    {

        if (ds.arrLop[i].MALOP == maLop || ds.arrLop[i].TENLOP == tenlop)
        {
            return false;
        }
    }
    return true;
}

bool ThemVaoDanhSach(dslop &ds, string maLop, string tenLop)
{

    if (!CheckMaLopTenLop(ds, maLop, tenLop))
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "MA LOP hoac TEN LOP bi trung", "Thong bao", MB_ICONASTERISK | MB_OK);
        return false;
    }

    if (ds.solop == MAXLOP)
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Danh sach lop day", "Thong bao", MB_ICONASTERISK | MB_OK);
        return false;
    }

    int i = 0;
    if (ds.solop == 0 || maLop > ds.arrLop[0].MALOP)
    {
        i = 0;
    }
    else if (maLop < ds.arrLop[ds.solop - 1].MALOP)
    {
        i = ds.solop;
    }
    else
    {
        for (i = 0; i < ds.solop - 1; i++)
        {
            if (ds.arrLop[i].MALOP < maLop)
            {
                break;
            }
        }
    }
    //--------------------------------------test---------------------------
    for (int j = ds.solop; j > i; j--)
    {
        ds.arrLop[j].MALOP = ds.arrLop[j - 1].MALOP;
        ds.arrLop[j].TENLOP = ds.arrLop[j - 1].TENLOP;
    }
    ds.arrLop[i].TENLOP = tenLop;
    ds.arrLop[i].MALOP = maLop;
    ds.solop++;
    AllocConsole();
    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "THEM VAO DANH SACH THANH CONG", "Thong bao", MB_OK);
    return true;
}

void xoaLop(dslop &ds, int viTri)
{
    if (ds.arrLop[viTri].dsSinhVien.First != nullptr)
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Lop co sinh vien, khong the XOA", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
    }
    else
    {
        string tenFileLop = "DATA\\" + ds.arrLop[viTri].MALOP + ".txt";
        remove(&tenFileLop[0]);

        for (int i = viTri; i < ds.solop -1; i++)
        {
            ds.arrLop[i] = ds.arrLop[i + 1];
        }
        ds.arrLop[ds.solop -1].MALOP = "";
        ds.arrLop[ds.solop -1].TENLOP = "";
        ds.arrLop[ds.solop -1].dsSinhVien.First = nullptr;
        ds.arrLop[ds.solop -1].dsSinhVien.Last = nullptr;
        ds.solop--;


        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "XOA lop thanh cong", "Thong bao", MB_OK);
    }
}

// Chinh sua nhung ko lam mat thu tu
bool chinhSuaLop(dslop &ds, int viTri, string maLop, string tenLop)
{
    // Kiem tra xem co can thiet chinh sua hay ko
    if ( ds.arrLop[viTri].MALOP == maLop && ds.arrLop[viTri].TENLOP == tenLop) {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong chinh sua, do MA LOP vs TEN LOP nhap vao van giu nguyen", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    // kiem tra no co ton tai truoc do khong
    for ( int i  = 0 ; i < ds.solop ;i++) {
        if (i == viTri ) {
            continue;
        }
        if (ds.arrLop[i].MALOP == maLop || ds.arrLop[i].TENLOP == tenLop)
        {
            AllocConsole();
            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ten hoac Ma lop da ton tai", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            return false;
        }

    }
    //rename(oldname, newname) // ham chinh sua ten file
    string oldname = "DATA\\" + ds.arrLop[viTri].MALOP + ".txt";
    string newname = "DATA\\" + maLop + ".txt";
    rename(&oldname[0], &newname[0]);
    ds.arrLop[viTri].MALOP = maLop;
    ds.arrLop[viTri].TENLOP = tenLop;

    if (ds.solop == 1 || ( viTri == 0 && ds.arrLop[0].MALOP > ds.arrLop[1].MALOP ) || ( viTri == ds.solop -1 && ds.arrLop[ds.solop -1].MALOP <  ds.arrLop[ds.solop -2].MALOP ) )
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thanh cong", "Thong bao", MB_OK);
        return true;;
    }

    else if (ds.arrLop[viTri].MALOP < ds.arrLop[viTri+1].MALOP  ) {
        lop temp;
        for ( int i = viTri; i <ds.solop -1; i++) {
            if (ds.arrLop[i].MALOP > ds.arrLop[i+1].MALOP) {
                break;
            }
            
            temp = ds.arrLop[i];
            ds.arrLop[i] = ds.arrLop[i+1];
            ds.arrLop[i+1] = temp;
        }

    }
    else if (ds.arrLop[viTri].MALOP > ds.arrLop[viTri -1].MALOP ) {
        lop temp;
        for ( int i = viTri; i > 0; i--) {
            if (ds.arrLop[i].MALOP < ds.arrLop[i -1].MALOP) {
                break;
            }
            temp = ds.arrLop[i];
            ds.arrLop[i] = ds.arrLop[i-1];
            ds.arrLop[i-1] = temp;
        }
    }
    AllocConsole();
    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thanh cong", "Thong bao", MB_OK);
    return true;

}

void docFileDsLop(dslop &DanhSachLop)
{
    ifstream fileIn;
    fileIn.open("DATA\\FileDSLop.txt", ios_base::in);

    fileIn >> DanhSachLop.solop;
    fileIn.ignore();
    for (int i = 0; i < DanhSachLop.solop; i++)
    {
        // DanhSachLop.arrLop[i] = new lop;
        getline(fileIn, DanhSachLop.arrLop[i].MALOP, ',');
        getline(fileIn, DanhSachLop.arrLop[i].TENLOP, '\n');
        DocDsSinhVien(DanhSachLop.arrLop[i].dsSinhVien, DanhSachLop.arrLop[i].MALOP);
        // DocFileDiem1Lop(dsl.l[i]);
    }
    fileIn.close();
}

void ghiFileDSlop(dslop DanhSachLop)
{
    ofstream fileOut;
    fileOut.open("DATA\\FileDSLop.txt", ios_base::out);
    if (!fileOut.is_open())
    {
        return;
    }

    fileOut << DanhSachLop.solop << endl;
    for (int i = 0; i < DanhSachLop.solop; i++)
    {
        fileOut << DanhSachLop.arrLop[i].MALOP << ',' << DanhSachLop.arrLop[i].TENLOP << '\n';
        // GhiFileLop(dsl.l[i], dsl.l[i].MALOP + ".txt");
        // GhiFileDiem(dsl.l[i],"DiemThi"+dsl.l[i].MALOP+".txt",dsch);
    }

    fileOut.close();
}
