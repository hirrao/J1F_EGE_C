#include<stdio.h>
#include<graphics.h>
#include<string.h>
void read();                      //ʵ�ֶ�ȡ�����ĺ���
void option();                    //ʵ�ֹ���ѡ������ĺ���
void print();                     //ʵ�ֻ�ͼѡ���ܵĺ���
void drawcircle();                //ʵ�ֻ�Բ��ع��ܵĺ���
void drawrec();                   //ʵ�ֻ�������ع��ܵĺ���
void choosecolor();               //ʵ����ɫ�ı���ع��ܵĺ���
char cho[20];
int choo = 0;
int main(void)
{
	setcaption("��ͼ");
	initgraph(1920, 1080);
	read();
	option();
	return 0;
}

void read(void)
{
	while(1)
	{
		inputbox_getline("�������", "��ӭ������ͼ����\n��ѡ���Ƿ�����ļ���ȡ����\n1.��ȡ\n2.����ȡ\n���������ѡ��", cho, 2);
		choo = atoi(cho);
		switch (choo)
		{
		case 1:
			inputbox_getline("�������", "�Ѷ�ȡ\n���������������", cho, 2);
			return;
		case 2:
			inputbox_getline("�������", "δ��ȡ\n���������������", cho, 2);
			return;
		default:
			inputbox_getline("�������", "��Ч������\n��س������»ص���ʼ��������", cho, 2);
		}
	}
}

void option(void)
{
	while (1)
	{
		inputbox_getline("�������", "��ѡ����������еĲ���\n1.��ͼ\n2.�����Ļ\n3.�˳�\n", cho, 2);
		choo = atoi(cho);
		switch (choo)
		{
		case 1:
			print();               //��ͼ�������빦�ܼ�����ʾ��Ч���룬���޷����
			break;
		case 2:
			cleardevice();
			break;
		case 3:
			exit(1);
		default:
			inputbox_getline("�������", "��Ч������\n��س������»ص���ʼ��������", cho, 2);
		}
	}
}

void print(void)
{
	inputbox_getline("�������", "��ѡ����������еĲ���\n1.��Բ\n2.������\n3.������ɫ\n4.�˳�\n", cho, 2);
	choo = atoi(cho);
	switch (choo)
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
		inputbox_getline("�������", "��Ч������\n��س���ص��������", cho, 2);
	}
}

void drawcircle(void)
{
	int data[3];
	inputbox_getline("��Բ", "������X��Y���뾶", cho, 20);
	data[0] = atoi(strtok(cho, " "));
	for (int i = 0;i < 2;i++)
		data[i + 1] = atoi(strtok(NULL, " "));
	if ((data[0] - data[2]) < 0 || (data[0] + data[2]) > 1920 || (data[1] - data[2]) < 0 || (data[1] + data[2]) > 1080 || data[2] < 0)
	{
		inputbox_getline("�������", "���볬������Ļ�߽磡\n�밴������ص��������", cho, 2);
		return;
	}
	circle(data[0], data[1], data[2]);
	getch();
	return;
}

void drawrec(void)
{
	int data[4];
	inputbox_getline("��Բ", "������X1��Y1��X1��Y2", cho, 20);
	data[0] = atoi(strtok(cho, " "));
	for (int i = 0;i < 3;i++)
		data[i + 1] = atoi(strtok(NULL, " "));
	if (data[0] < 0 || data[1]>1920 || data[2] < 0 || data[3]>1080)
	{
		inputbox_getline("�������", "���볬������Ļ�߽磡\n�밴������ص��������", cho, 2);
		return;
	}
	rectangle(data[0], data[1], data[2], data[3]);
	getch();
	return;
}

void choosecolor(void)
{
	inputbox_getline("������ɫ", "��ѡ����Ҫ���ĵ���ɫ\n1.��ɫ    2.��ɫ\n3.��ɫ    4.��ɫ\n5.�Զ�����ɫ    6.�ָ�ΪĬ����ɫ����ɫ��\n7.�˳�", cho, 2);
	choo = atoi(cho);
	switch (choo)
	{
	case 1:
		setcolor(RED);
		inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", cho, 2);
		return;
	case 2:
		setcolor(BLUE);
		inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", cho, 2);
		return;
	case 3:
		setcolor(YELLOW);
		inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", cho, 2);
		return;
	case 4:
		setcolor(GREEN);
		inputbox_getline("������ɫ", "�Ѹ�����ɫΪ��ɫ\n�밴������ص��������", cho, 2);
		return;
	case 5:

		int data[3];
		inputbox_getline("������ɫ", "����R��G��B��˳������RGBֵ,ɫ��Ϊ8bit", cho, 20);
		data[0] = atoi(strtok(cho, " "));
		for (int i = 0;i < 2;i++)
			data[i + 1] = atoi(strtok(NULL, " "));
		if (data[0] < 0 || data[0]>255 || data[1] < 0 || data[1]>255 || data[2] < 0 || data[2]>255)
		{
			inputbox_getline("�������", "����Խ�磡\n�밴������ص��������", cho, 2);
			return;
		}
		setcolor(EGERGB(data[0],data[1],data[2]));
		inputbox_getline("������ɫ", "�Ѹ�����ɫΪ�Զ�����ɫ\n�밴������ص��������", cho, 2);
		return;
	case 6:
		setcolor(WHITE);
		inputbox_getline("������ɫ", "��������ɫΪ��ɫ\n�밴������ص��������", cho, 2);
		return;
	case 7:
		return;
	default:
		inputbox_getline("�������", "��Ч������\n��س���ص��������", cho, 2);
	}
	return;
}