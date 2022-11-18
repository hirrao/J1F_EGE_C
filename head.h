#pragma once
#ifndef EGE_LAB_H
#define EGE_LAB_H
#define _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<tchar.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"resource.h"
bool opens();//打开文件操作相关函数
bool options();//菜单函数
bool read();//读取文件函数
void help();//可以引入帮助菜单
void savefiles(PIMAGE);//保存文件相关函数
void colors(mouse_msg);//选择和更改颜色相关函数
mouse_msg draws(mouse_msg);//绘图相关函数
void pline(mouse_msg);//画线
void pcircle(mouse_msg);//画圆
extern PIMAGE anewimage;//TEST
extern mouse_msg anmouse;//
extern int anmous;//以上两个使得在绘图函数中可以访问菜单
extern int ways;//绘图模式变量
void revoke();
enum wayss//绘图模式枚举
{
	MOUSE = 0,
	LINES = 1,
	CIRCLES = 2
};
typedef struct drimage
{
	int x1 = -1;
	int x2 = -1;
	int y1 = -1;
	int y2 = -1;
	int x3 = -1;
	int y3 = -1;
	int mode = -1;
}drimage;//绘图信息保存结构体
extern drimage nowimages[20];//绘图信息保存数组
drimage moutodri(mouse_msg msg, int mo = 1);//将mouse_msg结构体转换为自定义结构体
#endif 
