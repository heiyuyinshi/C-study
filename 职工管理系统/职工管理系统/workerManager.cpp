#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在，且有数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间，并将文件数据存到数组中
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}
//展示菜单
void WorkerManager::showMenu()
{
	cout << "*******************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ *********" << endl;
	cout << "*************  1.增加职工信息  ************" << endl;
	cout << "*************  2.显示职工信息  ************" << endl;
	cout << "*************  3.删除离职员工  ************" << endl;
	cout << "*************  4.修改职工信息  ************" << endl;
	cout << "*************  5.查找职工信息  ************" << endl;
	cout << "*************  6.按照编号排序  ************" << endl;
	cout << "*************  7.清空所有文档  ************" << endl;
	cout << "*************  0.退出职工系统  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}
//添加员工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加员工
		//重新计算新空间大小
		//新空间人数 = 原空间人数 + 新增人数
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原空间数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;//职工编号
			string name;//职工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请输入该职工岗位：" << endl;
			cout << "1——普通职工" << endl;
			cout << "2——经理" << endl;
			cout << "3——老板" << endl;
			cin >> dSelect;

			//创建父类指针
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将职工指针保存到数组
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更新新空间指向
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//更新职工标志
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}
//保存数据
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
//读取记录中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >>did)
	{
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}
//显示职工
void WorkerManager::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//查看职工是否存在
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			return index;
		}
	}
	return index;
}
//删除职工
void WorkerManager::del_Emp()
{
	//先判断文件是否存在
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入需要删除的职工号" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index == -1)
		{
			cout << "该职工不存在" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步更新
			this->save();
			cout << "删除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}
//修改职工
void WorkerManager::modify_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入修改职工的编号" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index == -1)
		{
			cout << "此员工不存在" << endl;
		}
		else
		{
			//释放原有空间
			delete this->m_EmpArray[index];

			int newId = 10;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新的职工号：" << endl;
			cin >> newId;
			cout << "请输入新姓名" << endl;
			cin >> newName;
			cout << "请输入新岗位：" << endl;
			cout << "1——普通职工" << endl
				<< "2——经理" << endl
				<< "3——老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			//保存数据
			this->save();
		}
	}
	system("pause");
	system("cls");
}
//查找员工（根据编号、姓名查找）
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl
			<< "1——按照职工号查找" << endl
			<< "2——按职工姓名查找" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int index = this->isExist(id);
			if (index != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下" << endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			//按照姓名查
			string findName;
			bool flag = false;
			cout << "请输入查找的姓名" << endl;
			cin >> findName;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == findName)
				{
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选择有误！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}
//排序员工
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl
			<< "1——按职工号升序" << endl
			<< "2——按职工号降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//声明最小值或最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//如果开始判断的最大值或最小值与最终计算的不同，交换位置
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功！排序结果为：" << endl;
		this->save();
		this->show_Emp();
	}
}
//清空文件
void WorkerManager::clean_File()
{
	cout << "确认清空？" << endl
		<< "1——确定" << endl
		<< "2——返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//trunc删除文件后再重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "数据已清空" << endl;
	}
	system("pause");
	system("cls");
}
//初始化职工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)//普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if(dId == 3)//老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
WorkerManager::~WorkerManager()
{
	//释放堆区数据
	if (this->m_EmpArray != NULL)
	{
		//释放每个堆区数据
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//最后统一清空数组
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}