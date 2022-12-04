#include"head.h"
PIMAGE Read = nullptr;
bool FunOpen()
{
	PIMAGE ImageOpen = newimage();
	getimage(ImageOpen, TEXT("JPG"), MAKEINTRESOURCE(IMAGEOPEN));
	putimage(0, 0, ImageOpen);
	delimage(ImageOpen);
	Read = newimage();
	flushmouse();
	for (;is_run();delay_fps(360))
	{
			mouse_msg m = getmouse();
			if (m.is_left())
			{
				/*若点击退出，则直接退出*/
				if (m.x > 500 && m.x < 1050 && m.y>680 && m.y < 780)
					exit(1);
				/*读取文件部分（暂时以PNG格式保存与读取文件）*/
				else if (m.x > 500 && m.x < 1050 && m.y>280 && m.y < 380)
				{
					char str[2];
					while (1)
					{
						TCHAR FileName[MAX_PATH] = { 0 };
						OPENFILENAME ofn = { 0 };
						ofn.lStructSize = sizeof(ofn);
						ofn.lpstrFilter = _T("图像文件(*.draw)\0*.draw\0\0");
						ofn.lpstrInitialDir = _T(".\\Images\\");
						ofn.lpstrFile = FileName;
						ofn.nMaxFile = sizeof(FileName) / sizeof(*FileName);
						ofn.nFilterIndex = 0;
						ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
						BOOL ReadOk = GetOpenFileName(&ofn);
						if (ReadOk != 1)
						{
							return false;
						}
						ReadOk = getimage(Read, FileName);
						if (ReadOk != 0)
						{
							inputbox_getline("控制面板", "读取失败！！\n请输入任意键返回开始界面", str, 2);
							return false;
						}
						return true;
					}
				}
				/*不读取文件*/
				else if (m.x > 500 && m.x < 1050 && m.y>480 && m.y < 580)
				{
					delimage(Read);
					Read = nullptr;
					return true;
				}
				/*进入帮助部分*/
				else if (m.x > 100 && m.x < 200 && m.y>300 && m.y < 700)
				{
					Help();
					return false;
				}
			}
	}
	return false;//未知错误时返回
}

/*将文件保存为PNG格式（后缀为DRAW）*/
void SaveFile()
{
	PIMAGE SaveImage = newimage();
	getimage(SaveImage, 0, 200, 1536, 664);
	TCHAR filename[MAX_PATH] = _T("image.draw");
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = _T("图像文件(*.draw)\0*.draw\0\0");
	ofn.lpstrInitialDir = _T(".\\Images\\");
	ofn.lpstrFile = filename;
	ofn.nMaxFile = sizeof(filename) / sizeof(*filename);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_OVERWRITEPROMPT;
	BOOL saveok = GetSaveFileName(&ofn);
	if (saveok == 0)
		return;
	saveimage(SaveImage, filename);
	delimage(SaveImage);
	return;
}

/*调出帮助文档*/
void Help()
{
	PIMAGE HelpFirst = newimage();
	getimage(HelpFirst, TEXT("JPG"), MAKEINTRESOURCE(HELPFIRST));
	putimage(0, 0, HelpFirst);
	flushmouse();
	for (;is_run();delay_fps(FPS))
	{
		mouse_msg m = getmouse();
		if (m.x > 10 && m.x < 160 && m.y>800 && m.y < 900&&m.is_down())
		{
			delimage(HelpFirst);
			return;
		}
	}
}