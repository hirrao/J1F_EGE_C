#include"head.h"
void drawcircle()
{
    char str[20] = {};
    int strint = 0;
    int data[3];
    inputbox_getline("画圆", "请输入X，Y，半径", str, 20);
    data[0] = atoi(strtok(str, " "));
    for (int i = 0;i < 2;i++)
    {
        if (strtok(NULL, str) != NULL)
            data[i + 1] = atoi(strtok(NULL, " "));
        else
        {
            inputbox_getline("控制面板", "输入有误！\n请按任意键回到控制面板", str, 2);
            return;
        }
    }
    if ((data[0] - data[2]) < 0 || (data[0] + data[2]) > 1920 || (data[1] - data[2]) < 0 || (data[1] + data[2]) > 1080 || data[2] < 0)
    {
        inputbox_getline("控制面板", "输入超过了屏幕边界！\n请按任意键回到控制面板", str, 2);
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
    inputbox_getline("画圆", "请输入X1，Y1，X1，Y2", str, 20);
    data[0] = atoi(strtok(str, " "));
    for (int i = 0;i < 3;i++)
        data[i + 1] = atoi(strtok(NULL, " "));
    if (data[0] < 0 || data[1]>1920 || data[2] < 0 || data[3]>1080)
    {
        inputbox_getline("控制面板", "输入超过了屏幕边界！\n请按任意键回到控制面板", str, 2);
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
    inputbox_getline("更改颜色", "请选择需要更改的颜色\n1.红色    2.蓝色\n3.黄色    4.绿色\n5.自定义颜色    6.恢复为默认颜色（白色）\n7.退出", str, 2);
    strint = atoi(str);
    switch (strint)
    {
    case 1:
        setcolor(RED);
        inputbox_getline("更改颜色", "已更改颜色为红色\n请按任意键回到控制面板", str, 2);
        return;
    case 2:
        setcolor(BLUE);
        inputbox_getline("更改颜色", "已更改颜色为蓝色\n请按任意键回到控制面板", str, 2);
        return;
    case 3:
        setcolor(YELLOW);
        inputbox_getline("更改颜色", "已更改颜色为黄色\n请按任意键回到控制面板", str, 2);
        return;
    case 4:
        setcolor(GREEN);
        inputbox_getline("更改颜色", "已更改颜色为绿色\n请按任意键回到控制面板", str, 2);
        return;
    case 5:

        int data[3];
        inputbox_getline("更改颜色", "请以R，G，B的顺序输入RGB值,色深为8bit", str, 20);
        data[0] = atoi(strtok(str, " "));
        for (int i = 0;i < 2;i++)
            data[i + 1] = atoi(strtok(NULL, " "));
        if (data[0] < 0 || data[0]>255 || data[1] < 0 || data[1]>255 || data[2] < 0 || data[2]>255)
        {
            inputbox_getline("控制面板", "输入越界！\n请按任意键回到控制面板", str, 2);
            return;
        }
        setcolor(EGERGB(data[0], data[1], data[2]));
        inputbox_getline("更改颜色", "已更改颜色为自定义颜色\n请按任意键回到控制面板", str, 2);
        return;
    case 6:
        setcolor(WHITE);
        inputbox_getline("更改颜色", "已重置颜色为白色\n请按任意键回到控制面板", str, 2);
        return;
    case 7:
        return;
    default:
        inputbox_getline("控制面板", "无效的输入\n请回车后回到控制面板", str, 2);
    }
    return;
}