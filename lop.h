
struct lop
{
    string MALOP;
    string TENLOP;
    // dssv *danhsachSinhVien;
};

#define MAXLOP 100
#define MAXMONHOC 100
#define STACKSIZE 1000

struct dslop
{
    int solop = 0;
    lop *arrLop[MAXLOP]; // danh sach tuyen tinh
};

// kiem tra ma lop hay ten lop co bi trung khong
bool CheckMaLopTenLop(dslop ds, string maLop, string tenlop)
{
    for (int i = 0; i < ds.solop; i++)
    {

        if (ds.arrLop[i]->MALOP == maLop || ds.arrLop[i]->TENLOP == tenlop)
        {
            return false;
        }
    }
    return true;
}

string ThemVaoDanhSach(dslop &ds, string maLop, string tenLop)
{

    if (maLop == "" ) {
        return "Ma lop khong duoc de trong";
    }

    if ( tenLop == "" ) {
        return "Ten lop khong duoc de trong";
    }

    if (!CheckMaLopTenLop(ds, maLop, tenLop))
    {
        return "MA LOP hoac TEN LOP da ton tai";
    }

    if (ds.solop == MAXLOP)
    {
        return "Danh sach lop da day";
    }

    ds.arrLop[ds.solop] = new lop;
    int i = 0;

    if (ds.solop == 0 || tenLop < ds.arrLop[0]->TENLOP)
    {
        i = 0;
    }
    else if (tenLop > ds.arrLop[ds.solop - 1]->TENLOP)
    {
        i = ds.solop;
    }
    else
    {
        for (i = 0; i < ds.solop - 1; i++)
        {
            if (ds.arrLop[i]->TENLOP > tenLop)
            {
                break;
            }
        }
    }
    for (int j = ds.solop; j > i; j--)
    {
        ds.arrLop[j]->MALOP = ds.arrLop[j - 1]->MALOP;
        ds.arrLop[j]->TENLOP = ds.arrLop[j - 1]->TENLOP;
    }
    ds.arrLop[i]->TENLOP = tenLop;
    ds.arrLop[i]->MALOP = maLop;
    ds.solop++;
    return "Nhap thanh cong";
}



