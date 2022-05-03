class radioButton
{
private:
	int x, y;
	int r;
	string title;
	bool isHover;

public:
	bool click;

	radioButton(int x, int y, int r, string title)
	{
		this->x = x;
		this->y = y;
		this->r = r;
		this->title = title;
	}
    //circle(int x, int y, int r)


	// vẽ cái nút
	void draw()
	{
		setcolor(GREEN);
		circle( x,  y, r);
		circle( x,  y, r -10);
		setfillstyle(SOLID_FILL,LIGHTGREEN);
		floodfill(x+ r - 5,y,GREEN);
		setfillstyle(SOLID_FILL, click ? RADIO_BUTTON_CLICK : (isHover ? RADIO_BUTTON_SELECT : RADIO_BUTTON_DEFAULT));
		floodfill(x,y,GREEN);
		
		settextstyle(BOLD_FONT, HORIZ_DIR, 3);
		setcolor(YELLOW);
		outtextxy(x + r + 10 , y - textheight("C")/2, &title[0]);
		setbkcolor(BG_COLOR);
		setcolor(DRAW_COLOR);
	}

	// chi ve cai nut, ko ve content
	void drawEffect()
	{
		// setfillstyle(SOLID_FILL,LIGHTGREEN);
		// floodfill(x + r - 5,y,GREEN);
		setfillstyle(SOLID_FILL, click ? RADIO_BUTTON_CLICK : (isHover ? RADIO_BUTTON_SELECT : RADIO_BUTTON_DEFAULT));
		// setcolor(GREEN);
		// circle( x,  y, r);
		// circle( x,  y, r -10);
		floodfill(x,y,GREEN);
		setbkcolor(BG_COLOR);
		setcolor(DRAW_COLOR);
	}


	bool isMouseHover()
	{
		int mx = mousex();
		int my = mousey();
		if (mx >= x - r && mx <= x + r && my >= y -r && my <= y + r)
		{
			return true;
		}
		return false;
	}

	// // hiệu ứng khi lướt chuột qua đổi màu
	void RadioEffect()
	{
		if (isMouseHover())
		{
			if (isHover == false)
			{
				isHover = true;
				drawEffect();
			}
		}
		else
		{
			if (isHover == true)
			{
				isHover = false;
				drawEffect();
			}
		}
	}
};
