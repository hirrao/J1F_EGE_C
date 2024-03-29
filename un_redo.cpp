﻿#include"head.h"
void Draw_Undo_Init()
{
	/*判断在绘图前是否进行了撤销操作，若是，则清除撤销前在撤销操作后的操作*/
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
	/*重绘所有图形以达到撤销目的*/
	for (int a = 0;a < Save;++a)
		Redo(a);
	return;
}


void Draw_Redo_Init(int Num, ...)
{
	/*将绘图信息进行保存，以便进行撤销重做*/
	va_list New = nullptr;
	va_start(New, Num);
	RMake[Save - 1].Color = getcolor();
	RMake[Save - 1].Mode = Modes;
	RMake[Save - 1].Width = width;
	for (int a = 1;a <= Num;++a)
	{
		mouse_msg m = va_arg(New, mouse_msg);
		RMake[Save - 1].coor[a].x = m.x;
		RMake[Save - 1].coor[a].y = m.y;
	}
	va_end(New);
	return;
}

void Redo(int Num)
{
	/*重做部分，即为绘制传入的图形（可能为重做，也可能为撤销部分）*/
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
	setlinewidth(float(NowIM.Width));
	switch (NowIM.Mode)
	{
	case CLEAR:
	{
		ClearDevice();
		Save += 1;
		break;
	}
	case PIXEL:
	{
		for (int n = 2;n < NowIM.pixel_[0].x;++n)
		{
			coordinate* coors = NowIM.pixel_;
			ege_line(float(coors[n - 1].x), float(coors[n - 1].y), float(coors[n].x), float(coors[n].y));
		}
		Save += 1;
		break;
	}
	case LINE:
	{
		ege_line(float(NowIM.coor[1].x), float(NowIM.coor[1].y), float(NowIM.coor[2].x), float(NowIM.coor[2].y));
		Save += 1;
		break;
	}
	case CIRCLE:
	{
		float r = float(sqrt(pow(double(NowIM.coor[2].x - NowIM.coor[1].x), 2) + pow(double(NowIM.coor[2].y - NowIM.coor[1].y), 2)));
		ege_ellipse(NowIM.coor[1].x - r, NowIM.coor[1].y - r, 2 * r, 2 * r);
		Save += 1;
		break;
	}
	case Homework_Polygon:
	{
		int pt[100] = {};
		for (int n = 0;n < NowIM.coor[0].x;++n)
		{
			pt[2 * n] = NowIM.coor[n + 1].x;
			pt[2 * n + 1] = NowIM.coor[n + 1].y;
		}
		fillpoly(NowIM.coor[0].x, pt);
		Save += 1;
		break;
	}
	}
	putimage(0, 0, NowOption);
	delimage(NowOption);
	setcolor(NowColor);
	setlinewidth(float(width));
}