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



