//----------------- NGUYEN MAU HAM -----------------
bool KiemTra_TrungDapAn(string A, string B, string C, string D);
bool KiemTra_TrungNoiDung(NodeCauHoi* root, int key, string NoiDung);
int Max(int a, int b);
int ChiSo_ChieuSau(NodeCauHoi* ptr);
int ChiSo_CanBang(NodeCauHoi* ptr);
NodeCauHoi* Tao_Node_Cau_Hoi(int key, CauHoi cauHoiMoi);
NodeCauHoi* Xoay_Trai(NodeCauHoi*& root);
NodeCauHoi* Xoay_Phai(NodeCauHoi*& root);
NodeCauHoi* Node_Cuc_Trai(NodeCauHoi* root);
NodeCauHoi* Them_Cau_Hoi_Moi(NodeCauHoi*& root, int key, CauHoi cauHoiMoi);
NodeCauHoi* Xoa_Cau_Hoi(NodeCauHoi*& root, int key);
void Hieu_Chinh_Cau_Hoi(NodeCauHoi*& root, int key);
void Them_Cau_Hoi_File(NodeCauHoi*& root, NodeCauHoi* cauHoiFile);
void Doc_File_Cau_Hoi(NodeCauHoi*& root);
void Duyet_Luu_Cau_Hoi(NodeCauHoi* p, ofstream& fileout);
void Luu_File_Cau_Hoi(NodeCauHoi* root);
void In_Danh_Sach_Cau_Hoi(NodeCauHoi* ptr);

//----------------- DINH NGHIA HAM -----------------

bool KiemTra_TrungDapAn(string A, string B, string C, string D) {
    if (A == B || A == C || A == D || B == C || B == D || C == D) {
        AllocConsole();
        MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Dap an khong duoc trung nhau", "Thong bao", MB_ICONASTERISK | MB_OK);
        return true;
    }
	return false;
}

bool KiemTra_TrungNoiDung(NodeCauHoi* root, int key, string NoiDung) {
	if (root != nullptr) {
		if (root->key != key && root->info.NoiDung == NoiDung) {
            AllocConsole();
            MessageBox(FindWindowA(nullptr, "THI TRAC NGHIEM"), "Noi dung cau hoi da ton tai", "Thong bao", MB_ICONASTERISK | MB_OK);
            return true;
        }    
		if (KiemTra_TrungNoiDung(root->left, key, NoiDung) || KiemTra_TrungNoiDung(root->right, key, NoiDung)) {
            return true;
        }
	}
	return false;
}

NodeCauHoi* Tao_Node_Cau_Hoi(int key, CauHoi cauHoiMoi) {
	NodeCauHoi* ptr = new NodeCauHoi;
	ptr->key = key;
	ptr->height = 1;
	ptr->info = cauHoiMoi;
	return ptr;
}

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int ChiSo_ChieuSau(NodeCauHoi* ptr) {
	if (ptr == nullptr) return 0;
	return ptr->height;
}

int ChiSo_CanBang(NodeCauHoi* ptr) {
	if (ptr == nullptr) return 0;
	return ChiSo_ChieuSau(ptr->left) - ChiSo_ChieuSau(ptr->right);
}

NodeCauHoi* Node_Cuc_Trai(NodeCauHoi* root) {
	while (root->left != nullptr) root = root->left;
	return root;
}

NodeCauHoi* Xoay_Trai(NodeCauHoi*& root) {
	//Thuc hien xoay
	NodeCauHoi* ptr = root;
	if (root != nullptr && root->right != nullptr) {
		ptr = root->right;
		root->right = ptr->left;
		ptr->left = root;
		//Cap nhat chieu sau
		root->height = Max(ChiSo_ChieuSau(root->left), ChiSo_ChieuSau(root->right)) + 1;
		ptr->height = Max(ChiSo_ChieuSau(ptr->left), ChiSo_ChieuSau(ptr->right)) + 1;
	}
	//Tra ve goc moi
	return ptr;
}

NodeCauHoi* Xoay_Phai(NodeCauHoi*& root) {
	//Thuc hien xoay
	NodeCauHoi* ptr = root;
	if (root != nullptr && root->left != nullptr) {
		ptr = root->left;
		root->left = ptr->right;
		ptr->right = root;
		//Cap nhat chieu sau
		root->height = Max(ChiSo_ChieuSau(root->left), ChiSo_ChieuSau(root->right)) + 1;
		ptr->height = Max(ChiSo_ChieuSau(ptr->left), ChiSo_ChieuSau(ptr->right)) + 1;
	}
	//Tra ve goc moi
	return ptr;
}

//Thực hiện thao tác thêm như sau
//if (/*KiemTra_TrungNoiDung*/) {
//	cout << "Noi dung cau hoi da ton tai. Khong the thuc hien them!";
//}
//else if (/*KiemTra_TrungDapAn*/) {
//	cout << "Xuat hien cac dap an trung nhau. Khong the thuc hien them!";
//}
//else {
//	//Tạo biến thông tin cauHoiMoi để truyền vào hàm thêm
//	//Gọi hàm thêm
//	cout << "Them thanh cong";
//}

NodeCauHoi* Them_Cau_Hoi_Moi(NodeCauHoi*& root, int key, CauHoi cauHoiMoi) {
	//Them nut moi
	if (root == nullptr) return Tao_Node_Cau_Hoi(key, cauHoiMoi);
	if (key < root->key) {
		root->left = Them_Cau_Hoi_Moi(root->left, key, cauHoiMoi);
	}
	else {
		root->right = Them_Cau_Hoi_Moi(root->right, key, cauHoiMoi);
	}
	//Cap nhat chieu sau
	root->height = Max(ChiSo_ChieuSau(root->left), ChiSo_ChieuSau(root->right)) + 1;
	//Kiem tra chi so can bang
	int bf = ChiSo_CanBang(root);
		//Truong hop trai trai
	if (bf > 1 && key < root->left->key) {
		return Xoay_Phai(root);
	}
		//Truong hop phai phai
	if (bf < -1 && key > root->right->key) {
		return Xoay_Trai(root);
	}
		//Truong hop trai phai
	if (bf > 1 && key > root->left->key) {
		root->left = Xoay_Trai(root->left);
		return Xoay_Phai(root);
	}
		//Truong hop phai trai
	if (bf < -1 && key < root->right->key) {
		root->right = Xoay_Phai(root->right);
		return Xoay_Trai(root);
	}
		//Truong hop khong mat can bang
	return root;
}

//Thực hiện thao tác xóa như sau
//if (root == nullptr) {
//	cout << "Danh sach rong. Khong the xoa!";
//}
//else {
//	//Bắt click trả về key
//	//Gọi hàm xóa
//	cout << "Xoa thanh cong";
//}

NodeCauHoi* Xoa_Cau_Hoi(NodeCauHoi*& root, int key) {
	//Xoa nut nhu cay BST
	if (root == nullptr) return root;
	if (key < root->key) {
		root->left = Xoa_Cau_Hoi(root->left, key);
	}
	else if (key > root->key) {
		root->right = Xoa_Cau_Hoi(root->right, key);
	}
	else {
		//Truong hop nut co 1 nut con hoac khong co nut con
		if (root->left == nullptr || root->right == nullptr) {
			NodeCauHoi* tmp = (root->left == nullptr) ? root->right : root->left;
			//Truong hop khong co nut con
			if (tmp == nullptr) {
				tmp = root;
				root = nullptr;
			}
			else { //Truong hop co 1 nut con
				*root = *tmp;
			}
			delete tmp;
		}
		else { //Truong hop nut co 2 nut con
			//Tim nut cuc trai cua nhanh con phai
			NodeCauHoi* tmp = Node_Cuc_Trai(root->right);
			//Copy thong tin tu nut tmp sang nut xoa
			root->key = tmp->key;
			root->info = tmp->info;
			//Xoa nut cuc trai
			root->right = Xoa_Cau_Hoi(root->right, tmp->key);
		}
	}
	//Truong hop cay chi co 1 nut
	if (root == nullptr) return root;
	//Cap nhat chieu sau
	root->height = Max(ChiSo_ChieuSau(root->left), ChiSo_ChieuSau(root->right)) + 1;
	//Kiem tra chi so can bang
	int bf = ChiSo_CanBang(root);
		//Truong hop trai trai
	if (bf > 1 && ChiSo_CanBang(root->left) >= 0) {
		return Xoay_Phai(root);
	}
		//Truong hop trai phai
	if (bf > 1 && ChiSo_CanBang(root->left) < 0) {
		root->left = Xoay_Trai(root->left);
		return Xoay_Phai(root);
	}
		//Truong hop phai phai
	if (bf < -1 && ChiSo_CanBang(root->right) <= 0) {
		return Xoay_Trai(root);
	}
		//Truong hop phai trai
	if (bf < -1 && ChiSo_CanBang(root->right) > 0) {
		root->right = Xoay_Phai(root->right);
		return Xoay_Trai(root);
	}
		//Truong hop khong mat can bang
	return root;
}

void Hieu_Chinh_Cau_Hoi(NodeCauHoi*& root, int key) {
	NodeCauHoi* ptr = root;
	while (ptr != nullptr && ptr->key != key) {
		if (key < ptr->key) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	//Cho phép thay đổi mã môn học, nội dung, các lựa chọn A, B, C, D và đáp án (Không được phép thay đổi ID [key])
	CauHoi tmp;
	tmp.id = key;
	//-------------------------- NHẬP LIỆU --------------------------
	getline(cin, tmp.NoiDung);
	getline(cin, tmp.A);
	getline(cin, tmp.B);
	getline(cin, tmp.C);
	getline(cin, tmp.D);
	cin >> tmp.DapAn;
	//Bắt mã môn học [Xuất danh sách môn học và bắt click trả về mã môn]
	//----------------------------------------------------------------
	//if (tmp == ptr->info) { //Bắt trường hợp không thay đổi thông tin
	//	cout << "Thong tin cau hoi khong thay doi. Khong the thuc hien hieu chinh!";

	//}else if (KiemTra_TrungNoiDung(root, key, tmp.NoiDung)) { //Bắt trường hợp trùng nội dung
	//	cout << "Noi dung cau hoi da ton tai. Khong the thuc hien hieu chinh!";
	//}else if (KiemTra_TrungDapAn(tmp.A, tmp.B, tmp.C, tmp.D)) { //Bắt trường hợp trùng đáp án
	//	cout << "Xuat hien cac dap an trung nhau. Khong the thuc hien hieu chinh!";
	//}
	//else {
	//	ptr->info = tmp;
	//	cout << "Hieu chinh thanh cong";
	//}
}

void Them_Cau_Hoi_File(NodeCauHoi*& ptr, NodeCauHoi* cauHoiFile) {
	if (ptr == nullptr) {
		ptr = cauHoiFile;
	}
	else if (cauHoiFile->key < ptr->key) {
		Them_Cau_Hoi_File(ptr->left, cauHoiFile);
	}
	else {
		Them_Cau_Hoi_File(ptr->right, cauHoiFile);
	}
}

void Doc_File_Cau_Hoi(NodeCauHoi*& root) {
	ifstream filein;
	filein.open("DATA\\FileDSCauHoi.txt", ios_base::in);
	if (!filein.is_open()) return;
	string id, height;
	while (getline(filein, id, ',')) {
		NodeCauHoi* cauHoiFile = new NodeCauHoi;
		cauHoiFile->key = cauHoiFile->info.id = stoi(id);
		getline(filein, cauHoiFile->info.maMonHoc, ',');
		getline(filein, height, ',');
		cauHoiFile->height = stoi(height);
		getline(filein, cauHoiFile->info.NoiDung);
		getline(filein, cauHoiFile->info.A);
		getline(filein, cauHoiFile->info.B);
		getline(filein, cauHoiFile->info.C);
		getline(filein, cauHoiFile->info.D);
		filein >> cauHoiFile->info.DapAn;
		filein.ignore();
		Them_Cau_Hoi_File(root, cauHoiFile);
	}
}

void Duyet_Luu_Cau_Hoi(NodeCauHoi* p, ofstream& fileout) {
	if (p != nullptr) {
		fileout << p->info.id << "," << p->info.maMonHoc << "," << p->height << "," << p->info.NoiDung << endl;
		fileout << p->info.A << endl << p->info.B << endl << p->info.C << endl << p->info.D << endl;
		fileout << p->info.DapAn << endl;
		Duyet_Luu_Cau_Hoi(p->left, fileout);
		Duyet_Luu_Cau_Hoi(p->right, fileout);
	}
}

void Luu_File_Cau_Hoi(NodeCauHoi* root) {
	ofstream fileout;
	fileout.open("DATA\\FileDSCauHoi.txt", ios_base::out);
	Duyet_Luu_Cau_Hoi(root, fileout);
}

// tinh nang phu

int countNodeCauHoi(NodeCauHoi *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + countNodeCauHoi(root->left) + countNodeCauHoi(root->right);
    }
}


void giaiPhongArrCauHoi(mangCauHoi &dsCauHoi) {
	for ( int i = 0 ; i < dsCauHoi.tongSoCau; i++) {
        dsCauHoi.arrCauHoiThi[i] = nullptr;
    }
	dsCauHoi.tongSoCau = 0;
    delete []dsCauHoi.arrCauHoiThi;

}

void taoMangCauHoi(NodeCauHoi *rootCauHoi, mangCauHoi &dsCauHoi, string maMon)
{

    // duyet LNR
    if (rootCauHoi != nullptr)
    {
        if (rootCauHoi->info.maMonHoc == maMon)
        {
            dsCauHoi.arrCauHoiThi[dsCauHoi.tongSoCau] = rootCauHoi;
            dsCauHoi.tongSoCau++;
            
        }
        taoMangCauHoi(rootCauHoi->left, dsCauHoi, maMon);
        taoMangCauHoi(rootCauHoi->right, dsCauHoi, maMon);
    }
}

int TreeToArray(NodeCauHoi *rootCauHoi, NodeCauHoi *arrCauHoi[], int i)
{
    if (rootCauHoi == nullptr)
    {
        return i;
    }

    arrCauHoi[i] = rootCauHoi;
    i++;
    if (rootCauHoi->left != nullptr)
    {
        i = TreeToArray(rootCauHoi->left, arrCauHoi, i);
    }

    if (rootCauHoi->right != nullptr)
    {
        i = TreeToArray(rootCauHoi->right, arrCauHoi, i);
    }

    return i;
}