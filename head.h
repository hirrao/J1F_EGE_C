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
	coordinate coor[20] = {};                       //��¼����
	int Mode = Modes;								//��¼��ͼ��ʽ
	color_t Color;									//��¼��ɫ
	int Width = width;								//��¼�������
	coordinate* pixel_ = nullptr;					//����Ǧ��ģʽ��������һ��Ǧ��ģʽ�滭��������Ϣ
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