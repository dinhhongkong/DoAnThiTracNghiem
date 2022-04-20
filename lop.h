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
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "MA LOP hoac TEN LOP bi trung", "Thong bao",MB_ICONASTERISK | MB_OK);
        return false;
    }

    if (ds.solop == MAXLOP)
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Danh sach lop day", "Thong bao",MB_ICONASTERISK | MB_OK);
        return false;
    }

    int i = 0;

    if (ds.solop == 0 || maLop < ds.arrLop[0].MALOP)
    {
        i = 0;
    }
    else if (maLop > ds.arrLop[ds.solop - 1].MALOP)
    {
        i = ds.solop;
    }
    else
    {
        for (i = 0; i < ds.solop - 1; i++)
        {
            if (ds.arrLop[i].MALOP > maLop)
            {
                break;
            }
        }
    }
    for (int j = ds.solop; j > i; j--)
    {
        ds.arrLop[j].MALOP = ds.arrLop[j - 1].MALOP;
        ds.arrLop[j].TENLOP = ds.arrLop[j - 1].TENLOP;
    }
    ds.arrLop[i].TENLOP = tenLop;
    ds.arrLop[i].MALOP = maLop;
    ds.solop++;
    AllocConsole();
    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"),"THEM VAO DANH SACH THANH CONG", "Thong bao", MB_OK);
    return true;
}

void chinhSuaLop(lop &LOP, string maLop, string tenLop) {
    LOP.MALOP = maLop;
    LOP.TENLOP = tenLop;
}


void docFileDsLop(dslop &DanhSachLop) {
    ifstream fileIn;
	fileIn.open("DATA\\FileDSLop.txt", ios_base:: in );
    
	fileIn >> DanhSachLop.solop;
	fileIn.ignore();
	for(int i = 0; i < DanhSachLop.solop; i++)
	{
		// DanhSachLop.arrLop[i] = new lop;
		getline(fileIn,DanhSachLop.arrLop[i].TENLOP,'\n');
		getline(fileIn,DanhSachLop.arrLop[i].MALOP,'\n');
		DocDsSinhVien(DanhSachLop.arrLop[i].dsSinhVien,DanhSachLop.arrLop[i].MALOP);
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
		cout << "Failed to open FileDSLop.txt file!" << endl;
		return;
	}

	fileOut << DanhSachLop.solop << endl;
	for (int i = 0; i < DanhSachLop.solop; i++) 
	{
		fileOut << DanhSachLop.arrLop[i].TENLOP << '\n'<< DanhSachLop.arrLop[i].MALOP << '\n';
		// GhiFileLop(dsl.l[i], dsl.l[i].MALOP + ".txt");
		// GhiFileDiem(dsl.l[i],"DiemThi"+dsl.l[i].MALOP+".txt",dsch);
	}

    fileOut.close();
}


