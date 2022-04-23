// // --------------------------- CHUC NANG PHU ------------------------------
// void Chuan_Hoa_MAMH(string& maMH);
// void Chuan_Hoa_TENMH(string& tenMH);
// int Tim_Kiem_MAMH(ListMonHoc listMH, string maMH);
// int Tim_Kiem_TENMH(ListMonHoc listMH, string tenMH);

// // --------------------------- CHUC NANG CHINH -----------------------------
void Them_Mon_Hoc(ListMonHoc& listMH, Mon_Hoc mh);
void Xuat_Danh_Sach_Mon_Hoc(ListMonHoc listMH);
void Xoa_Mon_Hoc(ListMonHoc& listMH, string maMH);
void Hieu_Chinh_Mon_Hoc(ListMonHoc& listMH, string maMH);
void Doc_File_Mon_Hoc(ListMonHoc& listMH);
void Luu_File_Mon_Hoc(ListMonHoc listMH);

void Doc_File_Mon_Hoc(ListMonHoc& listMH) {
	ifstream filein;
	filein.open("DATA\\DANHSACHMONHOC.txt", ios_base::in);
	if (!filein.is_open()) return;

	filein >> listMH.slmh;
	filein.ignore();
	for (int i = 0; i < listMH.slmh; i++) {
		Mon_Hoc mh;
		getline(filein, mh.MAMH, ',');
		getline(filein, mh.TENMH );
		listMH.monHoc[i] = new Mon_Hoc;
		*listMH.monHoc[i] = mh;
	}
	filein.close();
}

void Luu_File_Mon_Hoc(ListMonHoc listMH) {
	ofstream fileout;
	fileout.open("DATA\\DANHSACHMONHOC.txt", ios_base::out);
	fileout << listMH.slmh << endl; // bo xung
	for (int i = 0; i < listMH.slmh; i++) {
		fileout << listMH.monHoc[i]->MAMH << "," << listMH.monHoc[i]->TENMH << endl;
	}
	fileout.close();
}

void Them_Mon_Hoc(ListMonHoc& listMH, Mon_Hoc mh) {
	int N = listMH.slmh;
	if (N == MAXMONHOC) {
		AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Danh sach mon hoc da day!", "Thong bao", MB_ICONASTERISK | MB_OK);
	}
	else {
		listMH.monHoc[N] = new Mon_Hoc(); 
		listMH.slmh++;
		if (N == 0) {
			*listMH.monHoc[0] = mh;
		}
		else {
			if (mh.MAMH > listMH.monHoc[N - 1]->MAMH) {
				*listMH.monHoc[N] = mh;
			}
			else {
				for (int i = 0; i < N; i++) {
					if (mh.MAMH < listMH.monHoc[i]->MAMH) {
						for (int j = N; j > i; j--) {
							*listMH.monHoc[j] = *listMH.monHoc[j - 1];
						}
						*listMH.monHoc[i] = mh;
						break;
					}
				}
			}
		}
	}
	AllocConsole();
    MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them mon hoc thanh cong", "Thong bao", MB_OK);
}

void Hieu_Chinh_Mon_Hoc(ListMonHoc& listMH, int index) {
	Mon_Hoc mh;
	// --------------------------------------
	// NHẬP LIỆU
	getline(cin, mh.MAMH);
	getline(cin, mh.TENMH);
	// --------------------------------------
	for (int i = 0; i < listMH.slmh; i++) {
		if (mh.MAMH == listMH.monHoc[i]->MAMH || mh.TENMH == listMH.monHoc[i]->TENMH) {
			// BÁO LỖI
			return;
		}
	}
	*listMH.monHoc[index] = mh;
	if (listMH.slmh == 1) return;

	if (index == 0) {
		for (int i = 1; i < listMH.slmh; i++) {
			if (mh.MAMH < listMH.monHoc[i]->MAMH) break;
			swap(*listMH.monHoc[index], *listMH.monHoc[i]);
			index = i;
		}
	}
	else if (index == listMH.slmh - 1) {
		for (int i = listMH.slmh - 1; i >= 0; i--) {
			if (mh.MAMH > listMH.monHoc[i]->MAMH) break;
			swap(*listMH.monHoc[index], *listMH.monHoc[i]);
			index = i;
		}
	}
	else {
		if (mh.MAMH < listMH.monHoc[index - 1]->MAMH) {
			for (int i = index - 1; i >= 0; i--) {
				if (mh.MAMH > listMH.monHoc[i]->MAMH) break;
				swap(*listMH.monHoc[index], *listMH.monHoc[i]);
				index = i;
			}
		}
		else {
			for (int i = index + 1; i < listMH.slmh; i++) {
				if (mh.MAMH < listMH.monHoc[i]->MAMH) break;
				swap(*listMH.monHoc[index], *listMH.monHoc[i]);
				index = i;
			}
		}
	}
}

// void Xuat_Danh_Sach_Mon_Hoc(ListMonHoc listMH) {
// 	cout << listMH.slmh << endl;
// 	int N = listMH.slmh;
// 	if (N == 0) {
// 		cout << "Danh sach rong!";
// 	}
// 	else {
// 		for (int i = 0; i < N; i++) {
// 			cout << listMH.monHoc[i]->MAMH << " " << listMH.monHoc[i]->TENMH << endl;
// 		}
// 	}
// }

// void Xoa_Mon_Hoc(ListMonHoc& listMH, string maMH) {
// 	int index = Tim_Kiem_MAMH(listMH, maMH);
// 	if (index == -1) {
// 		cout << "Ma mon hoc khong ton tai!";
// 	}
// 	else {
// 		int N = listMH.slmh;
// 		for (int i = index + 1; i < N; i++) {
// 			*listMH.monHoc[i - 1] = *listMH.monHoc[i];
// 		}
// 		Mon_Hoc* ptr = listMH.monHoc[N - 1];
// 		delete ptr; 
// 		listMH.slmh--;
// 	}	
// }

// void Hieu_Chinh_Mon_Hoc(ListMonHoc& listMH, string maMH) {
// 	listMH.monHoc[i]
// 	if (index == -1) {
// 		cout << "Ma mon hoc khong ton tai!";
// 	}
// 	else {
// 		string tenMH;
// 		// cout << "Nhap ten mon hoc: "; getline(cin, tenMH);
// 		// Chuan_Hoa_TENMH(tenMH);
// 		listMH.monHoc[index]->TENMH = tenMH;
// 	}
// }