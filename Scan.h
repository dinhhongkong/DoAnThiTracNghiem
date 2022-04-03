void ScanNumber(editText *&txt, char c);
void ScanTextOnly(editText *&txt, char c);
void ScanTextSpace(editText *&txt, char c);
void ScanTextNumber(editText *&txt, char c);

void Scan(editText *&txt, int maxn, ScanType type)
{
	if (txt == nullptr)
		return;

	int mx = -1, my = -1, mrx = -1, mry = -1;
	getmouseclick(WM_LBUTTONDOWN, mx, my);
	clearmouseclick(WM_LBUTTONDOWN);

	getmouseclick(WM_RBUTTONDOWN, mrx, mry);
	clearmouseclick(WM_RBUTTONDOWN);
	if (((mx != -1 && my != -1) || (mrx != -1 && mry != -1)) && (!txt->isMouseHover()))
	{
		txt->isChoose = false;
		txt->draw();
		txt = nullptr;
		return;
	}

	if (kbhit())
	{
		char c = getch();
		if (c == BACKSPACE)
		{
			if (txt->content.size() > 0)
			{
				txt->content.pop_back();
				txt->draw();
			}
		}
		else if (c == ENTER)
		{
			txt->draw();
			txt = nullptr;
			return;
		}
		else if ( c == KEY_DOWN) {
			txt->isChoose =false;
			txt->draw();
			txt = txt->next;
			return;
		}
		else if ( c == KEY_UP) {
			txt->isChoose =false;
			txt->draw();
			txt = txt->pre;
			return;
		} 
		else if (txt->content.size() < maxn)
		{
			if (type == ONLY_NUMBER)
			{
				ScanNumber(txt, c);

				// }else if(type == ONLY_NUMBER_GREATER_0){
				// 	ScanNumberGreater0(txt, n, c);
			}
			else if (type == ONLY_TEXT)
			{
				ScanTextOnly(txt, c);
			}
			else if (type == SPACE_TEXT)
			{
				ScanTextSpace(txt, c);
			}
			else if (type == TEXT_NUMBER)
			{
				ScanTextNumber(txt, c);
				// }else if(type == DATE_TIME){
				// 	ScanDate(txt, n, c);
				// }else if(type == LIMIT_CHARACTER){
				// 	ScanLimit(txt, n, c, startLimit, endLimit);
				// }else if(type == ISBN){
				// 	ScanNumber(txt, n, c);
				// 	ScanTextOnly(txt, n, c);
				// }else if(type == MASACH){
				// 	ScanMaSach(txt, n, c);
				// }
			}
		
		}
	}
}

void ScanNumber(editText *&txt, char c)
{
	if (c >= '0' && c <= '9')
	{
		txt->content += c;
	}
}

void ScanTextOnly(editText *&txt, char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		txt->content += toupper(c);
	}
}

void ScanTextSpace(editText *&txt, char c)
{
	if (c == SPACE)
	{
		if (txt->content.size() > 0 && txt->content[txt->content.size() - 1] != ' ')
			txt->content += ' ';
	}
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		txt->content += toupper(c);
	}
}

void ScanTextNumber(editText *&txt, char c)
{
	// Chu cai, so, dau cach
	if (c == SPACE)
	{
		if (txt->content.size() > 0 && txt->content[txt->content.size() - 1] != ' ')
			txt->content += ' ';
	}
	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		txt->content += toupper(c);
	}
	else if (c >= '0' && c <= '9')
	{
		txt->content += c;
	}
}