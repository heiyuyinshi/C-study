#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//��ͨԱ����
class Employee :public Worker
{
public:
	Employee(int id,string name,int Did);
	void showInfo();
	string getDeptName();
};
