#include"head.h"
void colors(mouse_msg mouse)
{
	if (mouse.x < 1325 || mouse.is_left())
	{
		setcolor(EGEACOLOR(0XFF, getpixel(mouse.x, mouse.y)));
		setfillcolor(EGEACOLOR(0XFF, getpixel(mouse.x, mouse.y)));
		return;
	}
	else if (mouse.is_right())
	{
		int blocksx = 0;
		int blocksy = 0;
		if (mouse.x < 1400)
		{
			blocksx = 1350;
			if (mouse.y < 100)
				blocksy = 50;
			else if (mouse.y > 100)
				blocksy = 150;
		}
		else if (mouse.x > 1400)
		{
			blocksx = 1425;
			if (mouse.y < 100)
				blocksy = 50;
			else if (mouse.y > 100)
				blocksy = 150;
		}
		char buf[12];
		inputbox_getline("颜色选择", "请输入想要设置的R，G，B值", buf, 12);
		int data[3] = {};
		data[0] = atoi(strtok(buf, " "));
		for (int i = 0;i < 2;i++)
		{
			//while (strtok(NULL, buf) != NULL)
				data[i + 1] = atoi(strtok(NULL, " "));
		}
		if (data[2] == '\0')
		{
			inputbox_getline("控制面板", "输入有误！\n请按任意键回到画图界面", buf, 2);
			return;
		}
		if (data[0] > 255 || data[1] > 255 || data[2] > 255)
		{
			inputbox_getline("控制面板", "输入有误！\n请按任意键回到画图界面", buf, 2);
			return;
		}
		else
		{
			setcolor(EGERGB(data[0], data[1], data[2]));
			setfillcolor(EGERGB(data[0], data[1], data[2]));
			bar(blocksx - 25, blocksy - 50, blocksx + 50, blocksy + 50);
		}
	}
}