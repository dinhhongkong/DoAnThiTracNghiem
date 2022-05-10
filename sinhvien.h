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
bool InsertNodeSV(dslop DanhSachLop, listSV &l, sinhVien sv)
{
	nodeSV *node = nullptr;
	for (int i = 0; i < DanhSachLop.solop; i++)
	{
		node = DanhSachLop.arrLop[i].dsSinhVien.First;

		while (node != nullptr)
		{
			if (node->info.mssv == sv.mssv)
			{
				AllocConsole();
				MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong the them, Ma so sinh vien da ton tai", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
				return false;
			}
			node = node->pNext;
		}
	}

	if (l.First == nullptr)
	{
		AddFirst(l, CreateNodeSV(sv));
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
		return true;
	}

	if (l.First->info.mssv > sv.mssv)
	{
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
		AddLast(l, CreateNodeSV(sv));
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Them thanh cong", "Thong bao", MB_OK);
		return true;
	}

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
bool ChinhSuaSinhVien(dslop DanhSachLop, listSV &DsSinhVien, nodeSV *&nodeHieuChinh, string Mssv, string Ho, string Ten, int GioiTinh)
{

	if (nodeHieuChinh->info.mssv == Mssv && nodeHieuChinh->info.Ho == Ho && nodeHieuChinh->info.Ten == Ten && nodeHieuChinh->info.gioiTinh == GioiTinh)
	{
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Khong chinh sua, do thong tin nhap vao van giu nguyen", "Thong bao", MB_ICONEXCLAMATION | MB_OK);
		return false;
	}
	nodeSV *node = nullptr;
	for (int i = 0; i < DanhSachLop.solop; i++)
	{
		node = DanhSachLop.arrLop[i].dsSinhVien.First;
		if (Mssv != nodeHieuChinh->info.mssv)
		{
			while (node != nullptr)
			{
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
	}
	string oldname = "DATA\\bai thi\\" + nodeHieuChinh->info.mssv + ".txt";
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
	if (nodeHieuChinh == DsSinhVien.First && nodeHieuChinh == DsSinhVien.Last)
	{
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
	else if (DsSinhVien.First->info.mssv > Mssv || (nodeHieuChinh == DsSinhVien.First && Mssv < nodeHieuChinh->pNext->info.mssv))
	{
		if (nodeHieuChinh == DsSinhVien.Last)
		{
			nodeHieuChinh->pNext = DsSinhVien.First;
			DsSinhVien.First = DsSinhVien.First->pNext;
			DsSinhVien.Last = PreNodeHieuChinh;
			PreNodeHieuChinh->pNext = nullptr;
			DsSinhVien.First = nodeHieuChinh;
		}
		else if (PreNodeHieuChinh != nullptr)
		{
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
	else if (DsSinhVien.Last->info.mssv < Mssv || (nodeHieuChinh == DsSinhVien.Last && Mssv > PreNodeHieuChinh->info.mssv))
	{
		if (nodeHieuChinh == DsSinhVien.First)
		{
			DsSinhVien.First = DsSinhVien.First->pNext;
			DsSinhVien.Last->pNext = nodeHieuChinh;
			DsSinhVien.Last = nodeHieuChinh;
		}
		else if (PreNodeHieuChinh->pNext != DsSinhVien.Last)
		{
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
	//rename(oldname, newname) // ham chinh sua ten file
    string newname = "DATA\\bai thi\\" + nodeHieuChinh->info.mssv + ".txt";
	cout << oldname << endl << newname << endl;
	rename(&oldname[0], &newname[0]);
	AllocConsole();
	MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Chinh sua thong tin sinh vien thanh cong", "Thong bao", MB_OK);
	return true;
}

bool xoaSinhVien(listSV &DsSinhVien, nodeSV *&sv)
{
	if (sv->info.listDT.first!= nullptr)
	{
		AllocConsole();
		MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Thong the xoa, Sinh Vien co danh sach diem", "Thong bao", MB_OK);
		return false;
	}

	if ( sv == DsSinhVien.First && sv == DsSinhVien.Last) {
		DsSinhVien.First = nullptr;
		DsSinhVien.Last = nullptr;
		delete sv;
		sv = nullptr;
	}
	else if (sv == DsSinhVien.First)
	{
		DsSinhVien.First = sv->pNext;
		sv->pNext = nullptr;
		delete sv;
		sv = nullptr;
	}
	else if (sv != DsSinhVien.Last)
	{
		nodeSV *node = DsSinhVien.First;
		while (node->pNext != sv)
		{
			node = node->pNext;
		}
		node->pNext = sv->pNext;
		sv->pNext = nullptr;
		delete sv;
		sv = nullptr;
	}
	else if (sv == DsSinhVien.Last)
	{
		nodeSV *node = DsSinhVien.First;
		while (node->pNext != sv)
		{
			node = node->pNext;
		}
		DsSinhVien.Last = node;
		DsSinhVien.Last->pNext = nullptr;
		sv->pNext = nullptr;
		delete sv;
		sv = nullptr;
	}
	AllocConsole();
	MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Xoa sinh vien thanh cong", "Thong bao", MB_OK);

	return true;
}

void thayDoiMK(nodeSV *&sv, string matKhauMoi)
{
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
		return;
	}

	sinhVien sv;
	while (getline(fileIn, sv.mssv, ','))
	{
		getline(fileIn, sv.Ho, ',');
		getline(fileIn, sv.Ten, ',');
		fileIn >> sv.gioiTinh;
		fileIn.ignore();
		getline(fileIn, sv.Pass, '\n');
		docBaiThi(sv.mssv, sv.listDT);
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
		
		temp = temp->pNext;
	}
	cout << "ghi thanh cong sv" << endl;
	fileOut.close();
}
