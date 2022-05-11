void giaiPhongArrCauHoi(mangCauHoi &dsCauHoi) {
	for ( int i = 0 ; i < dsCauHoi.tongSoCau; i++) {
        dsCauHoi.arrCauHoiThi[i] = nullptr;
    }
	dsCauHoi.tongSoCau = 0;
    delete []dsCauHoi.arrCauHoiThi;

}

bool taoBaiThi(Bai_Thi &baiThi, mangCauHoi &arr, int soCau)
{
    int maxSoCau = arr.tongSoCau;

    if (soCau > maxSoCau)
    {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "So luong cau hoi khong du", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }
    baiThi.slcht = soCau;
    baiThi.arrCauHoi = new cauHoiThi[soCau];
    for (int i = 0; i < maxSoCau; i++)
    {
        int vitri = randomNumber(0, maxSoCau);
        swap(arr.arrCauHoiThi[i], arr.arrCauHoiThi[randomNumber(0, maxSoCau)]);
    }

    for (int i = 0; i < soCau; i++)
    {
        baiThi.arrCauHoi[i].cauHoiThi = arr.arrCauHoiThi[i]->info;
        arr.arrCauHoiThi[i]->info.used = true;
    }
    cout << "tao bai thi xong giai phong" << endl;
    giaiPhongArrCauHoi(arr);
    return true;
}

bool taoBaiThiThu(Diem_Thi &gvThiThu, mangCauHoi &arr, int soCau)
{
    int maxSoCau = arr.tongSoCau;

    if (soCau > maxSoCau)
    {
        cout << "ko tao dc bai thi xong giai phong" << endl;
        giaiPhongArrCauHoi(arr);
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "So luong cau hoi khong du", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }
    
    if (gvThiThu.MAMH.size()) {
        delete []gvThiThu.baithi.arrCauHoi;
    }

    gvThiThu.baithi.slcht = soCau;
    gvThiThu.baithi.arrCauHoi = new cauHoiThi[soCau];
    for (int i = 0; i < maxSoCau; i++)
    {
        int vitri = randomNumber(0, maxSoCau);
        swap(arr.arrCauHoiThi[i], arr.arrCauHoiThi[randomNumber(0, maxSoCau)]);
    }

    for (int i = 0; i < soCau; i++)
    {
        gvThiThu.baithi.arrCauHoi[i].cauHoiThi = arr.arrCauHoiThi[i]->info;
    }
    cout <<"giai phong" << endl;
    giaiPhongArrCauHoi(arr);
    return true;
}

bool kiemTraDaThi(Danh_Sach_Diem_Thi listDT, string maMon)
{
    Node_Diem_Thi *node = listDT.first;

    while (node != nullptr)
    {
        if (node->info.MAMH == maMon)
        {
            AllocConsole();
            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ban da thi mon nay!", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
            return false;
        }
        node = node->DTnext;
    }
    return true;
}

void lamBaiThi(cauHoiThi &lamBai, char chonDapAn)
{
    lamBai.luaChon = chonDapAn;
}

void chamBai(Diem_Thi &chamThi)
{
    float diemMoiCau = 10.0 / (float)chamThi.baithi.slcht;
    float tongDiem = 0;
    for (int i = 0; i < chamThi.baithi.slcht; i++)
    {
        if (chamThi.baithi.arrCauHoi[i].cauHoiThi.DapAn == chamThi.baithi.arrCauHoi[i].luaChon)
        {
            tongDiem += diemMoiCau;
        }
    }
    chamThi.Diem = ceilf(tongDiem * 100) / 100;
}

void luuBaiThi(string mssv, Danh_Sach_Diem_Thi dsDiem)
{
    ofstream fileOut;
    string fileName = "DATA\\bai thi\\" + mssv + ".txt";
    fileOut.open(fileName, ios_base::out);

    Node_Diem_Thi *nodeDiemThi = dsDiem.first;
    while (nodeDiemThi != nullptr)
    {
        fileOut << nodeDiemThi->info.MAMH << ',';
        fileOut << nodeDiemThi->info.Diem << endl;
        fileOut << nodeDiemThi->info.baithi.slcht << endl;
        for (int i = 0; i < nodeDiemThi->info.baithi.slcht; i++)
        {
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.id << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.NoiDung << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.A << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.B << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.C << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.D << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.DapAn << endl;
            fileOut << nodeDiemThi->info.baithi.arrCauHoi[i].luaChon << endl;
        }
        nodeDiemThi = nodeDiemThi->DTnext;
    }
    fileOut.close();
}

bool docBaiThi(string mssv, Danh_Sach_Diem_Thi &dsDiem)
{
    ifstream fileIn;
    string fileName = "DATA\\bai thi\\" + mssv + ".txt";
    fileIn.open(fileName, ios_base::in);
    if (!fileIn.is_open())
    {
        dsDiem.first = nullptr;
        return false;
    }

    Diem_Thi diemthi;
    while (getline(fileIn, diemthi.MAMH, ','))
    {
        fileIn >> diemthi.Diem;
        fileIn >> diemthi.baithi.slcht;
        diemthi.baithi.arrCauHoi = new cauHoiThi[diemthi.baithi.slcht];
        cout << diemthi.MAMH << endl
             << diemthi.Diem << endl
             << diemthi.baithi.slcht << endl;
        for (int i = 0; i < diemthi.baithi.slcht; i++)
        {
            fileIn >> diemthi.baithi.arrCauHoi[i].cauHoiThi.id;
            fileIn.ignore();
            cout << diemthi.baithi.arrCauHoi[i].cauHoiThi.id << endl;
            getline(fileIn, diemthi.baithi.arrCauHoi[i].cauHoiThi.NoiDung, '\n');
            getline(fileIn, diemthi.baithi.arrCauHoi[i].cauHoiThi.A, '\n');
            getline(fileIn, diemthi.baithi.arrCauHoi[i].cauHoiThi.B, '\n');
            getline(fileIn, diemthi.baithi.arrCauHoi[i].cauHoiThi.C, '\n');
            getline(fileIn, diemthi.baithi.arrCauHoi[i].cauHoiThi.D, '\n');
            fileIn >> diemthi.baithi.arrCauHoi[i].cauHoiThi.DapAn;
            fileIn >> diemthi.baithi.arrCauHoi[i].luaChon;
            fileIn.ignore();
        }
        Node_Diem_Thi *nodeDiemSV = new Node_Diem_Thi;
        nodeDiemSV->info = diemthi;
        nodeDiemSV->DTnext = nullptr;
        Them_Diem_Vao_Cuoi(dsDiem, nodeDiemSV);
    }
    fileIn.close();
    return true;
}
