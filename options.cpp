#include"head.h"
void option()
{
    char str[20] = {};
    int strint = 0;
    while (1)
    {
        inputbox_getline("控制面板", "请选择接下来进行的操作\n1.绘图\n2.清空屏幕\n3.退出\n", str, 2);
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
            inputbox_getline("控制面板", "无效的输入\n请回车后重新回到开始界面输入", str, 2);
        }
    }
}

void print()
{
    char str[20] = {};
    int strint = 0;
    inputbox_getline("控制面板", "请选择接下来进行的操作\n1.画圆\n2.画矩形\n3.更改颜色\n4.退出\n", str, 2);
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
        inputbox_getline("控制面板", "无效的输入\n请回车后回到控制面板", str, 2);
    }
}