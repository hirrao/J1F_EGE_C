#include"head.h"
void option()
{
    char str[20] = {};
    int strint = 0;
    while (1)
    {
        inputbox_getline("�������", "��ѡ����������еĲ���\n1.��ͼ\n2.�����Ļ\n3.�˳�\n", str, 2);
        strint = atoi(str);
        switch (strint)
        {
        case 1:
            print();
            break;
        case 2:
            cleardevice();
            break;
        case 3:
            exit(1);
        default:
            inputbox_getline("�������", "��Ч������\n��س������»ص���ʼ��������", str, 2);
        }
    }
}

void print()
{
    char str[20] = {};
    int strint = 0;
    inputbox_getline("�������", "��ѡ����������еĲ���\n1.��Բ\n2.������\n3.������ɫ\n4.�˳�\n", str, 2);
    strint = atoi(str);
    switch (strint)
    {
    case 1:
        drawcircle();
        return;
    case 2:
        drawrec();
        return;
    case 3:
        choosecolor();
        return;
    case 4:
        exit(1);
    default:
        inputbox_getline("�������", "��Ч������\n��س���ص��������", str, 2);
    }
}