#include"head.h"
bool opens()
{
	PIMAGE open1 = newimage();
	getimage(open1, TEXT("JPG"), MAKEINTRESOURCE(OPENS));
	putimage(0, 0,open1);
	delimage(open1);
	while (mousemsg())
		getmouse();
	for (;is_run();delay_fps(60))
	{
		while (mousemsg())
		{
			mouse_msg m = getmouse();
			if (m.is_left())
			{
				if (m.x > 500 && m.x < 1100 && m.y>700 && m.y < 800)
					exit(1);
				else if (m.x > 500 && m.x < 1100 && m.y>300 && m.y < 400)
				{
					return read();
				}
				else if (m.x > 500 && m.x < 1100 && m.y>500 && m.y < 600)
				{
					return newimage();
				}
				else if (m.x > 100 && m.x < 200 && m.y>300 && m.y < 700)
				{
					help();
					return false;
				}
			}
		}
	}
	return false;
}