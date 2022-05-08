void Them_Diem_Vao_Cuoi(Danh_Sach_Diem_Thi& dsDiem, Node_Diem_Thi* nodeDiemThi) {
	if (dsDiem.first == nullptr) {
		dsDiem.first = nodeDiemThi;
		return;
	}
	Node_Diem_Thi* ptr = dsDiem.first;
	while (ptr->DTnext != nullptr) {
		ptr = ptr->DTnext;
	}
	ptr->DTnext = nodeDiemThi;
}


void Them_Diem_Vao_Dau(Danh_Sach_Diem_Thi& dsDiem, Node_Diem_Thi* nodeDiemThi) {
	if (dsDiem.first == nullptr) {
		dsDiem.first = nodeDiemThi;
		return;
	}
	nodeDiemThi->DTnext = dsDiem.first->DTnext;
	dsDiem.first = nodeDiemThi;
}

Node_Diem_Thi *createNodeDiem( Diem_Thi diemthi) {
	Node_Diem_Thi *a = new Node_Diem_Thi;
	a->info = diemthi;
	a->DTnext = nullptr;
	return a;
}