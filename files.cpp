#include"head.h"
PIMAGE Read = nullptr;
FILE* savefiles = nullptr;
TCHAR filename[MAX_PATH] = _T("newimage");
TCHAR FileName[MAX_PATH] = {};
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
					char str[2] = {};
					while (1)
					{
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
						return true;
					}
				}
				/*不读取文件*/
				else if (m.x > 500 && m.x < 1050 && m.y>480 && m.y < 580)
				{
					FileName[250] = 1;
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

void ReadFromFile(TCHAR* fn)
{
	FILE* openfile = _wfopen(fn, _T("r"));
	int ReadMode = -1;
	for (;is_run();delay_fps(FPS))
	{
		int n=fwscanf(openfile, _T("%d "), &ReadMode);
		if (n <= 0)
			return;
		switch (ReadMode)
		{
		case 2:
		{
			int* XY = (int*)malloc(MAX * 2 * sizeof(int));
			int r = 0, g = 0, b = 0;
			double wi = 0;
			int N = 0;
			fwscanf(openfile, _T("%d "), &N);
			for (int a = 0;a < (2 * N - 2);++a)
			{
				fwscanf(openfile, _T("%d "), &XY[a]);
			}
			fwscanf(openfile, _T("%d %d %d %lf"), &r, &g, &b, &wi);
			setlinewidth(wi);
			setcolor(EGEACOLOR(0xFF, EGERGB(r, g, b)));
			for (int a = 2;a < (2 * N - 2);a = a + 2)
			{
				ege_line(XY[a - 2], XY[a - 1], XY[a], XY[a + 1]);
			}
			free(XY);
			break;
		}
		case 3:
		{
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0, r = 0, g = 0, b = 0;
			double wi = 0;
			fwscanf(openfile, _T("%d %d %d %d %d %d %d %lf\n"), &x1, &y1, &x2, &y2, &r, &g, &b, &wi);
			setlinewidth(wi);
			setcolor(EGEACOLOR(0xFF, EGERGB(r, g, b)));
			ege_line(x1, y1, x2, y2);
			break;
		}
		case 4:
		{
			int x1 = 0, x2 = 0, y1 = 0, y2 = 0, r = 0, g = 0, b = 0;
			double wi = 0;
			fwscanf(openfile, _T("%d %d %d %d %d %d %d %lf\n"), &x1, &y1, &x2, &y2, &r, &g, &b, &wi);
			setlinewidth(wi);
			setcolor(EGEACOLOR(0xFF, EGERGB(r, g, b)));
			float R = float(sqrt(pow(double(x2 - x1), 2) + pow(double(y2 - y1), 2)));
			ege_ellipse(x1 - R, y1 - R, 2 * R, 2 * R);
			break;
		}
		case 5:
		{
			int pt[100] = {};
			int r = 0, g = 0, b = 0;
			double wi = 0;
			int N = 0;
			fwscanf(openfile, _T("%d "), &N);
			for (int n = 0;n < N;++n)
			{
				fwscanf(openfile, _T("%d %d "), &pt[2 * n], &pt[2 * n + 1]);
			}
			setlinewidth(wi);
			setcolor(EGEACOLOR(0xFF, EGERGB(r, g, b)));
			fillpoly(N, pt);
			break;
		}
		}
	}
}

void SaveFile()
{
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = _T("图像文件(*.draw)\0*.draw\0\0");
	ofn.lpstrInitialDir = _T("./Images/");
	ofn.lpstrFile = filename;
	ofn.nMaxFile = sizeof(filename) / sizeof(*filename);
	ofn.nFilterIndex = 0;
	ofn.lpstrDefExt = _T(".draw");
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_OVERWRITEPROMPT;
	BOOL saveok = GetSaveFileName(&ofn);
	if (saveok != 1)
		return;
	savefiles = _wfopen(filename,_T("w"));
	for (int a = 0;a < Save;++a)
	{
		WriteToFile(RMake[a]);
	}
	fclose(savefiles);
	savefiles = nullptr;
	return;
}

void WriteToFile(Draw_Modes IM)
{
	switch (IM.Mode)
	{
	case CLEAR:
	{
		fclose(savefiles);
		savefiles = nullptr;
		savefiles = _wfopen(filename, _T("w"));
		break;
	}
	case PIXEL:
	{
		fwprintf(savefiles, _T("2 %04d "),IM.pixel_[0].x);
		for (int n = 1;n < IM.pixel_[0].x;++n)
		{
			fwprintf(savefiles, _T("%04d %04d "), IM.pixel_[n].x, IM.pixel_[n].y);
		}
		fwprintf(savefiles, _T("%04d %04d %04d %.04lf\n"), EGEGET_R(IM.Color), EGEGET_G(IM.Color), EGEGET_B(IM.Color), IM.Width);
		break;
	}
	case LINE:
	{
		fwprintf(savefiles, _T("3 %04d %04d %04d %04d %04d %04d %04d %.04lf\n"), IM.coor[1].x, IM.coor[1].y, IM.coor[2].x, IM.coor[2].y, EGEGET_R(IM.Color), EGEGET_G(IM.Color), EGEGET_B(IM.Color), IM.Width);
		break;
	}
	case CIRCLE:
	{
		fwprintf(savefiles, _T("4 %04d %04d %04d %04d %04d %04d %04d %.04lf\n"), IM.coor[1].x, IM.coor[1].y, IM.coor[2].x, IM.coor[2].y, EGEGET_R(IM.Color), EGEGET_G(IM.Color), EGEGET_B(IM.Color), IM.Width);
		break;
	}
	case Homework_Polygon:
	{
		fwprintf(savefiles, _T("5 %04d "), IM.coor[0].x);
		for (int n = 0;n < IM.coor[0].x;++n)
		{
			fwprintf(savefiles, _T("%04d %04d "), IM.coor[n + 1].x, IM.coor[n + 1].y);
		}
		fwprintf(savefiles, _T("%04d %04d %04d %.04lf\n"), EGEGET_R(IM.Color), EGEGET_G(IM.Color), EGEGET_B(IM.Color), IM.Width);
		break;
	}
	}
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