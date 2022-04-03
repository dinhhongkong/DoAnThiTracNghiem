int curMenu = 0;
int curGV = 0;

editText *Edit = nullptr;

// ma hinh dang nhap
editText taiKhoan(0, 500, 300, 600, 50, "TAI KHOAN: ", "Nhap ma so sinh vien", 100);
editText matKhau(0, 500, 400, 600, 50, "MAT KHAU: ", "Toi da 20 ki tu", 20, 1);
button dangnhap(0, 700, 500, 200, 70, "DANG NHAP");

// man hinh giao vien
button btnMonHoc(100,700,200,250,50,"DANH SACH MON HOC");
button btnDsLop(100,700,300,250,50,"DANH SACH LOP");
button btnDiemThi(100,700 ,400,250, 50,"DIEM THI");
button btnCauHoiThi(100,700, 500,250,50,"CAU HOI THI");
button btnThiThu(100,700,600,250,50,"THI THU");
button btnDangXuat(100,750,700,150,50,"DANG XUAT");

// nut chuc nang mon hoc tai man hinh gv
int xDsMon[3] = {70,170,370};
int yDsMon[3] = {210,210,210};
button btnQuaylai(200,20,20,100,50,"< BACK");
editText timKiemMon(0,100,100,600,50,"TIM KIEM: ","Nhap ten mon hoc muon tim",100);
button btnThemMon(200, 1200,20,200,50,"THEM MON HOC");
button btnLui(200,70, 820, 100,50,"<-");
button btnTien(200, 800, 820, 100,50,"->");


// man hinh hoc sinh
button btnThi(1, 350, 100, 200, 50, "THI");
button btnXemLai(1, 350, 200, 200, 50, "XEM LAI BAI THI");
button btnDoiMK(1, 350, 300, 200, 50, "DOI MAT KHAU");
button btndangxuat(1,350, 400, 200,50, "DANG XUAT");

void ClearStream();

// ve man hinh login
void drawLogin() {
    cleardevice();
    taiKhoan.content = "";
    matKhau.content = "";
    settextstyle(BOLD_FONT, 0, 7);
    string nameApp = "PHAN MEM THI TRAC NGHIEM";
    outtextxy((w - textwidth(&nameApp[0])) / 2, 150, &nameApp[0]);
    taiKhoan.draw();
    matKhau.draw();
    dangnhap.draw();
    taiKhoan.setNext(&matKhau);
    matKhau.setPre(&taiKhoan);
}


// void drawKhungMonHoc() {
//     setlinestyle(0,0,2);
//     // ve cai khung
//     line(50,100, 50, 750);
//     line(50,100, 900 , 100);
//     line(50,750, 900 , 750);
//     line(900,750, 900 , 100);

//     // ve stt
//     line(150,100, 150, 750);
//     // ve ma mon
//     line(300,100, 300, 750);
//     // ve gach ngang
//     line(50,150,900,150);

//     outtextxy(xDsMon[0],110,"STT");
//     outtextxy(xDsMon[1],110,"MA MON");
//     outtextxy(xDsMon[2],110,"TEN MON HOC");

// }


// ve man hinh chuc nang giao vien
void drawGV() {
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    string nameApp = "QUAN TRI VIEN HE THONG THI";
    outtextxy((w - textwidth(&nameApp[0])) / 2, 100, &nameApp[0]);
    btnMonHoc.draw();
    btnDsLop.draw();
    btnDiemThi.draw();
    btnCauHoiThi.draw();
    btnThiThu.draw();
    btnDangXuat.draw();
}

// ve man hinh mon hoc ơ chuc nang GV
void drawMonHoc() {
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    string nameApp = "DANH SACH MON HOC";
    outtextxy( 200, 20, &nameApp[0]);
    btnQuaylai.draw();
    timKiemMon.draw();
    btnThemMon.draw();
    btnLui.draw();
    btnTien.draw();
    line(1000,0,1000,900);

    rectangle(50,200,950,800);
    // ve stt
    line(150,200, 150, 800);
    // ve ma mon
    line(350,200, 350, 800);
    // ve gach ngang
    line(50,250,950,250);
    outtextxy(xDsMon[0], yDsMon[0],"STT");
    outtextxy(xDsMon[1] + 20,yDsMon[1],"MA MON");
    outtextxy(600,yDsMon[2],"TEN MON HOC");
    char c = '1';
    for ( int i =  1 ; i * yDsMon[0] < 800; i++ ) {
        outtextxy(xDsMon[0], yDsMon[0] * i, &c);
        c+= 1;
    }

}

void KbEvent()
{
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
    {
        ClearStream();
        return;
    }

    if (Edit != nullptr) {
        Edit->isChoose = true;
		Edit->draw();
        if ( curMenu == DISPLAY_LOGIN) {
            if ( Edit == &taiKhoan) {
                Scan(Edit,100,TEXT_NUMBER);
            }

            if ( Edit == &matKhau) {
                Scan(Edit,10,TEXT_NUMBER);
            }
        }
    }
    else {
        ClearStream();
    }

}

void ClearStream()
{
    while (kbhit())
    {
        char c = getch();
    }
}
