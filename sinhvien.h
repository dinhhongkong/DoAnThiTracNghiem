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

// chinh sua ko lam thay doi thu tu
bool ChinhSuaSinhVien(listSV &DsSinhVien, nodeSV *&nodeHieuChinh, string Mssv, string Ho, string Ten, int GioiTinh)
{
	nodeSV *node = DsSinhVien.First;
	if (Mssv != nodeHieuChinh->info.mssv)
	{
		while (node != nullptr)
		{
			cout << "chay dc ko" << endl;
			if (node == nodeHieuChinh)
			{

				node = nodeHieuChinh->pNext;
				continue;
			}

			if (node->info.mssv == Mssv)
			{
				AllocConsole();
				MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong the chinh sua, Ma so sinh vien da ton tai", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
				return false;
			}
			node = node->pNext;
		}
	}
	nodeSV *PreNodeHieuChinh = nullptr;
	if (nodeHieuChinh != DsSinhVien.First)
	{
		PreNodeHieuChinh = DsSinhVien.First;
		while (PreNodeHieuChinh->pNext != nodeHieuChinh)
		{
			PreNodeHieuChinh = PreNodeHieuChinh->pNext;
		}
	}

	// neu chi co 1 phan tu duy nhat
	if (nodeHieuChinh == DsSinhVien.First && nodeHieuChinh == DsSinhVien.Last) {
		nodeHieuChinh->info.mssv = Mssv;
		nodeHieuChinh->info.Ho = Ho;
		nodeHieuChinh->info.Ten = Ten;
		nodeHieuChinh->info.gioiTinh = GioiTinh;
	}
	// neu ko thay doi mssv khoi sap sep lai
	else if (nodeHieuChinh->info.mssv == Mssv)
	{
		nodeHieuChinh->info.mssv = Mssv;
		nodeHieuChinh->info.Ho = Ho;
		nodeHieuChinh->info.Ten = Ten;
		nodeHieuChinh->info.gioiTinh = GioiTinh;
	}
	// neu mssv dau tien lon hon mssv hieu chinh
	else if (DsSinhVien.First->info.mssv > Mssv || ( nodeHieuChinh == DsSinhVien.First && Mssv < nodeHieuChinh->pNext->info.mssv) )
	{
		if ( nodeHieuChinh == DsSinhVien.Last) {
			nodeHieuChinh->pNext = DsSinhVien.First;
			DsSinhVien.First = DsSinhVien.First->pNext;
			DsSinhVien.Last = PreNodeHieuChinh;
			PreNodeHieuChinh->pNext = nullptr;
			DsSinhVien.First = nodeHieuChinh;
		}
		else if ( PreNodeHieuChinh != nullptr) {
			PreNodeHieuChinh->pNext = nodeHieuChinh->pNext;
			nodeHieuChinh->pNext = DsSinhVien.First;
			DsSinhVien.First = nodeHieuChinh;
		}
		nodeHieuChinh->info.mssv = Mssv;
		nodeHieuChinh->info.Ho = Ho;
		nodeHieuChinh->info.Ten = Ten;
		nodeHieuChinh->info.gioiTinh = GioiTinh;
	}
	// neu mssv cuoi lon hon mssv hieu chinh
	else if (DsSinhVien.Last->info.mssv < Mssv || ( nodeHieuChinh == DsSinhVien.Last && Mssv > PreNodeHieuChinh->info.mssv) )
	{
		if ( nodeHieuChinh == DsSinhVien.First) {
			DsSinhVien.First = DsSinhVien.First->pNext;
			DsSinhVien.Last->pNext = nodeHieuChinh;
			DsSinhVien.Last = nodeHieuChinh;
		}
		else if ( PreNodeHieuChinh->pNext != DsSinhVien.Last) {
			PreNodeHieuChinh->pNext = nodeHieuChinh->pNext;
			DsSinhVien.Last->pNext = nodeHieuChinh;
			DsSinhVien.Last = nodeHieuChinh;
		}
		nodeHieuChinh->info.mssv = Mssv;
		nodeHieuChinh->info.Ho = Ho;
		nodeHieuChinh->info.Ten = Ten;
		nodeHieuChinh->info.gioiTinh = GioiTinh;
		nodeHieuChinh->pNext = nullptr;
	}
	else
	{
		node = DsSinhVien.First;
		nodeSV *preNode = nullptr;
		while (node != nullptr)
		{
			if (node->info.mssv > Mssv)
			{
				PreNodeHieuChinh->pNext = nodeHieuChinh->pNext;
				nodeHieuChinh->pNext = preNode->pNext;
				preNode->pNext = nodeHieuChinh;
				nodeHieuChinh->info.mssv = Mssv;
				nodeHieuChinh->info.Ho = Ho;
				nodeHieuChinh->info.Ten = Ten;
				nodeHieuChinh->info.gioiTinh = GioiTinh;
				break;
			}
			preNode = node;
			node = node->pNext;
		}
	}
	AllocConsole();
	MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thong tin sinh vien thanh cong", "Thong bao", MB_OK);
	return true;
}

bool xoaSinhVien( nodeSV *&sv) {

}

void thayDoiMK(nodeSV *&sv, string matKhauMoi) {
	sv->info.Pass = matKhauMoi;
}

// dem so luong phan tu danh sach lien ket don sinh vien
int SizeListSV(listSV l)
{
	int count = 0;
	nodeSV *node = l.First;
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
