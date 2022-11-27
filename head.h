#pragma once
#include<graphics.h>
#include<stdarg.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<tchar.h>
#include"resource.h"
#include<stdio.h>
/*���ֳ�����ö�ٵ��������ż��ṹ��Ķ���*/
#define FPS 360																//��ͼˢ���ʣ���δ֪ԭ�򣬵��ڴ����ڻ�ͼʱ�������Ե��ӳ٣�
#define MAX 1000															//�����ܴ洢����������Ĳ���
extern int Modes;															//��ǰ��ͼģʽ
extern int Save;															//��ǰ�洢��ͼ������
extern bool Undo_Or_Not;													//�Ƿ��ڳ����������»�ͼ
extern int width;															//��ǰ�߿�
/*���鳤��ö��*/
enum BLOCKS
{
	BlockOption = 100,														//��������ĳ��ȣ�Ŀǰ�����ͼ����һ�£�����֮��������޸���ʱ������
	BlockDrawStart = 400,													//��ͼ����ʼ��X����
	BlockDraw = 100,														//��ͼ����ĳ���
	BlockY = 100,															//��������Ŀ��
	BlockColor = 75,														//��ɫѡ������ĳ���
	BlockColorStart = 800,													//��ɫѡ������ʼ��X����
	BlockColorEnd = 1550													//��ɫѡ�����������X���꣨Ϊ�˷��㣩
};
/*��ͼģʽ���ö��*/
enum DrawWays
{
	MOUSE = 0,																//������
	CLEAR = 1,																//���β���Ϊ������������ʱ������
	PIXEL = 2,																//Ǧ��	
	LINE = 3,																//����
	CIRCLE = 4																//��Բ
};
/*�洢���β���������*/
typedef struct coordinate
{
	int x = -1;
	int y = -1;
}coordinate;
/*��¼���β�����ȫ��������Ϣ*/
typedef struct Draw_Modes
{
	coordinate coor[20] = {};                       //��¼����
	int Mode = Modes;								//��¼��ͼ��ʽ
	color_t Color;									//��¼��ɫ
	int Width = width;								//��¼�������
	coordinate* pixel_ = nullptr;					//����Ǧ��ģʽ��������һ��Ǧ��ģʽ�滭��������Ϣ
}Draw_Modes;
extern Draw_Modes* RMake;													//������ͼ��Ϣ�ı���
extern PIMAGE Read;															//ָ���Զ�ȡ��ͼ���ָ�루��ʱ��ͼƬ��ʽִ�У�
/*�����Ǹ��ֺ���������*/
mouse_msg StartDraw(mouse_msg mouse);
void Undo();
void Redo(int Num = -1);
void Draw_Line(mouse_msg mouse);											//���ߺ���
void Draw_Pixel(mouse_msg mouse);											//Ǧ��ģʽ
void Draw_Circle(mouse_msg mouse);											//��Բ
void Draw_Undo_Init();														//��ʼ������ģ�飨�жϳ������Ƿ񾭹�������
void Draw_Redo_Init(int Num, ...);											//��ʼ������ģ�飨��¼���λ�ͼ��Ϣ��
void ClearDevice();															//����ģ�飨�޶����޻�ͼ�����������
void SetColor(mouse_msg mouse);												//�޸���ɫģ��
bool FunOpen();																//���ļ�
void SaveFile();															//�����ļ�