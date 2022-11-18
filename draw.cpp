#include"head.h"
void drawcircle()
{
    char str[20] = {};
    int strint = 0;
    int data[3];
    inputbox_getline("��Բ", "������X��Y���뾶", str, 20);
    data[0] = atoi(strtok(str, " "));
    for (int i = 0;i < 2;i++)
    {
        if (strtok(NULL, str) != NULL)
            data[i + 1] = atoi(strtok(NULL, " "));
        else
        {
            inputbox_getline("�������", "��������\n�밴������ص��������", str, 2);
            return;
        }
    }
    if ((data[0] - data[2]) < 0 || (data[0] + data[2]) > 1920 || (data[1] - data[2]) < 0 || (data[1] + data[2]) > 1080 || data[2] < 0)
    {
        inputbox_getline("�������", "���볬������Ļ�߽磡\n�밴������ص��������", str, 2);
        return;
    }
    circle(data[0], data[1], data[2]);
    getch();
    return;
}

void drawrec()
{
    char str[20] = {};
    int strint = 0;
    int data[4];
    inputbox_getline("��Բ", "������X1��Y1��X1��Y2", str, 20);
    data[0] = atoi(strtok(str, " "));
    for (int i = 0;i < 3;i++)
        data[i + 1] = atoi(strtok(NULL, " "));
    if (data[0] < 0 || data[1]>1920 || data[2] < 0 || data[3]>1080)
    {
        inputbox_getline("�������", "���볬������Ļ�߽磡\n�밴������ص��������", str, 2);
        return;
    }
    rectangle(data[0], data[1], data[2], data[3]);
    getch();
    return;
}

void choosecolor()
{
    char str[20] = {};
    int strint = 0;
    inputbox_getline("������ɫ", "��ѡ����Ҫ���ĵ���ɫ\n1.��ɫ    2.��ɫ\n3.��ɫ    4.��ɫ\n5.�Զ�����ɫ    6.�ָ�ΪĬ����ɫ����ɫ��\n7.�˳�", str, 2);
    strint = atoi(str);
    switch (strint)
    {
    case 1:
        setcolor(RED);
        inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", str, 2);
        return;
    case 2:
        setcolor(BLUE);
        inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", str, 2);
        return;
    case 3:
        setcolor(YELLOW);
        inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", str, 2);
        return;
    case 4:
        setcolor(GREEN);
        inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", str, 2);
        return;
    case 5:

        int data[3];
        inputbox_getline("������ɫ", "����R��G��B��˳������RGBֵ,ɫ��Ϊ8bit", str, 20);
        data[0] = atoi(strtok(str, " "));
        for (int i = 0;i < 2;i++)
            data[i + 1] = atoi(strtok(NULL, " "));
        if (data[0] < 0 || data[0]>255 || data[1] < 0 || data[1]>255 || data[2] < 0 || data[2]>255)
        {
            inputbox_getline("�������", "����Խ�磡\n�밴������ص��������", str, 2);
            return;
        }
        setcolor(EGERGB(data[0], data[1], data[2]));
        inputbox_getline("������ɫ", "�Ѹ�����ɫΪ�Զ�����ɫ\n�밴������ص��������", str, 2);
        return;
    case 6:
        setcolor(WHITE);
        inputbox_getline("������ɫ", "��������ɫΪ��ɫ\n�밴������ص��������", str, 2);
        return;
    case 7:
        return;
    default:
        inputbox_getline("�������", "��Ч������\n��س���ص��������", str, 2);
    }
    return;
}