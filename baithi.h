bool taoBaiThi(Bai_Thi &baiThi, mangCauHoi arr, int soCau)
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
        swap(arr.arrCauHoiThi[i], arr.arrCauHoiThi[randomNumber(0, maxSoCau)]);
    }

    for (int i = 0; i < soCau; i++)
    {
        baiThi.arrCauHoi[i].cauHoiThi = arr.arrCauHoiThi[i]->info;
    }
    return true;
}

void lamBaiThi(cauHoiThi &lamBai, char chonDapAn)
{
    lamBai.luaChon = chonDapAn;
}

float chamBai(Bai_Thi &baiThi)
{
    float diemMoiCau = 10.0 / (float)baiThi.slcht;
    float tongDiem = 0;
    for (int i = 0; i < baiThi.slcht; i++)
    {
        if (baiThi.arrCauHoi[i].cauHoiThi.DapAn == baiThi.arrCauHoi[i].luaChon)
        {
            tongDiem += diemMoiCau;
        }
    }
    tongDiem = ceilf(tongDiem * 100) / 100;
    return tongDiem;
}

void luuBaiThi(string mssv, Danh_Sach_Diem_Thi *dsDiem)
{
    ofstream fileOut;
    string fileName = "DATA\\bai thi\\" + mssv + ".txt";
    fileOut.open(fileName, ios_base::out);

    Node_Diem_Thi *nodeDiemThi = dsDiem->first;
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

void docBaiThi(string mssv, Danh_Sach_Diem_Thi &dsDiem)
{
    ifstream fileIn;
    string fileName = "DATA\\bai thi\\" + mssv + ".txt";
    fileIn.open(fileName, ios_base::in);
    if (!fileIn.is_open())
    {
        return;
    }

    Node_Diem_Thi *nodeDiemThi = dsDiem.first;
    while (getline(fileIn, nodeDiemThi->info.MAMH, ','))
    {
        fileIn >> nodeDiemThi->info.Diem;
        cin.ignore();
        fileIn >> nodeDiemThi->info.baithi.slcht;
        cin.ignore();
        nodeDiemThi->info.baithi.arrCauHoi = new cauHoiThi[nodeDiemThi->info.baithi.slcht];
        for (int i = 0; i < nodeDiemThi->info.baithi.slcht; i++)
        {
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.id;
            cin.ignore();
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.NoiDung;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.A;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.B;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.C;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.D;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].cauHoiThi.DapAn;
            fileIn >> nodeDiemThi->info.baithi.arrCauHoi[i].luaChon;
        }
        // addlasst ()
        nodeDiemThi = nodeDiemThi->DTnext;
    }
    fileIn.close();
}
