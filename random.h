struct IDRandom {
	int ID;
	IDRandom* next;
};

IDRandom* Tao_IDNode(int ID) {
	IDRandom* Node = new IDRandom;
	Node->ID = ID;
	Node->next = nullptr;
	return Node;
}

//Gọi hàm này vào đầu chương trình
void Tao_MIN_MAX(IDRandom*& first, int ID) {
	IDRandom* ptr = Tao_IDNode(ID);
	if (first == nullptr) {
		first = ptr;
	}
	else {
		first->next = ptr;
	}
}

//Gọi hàm này khi đọc file câu hỏi
void Them_ID(IDRandom*& first, int ID) {
	IDRandom* ptr = first;
	while (ptr->next->ID < ID) ptr = ptr->next;
	IDRandom* Node = Tao_IDNode(ID);
	Node->next = ptr->next;
	ptr->next = Node;
}

//Gọi hàm này khi xóa câu hỏi
void Xoa_ID(IDRandom*& first, int ID) {
	IDRandom* ptr = first;
	while (ptr->next->ID != ID) ptr = ptr->next;
	IDRandom* tmp = ptr->next;
	ptr->next = tmp->next;
	delete tmp;
}


// [min max]
int Random(int Min, int Max) {
	return Min + rand() % (Max + 1 - Min);
}

//Dùng hàm này khi cấp phát ID
int Cap_ID(IDRandom* first) {
	IDRandom* ptr = first;
	while (ptr->next != nullptr && ptr->next->ID - ptr->ID == 1) ptr = ptr->next;
	if (ptr->next == nullptr) {
		return 0; //Hệ thống câu hỏi đã đầy, không thể thêm câu hỏi
	}
	else {
		int ID = Random(ptr->ID + 1, ptr->next->ID - 1); //Lấy trong đoạn (Min ; Max)
		Them_ID(first, ID);
		return ID;
	}
}
