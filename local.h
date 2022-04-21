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
editText taiKhoan(500, 300, 600, 50, "TAI KHOAN: ", "Nhap ma so sinh vien", 100);
editText matKhau(500, 400, 600, 50, "MAT KHAU: ", "Toi da 20 ki tu", 20, 1);
button dangnhap(700, 500, 200, 70, "DANG NHAP");

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
button btnThem(1250, 625,100,50,"THEM");
// button btnHieuChinh(200,1100, 625,400,50,"HIEU CHINH");
// button btnXoaVinhVien(200,1200, 710,200,50,"XOA VINH VIEN");
button btnHieuChinh(1075, 625,200,50,"HIEU CHINH");
button btnXoaVinhVien(1325, 625,200,50,"XOA VINH VIEN");
button btnThoat(1050,20,220,50,"< THOAT CHUC NANG");

// nut chuc nang mon hoc tai man hinh gv
int xDsMon[3] = {50,300,950};
int yDsMon[2] = {250,760};
button btnQuaylai(20,20,100,50,"< BACK");
editText timKiemMon(100,100,600,50,"TIM KIEM: ","Nhap ten mon hoc muon tim",100);
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
int xDsSV[6] = {50,200,500,650,  950};
button btnMenuThemSV(1175,20,250,50,"MENU THEM SINH VIEN");
editText edtimKiemSV(100,100,600,50,"TIM KIEM: ","Nhap MA hoac TEN sinh vien muon tim",100);
editText edMSSV(1075,325,450,50,"MSSV:","Toi da 10 ki tu",10);
editText edHoSV(1075,400,450,50,"Ho va ten dem:","nhap ho vs ten lot",40);
editText edTenSV(1075,475,450,50,"Ten:","Toi da 7 ki tu",7);
button btnNam(1225, 540, 100,40,"NAM");
button btnNu(1350, 540, 100,40,"NU");



// man hinh hoc sinh
button btnThi(350, 100, 200, 50, "THI");
button btnXemLai(350, 200, 200, 50, "XEM LAI BAI THI");
button btnDoiMK(350, 300, 200, 50, "DOI MAT KHAU");
button btndangxuat(350, 400, 200,50, "DANG XUAT");

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
            if ( Edit == &themTenMon) {
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
