#include<iostream>
#include<fstream>
#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main()
{
	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.showMenu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://增加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.modify_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			wm.sort_Emp();
			break;
		case 7://清空文档
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}