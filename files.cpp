#include"head.h"
void read()
{
    PIMAGE cd = newimage();
    char str[20];
    int strint = 0;
    while (1)
    {
        inputbox_getline("�������", "��ӭ������ͼ����\n��ѡ���Ƿ�����ļ���ȡ����\n1.��ȡ\n2.����ȡ\n���������ѡ��", str, 2);
        strint = atoi(str);
        switch (strint)
        {
        case 1:
        {
            TCHAR filename[MAX_PATH] = { 0 };
            OPENFILENAME ofn = { 0 };
            ofn.lStructSize = sizeof(ofn);
            ofn.lpstrFilter = _T("ͼ���ļ�(*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico)");
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
                inputbox_getline("�������", "��ȡʧ�ܣ�����ȷ������ѡ���ļ�\n��������������ض�ȡѡ�����", str, 2);
                break;
            }
            if (readokk != 0)
            {
                inputbox_getline("�������", "��ȡʧ�ܣ���\n��ѡ��涨�ļ���ʽ��һ�֣�*.png *.jpg *.bmp *.gif *.emf *.wmf *.ico��\n��������������ض�ȡѡ�����", str, 2);
                break;
            }
            inputbox_getline("�������", "�Ѷ�ȡ\n���������������", str, 2);
            return;
        }
        case 2:
            inputbox_getline("�������", "δ��ȡ\n���������������", str, 2);
            return;
        default:
            inputbox_getline("�������", "��Ч������\n��س������»ص���ʼ��������", str, 2);
        }
    }
}

void save()
{
    return;
}