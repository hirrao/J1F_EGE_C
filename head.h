#pragma once
#include<graphics.h>
#include<stdarg.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<tchar.h>
#include"resource.h"
#include<stdio.h>
#define FPS 360
#define MAX 1000
extern int Modes;
extern int Save;
extern bool Undo_Or_Not;
extern int width;
enum BLOCKS
{
	BlockOption = 100,
	BlockDrawStart = 400,
	BlockDraw = 100,
	BlockY = 100,
	BlockColor = 75,
	BlockColorStart = 800,
	BlockColorEnd = 1550
};
enum DrawWays
{
	MOUSE = 0,
	CLEAR = 1,
	PIXEL = 2,
	LINE = 3,
	CIRCLE = 4
};
typedef struct coordinate
{
	int x = -1;
	int y = -1;
}coordinate;
typedef struct Draw_Modes
{
	coordinate coor[20] = {};                       //记录坐标
	int Mode = Modes;								//记录绘图方式
	color_t Color;									//记录颜色
	int Width = width;								//记录线条宽度
	coordinate* pixel_ = nullptr;					//仅限铅笔模式，保留这一次铅笔模式绘画的完整信息
}Draw_Modes;
extern Draw_Modes* RMake;
void ClearDevice();
void SetColor(mouse_msg mouse);
bool FunOpen();
void SaveFile();
extern PIMAGE Read;
void Undo();
void Redo(int Num = -1);
mouse_msg StartDraw(mouse_msg mouse);
void Draw_Line(mouse_msg mouse);
void Draw_Pixel(mouse_msg mouse);
void Draw_Circle(mouse_msg mouse);
void Draw_Undo_Init();
void Draw_Redo_Init(int Num, ...);