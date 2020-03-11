#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//普通员工类
class Employee :public Worker
{
public:
	Employee(int id,string name,int Did);
	void showInfo();
	string getDeptName();
};
