#include"head.h"
mouse_msg anmouse;
int anmous = 0;
mouse_msg draws(mouse_msg mouse)
{
	for (;is_run();delay_fps(480))
	{
		while (mousemsg())
			getmouse();
		mouse = getmouse();
		if (mouse.y < 200)
			return mouse;
		else
		{
			if (mouse.is_down())
			{
				switch (ways)
				{
				case LINES:
					pline(mouse);
					break;
				case CIRCLES:
					pcircle(mouse);
					break;
				case 3:
					break;
				}
			}
		}
		if (anmous == 1)
		{
			anmous = 0;
			return mouse;
		}
	}
	return mouse;
}