#include"head.h"
void Draw_Undo_Init()
{
	Save += 1;
	if (Undo_Or_Not == true)
	{
		Draw_Modes New;
		New.Mode = -1;
		for (int a = Save;a <= MAX;++a)
			RMake[a - 1] = New;
		Undo_Or_Not = false;
	}
	return;
}

void Undo()
{
	Undo_Or_Not = true;
	PIMAGE Undo = newimage();
	char FileName[20] = {};
	if (Save <= 0)
		return;
	ClearDevice();
	if (Read != nullptr)
		putimage(0, 200, Read);
	Save -= 1;
	for (int a = 0;a < Save;++a)
		Redo(a);
	return;
}


void Draw_Redo_Init(int Num, ...)
{
	va_list New = nullptr;
	va_start(New, Num);
	RMake[Save - 1].Color = getcolor();
	RMake[Save - 1].Mode = Modes;
	RMake[Save - 1].Width = width;
	for (int a = 0;a < Num;++a)
	{
		mouse_msg m = va_arg(New, mouse_msg);
		RMake[Save-1].coor[a].x = m.x;
		RMake[Save-1].coor[a].y = m.y;
	}
	va_end(New);
	return;
}

void Redo(int Num)
{
	color_t NowColor = getcolor();
	PIMAGE NowOption = newimage();
	getimage(NowOption, 0, 0, 1536, 200);
	Draw_Modes NowIM;
	if (Num == -1)
		NowIM = RMake[Save];
	else
	{
		NowIM = RMake[Num];
		Save -= 1;
	}
	setcolor(NowIM.Color);
	setlinewidth(NowIM.Width);
	switch (NowIM.Mode)
	{
	case CLEAR:
		ClearDevice();
		Save += 1;
		break;
	case PIXEL:
		ege_fillellipse(NowIM.coor[0].x - (width / 2), NowIM.coor[0].y - (width / 2), width, width);
		Save += 1;
		break;
	case LINE:
		ege_line(NowIM.coor[0].x, NowIM.coor[0].y, NowIM.coor[1].x, NowIM.coor[1].y);
		Save += 1;
		break;
	case CIRCLE:
		int r = sqrt(pow((NowIM.coor[1].x - NowIM.coor[0].x), 2) + pow((NowIM.coor[1].y - NowIM.coor[0].y), 2));
		ege_ellipse(NowIM.coor[0].x - r, NowIM.coor[0].y - r, 2 * r, 2 * r);
		Save += 1;
		break;
	}
	putimage(0, 0, NowOption);
	delimage(NowOption);
	setcolor(NowColor);
	setlinewidth(width);
}