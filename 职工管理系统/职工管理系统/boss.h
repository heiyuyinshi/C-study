#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//�ϰ���
class Boss :public Worker
{
public:
	//���캯��
	Boss(int id, string name, int Did);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();
};