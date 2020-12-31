#pragma once
#ifndef HUNGARIAN_H
#define HUNGARIAN_H
#include "AdjMatrix.h"
class Hungarian :public AdjMatrix{
public:
	Hungarian(AdjMatrix Adj):AdjMatrix(Adj){}
	bool find(int i);
	int getMaxLength();
public:
    bool search_P();//Ѱ��δƥ��ĵ�
    bool match_(int u);//ƥ��DFS
    int MaxMatch();//HK�㷨��������ƥ����
    void print_adj();//�������ʾ�ṹ��
private:
    int Mx[MAX],My[MAX];
    int dx[MAX],dy[MAX],dis;
private:
	int MaxLength;
	bool IsUsed[MAX];
};
#endif