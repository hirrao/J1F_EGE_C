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
            ofn.lpstrFilter = _T("ͼ���ļ�(*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico)");
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
                inputbox_getline("�������", "��ȡʧ�ܣ���\n��ѡ��涨�ļ���ʽ��һ�֣�*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico��\n��������������ؿ�ʼ����", str, 2);
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
    ofn.lpstrFilter = _T("ͼ���ļ�(*.draw)");
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