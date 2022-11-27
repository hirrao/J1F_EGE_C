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
	RMake[Save].pixel_ = (coordinate*)malloc(MAX * sizeof(coordinate));
	if (RMake[Save].pixel_ == nullptr)
	{
		return;
	}
	coordinate* coors = RMake[Save].pixel_;
	flushmouse();
	coors[0].x = mouse.x;
	coors[0].y = mouse.y;
	for (int n = 1;is_run();delay_fps(300))
	{
		mouse_msg m = getmouse();
		coors[n].x = m.x;
		coors[n].y = m.y;
		ege_line(float(coors[n - 1].x), float(coors[n - 1].y), float(coors[n].x), float(coors[n].y));
		n++;
		if (m.is_up())
		{
			Draw_Undo_Init();
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