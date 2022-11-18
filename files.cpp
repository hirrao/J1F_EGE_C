#include"head.h"
void read()
{
    PIMAGE cd = newimage();
    char str[20];
    int strint = 0;
    while (1)
    {
        inputbox_getline("控制面板", "欢迎来到画图程序！\n请选择是否进行文件读取操作\n1.读取\n2.不读取\n请输入你的选择", str, 2);
        strint = atoi(str);
        switch (strint)
        {
        case 1:
        {
            TCHAR filename[MAX_PATH] = { 0 };
            OPENFILENAME ofn = { 0 };
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = _T("图像文件(*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico)");
            ofn.lpstrInitialDir = _T("D:");
            ofn.lpstrFile = filename;
            ofn.nMaxFile = sizeof(filename) / sizeof(*filename);
            ofn.nFilterIndex = 0;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
            BOOL readok = GetOpenFileName(&ofn);
            PIMAGE cd = newimage();
            BOOL readokk = getimage(cd, filename);
            putimage(0, 0, cd);
            delimage(cd);
            if (readok != 1)
            {
                inputbox_getline("控制面板", "读取失败！！请确认你已选择文件\n请输入任意键返回读取选择界面", str, 2);
                break;
            }
            if (readokk != 0)
            {
                inputbox_getline("控制面板", "读取失败！！\n请选择规定文件格式的一种（*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico）\n请输入任意键返回读取选择界面", str, 2);
                break;
            }
            inputbox_getline("控制面板", "已读取\n请输入任意键继续", str, 2);
            return;
        }
        case 2:
            inputbox_getline("控制面板", "未读取\n请输入任意键继续", str, 2);
            return;
        default:
            inputbox_getline("控制面板", "无效的输入\n请回车后重新回到开始界面输入", str, 2);
        }
    }
}

void save()
{
    return;
}