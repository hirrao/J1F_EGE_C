#include"head.h"
void pline(mouse_msg mouse1)
{
	while (mousemsg())
		getmouse();
	for (;is_run();delay_fps(480))
	{
		PIMAGE nows = newimage();
		getimage(nows, 0, 200, 1600, 700);
		mouse_msg mouse2 = getmouse();
		if (mouse2.y < 200)
		{
			anmouse = mouse2;
			anmous = 1;
			return;
		}
		if (mouse2.is_down())
		{
			ege_line(mouse1.x, mouse1.y, mouse2.x, mouse2.y);
			return;
		}
	}
}

void pcircle(mouse_msg mouse1)
{
	while (mousemsg())
		getmouse();
	for (;is_run();delay_fps(480))
	{
		mouse_msg mouse2 = getmouse();
		if (mouse2.y < 200)
		{
			anmouse = mouse2;
			anmous = 1;
			return;
		}
		if (mouse2.is_down())
		{
			PIMAGE cirimage = newimage();
			getimage(cirimage, 0, 0, 1600, 200);
			double r = sqrt((pow(mouse1.x - mouse2.x, 2)) + pow(mouse1.y - mouse2.y, 2));
			int xx = mouse1.x - r;
			int yy = mouse1.y - r;
			ege_ellipse(xx, yy, 2 * r, 2 * r);
			putimage(0, 0, cirimage);
			delimage(cirimage);
			return;
		}
	}
}