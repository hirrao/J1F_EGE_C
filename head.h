#pragma once
#ifndef EGE_LAB_H
#define EGE_LAB_H
#include<stdio.h>
#include<graphics.h>
#include<string.h>
#include<tchar.h>
void read();                      //实现读取操作的函数
void option();                    //实现功能选择操作的函数
void print();                     //实现画图选择功能的函数
void drawcircle();                //实现画圆相关功能的函数
void drawrec();                   //实现画矩形相关功能的函数
void choosecolor();               //实现颜色改变相关功能的函数       
void save();                      //实现图形存储相关功能的函数（未实现）
#endif