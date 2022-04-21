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

nodeSV *CreateNodeSV(sinhVien sv) {
	nodeSV *a = new nodeSV;
    a->info = sv;
    a->pNext = nullptr;
    return a;
}

void CreateList(listSV &l) {
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
        sv->pNext = l.First;
        l.First = sv;
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
        l.First->pNext = sv;
		l.Last = sv;
    }
}



// CHEN VAO DANH SACH SINH VIEN THEO THU TU
void InsertNodeSV(listSV &l, sinhVien sv) {
	if(l.First == nullptr) {
		AddFirst(l, CreateNodeSV(sv) );
		return;
	}
	if ( l.First->info.mssv > sv.mssv) {
		nodeSV *p = new nodeSV;
		p->info = sv;
		p->pNext = l.First;
		l.First = p; 
		return;
	}

	if (l.Last->info.mssv < sv.mssv) {
		AddLast(l, CreateNodeSV(sv));
		return;
	}

	nodeSV *temp = l.First;
	while (temp != nullptr )
	{
		if ( temp->pNext->info.mssv > sv.mssv) {
			nodeSV *chenSV = CreateNodeSV(sv);

			chenSV->pNext = temp->pNext;
			temp->pNext = chenSV;
			return;
		}
		temp = temp->pNext;
	}
	

	cout <<"khong chen dc, vi da ton tai" << endl;
}

void DocDsSinhVien(listSV &dsSinhVien, string maLop) {
	ifstream fileIn;
	string nameFILE ="DATA\\" + maLop + ".txt";
	fileIn.open(nameFILE, ios_base:: in );
	if ( !fileIn.is_open()) {
		cout << "Khong mo dc file " << maLop << endl;
		return;
	}
	else {
		cout << "doc dc file " << maLop << endl;
	}

	sinhVien sv;
	while (getline(fileIn, sv.mssv, '\n')) {
		getline(fileIn,sv.Ho, '\n');
		getline(fileIn,sv.Ten,'\n');
		fileIn >> sv.gioiTinh;
		fileIn.ignore();
		getline(fileIn,sv.Pass,'\n');
		// cout << sv.mssv << '\n'<< sv.Ho << '\n' << sv.Ten << '\n' << sv.gioiTinh << '\n' << sv.Pass << '\n';
		AddLast(dsSinhVien,CreateNodeSV(sv));
	}
	fileIn.close();

}

void ghiFileDsSinhVien(listSV &dsSinhVien, string maLop)
{
	ofstream fileOut;
	string nameFILE ="DATA\\" + maLop +".txt";
	fileOut.open(nameFILE, ios_base::out);
	nodeSV *temp = dsSinhVien.First;
	while (temp!= nullptr)
	{
		fileOut << temp->info.mssv << '\n'<< temp->info.Ho << '\n' << temp->info.Ten << '\n' << temp->info.gioiTinh << '\n' << temp->info.Pass << '\n';
		//cout << temp->info.mssv << '\n'<< temp->info.Ho << '\n' << temp->info.Ten << '\n' << temp->info.gioiTinh << '\n' << temp->info.Pass << '\n';
		temp = temp->pNext;
	}
	cout << "ghi thanh cong sv" << endl;
    fileOut.close();
}


