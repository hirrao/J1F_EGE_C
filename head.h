#pragma once
#include<graphics.h>
#include<stdarg.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<tchar.h>
#include"resource.h"
#include<stdio.h>
/*各种常量和枚举的声明，遗迹结构体的定义*/
#define FPS 360																//绘图刷新率（因未知原因，低于此数在绘图时有着明显的延迟）
#define MAX 10000															//程序能存储的最大数量的操作
extern int Modes;															//当前绘图模式
extern int Save;															//当前存储的图形数量
extern bool Undo_Or_Not;													//是否在撤销后又重新绘图
extern double width;														//当前线宽
/*区块长宽枚举*/
enum BLOCKS
{
	BlockOption = 100,														//操作区域的长度（目前已与绘图区域一致，考虑之后可能有修改暂时保留）
	BlockDrawStart = 400,													//绘图区域开始的X坐标
	BlockDraw = 100,														//绘图区域的长度
	BlockY = 100,															//各种区域的宽度
	BlockColor = 75,														//颜色选择区域的长度
	BlockColorStart = 800,													//颜色选择区域开始的X坐标
	BlockColorEnd = 1550													//颜色选择区域结束的X坐标（为了方便）
};
/*绘图模式相关枚举*/
enum DrawWays
{
	MOUSE = 0,																//鼠标操作
	CLEAR = 1,																//本次操作为清屏（仅清屏时保留）
	PIXEL = 2,																//铅笔	
	LINE = 3,																//画线
	CIRCLE = 4																//画圆
};
/*存储本次操作的坐标*/
typedef struct coordinate
{
	int x = -1;
	int y = -1;
}coordinate;
/*记录本次操作的全部具体信息*/
typedef struct Draw_Modes
{
	coordinate coor[20] = {};                       //记录坐标
	int Mode = Modes;								//记录绘图方式
	color_t Color = WHITE;							//记录颜色
	double Width = width;							//记录线条宽度
	coordinate* pixel_ = nullptr;					//仅限铅笔模式，保留这一次铅笔模式绘画的完整信息
}Draw_Modes;
extern Draw_Modes* RMake;													//完整绘图信息的保存
extern PIMAGE Read;															//指向以读取的图像的指针（暂时以图片形式执行）
/*以下是各种函数的声明*/
mouse_msg StartDraw(mouse_msg mouse);
void Undo();
void Redo(int Num = -1);
void Draw_Line(mouse_msg mouse);											//画线函数
void Draw_Pixel(mouse_msg mouse);											//铅笔模式
void Draw_Circle(mouse_msg mouse);											//画圆
void Draw_Undo_Init();														//初始化撤销模块（判断撤销后是否经过重做）
void Draw_Redo_Init(int Num, ...);											//初始化重做模块（记录本次绘图信息）
void ClearDevice();															//清屏模块（限定仅限绘图区域的清屏）
void SetColor(mouse_msg mouse);												//修改颜色模块
bool FunOpen();																//打开文件
void SaveFile();															//保存文件