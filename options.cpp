#include"head.h"
extern int ways = -1;
PIMAGE anewimage = nullptr;
bool options()
{
	ege_enable_aa(true);
	PIMAGE opts = newimage(1600,900);
	getimage(opts, TEXT("JPG"), MAKEINTRESOURCE(OPTS));
	setbkcolor(WHITE);
	cleardevice();
	PIMAGE options = newimage();
	getimage(options, TEXT("JPG"), MAKEINTRESOURCE(OPTIONS));
	putimage(0, 0, options);
	delimage(options);
	PIMAGE mouses = newimage();
	getimage(mouses, TEXT("JPG"), MAKEINTRESOURCE(MOUSES));
	putimage(150, 0, mouses);
	delimage(mouses);
	if (anewimage != nullptr)
	{
		putimage(0, 200, anewimage);
		delimage(anewimage);
	}
	delay_ms(0);
	while (mousemsg())
		getmouse();
	setcolor(0xFF000000);
	for (;is_run();delay_fps(60))
	{
		while (mousemsg())
		{
			mouse_msg mouse = getmouse();
			if (mouse.y > 200)
			{
				mouse = draws(mouse);
			}
			if (mouse.is_down())
			{
				if (mouse.y < 200)
				{
					if (mouse.x > 750 && mouse.x < 1475)
					{
						colors(mouse);
					}
					if (mouse.is_left())
					{
						if (mouse.x > 0 && mouse.x < 50)
						{
							exit(1);
						}
						if (mouse.x > 50 && mouse.x < 100)
						{
							color_t nowcolor = getfillcolor();
							setfillcolor(WHITE);
							bar(0, 200, 1600, 900);
							setfillcolor(nowcolor);
						}
						if (mouse.x > 100 && mouse.x < 150)
						{
							revoke;
						}
						if (mouse.x > 1475 && mouse.x < 1536)
						{
							PIMAGE nowfiles = newimage();
							getimage(nowfiles, 0, 200, 1600, 700);
							savefiles(nowfiles);
							delay_ms(0);
						}
						if (mouse.x > 150)
						{
							if (mouse.x < 250 && mouse.y < 100)
							{
								ways = MOUSE;
								putimage(150, 0, opts);
								PIMAGE mouses = newimage();
								getimage(mouses, TEXT("JPG"), MAKEINTRESOURCE(MOUSES));
								putimage(150, 0, mouses);
								delimage(mouses);
							}
							if (mouse.x < 250 && mouse.y > 100)
							{
								ways = LINES;
								putimage(150, 0, opts);
								PIMAGE plines = newimage();
								getimage(plines, TEXT("JPG"), MAKEINTRESOURCE(PLINES));
								putimage(150, 100, plines);
								delimage(plines);
							}
							if (mouse.x > 250 && mouse.x < 350 && mouse.y < 100)
							{
								ways = CIRCLES;
								putimage(150, 0, opts);
								PIMAGE pcircles = newimage();
								getimage(pcircles, TEXT("JPG"), MAKEINTRESOURCE(PCIRCLES));
								putimage(250, 0, pcircles);
								delimage(pcircles);
							}
						}
					}
				}
			}
		}
	}
	return true;
}