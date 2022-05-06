#define MAXLOP 100
#define MAXMONHOC 100
#define STACKSIZE 1000
#pragma once
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
    char DapAn; // A, B C, D la dap an dung
};


struct NodeCauHoi
{
	int key;
    CauHoi info;
    int height;
    NodeCauHoi *left = nullptr, *right = nullptr;
};

struct mangCauHoi
{
    int tongSoCau = 0;
    NodeCauHoi *arrCauHoiThi[MAX_CAUHOI];
};

// struct TreeCauHoi
// {
//     NodeCauHoi *root = nullptr;
// };


// ------------------------ CAU HOI THI & BAI THI --------------------------
struct cauHoiThi {
	CauHoi cauHoiThi;
	char luaChon;
};


struct Bai_Thi {
	int slcht =0;
	cauHoiThi *arrCauHoi;
};


// ------------------ KHAI BAO CTLD DIEM THI -------------------
struct Diem_Thi {
	string MAMH;
	float Diem;
	Bai_Thi baithi;
};

struct Node_Diem_Thi {
	Diem_Thi info;
	Node_Diem_Thi* DTnext = nullptr;
};
// typedef Node_Diem_Thi* DTNode;

struct Danh_Sach_Diem_Thi {
	Node_Diem_Thi  *first = nullptr;
};
// typedef Danh_Sach_Diem_Thi ListDiemThi;



//---------------------------------------SINH VIEN---------------------------------------------------
struct sinhVien{
	string mssv;
    string Pass;
	string Ho;
	string Ten;
	int gioiTinh;
    Danh_Sach_Diem_Thi listDT;
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
