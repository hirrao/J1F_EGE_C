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

/*void Draw_Pixel(mouse_msg mouse)
{
	ege_fillellipse(mouse.x - (width / 2.0), mouse.y - (width / 2.0), width, width);
	Draw_Undo_Init();
	Draw_Redo_Init(1, mouse);
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		mouse_msg m = getmouse();
		ege_fillellipse(m.x - (width / 2.0), m.y - (width / 2.0), width, width);
		Draw_Undo_Init();
		Draw_Redo_Init(1, m);
		if (m.is_up())
			return;
	}
}*/

void Draw_Pixel(mouse_msg mouse)
{
	coordinate coor[10000];
	coor[0].x = mouse.x;
	coor[0].y = mouse.y;
	flushmouse();
	for (int n = 1;is_run();delay_fps(300))
	{
		mouse_msg m = getmouse();
		coor[n].x = m.x;
		coor[n].y = m.y;
		ege_line(coor[n - 1].x, coor[n - 1].y, coor[n].x, coor[n].y);
		n++;
		if (m.is_up())
			return;
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
		ege_line(mouse.x, mouse.y, m.x, m.y);
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
		int r = sqrt(pow((m.x - mouse.x), 2) + pow((m.y - mouse.y), 2));
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