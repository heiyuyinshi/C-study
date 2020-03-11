#pragma once//防止头文件重复包含
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;//使用标准命名空间

#define FILENAME "empFile.txt"

//职工管理类
class WorkerManager
{
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//添加职工
	void Add_Emp();
	//保存文件函数
	void save();
	//读取文件记录人数
	int get_EmpNum();
	//析构函数
	~WorkerManager();
	//记录系统中人数
	int m_EmpNum;
	//初始化员工数组
	void init_Emp();
	//显示职工
	void show_Emp();
	//判断职工是否存在
	int isExist(int id);
	//删除职工
	void del_Emp();
	//修改职工
	void modify_Emp();
	//查找员工
	void find_Emp();
	//排序员工
	void sort_Emp();
	//清空数据
	void clean_File();
	//职工数组指针
	Worker** m_EmpArray;
	//文件是否为空标志
	bool m_FileIsEmpty;
};
