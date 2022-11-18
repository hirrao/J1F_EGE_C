#include"head.h"
bool read()
{
    PIMAGE cd = newimage();
    char str[5];
    while (1)
    {
            TCHAR filename[MAX_PATH] = { 0 };
            OPENFILENAME ofn = { 0 };
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = _T("图像文件(*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico)");
            ofn.lpstrInitialDir = _T(".\\Images\\");
            ofn.lpstrFile = filename;
            ofn.nMaxFile = sizeof(filename) / sizeof(*filename);
            ofn.nFilterIndex = 0;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
            BOOL readok = GetOpenFileName(&ofn);
            if (readok != 1)
            {
                return false;
            }
            PIMAGE cd = newimage(1600, 700);
            BOOL readokk = getimage(cd, filename);
            if (readokk != 0)
            {
                inputbox_getline("控制面板", "读取失败！！\n请选择规定文件格式的一种（*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico）\n请输入任意键返回开始界面", str, 2);
                return false;
            }
            anewimage = cd;
            return true;
        }
    }

void savefiles(PIMAGE images)
{
    TCHAR filename[MAX_PATH] = _T("image.draw");
    OPENFILENAME ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = _T("图像文件(*.draw)");
    ofn.lpstrInitialDir = _T(".\\Images\\");
    ofn.lpstrFile = filename;
    ofn.nMaxFile = sizeof(filename) / sizeof(*filename);
    ofn.nFilterIndex = 0;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_OVERWRITEPROMPT;
    BOOL saveok = GetSaveFileName(&ofn);
    if (saveok == 0)
        return;
    saveimage(images,filename);
}