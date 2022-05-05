void taoBaiThi(Bai_Thi &baiThi, NodeCauHoi *arr[], int soCau) {
    int maxSoCau  = 0;

    while (arr[maxSoCau] != nullptr) {
        maxSoCau++;
    }

    if ( soCau > maxSoCau) {
        return;
    }
    baiThi.slcht = soCau;
    baiThi.arrCauHoi = new cauHoiThi[soCau];

    for ( int i = 0; i < maxSoCau; i++) {
        swap(arr[i], arr[randomNumber(0, maxSoCau)]);
    }

    for ( int i = 0; i < soCau; i++) {
        baiThi.arrCauHoi[i].cauHoiThi = arr[i]->info;
    }
    return;
}


void lamBaiThi(cauHoiThi &lamBai, char chonDapAn) {
    lamBai.luaChon = chonDapAn;
}

float chamBai(Bai_Thi &baiThi) {
    float diemMoiCau  = 10 / (float)baiThi.slcht;
    float tongDiem = 0;
    for ( int i = 0 ; i < baiThi.slcht; i++) {
        if ( baiThi.arrCauHoi[i].cauHoiThi.DapAn == baiThi.arrCauHoi[i].luaChon) {
            tongDiem += diemMoiCau;
        }
    }
    tongDiem = ceilf(tongDiem * 100) / 100 ;
    return tongDiem;
}

void luuBaiThi(string mssv, Bai_Thi baiThi) {
    ofstream fileOut;
    string fileName = "DATA\\bai thi" + mssv + ".txt";
    fileOut.open(fileName, ios_base::out);

    if (!fileOut.is_open())
    {
        cout << "ko doc dc file"<< endl;
        return;
    }

    fileOut << baiThi.slcht << endl;
    for (int i = 0; i < baiThi.slcht; i++)
    {
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.id << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.maMonHoc << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.NoiDung << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.A << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.B << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.C << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.D << endl;
        fileOut << baiThi.arrCauHoi[i].cauHoiThi.DapAn<< endl;

        fileOut << baiThi.arrCauHoi[i].luaChon << endl;
    }

    fileOut.close();
}

