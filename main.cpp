#include<stdio.h>
#include<graphics.h>
#include<string.h>
void read();                      //实现读取操作的函数
void option();                    //实现功能选择操作的函数
void print();                     //实现画图选择功能的函数
void drawcircle();                //实现画圆相关功能的函数
void drawrec();                   //实现画矩形相关功能的函数
void choosecolor();               //实现颜色改变相关功能的函数
char cho[20];
int choo = 0;
int main(void)
{
	setcaption("画图");
	initgraph(1920, 1080);
	read();
	option();
	return 0;
}

void read(void)
{
	while(1)
	{
		inputbox_getline("控制面板", "欢迎来到画图程序！\n请选择是否进行文件读取操作\n1.读取\n2.不读取\n请输入你的选择", cho, 2);
		choo = atoi(cho);
		switch (choo)
		{
		case 1:
			inputbox_getline("控制面板", "已读取\n请输入任意键继续", cho, 2);
			return;
		case 2:
			inputbox_getline("控制面板", "未读取\n请输入任意键继续", cho, 2);
			return;
		default:
			inputbox_getline("控制面板", "无效的输入\n请回车后重新回到开始界面输入", cho, 2);
		}
	}
}

void option(void)
{
	while (1)
	{
		inputbox_getline("控制面板", "请选择接下来进行的操作\n1.绘图\n2.清空屏幕\n3.退出\n", cho, 2);
		choo = atoi(cho);
		switch (choo)
		{
		case 1:
			print();               //画图后若输入功能键会显示无效输入，暂无法解决
			break;
		case 2:
			cleardevice();
			break;
		case 3:
			exit(1);
		default:
			inputbox_getline("控制面板", "无效的输入\n请回车后重新回到开始界面输入", cho, 2);
		}
	}
}

void print(void)
{
	inputbox_getline("控制面板", "请选择接下来进行的操作\n1.画圆\n2.画矩形\n3.更改颜色\n4.退出\n", cho, 2);
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
		inputbox_getline("控制面板", "无效的输入\n请回车后回到控制面板", cho, 2);
	}
}

void drawcircle(void)
{
	int data[3];
	inputbox_getline("画圆", "请输入X，Y，半径", cho, 20);
	data[0] = atoi(strtok(cho, " "));
	for (int i = 0;i < 2;i++)
		data[i + 1] = atoi(strtok(NULL, " "));
	if ((data[0] - data[2]) < 0 || (data[0] + data[2]) > 1920 || (data[1] - data[2]) < 0 || (data[1] + data[2]) > 1080 || data[2] < 0)
	{
		inputbox_getline("控制面板", "输入超过了屏幕边界！\n请按任意键回到控制面板", cho, 2);
		return;
	}
	circle(data[0], data[1], data[2]);
	getch();
	return;
}

void drawrec(void)
{
	int data[4];
	inputbox_getline("画圆", "请输入X1，Y1，X1，Y2", cho, 20);
	data[0] = atoi(strtok(cho, " "));
	for (int i = 0;i < 3;i++)
		data[i + 1] = atoi(strtok(NULL, " "));
	if (data[0] < 0 || data[1]>1920 || data[2] < 0 || data[3]>1080)
	{
		inputbox_getline("控制面板", "输入超过了屏幕边界！\n请按任意键回到控制面板", cho, 2);
		return;
	}
	rectangle(data[0], data[1], data[2], data[3]);
	getch();
	return;
}

void choosecolor(void)
{
	inputbox_getline("更改颜色", "请选择需要更改的颜色\n1.红色    2.蓝色\n3.黄色    4.绿色\n5.自定义颜色    6.恢复为默认颜色（白色）\n7.退出", cho, 2);
	choo = atoi(cho);
	switch (choo)
	{
	case 1:
		setcolor(RED);
		inputbox_getline("更改颜色", "已更改颜色为红色\n请按任意键回到控制面板", cho, 2);
		return;
	case 2:
		setcolor(BLUE);
		inputbox_getline("更改颜色", "已更改颜色为蓝色\n请按任意键回到控制面板", cho, 2);
		return;
	case 3:
		setcolor(YELLOW);
		inputbox_getline("更改颜色", "已更改颜色为黄色\n请按任意键回到控制面板", cho, 2);
		return;
	case 4:
		setcolor(GREEN);
		inputbox_getline("更改颜色", "已更改颜色为绿色\n请按任意键回到控制面板", cho, 2);
		return;
	case 5:

		int data[3];
		inputbox_getline("更改颜色", "请以R，G，B的顺序输入RGB值,色深为8bit", cho, 20);
		data[0] = atoi(strtok(cho, " "));
		for (int i = 0;i < 2;i++)
			data[i + 1] = atoi(strtok(NULL, " "));
		if (data[0] < 0 || data[0]>255 || data[1] < 0 || data[1]>255 || data[2] < 0 || data[2]>255)
		{
			inputbox_getline("控制面板", "输入越界！\n请按任意键回到控制面板", cho, 2);
			return;
		}
		setcolor(EGERGB(data[0],data[1],data[2]));
		inputbox_getline("更改颜色", "已更改颜色为自定义颜色\n请按任意键回到控制面板", cho, 2);
		return;
	case 6:
		setcolor(WHITE);
		inputbox_getline("更改颜色", "已重置颜色为白色\n请按任意键回到控制面板", cho, 2);
		return;
	case 7:
		return;
	default:
		inputbox_getline("控制面板", "无效的输入\n请回车后回到控制面板", cho, 2);
	}
	return;
}