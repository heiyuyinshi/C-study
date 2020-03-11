#include<iostream>
using namespace std;
#define MAX 1000 //定义通讯录最大人数

//联系人结构体
struct Person 
{
	string m_Name; //姓名
	int m_Sex; //性别，1 男， 2 女
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};
//通讯录结构体
struct AddressBooks
{
	struct Person personArr[MAX]; //记录通讯录中保存的联系人信息
	int m_size;//通讯录中人员个数
};
void showMenu();//显示菜单界面
void addPerson(AddressBooks* abs);//添加联系人
void printAdd(AddressBooks* abs);//显示联系人
int isExist(AddressBooks* abs, string name);//判断联系人是否存在
void delPerson(AddressBooks* abs);//删除联系人
void findPerson(AddressBooks* abs);//查找联系人
void modifyPerson(AddressBooks* abs);//修改指定联系人信息
void clearBook(AddressBooks* abs);//清空通讯录

int main()
{
	//创建通讯录结构体变量
	AddressBooks abs;
	abs.m_size = 0;

	char select = '1';//记录用户选择输入的变量
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case '1'://添加联系人
			addPerson(&abs);
			break;
		case '2'://显示联系人
			printAdd(&abs);
			break;
		case '3'://删除联系人
			delPerson(&abs);
			break;
		case '4'://查找联系人
			findPerson(&abs);
			break;
		case '5'://修改联系人
			modifyPerson(&abs);
			break;
		case '6'://清空联系人
			clearBook(&abs);
			break;
		case '0'://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
//显示菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
	cout << "请输入你的选择" << endl;
}
//添加联系人
void addPerson(AddressBooks* abs)
{
	//判断通讯录是否满
	if (abs->m_size == MAX) {
		cout << "通讯录已满，无法添加！！！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArr[abs->m_size].m_Name = name;
		//性别
		int sex = 0;
		do
		{
			cout << "请输入性别" << endl;
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->m_size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误！！！" << endl;
			}
		} while (true);
		//年龄
		int age = 0;
		do
		{
			cout << "请输入年龄" << endl;
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArr[abs->m_size].m_Age = age;
				break;
			}
			else
			{
				cout << "输入有误！！！" << endl;
			}
		} while (true);
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArr[abs->m_size].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_size].m_Addr = address;
		//更新人数
		abs->m_size++;
		cout << "添加成功！" << endl;
		system("pause");//按任意键继续
		system("cls");//清屏
	}
}
//显示所有联系人
void printAdd(AddressBooks* abs)
{
	//判断人数是否为0，为0则提示
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		cout << "姓名\t性别\t年龄\t电话\t住址" << endl;
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << abs->personArr[i].m_Name << "\t"
				<< (abs->personArr[i].m_Sex == 1?"男":"女") << "\t"
				<< abs->personArr[i].m_Age << "\t"
				<< abs->personArr[i].m_Phone << "\t"
				<< abs->personArr[i].m_Addr << "\t"
				<< endl;
		}
		cout << "总人数：" << abs->m_size << endl;
	}
	system("pause");
	system("cls");
}
//判断联系人是否存在
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArr[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;//没有找到返回-1
}
//删除联系人
void delPerson(AddressBooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int response = isExist(abs, name);
	if (response == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//删除，将后面的数据前移，并将总数-1
		for (int i = response; i < abs->m_size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "未找到此联系人" << endl;
	}
	else
	{
		cout << "姓名:" << abs->personArr[res].m_Name << "\t"
			<< "性别:" << (abs->personArr[res].m_Sex == 1 ? "男" : "女") << "\t"
			<< "年龄:" << abs->personArr[res].m_Age << "\t"
			<< "电话:" << abs->personArr[res].m_Phone << "\t"
			<< "住址:" << abs->personArr[res].m_Addr << "\t" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(AddressBooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "未找到此联系人" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArr[res].m_Name = name;
		//性别
		int sex = 0;
		do
		{
			cout << "请输入性别" << endl;
			cout << "1 --- 男" << endl;
			cout << "2 --- 女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[res].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误！！！" << endl;
			}
		} while (true);
		//年龄
		int age = 0;
		do
		{
			cout << "请输入年龄" << endl;
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArr[res].m_Age = age;
				break;
			}
			else
			{
				cout << "输入有误！！！" << endl;
			}
		} while (true);
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArr[res].m_Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArr[res].m_Addr = address;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
//清空通讯录
void clearBook(AddressBooks* abs) 
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}