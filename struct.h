#define MAXLOP 100
#define MAXMONHOC 100
#define STACKSIZE 1000
#include<iostream>
using namespace std;


// ------------------ KHAI BAO CTDL MON HOC --------------------
struct Mon_Hoc {
	string MAMH;
	string TENMH;
};

struct Danh_Sach_Mon_Hoc {
	Mon_Hoc* monHoc[MAXMONHOC];
	int slmh = 0;
};
typedef Danh_Sach_Mon_Hoc ListMonHoc;

// ------------------ KHAI BAO CTLD DIEM THI -------------------
struct Diem_Thi {
	string MAMH;
	float Diem;
};

struct Node_Diem_Thi {
	Diem_Thi info;
	Node_Diem_Thi* DTnext = NULL;
};
typedef Node_Diem_Thi* DTNode;

struct Danh_Sach_Diem_Thi {
	DTNode* first = NULL;
};
typedef Danh_Sach_Diem_Thi ListDiemThi;



//------------------------------------------------CAU HOI------------------------------------------------
struct CauHoi 
{
    int id;
    string maMonHoc;
    string NoiDung;
    string A;
    string B; 
    string C; 
    string D;
    char DapAn;
};


struct NodeCauHoi
{
    CauHoi info;
    int key;
    int bf;
    NodeCauHoi *Left = nullptr, *Right = nullptr;
};

struct TreeCauHoi
{
    CauHoi *root = nullptr;
};




//---------------------------------------SINH VIEN---------------------------------------------------
struct sinhVien{
	string mssv;
    string Pass;
	string Ho;
	string Ten;
	int gioiTinh;
	// string password;
	// con tro tro den cac mon da thi trac nghiem
	//dsdiemThi diem;
};

struct nodeSV{
	sinhVien info;
	nodeSV *pNext = nullptr;
};

struct listSV
{
	nodeSV *First = nullptr;	
	nodeSV *Last = nullptr;
};

//---------------------------------------LOP HOC-------------------------------------------------------

struct lop
{
    string MALOP;
    string TENLOP;
    listSV dsSinhVien;
};

struct dslop
{
    int solop = 0;
    lop arrLop[MAXLOP]; // danh sach tuyen tinh
};

//------------------------------------struct thoi gian--------------------------------------------

struct ngayThangNam {
	int ngay = 0;
	int thang = 0 ;
	int nam = 0;
};

struct gioPhuGiay {
	int gio = 0;
	int phut = 0;
	int giay = 0;
};

































// // CAU TRUC DANH SACH MON HOC
// //Danh sach tuyen tinh: MAMH, TENMH

// struct monHoc{
// 	string MAMH;
// 	string TENMH;
// };

// struct DSMH{
// 	int somon = 0;
// 	monHoc *m[MAXMONHOC] = {NULL};
// };

// struct CTdethi
// {
// 	int sct;
// 	int tg;
// 	int *bode;
// 	int *dapan;
// };

// // CAU TRUC DANH SACH DIEM THI
// //Danh sach lien ket don MAMH, DIem

// struct diemThi{
// 	string MAMH;
// 	float DIEM;
// 	CTdethi ctdt;
// };

// struct nodediemThi{
// 	diemThi info;
// 	nodediemThi *pNext = NULL;
// };


// struct dsdiemThi
// {
// 	nodediemThi *First = NULL;
// };


// // CAU TRUC DANH SACH SINH VIEN
// //Danh sach lien ket don (MASV, HO, TEN,  PHAI, password, con tro), con tro tro den diem cac mon da thi trac nghiem

// struct sinhVien{
// 	string MASV;
// 	string HO;
// 	string TEN;
// 	string PHAI;
// 	string password;
// 	// con tro tro den cac mon da thi trac nghiem
// 	dsdiemThi diem;
// };

// struct nodeSV{
// 	sinhVien info;
// 	nodeSV *pNext = NULL;
// };

// struct dssv
// {
// 	nodeSV	*First = NULL;	
// };
// //CAU TRUC DANH SACH LOP
// //Mang con tro: MALOP, TENLOP con tro (con tro se tro den danh sach sinh vien thuoc lop do)

// struct lop{
// 	string MALOP;
// 	string TENLOP;
// 	dssv danhsach;
// };

// struct dslop{
// 	int solop;
// 	lop *l [MAXLOP] = {NULL};
// };
//  /*CAU TRUC CAU HOI THI
// cay nhi phan tim kiem can bang: key= id Id, MA MH, Noi dung, A, B, C, D, DapAn
//  A,B,C,D la 4 lua chon tuong ung noi dung cau hoi*/

// struct cauHoi{
// 	string MAMH;
// 	string NOIDUNG;
// 	string A;
// 	string B;
// 	string C;
// 	string D;
// 	char DAPAN;			//string DAPAN;
// };

// struct nodecauHoi
// {
// 	int id;
// 	cauHoi info;
// 	nodecauHoi *pLeft = NULL;
// 	nodecauHoi *pRight = NULL;
// };

// typedef struct nodecauHoi *NODECH;

// struct dscauhoi
// {
// 	nodecauHoi *Root = NULL;
// };

// // thoi gian
// struct TG 
// {
// 	int gio;
// 	int phut;
// 	int giay;
// };
// #endif
