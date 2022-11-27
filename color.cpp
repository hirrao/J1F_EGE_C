#include"head.h"
void SetColor(mouse_msg mouse)
{
	if (mouse.x < BlockColorEnd && mouse.is_left())
	{
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
		inputbox_getline("��ɫѡ��", "��������Ҫ���õ�R��G��Bֵ(����֮���Կո������", buf, 12);
		int data[3] = {};
		int OK = sscanf(buf, "%d %d %d", &data[0], &data[1], &data[2]);
		if (OK < 3)
		{
			inputbox_getline("�������", "��������̫�٣�\n�밴������ص���ͼ����", buf, 2);
			return;
		}
		if (data[0] > 255 || data[1] > 255 || data[2] > 255)
		{
			inputbox_getline("�������", "����Խ�磡\n�밴������ص���ͼ����", buf, 2);
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