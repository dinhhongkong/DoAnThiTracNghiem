int curMenu = 0;
int curGV = 0;
bool drawList = true;

editText *Edit = nullptr;

class listview
{
public:
    int size = 0;
    int idItem[10];
    bool click = false;
};


// ma hinh dang nhap
editText taiKhoan(500, 300, 600, 50, "TAI KHOAN: ", "Nhap ma so sinh vien", 100);
editText matKhau(500, 400, 600, 50, "MAT KHAU: ", "Nhan chu, so, ki tu dac biet (chu y CapsLock)", 20, 1);
button dangnhap(700, 500, 200, 70, "DANG NHAP");

// man hinh giao vien
button btnMonHoc(700,200,250,50,"QUAN LY MON HOC");
button btnDsLop(700,300,250,50,"QUAN LY LOP");
button btnDiemThi(700 ,400,250, 50,"DIEM THI");
button btnCauHoiThi(700, 500,250,50,"CAU HOI THI");
button btnCaiDatThi(700,600,250,50,"THIET LAP THI");
button btnDangXuat(750,700,150,50,"DANG XUAT");

listview listviewDS;
button btnLui(70, 820, 100,50,"PRE");
button btnTien(800, 820, 100,50,"NEXT");
button btnThem(1250, 625,100,50,"THEM");
button btnHieuChinh(1075, 625,200,50,"HIEU CHINH");
button btnXoaVinhVien(1325, 625,200,50,"XOA VINH VIEN");
button btnThoat(1050,20,220,50,"< THOAT CHUC NANG");

// nut chuc nang mon hoc tai man hinh gv
int xDsMon[3] = {50,300,950};
int yDsMon[2] = {250,750};
button btnQuaylai(20,20,100,50,"< BACK");
editText timKiemMon(100,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN mon hoc muon tim",100);
button btnMenuThemMon(1175,20,250,50,"MENU THEM MON HOC");
editText themMaMon(1075,350,450,50,"MA MON:","Toi da 10 ki tu",10);
editText themTenMon(1075,475,450,50,"TEN MON:","Toi da 35 ki tu",35);


// nut chuc nang quan ly lop
int xDsLop[3] = {50, 350, 950};
int yDsLop[2] = {250,750};
button btnMenuThemLop(1175,20,250,50,"MENU THEM LOP HOC");
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



// man hinh hoc sinh
button btnThi(350, 100, 200, 50, "THI");
button btnXemLai(350, 200, 200, 50, "XEM LAI BAI THI");
button btnDoiMK(350, 300, 200, 50, "DOI MAT KHAU");
button btndangxuat(350, 400, 200,50, "DANG XUAT");

// man hinh thiet lap chuc nang thi
button btnThietLapThi(700,300,250,50,"THIET LAP LICH THI");
button btnThiThu(700,450,250,50,"THI THU");
editText edNgayThi(975,200,200,50,"","dd",2);
editText edThangThi(1150,200,200,50,"","mm",2);
editText edNamThi(1325,200,230,50,"","yyyy",4);

// editText edbatdauGio(950,350,200,50,"","gio",2);
// editText edbatdauPhut(1040,350,210,50,"","phut",2);
editText edbatdauGio(1075,350,450,50,"GIO THI:","Tu 6h -> 17h",15);
editText edbatdauPhut(1075,425,450,50,"PHUT:","Tu 0 -> 60p",2);
editText edTimeThi(1075,575,450,50,"T/G LAM BAI:","Tinh theo phut",15);
editText edsoCau(1075,650,450,50,"SO CAU:","So cau trong bai thi",15);



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
        else if ( curMenu == DISPLAY_LICHTHI) {
            if (Edit == & timKiemMon) {
                Scan(Edit,Edit->textSize,TEXT_NUMBER);
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
