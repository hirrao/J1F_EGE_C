#include "head.h"
int Modes = -1;
bool Line_Mode = 0;
int Save = 0;
int width = 1;
extern Draw_Modes* RMake = (Draw_Modes*)malloc(MAX * sizeof(Draw_Modes));
bool Undo_Or_Not = false;
int main()
{
	initgraph(1536, 864, INIT_NOBORDER | INIT_RENDERMANUAL);
	ege_enable_aa(true);
	bool Funopen = false;
	do
	{
		Funopen = FunOpen();
	} while (Funopen == false);
	setcolor(EGEACOLOR(0xFF,BLACK));
	setfillcolor(EGEACOLOR(0xFF, BLACK));
	setbkcolor(WHITE);
	cleardevice();
	PIMAGE Option = newimage();
	getimage(Option, TEXT("JPG"), MAKEINTRESOURCE(IMAGEOPTION));
	putimage(0, 0, Option);
	delimage(Option);
	/*初始化各个图标与全局变量*/
	PIMAGE NewOption = newimage();
	getimage(NewOption, TEXT("JPG"), MAKEINTRESOURCE(NEWOPTION));
	PIMAGE Draw_Line = newimage();
	getimage(Draw_Line, TEXT("JPG"), MAKEINTRESOURCE(DRAW_LINE));
	PIMAGE Draw_Circle = newimage();
	getimage(Draw_Circle, TEXT("JPG"), MAKEINTRESOURCE(DRAW_CIRCLE));
	if (Read != nullptr)
		putimage(0, 2 * BlockY, Read);
	PIMAGE StartImage = newimage();
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		mouse_msg m = getmouse();
		if (m.y > (2 * BlockY))
		{
			m = StartDraw(m);
		}
		else
		{
			if (m.x < BlockDrawStart && m.is_left() && m.is_down())
			{
				if (m.y < BlockY)
				{
					if (m.x < BlockOption)
					{
						exit(1);
					}
					if (m.x < (2 * BlockOption))
					{
						Undo();
						continue;
					}
					if (m.x < (3 * BlockOption))
					{
						ClearDevice();
						Draw_Undo_Init();
						Draw_Redo_Init(0);
						RMake[Save - 1].Mode = CLEAR;
						continue;
					}
					if (m.x < (4 * BlockOption))
					{
						char buf[4] = {};
						inputbox_getline("设置线宽", "请输入线宽", buf, 4);
						width = atoi(buf);
						setlinewidth(width);
					}
				}
				else
				{
					if (m.x < BlockOption)
					{
						SaveFile();
						continue;
					}
					if (m.x < (2 * BlockOption))
					{
						Redo();
						continue;
					}
					if (m.x < 3 * BlockOption)
					{
						Modes = MOUSE;
						continue;
					}
					if (m.x < 4 * BlockOption)
					{
						flushmouse();
						for (;is_run();delay_fps(FPS))
						{
							mouse_msg mou = getmouse();
							if (mou.is_left() && mou.is_down())
							{
								setcolor(EGEACOLOR(0XFF, getpixel(mou.x, mou.y)));
								setfillcolor(EGEACOLOR(0XFF, getpixel(mou.x, mou.y)));
								break;
							}
						}
						continue;
					}
				}
			}
			else if (m.x < BlockColorStart)
			{
				if (m.is_down())
				{
					if (m.y < BlockY)
					{
						if (m.x < (BlockDrawStart + BlockDraw))
						{
							Modes = PIXEL;
							continue;
						}
						if (m.x < (BlockDrawStart + 2 * BlockDraw))
						{
							Modes = CIRCLE;
							putimage(BlockDrawStart, 0, NewOption);
							putimage((BlockDrawStart + BlockDraw), 0, Draw_Circle);
							continue;
						}
					}
					else
					{
						if (m.x < (BlockDrawStart + 2*BlockDraw))
						{
							if (m.is_right())
								Line_Mode = !Line_Mode;
							Modes = LINE + 100 * Line_Mode;
							if (m.is_left())
								Modes = LINE;
							putimage(BlockDrawStart, 0, NewOption);
							if (Modes == LINE)
								putimage(BlockDrawStart, BlockY, Draw_Line);
							else
							{
								if (m.is_right())
								{
									char inputs[3] = {};
									inputbox_getline("多边形边数选择", "请输入多边形边数", inputs, 2);
									Modes += atoi(inputs);
								}
								//putimage(BlockDrawStart, BlockY, Draw_Polygon);
							}
							continue;
						}
					}
				}
			}
			else if (m.is_down())
			{
				SetColor(m);
				continue;
			}
		}
	}
}