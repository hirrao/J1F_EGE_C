#include"head.h"
void SetColor(mouse_msg mouse)
{
	if (mouse.x < BlockColorEnd && mouse.is_left())
	{
		/*设置颜色，直接设置为鼠标点击处的颜色*/
		if (mouse.y != 100 && mouse.y != 99)
		{
			for (int n = 0;n < 9;++n)
			{
				if (mouse.x == BlockColorStart + n * BlockColor - 1 || mouse.x == BlockColorStart + n * BlockColor)
					return;
			}
			setcolor(EGEACOLOR(0XFF, getpixel(mouse.x, mouse.y)));
			setfillcolor(EGEACOLOR(0XFF, getpixel(mouse.x, mouse.y)));
			return;
		}
	}
	/*对四个预设框尽心颜色修改*/
	else if (mouse.is_right())
	{
		int blocksx = 0;
		int blocksy = 0;
		if (mouse.x < (BlockColorEnd - BlockColor))
		{
			blocksx = 1;
			if (mouse.y < BlockY)
				blocksy = 1;
			else if (mouse.y > BlockY)
				blocksy = 2;
		}
		else
		{
			blocksx = 2;
			if (mouse.y < BlockY)
				blocksy = 1;
			else if (mouse.y > BlockY)
				blocksy = 2;
		}
		char buf[12];
		inputbox_getline("颜色选择", "请输入想要设置的R，G，B值(数字之间以空格隔开）", buf, 12);
		int data[3] = {};
		int OK = sscanf(buf, "%d %d %d", &data[0], &data[1], &data[2]);
		if (OK < 3)
		{
			inputbox_getline("控制面板", "输入数量太少！\n请按任意键回到画图界面", buf, 2);
			return;
		}
		if (data[0] > 255 || data[1] > 255 || data[2] > 255)
		{
			inputbox_getline("控制面板", "输入越界！\n请按任意键回到画图界面", buf, 2);
			return;
		}
		else
		{
			setcolor(EGERGB(data[0], data[1], data[2]));
			setfillcolor(EGERGB(data[0], data[1], data[2]));
			if (blocksx == 1)
			{
				if (blocksy == 1)
					bar(BlockColorEnd - 2 * BlockColor + 1, 0, BlockColorEnd - BlockColor - 1, BlockY - 1);
				else
					bar(BlockColorEnd - 2 * BlockColor + 1, BlockY + 1, BlockColorEnd - BlockColor - 1, 2 * BlockY);
			}
			else
			{
				if (blocksy == 1)
					bar(BlockColorEnd - BlockColor + 1, 0, BlockColorEnd - 13, BlockY - 1);
				else
					bar(BlockColorEnd - BlockColor + 1, BlockY + 1, BlockColorEnd - 13, 2 * BlockY);
			}
		}
	}
}