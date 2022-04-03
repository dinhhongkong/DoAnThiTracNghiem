class editText
{
private:
	int id;
	int x, y;
	int width, height;
	string title, hint;
	bool isHover;
	string cursor = "_"; // khong dung char dc, vi loi, da test
	int i = 0;			 // toa do cua content
	string pass;

public:
	bool isChoose;
	int textSize = 0;
	string content;
	bool inputPass;
	editText *next = nullptr;
	editText *pre = nullptr;

	editText(int id, int x, int y, int width, int heigh, string title, string hint, int textSize)
	{
		this->id = id;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = heigh;
		this->title = title;
		this->hint = hint;
		isHover = false;
		this->textSize = textSize;
		this->next = nullptr;
		this->pre = nullptr;
	}

	// them nhap tuy chon nhap mat khau o cuoi (true la nhap mk)
	editText(int id, int x, int y, int width, int heigh, string title, string hint, int textSize, bool inputPass)
	{
		this->id = id;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = heigh;
		this->title = title;
		this->hint = hint;
		isHover = false;
		this->textSize = textSize;
		this->inputPass = inputPass;
		this->next = nullptr;
		this->pre = nullptr;
	}

	void draw()
	{
		// vuot qua do dai text box thi tien len

		if (textwidth(&content[i]) >= width - 170 - textwidth("_"))
		{
			i++;
			if (textwidth(&content[i]) >= width - 170 - textwidth("_"))
			{
				i++;
			}
		}
		else if (textwidth(&content[0]) < width - 170 - textwidth("_"))
		{
			i = 0;
		}
		else if (textwidth(&content[i]) < width - 170 - textwidth("_"))
		{
			i--;
			if (textwidth(&content[i]) >= width - 170 - textwidth("_"))
			{
				i++;
			}
		}

		setbkcolor(BG_COLOR);
		// Ve tieu de
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
		setcolor(TEXT_EDIITEXT_TITLE_COLOR);
		outtextxy(x, y + (height - textheight("TD")) / 2, &title[0]);

		// Ve background
		setfillstyle(SOLID_FILL, BG_EDITTEXT_COLOR);
		bar(x + 150, y, x + width, y + height);

		// click vo hien con tro
		if (isChoose == true && content.size() == 0)
		{
			setcolor(TEXT_EDITTEXT_COLOR);
			setbkcolor(BG_EDITTEXT_COLOR);
			outtextxy(x + 160, y + (height - textheight("C")) / 2, &cursor[0]);
		}
		else if (content.size() == 0)
		{
			// Ve hint
			setcolor(TEXT_EDIITEXT_HINT_COLOR);
			setbkcolor(BG_EDITTEXT_COLOR);
			outtextxy(x + 160, y + (height - textheight("H")) / 2, &hint[0]);
		}
		else
		{
			// Ve noi dung nguoi dung nhap vao
			setcolor(TEXT_EDITTEXT_COLOR);
			setbkcolor(BG_EDITTEXT_COLOR);
			if (inputPass == false)
			{
				outtextxy(x + 160, y + (height - textheight("C")) / 2, &content[i]);
			}
			else
			{
				pass = content;
				for (int j = 0; j < pass.size(); j++)
				{
					pass[j] = '*';
				}
				outtextxy(x + 160, y + (height - textheight("C")) / 2, &pass[i]);
			}

			if (isChoose)
			{
				if (!inputPass)
					outtextxy(x + 160 + textwidth(&content[i]), y + (height - textheight("C")) / 2, &cursor[0]);
				else
				{
					outtextxy(x + 160 + textwidth(&pass[i]), y + (height - textheight("C")) / 2, &cursor[0]);
				}
			}
		}

		setbkcolor(BG_COLOR);
		setcolor(DRAW_COLOR);
	}

	// bat su kien chuot luot qua
	bool isMouseHover()
	{
		int mx = mousex();
		int my = mousey();
		if (mx >= x + 160 && mx <= x + width && my >= y && my <= y + height)
		{
			return true;
		}
		return false;
	}

	int toInt(){
		int x = 0;
		for(int i=0; i < content.size(); i++){
			if(i > 0 && content[i] == '_') break;
			if(content[i] >= '0' && content[i] <= '9') x = x*10 + (content[i]-'0');
			else return -1;
		}
		return x;
	}

	string ToString() {
		if ( content[content.size() - 1] == ' ' && !inputPass) {
			content.pop_back();
		} 
		return content;
	}

	void setNext(editText *a) {
		this->next = a;
	}

	void setPre(editText *a) {
		this->pre = a;
	}
};

//////////////////////////////////////////////////////////////////////////////

//				test code

// editText a(1, 100, 100, 400, 50, "ten:", "dien vo");
// void Menu()
// {
// 	if (GetAsyncKeyState(VK_LBUTTON))
// 	{
// 		a.scanTextNumber();
// 	}
// }

// void MenuEvent()
// {

// 	if (GetAsyncKeyState(VK_LBUTTON))
// 	{
// 		if (a.isMouseHover())
// 		{
// 			a.scanTextNumber();
// 		}
// 	}
// }

// int main()
// {
// 	int w = GetSystemMetrics(SM_CXSCREEN);
// 	int h = GetSystemMetrics(SM_CYSCREEN);
// 	initwindow(w, h, "man hinh do hoa");
// 	a.draw();
// 	while (true)
// 	{
// 		MenuEvent();
// 		Sleep(50);
// 	}

// 	getch();
// }