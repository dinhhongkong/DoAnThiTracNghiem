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
bool Doc_File_Mon_Hoc(ListMonHoc& listMH);
void Luu_File_Mon_Hoc(ListMonHoc listMH);

// // ------------------------- DINH NGHIA HAM PHU ----------------------------
// void Chuan_Hoa_MAMH(string& maMH) {
// 	for (int i = 0; i < maMH.length(); i++) {
// 		if (maMH[i] >= 'a' && maMH[i] <= 'z') {
// 			maMH[i] -= 32;
// 		}
// 	}
// }

// void Chuan_Hoa_TENMH(string& tenMH) {
// 	string str, temp;
// 	stringstream ss(tenMH);
// 	while (ss >> temp) {
// 		for (int i = 0; i < temp.length(); i++) {
// 			if (temp[i] >= 'A' && temp[i] <= 'Z') {
// 				temp[i] += 32;
// 			}
// 		}
// 		str.append(temp);
// 		str.append(" ");
// 	}
// 	str.front() -= 32;
// 	str.pop_back();
// 	tenMH = str;
// }

int Tim_Kiem_MAMH(ListMonHoc listMH, string maMH) {
	for (int i = 0; i < listMH.slmh; i++) {
		if (maMH == listMH.monHoc[i]->MAMH) return i;
	}
	return -1;
}

int Tim_Kiem_TENMH(ListMonHoc listMH, string tenMH) {
	for (int i = 0; i < listMH.slmh; i++) {
		if (tenMH == listMH.monHoc[i]->TENMH) return i;
	}
	return -1;
}

// ------------------------ DINH NGHIA HAM CHINH ---------------------------
bool Doc_File_Mon_Hoc(ListMonHoc& listMH) {
	ifstream filein;
	filein.open("DS_MONHOC.TXT", ios_base::in);
	while (filein.eof() != true) {
		Mon_Hoc mh;
		getline(filein, mh.MAMH, ',');
		getline(filein, mh.TENMH);
		Them_Mon_Hoc(listMH, mh);
	}
	filein.close();
	if (filein.eof() == true) {
		cout << "Doc du lieu thanh cong!";
		return true;
	}
	else {
		cout << "Doc du lieu that bai!";
		return false;
	}
}

void Luu_File_Mon_Hoc(ListMonHoc listMH) {
	ofstream fileout;
	fileout.open("DS_MONHOC.TXT", ios_base::out);
	for (int i = 0; i < listMH.slmh; i++) {
		fileout << listMH.monHoc[i]->MAMH << "," << listMH.monHoc[i]->TENMH << endl;
	}
	fileout.close();
	cout << "Luu du lieu thanh cong!";
}

void Them_Mon_Hoc(ListMonHoc& listMH, Mon_Hoc mh) {
	int N = listMH.slmh;
	if (N == MAXMONHOC) {
		cout << "Danh sach mon hoc da day!" << endl;
		cout << N << endl;
	}
	else {
		listMH.monHoc[N] = new Mon_Hoc(); listMH.slmh++;
		if (N == 0) {
			*listMH.monHoc[0] = mh;
		}
		else {
			if (mh.TENMH > listMH.monHoc[N - 1]->TENMH) {
				*listMH.monHoc[N] = mh;
			}
			else {
				for (int i = 0; i < N; i++) {
					if (mh.TENMH < listMH.monHoc[i]->TENMH) {
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
}

void Xuat_Danh_Sach_Mon_Hoc(ListMonHoc listMH) {
	int N = listMH.slmh;
	if (N == 0) {
		cout << "Danh sach rong!";
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << listMH.monHoc[i]->MAMH << " " << listMH.monHoc[i]->TENMH << endl;
		}
	}
}

void Xoa_Mon_Hoc(ListMonHoc& listMH, string maMH) {
	int index = Tim_Kiem_MAMH(listMH, maMH);
	if (index == -1) {
		cout << "Ma mon hoc khong ton tai!";
	}
	else {
		int N = listMH.slmh;
		for (int i = index + 1; i < N; i++) {
			*listMH.monHoc[i - 1] = *listMH.monHoc[i];
		}
		Mon_Hoc* ptr = listMH.monHoc[N - 1];
		delete ptr; listMH.slmh--;
	}	
}

void Hieu_Chinh_Mon_Hoc(ListMonHoc& listMH, string maMH) {
	int index = Tim_Kiem_MAMH(listMH, maMH);
	if (index == -1) {
		cout << "Ma mon hoc khong ton tai!";
	}
	else {
		string tenMH;
		// cout << "Nhap ten mon hoc: "; getline(cin, tenMH);
		// Chuan_Hoa_TENMH(tenMH);
		listMH.monHoc[index]->TENMH = tenMH;
	}
}