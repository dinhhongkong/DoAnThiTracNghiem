int curMenu = 0;
int preMenu = -1;
bool drawList = true;
int luaChonLop = -1;
thread timer;

editText *Edit = nullptr;

class listview
{
public:
    int size = 0;
    int idItem[10];
    bool click = false;
};


// man hinh dang nhap
editText taiKhoan(500, 300, 600, 50, "TAI KHOAN: ", "Nhap ma so sinh vien", 100);
editText matKhau(500, 400, 600, 50, "MAT KHAU: ", "Nhan chu, so, ki tu dac biet (chu y CapsLock)", 20, 1);
button dangnhap(700, 500, 200, 70, "DANG NHAP");

// man hinh doi mat khau ben hoc sinh
editText matKhauCu(500, 300, 600, 50, "Mat khau cu: ", "Nhan chu, so, ki tu dac biet (chu y CapsLock)", 20,1);
editText matKhauMoi(500, 400, 600, 50, "Mat khau moi: ", "Nhan chu, so, ki tu dac biet (chu y CapsLock)", 20, 1);
editText nhapLaiMatKhau(500, 500, 600, 50, "Nhap lai MK: ", "Nhan chu, so, ki tu dac biet (chu y CapsLock)", 20, 1);
button btnDoiMKMoi(700, 600, 200, 50, "DOI MAT KHAU");

// man hinh giao vien
button btnMonHoc(700,200,250,50,"QUAN LY MON HOC");
button btnDsLop(700,300,250,50,"QUAN LY LOP");
button btnDiemThi(700 ,400,250, 50,"DIEM THI");
button btnCauHoiThi(700, 500,250,50,"CAU HOI THI");
button btnThiThu(700,600,250,50,"THI THU");
button btnDangXuat(750,700,150,50,"DANG XUAT");

listview listviewDS;
button btnLui(70, 820, 100,50,"PRE");
button btnTien(800, 820, 100,50,"NEXT");
button btnTien_L(640, 820, 100,50,"NEXT");
button btnThem(1250, 625,100,50,"THEM");
button btnHieuChinh(1075, 625,200,50,"HIEU CHINH");
button btnXoaVinhVien(1325, 625,200,50,"XOA VINH VIEN");
button btnThoat(1050,20,220,50,"< THOAT CHUC NANG");

// nut chuc nang mon hoc tai man hinh gv
int xDsMon[3] = {50,300,950};
int yDsMon[2] = {250,750};
button btnQuaylai(20,20,100,50,"< BACK");
editText timKiemMon(100,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN mon hoc muon tim",100);
// button btnMenuThemMon(1175,20,250,50,"MENU THEM MON HOC");
bool MenuThemMon = true;
editText themMaMon(1075,350,450,50,"MA MON:","Toi da 10 ki tu",10);
editText themTenMon(1075,475,450,50,"TEN MON:","Toi da 35 ki tu",35);

// man hinh hoc sinh
button btnThi(325, 50, 200, 50, "THI");
button btnXemDiemSV(575, 50, 200, 50, "XEM DIEM");
button btnDoiMK(825, 50, 200, 50, "DOI MAT KHAU");
button btndangxuat(1075, 50, 200,50, "DANG XUAT");


// nut chuc nang quan ly lop
int xDsLop[3] = {50, 350, 950};
int yDsLop[2] = {250,750};
// button btnMenuThemLop(1175,20,250,50,"MENU THEM LOP HOC");
bool MenuThemLop = true;
editText themMaLop(1075,350,450,50,"MA LOP HOC:","Toi da 15 ki tu",15);
editText themTenLop(1075,475,450,50,"TEN LOP HOC:","Toi da 40 ki tu",40);
editText timKiemLop(100,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN lop muon tim",100);

// danh sach hoc sinh trong 1 lop
int xDsSV[6] = {50,250,600,800,950};
int yDsSV[2] = {250,750};
button btnMenuThemSV(1175,20,250,50,"MENU THEM SINH VIEN");
editText edtimKiemSV(100,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN sinh vien muon tim",100);
editText edMSSV(1075,325,450,50,"MSSV:","Toi da 10 ki tu",10);
editText edHoSV(1075,400,450,50,"Ho va ten dem:","nhap ho vs ten lot",40);
editText edTenSV(1075,475,450,50,"Ten:","Toi da 7 ki tu",7);
button btnNam(1225, 540, 100,40,"NAM");
button btnNu(1350, 540, 100,40,"NU");
button btnResetMK(1150, 710, 300,50,"RESET MAT KHAU MAC DINH");

// chuc nang xem diem tai man hinh giao vien
int xDsDiem[5] = {350,550,900,1100,1250};
editText edtimKiemSV_R(500,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN sinh vien muon tim",100);
button btnLui_L(370, 820, 100,50,"PRE");
button btnTien_L1(1120, 820, 100,50,"NEXT");



// cau hoi
int xDsCauHoi[4] = {50,125,250,800};
int yDsCauHoi[2] = {250,750};
editText edCauHoi(860, 325, 670,40,"CAU HOI:","toi da x ki tu",50);
editText edDapAnA(860, 375, 670,40,"DAP AN A:","toi da x ki tu",50);
editText edDapAnB(860, 425, 670,40,"DAP AN B:","toi da x ki tu",50);
editText edDapAnC(860, 475, 670,40,"DAP AN C:","toi da x ki tu",50);
editText edDapAnD(860, 525, 670,40,"DAP AN D:","toi da x ki tu",50);
editText edChonMaMon(860, 630, 500,40,"","An nut ben canh de chon tu danh sach",50);
button btnChonMaMon(860, 630, 140,40,"MA MON:");
button btnXoaMaMon(1380, 630, 130,40,"XOA MA MON");
button btnDapAnA(1040, 575, 100,40,"A");
button btnDapAnB(1165, 575, 100,40,"B");
button btnDapAnC(1290, 575, 100,40,"C");
button btnDapAnD(1415, 575, 100,40,"D");
button btnThemCauHoi(1100, 695, 200,50,"THEM CAU HOI");
editText timKiemCauHoi(100,100,600,50,"TIM KIEM: ","Nhap cau hoi muon tim",100);

// chuc nang tuy chon truoc khi thi

editText edChonMonThi(1075,350,450,50,"MA MON THI:","Chon mon thi trong danh sach",10);
editText edTimeThi(1075,420,450,50,"T/G LAM BAI:","Tinh theo phut",3);
editText edsoCau(1075,490,450,50,"SO CAU:","So cau trong bai thi",3);
button btnVaoThi(1250, 625,100,50,"VAO THI");


// THI
button btnChonA(70,225,70,50,"A:");
button btnChonB(70,375,70,50,"B:");
button btnChonC(70,525,70,50,"C:");
button btnChonD(70,675,70,50,"D:");


void ClearStream();

void KbEvent()
{
    if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
    {
        ClearStream();
        return;
    }
    static editText *PreEdit = nullptr;
    if (Edit != nullptr) {
        if ( Edit != PreEdit && PreEdit != nullptr) {
            PreEdit->isChoose = false;
            PreEdit->draw();
        }
        PreEdit = Edit;
        Edit->isChoose = true;
		Edit->draw();
        if ( curMenu == DISPLAY_LOGIN) {
            
            if ( Edit == &taiKhoan) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }

            else if ( Edit == &matKhau) {
                Scan(Edit,Edit->textSize,SCAN_PASS);
            }
        }
        else if ( curMenu == DISPLAY_DSMON) {
            if ( Edit == &themMaMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER_NO_SPACE);
            }
            else if ( Edit == &themTenMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
            else if ( Edit == &timKiemMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if ( curMenu == DISPLAY_DSLOP) {
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
        else if ( curMenu == DISPLAY_DSSV ) {
            if ( Edit == &edMSSV) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER_NO_SPACE);
            }
            else if (Edit == &edHoSV) {
                Scan(Edit,Edit->textSize,SPACE_TEXT);
            }
            else if (Edit == &edTenSV) {
                Scan(Edit,Edit->textSize,SPACE_TEXT);
            }
            else if (Edit == &edtimKiemSV) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        
        else if (curMenu == LUACHON_MON ) {
            if (Edit == & timKiemMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if ( curMenu == LUACHON_LOP) {
            if (Edit == & timKiemLop) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if (curMenu == DISPLAY_DSDIEMGV ) {
            if (Edit == &edtimKiemSV_R) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if ( curMenu == CHUCNANG_CAUHOI) {
            if ( Edit == &timKiemCauHoi || Edit == &edCauHoi || Edit == &edDapAnA || Edit == &edDapAnB || Edit == &edDapAnC || Edit == &edDapAnD) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
        }
        else if ( curMenu == DISPLAY_THITHU) {
            if (Edit == & timKiemMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
            }
            else if ( Edit == &edTimeThi || Edit == &edsoCau) {
                Scan(Edit,Edit->textSize,ONLY_NUMBER);
            }
        }
        // man hinh hoc sinh
        else if ( curMenu == DISPLAY_DOIMK) {
            if ( Edit == &matKhauCu || Edit == &matKhauMoi || Edit == &nhapLaiMatKhau ) {
                Scan(Edit,Edit->textSize,SCAN_PASS);
            }
        }

        
    }
    else {
        if ( PreEdit != nullptr) {
            PreEdit->isChoose = false;
            // PreEdit->draw();
            PreEdit = nullptr;
        }
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
