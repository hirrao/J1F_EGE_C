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
bool opens();//���ļ�������غ���
bool options();//�˵�����
bool read();//��ȡ�ļ�����
void help();//������������˵�
void savefiles(PIMAGE);//�����ļ���غ���
void colors(mouse_msg);//ѡ��͸�����ɫ��غ���
mouse_msg draws(mouse_msg);//��ͼ��غ���
void pline(mouse_msg);//����
void pcircle(mouse_msg);//��Բ
extern PIMAGE anewimage;//TEST
extern mouse_msg anmouse;//
extern int anmous;//��������ʹ���ڻ�ͼ�����п��Է��ʲ˵�
extern int ways;//��ͼģʽ����
void revoke();
enum wayss//��ͼģʽö��
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
}drimage;//��ͼ��Ϣ����ṹ��
extern drimage nowimages[20];//��ͼ��Ϣ��������
drimage moutodri(mouse_msg msg, int mo = 1);//��mouse_msg�ṹ��ת��Ϊ�Զ���ṹ��
#endif 
