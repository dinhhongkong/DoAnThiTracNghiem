int curMenu = 0;
int curGV = 0;
bool drawList = true;

editText *Edit = nullptr;

class listview
{
public:
    int size = 0;
    int idItem[10];
};


// ma hinh dang nhap
editText taiKhoan(0, 500, 300, 600, 50, "TAI KHOAN: ", "Nhap ma so sinh vien", 100);
editText matKhau(0, 500, 400, 600, 50, "MAT KHAU: ", "Toi da 20 ki tu", 20, 1);
button dangnhap(0, 700, 500, 200, 70, "DANG NHAP");

// man hinh giao vien
button btnMonHoc(100,700,200,250,50,"QUAN LY MON HOC");
button btnDsLop(101,700,300,250,50,"QUAN LY LOP");
button btnDiemThi(102,700 ,400,250, 50,"DIEM THI");
button btnCauHoiThi(103,700, 500,250,50,"CAU HOI THI");
button btnThiThu(104,700,600,250,50,"THI THU");
button btnDangXuat(0,750,700,150,50,"DANG XUAT");

listview listviewDS;
button btnLui(200,70, 820, 100,50,"PRE");
button btnTien(200, 800, 820, 100,50,"NEXT");
button btnThem(200,1250, 625,100,50,"THEM");
// button btnHieuChinh(200,1100, 625,400,50,"HIEU CHINH");
// button btnXoaVinhVien(200,1200, 710,200,50,"XOA VINH VIEN");
button btnHieuChinh(200,1075, 625,200,50,"HIEU CHINH");
button btnXoaVinhVien(200,1325, 625,200,50,"XOA VINH VIEN");
button btnThoat(200, 1050,20,220,50,"< THOAT CHUC NANG");

// nut chuc nang mon hoc tai man hinh gv
int xDsMon[3] = {50,300,950};
int yDsMon[2] = {250,760};
button btnQuaylai(200,20,20,100,50,"< BACK");
editText timKiemMon(0,100,100,600,50,"TIM KIEM: ","Nhap ten mon hoc muon tim",100);
button btnMenuThemMon(200, 1175,20,250,50,"MENU THEM MON HOC");
editText themMaMon(200,1075,350,450,50,"MA MON:","Toi da 10 ki tu",10);
editText themTenMon(200,1075,475,450,50,"TEN MON:","Toi da 35 ki tu",35);


// nut chuc nang quan ly lop
int xDsLop[3] = {50, 350, 950};
int yDsLop[2] = {250,750};
button btnMenuThemLop(300, 1175,20,250,50,"MENU THEM LOP HOC");
editText themMaLop(300,1075,350,450,50,"MA LOP HOC:","Toi da 15 ki tu",15);
editText themTenLop(300,1075,475,450,50,"TEN LOP HOC:","Toi da 35 ki tu",35);
editText timKiemLop(0,100,100,600,50,"TIM KIEM: ","Nhap MA hoac Ten lop muon tim",100);

// danh sach hoc sinh trong 1 lop
int xDsSV[6] = {50,200,500,650,  950};
button btnMenuThemSV(1175,20,250,50,"MENU THEM SINH VIEN");
editText edtimKiemSV(100,100,600,50,"TIM KIEM: ","Nhap MA hoac Ten SV muon tim",100);
editText edMSSV(1075,325,450,50,"MSSV:","Toi da 10 ki tu",10);
editText edHoSV(1075,400,450,50,"Ho va ten dem","nhap ho vs ten lot",40);
editText edTenSV(1075,475,450,50,"Ten:","Toi da 7 ki tu",7);
button btnNam(1225, 540, 100,40,"NAM");
// button btnNu(1375, 540, 100,40,"NU");
button btnNu(1350, 540, 100,40,"NU");







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
    setcolor(YELLOW);
    string nameApp = "PHAN MEM THI TRAC NGHIEM";
    outtextxy((w - textwidth(&nameApp[0])) / 2, 150, &nameApp[0]);
    taiKhoan.draw();
    matKhau.draw();
    dangnhap.draw();
    taiKhoan.setNext(&matKhau);
    matKhau.setPre(&taiKhoan);
    taiKhoan.setPre(&matKhau);
    matKhau.setNext(&taiKhoan);
}



// ve man hinh chuc nang giao vien
void drawGV() {
    cleardevice();
    settextstyle(BOLD_FONT, 0, 7);
    setcolor(YELLOW);
    outtextxy((w - textwidth("QUAN TRI VIEN HE THONG THI")) / 2, 100, "QUAN TRI VIEN HE THONG THI");
    btnMonHoc.draw();
    btnDsLop.draw();
    btnDiemThi.draw();
    btnCauHoiThi.draw();
    btnThiThu.draw();
    btnDangXuat.draw();
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
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }

            else if ( Edit == &matKhau) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }

        else if ( curMenu == btnMenuThemMon.id) {
            if ( Edit == &themMaMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER_NO_SPACE);
            }
            if ( Edit == &themTenMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if ( curMenu = btnDsLop.id) {
            if ( Edit == &themMaLop) {
                Scan(Edit,Edit->textSize,SCAN_MALOP);
            }
            else if (Edit == &themTenLop) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
            else if (Edit == &timKiemLop) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
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
