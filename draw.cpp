#include"head.h"
mouse_msg StartDraw(mouse_msg mouse)
{
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		PIMAGE NowOption = newimage();
		getimage(NowOption, 0, 0, 1536, 200);
		mouse_msg m = getmouse();
		if (m.y < 2 * BlockY)
			return m;
		if (m.is_left()&&m.is_down())
		{
			switch (Modes)
			{
			case MOUSE:
				break;
			case PIXEL:
				Draw_Pixel(m);
				break;
			case LINE:
				Draw_Line(m);
				break;
			case CIRCLE:
				Draw_Circle(m);
				break;
			}
			putimage(0, 0, NowOption);
		}
		delimage(NowOption);
	}
}

void ClearDevice()
{
	color_t NowColor = getfillcolor();
	setfillcolor(WHITE);
	bar(0, 200, 1600, 900);
	setfillcolor(NowColor);
	return;
}

void Draw_Pixel(mouse_msg mouse)
{
	Draw_Undo_Init();
	RMake[Save-1].pixel_ = (coordinate*)malloc(MAX * sizeof(coordinate));
	if (RMake[Save-1].pixel_ == nullptr)
	{
		return;
	}
	coordinate* coors = RMake[Save-1].pixel_;
	coors[1].x = mouse.x;
	coors[1].y = mouse.y;
	flushmouse();
	for (int n = 2;is_run();delay_fps(300))
	{
		mouse_msg m = getmouse();
		coors[n].x = m.x;
		coors[n].y = m.y;
		ege_line(float(coors[n - 1].x), float(coors[n - 1].y), float(coors[n].x), float(coors[n].y));
		n++;
		if (m.is_up())
		{
			RMake[Save-1].Mode = PIXEL;
			RMake[Save-1].Color = getcolor();
			RMake[Save-1].Width = width;
			coors[0].x = coors[0].y = n;
			return;
		}
	}
}

void Draw_Line(mouse_msg mouse)
{
	PIMAGE NowImage = newimage();
	getimage(NowImage, 0, 0, 1536, 864);
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		mouse_msg m = getmouse();
		putimage(0, 0, NowImage);
		ege_line(float(mouse.x), float(mouse.y), float(m.x), float(m.y));
		if (m.is_left() && m.is_down())
		{
			Draw_Undo_Init();
			Draw_Redo_Init(2, mouse, m);
			delimage(NowImage);
			return;
		}
	}
}

void Draw_Circle(mouse_msg mouse)
{
	PIMAGE NowImage = newimage();
	getimage(NowImage, 0, 0, 1536, 864);
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		mouse_msg m = getmouse();
		putimage(0, 0, NowImage);
		float r = float(sqrt(pow(double(m.x - mouse.x), 2) + pow(double((m.y - mouse.y)), 2)));
		ege_ellipse(mouse.x - r, mouse.y - r, 2 * r, 2 * r);
		if (m.is_left() && m.is_down())
		{
			Draw_Undo_Init();
			Draw_Redo_Init(2, mouse, m);
			delimage(NowImage);
			return;
		}
	}
}

void Draw_Homework_Polygon()
{
	PIMAGE NowOption = newimage();
	getimage(NowOption, 0, 0, 1536, 200);
	char buf[100] = {};
	inputbox_getline("多边形边数选择", "请输入多边形边数", buf, 4);
	int side = atoi(buf);
	if (side < 3)
	{
		inputbox_getline("多边形边数选择", "输入有误！\n请输入正确的多边形边数！\n按回车返回操作界面", buf, 2);
		return;
	}
	inputbox_getline("多边形坐标输入", "请以x1，y1，x2，y2......的形式输入多边形坐标\n坐标之间用空格隔开\n（提示，画图区域大小为1536X664(不包含边界）,请不要越界）", buf, 50);
	char* Buf = buf;
	int pt[100] = {};
	RMake[Save].coor[0].x = RMake[Save].coor[0].y = side;
	for (int n = 1;n <= side;++n)
	{
		if (Buf == NULL)
		{
			inputbox_getline("多边形坐标输入", "输入有误，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		int x = atoi(Buf);
		Buf = strstr(Buf, " ");
		if (Buf == NULL)
		{
			inputbox_getline("多边形坐标输入", "输入有误，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		Buf++;
		int y = atoi(Buf) + 200;
		RMake[Save].coor[n].x = x;
		RMake[Save].coor[n].y = y;
		Buf = strstr(Buf, " ");
		pt[(2 * n) - 2] = x;
		pt[(2 * n) - 1] = y;
		if (x == 0 || y == 0 || (n != side && Buf == NULL))
		{
			inputbox_getline("多边形坐标输入", "输入有误，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		if (x <= 0 || y <= 0 || x > 1536 || y > 864)
		{
			inputbox_getline("多边形坐标输入", "输入越界，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		Buf++;
	}
	fillpoly(side, pt);
	Save += 1;
	if (Undo_Or_Not == true)
	{
		Draw_Modes New;
		New.Mode = -1;
		for (int a = Save;a <= MAX;++a)
			RMake[a - 1] = New;
		Undo_Or_Not = false;
	}
	RMake[Save - 1].Color = getcolor();
	RMake[Save - 1].Mode = Homework_Polygon;
	putimage(0, 0, NowOption);
	delimage(NowOption);
}