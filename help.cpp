#include"head.h"
void help()
{
	PIMAGE helpjpg = newimage();
	getimage(helpjpg, TEXT("JPG"), MAKEINTRESOURCE(HELPS));
	putimage(0, 0, helpjpg);
	while (mousemsg())
		getmouse();
	for (;is_run();delay_ms(60))
	{
		while (mousemsg())
		{
			mouse_msg mo = getmouse();
			if (mo.is_left())
			{
				if (mo.x > 10 && mo.x < 160 && mo.y>800 && mo.y < 850)
					return;
			}
		}
	}
	return;
}