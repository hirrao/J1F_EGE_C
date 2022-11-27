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
				if (m.x > 500 && m.x < 1050 && m.y>680 && m.y < 780)
					exit(1);
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
				else if (m.x > 500 && m.x < 1050 && m.y>480 && m.y < 580)
				{
					delimage(Read);
					Read = nullptr;
					return true;
				}
				else if (m.x > 100 && m.x < 200 && m.y>300 && m.y < 700)
				{
					return false;
				}
			}
	}
	return false;//未知错误时返回
}

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