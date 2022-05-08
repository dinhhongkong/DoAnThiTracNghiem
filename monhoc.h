// // --------------------------- CHUC NANG PHU ------------------------------
// void Chuan_Hoa_MAMH(string& maMH);
// void Chuan_Hoa_TENMH(string& tenMH);
// int Tim_Kiem_MAMH(ListMonHoc listMH, string maMH);
// int Tim_Kiem_TENMH(ListMonHoc listMH, string tenMH);

// // --------------------------- CHUC NANG CHINH -----------------------------
bool Them_Mon_Hoc(ListMonHoc &listMH, Mon_Hoc mh);
void Xuat_Danh_Sach_Mon_Hoc(ListMonHoc listMH);
void Xoa_Mon_Hoc(ListMonHoc &listMH, string maMH);
void Hieu_Chinh_Mon_Hoc(ListMonHoc &listMH, string maMH);
void Doc_File_Mon_Hoc(ListMonHoc &listMH);
void Luu_File_Mon_Hoc(ListMonHoc listMH);

void Doc_File_Mon_Hoc(ListMonHoc &listMH)
{
	ifstream filein;
	filein.open("DATA\\DANHSACHMONHOC.txt", ios_base::in);
	if (!filein.is_open())
		return;

	filein >> listMH.slmh;
	filein.ignore();
	for (int i = 0; i < listMH.slmh; i++)
	{
		Mon_Hoc mh;
		getline(filein, mh.MAMH, ',');
		getline(filein, mh.TENMH);
		listMH.monHoc[i] = new Mon_Hoc;
		*listMH.monHoc[i] = mh;
	}
	filein.close();
}

void Luu_File_Mon_Hoc(ListMonHoc listMH)
{
	ofstream fileout;
	fileout.open("DATA\\DANHSACHMONHOC.txt", ios_base::out);
	fileout << listMH.slmh << endl; // bo xung
	for (int i = 0; i < listMH.slmh; i++)
	{
		fileout << listMH.monHoc[i]->MAMH << "," << listMH.monHoc[i]->TENMH << endl;
	}
	fileout.close();
}

bool Them_Mon_Hoc(ListMonHoc &listMH, Mon_Hoc mh)
{
	// bat trung ten hoac ma
	for (int i = 0; i < listMH.slmh; i++)
	{
		if (mh.MAMH == listMH.monHoc[i]->MAMH || mh.TENMH == listMH.monHoc[i]->TENMH)
		{
			AllocConsole();
			MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "MA MON hoac TEN MON da ton tai!", "Thong bao", MB_ICONASTERISK | MB_OK);
			return false;
		}
	}

	int N = listMH.slmh;
	if (N == MAXMONHOC)
	{
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Danh sach mon hoc da day!", "Thong bao", MB_ICONASTERISK | MB_OK);
	}
	else
	{
		listMH.monHoc[N] = new Mon_Hoc();
		listMH.slmh++;
		if (N == 0)
		{
			*listMH.monHoc[0] = mh;
		}
		else
		{
			if (mh.MAMH > listMH.monHoc[N - 1]->MAMH)
			{
				*listMH.monHoc[N] = mh;
			}
			else
			{
				for (int i = 0; i < N; i++)
				{
					if (mh.MAMH < listMH.monHoc[i]->MAMH)
					{
						for (int j = N; j > i; j--)
						{
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
	return true;
}


bool KiemTra_MH_TonTai_CH(NodeCauHoi *r, string maMonHoc)
{
	if (r != nullptr)
	{
		if (r->info.maMonHoc == maMonHoc)
			return true;
		if (KiemTra_MH_TonTai_CH(r->left, maMonHoc) || KiemTra_MH_TonTai_CH(r->right, maMonHoc))
			return true;
	}
	return false;
}

bool Hieu_Chinh_Mon_Hoc(NodeCauHoi *r , ListMonHoc &listMH, int index, string maMon, string tenMon)
{
	if (maMon == listMH.monHoc[index]->MAMH && tenMon == listMH.monHoc[index]->TENMH)
	{
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong chinh sua, do MA MON vs TEN MON nhap vao van giu nguyen ", "Thong bao", MB_OK);
		return false;
	}

	if (KiemTra_MH_TonTai_CH(r,listMH.monHoc[index]->MAMH) ) {
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong chinh sua MA MON, do co cau hoi", "Thong bao", MB_OK);
		return false;
	}

	Mon_Hoc mh;
	mh.MAMH = maMon;
	mh.TENMH = tenMon;
	// --------------------------------------
	for (int i = 0; i < listMH.slmh; i++)
	{
		if (i == index)
		{
			continue;
		}
		if (mh.MAMH == listMH.monHoc[i]->MAMH || mh.TENMH == listMH.monHoc[i]->TENMH)
		{
			AllocConsole();
			MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "MA MON hoac TEN MON da ton tai!", "Thong bao", MB_ICONASTERISK | MB_OK);
			return false;
		}
	}
	*listMH.monHoc[index] = mh;
	if (listMH.slmh == 1)
		return true;

	if (index > 0 && mh.MAMH < listMH.monHoc[index - 1]->MAMH)
	{
		for (int i = index - 1; i >= 0; i--)
		{
			if (mh.MAMH > listMH.monHoc[i]->MAMH)
				break;
			swap(*listMH.monHoc[index], *listMH.monHoc[i]);
			index = i;
		}
	}
	else if (index < listMH.slmh - 1 && mh.MAMH > listMH.monHoc[index + 1]->MAMH)
	{
		for (int i = index + 1; i < listMH.slmh; i++)
		{
			if (mh.MAMH < listMH.monHoc[i]->MAMH)
				break;
			swap(*listMH.monHoc[index], *listMH.monHoc[i]);
			index = i;
		}
	}
	AllocConsole();
	MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thanh cong", "Thong bao", MB_OK);
	return true;
}





bool Xoa_Mon_Hoc(NodeCauHoi *r, ListMonHoc &listMH, int index)
{
	if (KiemTra_MH_TonTai_CH(r, listMH.monHoc[index]->MAMH))
	{
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Mon hoc ton tai cau hoi thi. Khong the xoa!", "Thong bao", MB_OK);
		return false;
	}

	for (int i = index + 1; i < listMH.slmh; i++)
	{
		*listMH.monHoc[i - 1] = *listMH.monHoc[i];
	}
	Mon_Hoc *ptr = listMH.monHoc[listMH.slmh - 1];
	delete ptr;
	listMH.slmh--;
	AllocConsole();
	MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Xoa mon hoc thanh cong", "Thong bao", MB_OK);
	return true;
}

string Truy_Xuat_Ten_Mon(ListMonHoc listMH, string maMonHoc)
{
	int left = 0, right = listMH.slmh - 1;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (listMH.monHoc[middle]->MAMH == maMonHoc)
		{
			return listMH.monHoc[middle]->TENMH;
		}
		if (maMonHoc < listMH.monHoc[middle]->MAMH)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return "";
}
