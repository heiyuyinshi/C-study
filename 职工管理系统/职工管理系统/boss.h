#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

//老板类
class Boss :public Worker
{
public:
	//构造函数
	Boss(int id, string name, int Did);
	//显示个人信息
	void showInfo();
	//获取岗位名称
	string getDeptName();
};