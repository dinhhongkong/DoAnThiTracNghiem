// struct sinhVien{
// 	string mssv;
// 	string HO;
// 	string TEN;
// 	string gioiTinh;
// 	string password;
// 	// con tro tro den cac mon da thi trac nghiem
// 	//dsdiemThi diem;
// };

// struct nodeSV{
// 	sinhVien info;
// 	nodeSV *pNext = nullptr;
// };

// struct listSV
// {
// 	nodeSV *First = nullptr;
// 	nodeSV *Last = nullptr;
// };

nodeSV *CreateNodeSV(sinhVien sv)
{
	nodeSV *a = new nodeSV;
	a->info = sv;
	a->pNext = nullptr;
	return a;
}

void CreateList(listSV &l)
{
	l.First = nullptr;
	l.Last = nullptr;
}

void AddLast(listSV &l, nodeSV *sv)
{
	if (l.First == nullptr)
	{
		l.First = sv;
		l.Last = sv;
	}
	else
	{
		l.Last->pNext = sv;
		l.Last = sv;
	}
}



void AddFirst(listSV &l, nodeSV *sv)
{
	if (l.First == nullptr)
	{
		l.First = sv;
		l.Last = sv;
	}
	else
	{
		sv->pNext = l.First;
		l.First = sv;
	}
}

// CHEN VAO DANH SACH SINH VIEN THEO THU TU
bool InsertNodeSV(listSV &l, sinhVien sv)
{
	if (l.First == nullptr)
	{
		AddFirst(l, CreateNodeSV(sv));
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
		return true;
	}

	if (l.First->info.mssv > sv.mssv)
	{
		cout << " chen sinh vien len dau" << endl;
		nodeSV *p = new nodeSV;
		p->info = sv;
		p->pNext = l.First;
		l.First = p;
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
		return true;
	}

	if (l.Last->info.mssv < sv.mssv)
	{
		cout << " chen sinh vien xuong cuoi" << endl;
		AddLast(l, CreateNodeSV(sv));
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
		return true;
	}

	cout << " chen sinh vien vao giua" << endl;
	nodeSV *temp = l.First;
	while (temp != nullptr)
	{
		if (temp->info.mssv == sv.mssv)
		{
			AllocConsole();
			MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Ma so sinh vien da ton tai", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
			return false;
		}

		if (temp->pNext->info.mssv > sv.mssv)
		{
			nodeSV *chenSV = CreateNodeSV(sv);

			chenSV->pNext = temp->pNext;
			temp->pNext = chenSV;
			AllocConsole();
			MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
			return true;
		}
		temp = temp->pNext;
	}
	return false;
}

bool ChinhSuaSinhVien(nodeSV *node) {

	

}

// dem so luong phan tu danh sach lien ket don sinh vien
int SizeListSV(listSV l)
{
	int count = 0;
	nodeSV* node = l.First;
	while (node != NULL)
	{
		count++;
		node = node->pNext;
	}
	return count;
}

void DocDsSinhVien(listSV &dsSinhVien, string maLop)
{
	ifstream fileIn;
	string nameFILE = "DATA\\" + maLop + ".txt";
	fileIn.open(nameFILE, ios_base::in);
	if (!fileIn.is_open())
	{
		cout << "Khong mo dc file " << maLop << endl;
		return;
	}
	else
	{
		cout << "doc dc file " << maLop << endl;
	}

	sinhVien sv;
	while (getline(fileIn, sv.mssv, ','))
	{
		getline(fileIn, sv.Ho, ',');
		getline(fileIn, sv.Ten, ',');
		fileIn >> sv.gioiTinh;
		fileIn.ignore();
		getline(fileIn, sv.Pass, '\n');
		// cout << sv.mssv << '\n'<< sv.Ho << '\n' << sv.Ten << '\n' << sv.gioiTinh << '\n' << sv.Pass << '\n';
		AddLast(dsSinhVien, CreateNodeSV(sv));
	}
	fileIn.close();
}

void ghiFileDsSinhVien(listSV &dsSinhVien, string maLop)
{
	ofstream fileOut;
	string nameFILE = "DATA\\" + maLop + ".txt";
	fileOut.open(nameFILE, ios_base::out);
	nodeSV *temp = dsSinhVien.First;
	while (temp != nullptr)
	{
		fileOut << temp->info.mssv << ',' << temp->info.Ho << ',' << temp->info.Ten << ',' << temp->info.gioiTinh << ',' << temp->info.Pass << '\n';
		// cout << temp->info.mssv << '\n'<< temp->info.Ho << '\n' << temp->info.Ten << '\n' << temp->info.gioiTinh << '\n' << temp->info.Pass << '\n';
		temp = temp->pNext;
	}
	cout << "ghi thanh cong sv" << endl;
	fileOut.close();
}
