#include"head.h"
mouse_msg StartDraw(mouse_msg mouse)
{
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		PIMAGE NowOption = newimage();
		getimage(NowOption, 0, 0, 1536, 200);
		mouse_msg m = getmouse();
		/*当鼠标退出绘图区域，直接退出绘图函数，以降低延迟*/
		if (m.y < 2 * BlockY)
			return m;
		if (m.is_left()&&m.is_down())
		{
			/*进行当前绘画模式的选取，并调用对应函数*/
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
	/*实现方式为用白色覆盖绘图区域*/
	color_t NowColor = getfillcolor();
	setfillcolor(WHITE);
	bar(0, 200, 1600, 900);
	setfillcolor(NowColor);
	return;
}

void Draw_Pixel(mouse_msg mouse)
{
	/*铅笔模式，在最近两点间画一条线，由于刷新率很快，较难看出来在画线*/
	Draw_Undo_Init();
	/*分配堆空间，将该模式绘图信息存储于堆中*/
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
			/*相当于改写了绘图信息保存的初始化函数*/
			RMake[Save-1].Mode = PIXEL;
			RMake[Save-1].Color = getcolor();
			RMake[Save-1].Width = width;
			coors[0].x = coors[0].y = n;
			return;
		}
	}
}

/*画线模式*/
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

/*画圆模式*/
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

/*键盘绘制多边形模式*/
void Draw_Homework_Polygon()
{
	PIMAGE NowOption = newimage();
	getimage(NowOption, 0, 0, 1536, 200);
	char buf[100] = {};
	/*输入并记录多边形边数，当边数小于3时不绘制直接返回*/
	inputbox_getline("多边形边数选择", "请输入多边形边数", buf, 4);
	int side = atoi(buf);
	if (side < 3)
	{
		inputbox_getline("多边形边数选择", "输入有误！\n请输入正确的多边形边数！\n按回车返回操作界面", buf, 2);
		return;
	}
	inputbox_getline("多边形坐标输入", "请以x1，y1，x2，y2......的形式输入多边形坐标\n坐标之间用空格隔开\n（提示，画图区域大小为1536X664(不包含边界）,请不要越界）", buf, 50);
	/*将buf的const char*类型变为Buf的char*类型，便于后续操作*/
	char* Buf = buf;
	int pt[100] = {};
	RMake[Save].coor[0].x = RMake[Save].coor[0].y = side;
	for (int n = 1;n <= side;++n)
	{
		/*若输入存在错误，则strstr函数找不到对象可能返回NULL*/
		if (Buf == NULL)
		{
			/*清除以保存内容并返回错误消息*/
			inputbox_getline("多边形坐标输入", "输入有误，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		/*atoi函数仅会读取遇到的第一个数字，遇到空格会直接结束读取*/
		int x = atoi(Buf);
		Buf = strstr(Buf, " ");
		if (Buf == NULL)
		{
			inputbox_getline("多边形坐标输入", "输入有误，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		/*跳过找到的那个空格，防止strstr函数重复查找这一内容*/
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
			/*若输入越过画图范围，则返回错误信息*/
			inputbox_getline("多边形坐标输入", "输入越界，请正确输入坐标\n按回车返回操作界面", buf, 3);
			Draw_Modes ne;
			RMake[Save] = ne;
			return;
		}
		Buf++;
	}
	fillpoly(side, pt);
	/*相当于撤销重做的初始化部分*/
	Save += 1;
	if (Undo_Or_Not == true)
	{
		Draw_Modes New;
		New.Mode = -1;
		for (int a = Save;a <= MAX;++a)
			RMake[a - 1] = New;
		Undo_Or_Not = false;
	}
	RMake[Save - 1].Width = width;
	RMake[Save - 1].Color = getcolor();
	RMake[Save - 1].Mode = Homework_Polygon;
	putimage(0, 0, NowOption);
	delimage(NowOption);
}