class button
{
private:
	int x, y;
	int width, height;
	string title;
	bool isHover;
	/*
	-1: Left
	0: center
	1: right
	*/
public:
	bool click;
	int id ;

	button(int x, int y, int width, int height, string title)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->title = title;
	}

	button(int id, int x, int y, int width, int height, string title)
	{
		this->id = id;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
		this->title = title;
	}

	// vẽ cái nút
	void draw()
	{
		setfillstyle(SOLID_FILL, click ? BG_BUTTON_CLICK : (isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT));
		bar(x, y, x + width, y + height);

		settextstyle(BOLD_FONT, HORIZ_DIR, 2);
		setbkcolor(click ? BG_BUTTON_CLICK : (isHover ? BG_BUTTON_SELECT : BG_BUTTON_DEFAULT));
		setcolor(isHover ? TEXT_BUTTON_SELECT : TEXT_BUTTON_DEFAULT);

		outtextxy(x + width / 2 - textwidth(&title[0]) / 2, y + (height - textheight(&title[0])) / 2, &title[0]);
		setbkcolor(BG_COLOR);
		setcolor(DRAW_COLOR);
	}

	bool isMouseHover()
	{
		int mx = mousex();
		int my = mousey();
		if (mx >= x && mx <= x + width && my >= y && my <= y + height)
		{
			return true;
		}
		return false;
	}

	// hiệu ứng khi lướt chuột qua đổi màu
	void ButtonEffect()
	{
		if (isMouseHover())
		{
			if (isHover == false)
			{
				isHover = true;
				draw();
			}
		}
		else
		{
			if (isHover == true)
			{
				isHover = false;
				draw();
			}
		}
	}
};

// test code

// button a(1, 100, 100, 200, 100, "cau a");
// button b(2, 400, 100, 200, 100, "cau b");
// button c(2, 100, 300, 200, 100, "cau c");
// button d(2, 400, 300, 200, 100, "cau d");

// void DeleteClickAnswer(button &a, button &b, button &c)
// {
// 	a.click = false;
// 	b.click = false;
// 	c.click = false;
// 	a.draw();
// 	b.draw();
// 	c.draw();
// }

// void MenuEvent()
// {
// 	a.ButtonEffect();
// 	b.ButtonEffect();
// 	c.ButtonEffect();
// 	d.ButtonEffect();
// 	if (GetAsyncKeyState(VK_LBUTTON))
// 	{
// 		if (a.isMouseHover())
// 		{
// 			a.click = true;
// 			cout << "hello " << endl;
// 			DeleteClickAnswer(b,c,d);
// 		}
// 		if (b.isMouseHover())
// 		{
// 			b.click = true;
// 			cout << "cau b ne" << endl;
// 			DeleteClickAnswer(a,c,d);
// 		}
// 		if (c.isMouseHover()) {
// 			c.click = true;
// 			cout << "cau c ne" << endl;
// 			DeleteClickAnswer(b,a,d);
// 		}
// 		if (d.isMouseHover()) {
// 			d.click = true;
// 			cout << "cau d ne" << endl;
// 			DeleteClickAnswer(b,c,a);
// 		}

// 	}
// }

// int main()
// {

// 	initwindow(1000, 800, "man hinh do hoa");
// 	a.draw();
// 	b.draw();
// 	c.draw();
// 	d.draw();
	
// 	while (true)
// 	{

// 		MenuEvent();
// 		Sleep(100);
// 	}

// 	getch();
// }