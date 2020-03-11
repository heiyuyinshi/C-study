#include<iostream>
using namespace std;
#define MAX 1000 //����ͨѶ¼�������

//��ϵ�˽ṹ��
struct Person 
{
	string m_Name; //����
	int m_Sex; //�Ա�1 �У� 2 Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};
//ͨѶ¼�ṹ��
struct AddressBooks
{
	struct Person personArr[MAX]; //��¼ͨѶ¼�б������ϵ����Ϣ
	int m_size;//ͨѶ¼����Ա����
};
void showMenu();//��ʾ�˵�����
void addPerson(AddressBooks* abs);//�����ϵ��
void printAdd(AddressBooks* abs);//��ʾ��ϵ��
int isExist(AddressBooks* abs, string name);//�ж���ϵ���Ƿ����
void delPerson(AddressBooks* abs);//ɾ����ϵ��
void findPerson(AddressBooks* abs);//������ϵ��
void modifyPerson(AddressBooks* abs);//�޸�ָ����ϵ����Ϣ
void clearBook(AddressBooks* abs);//���ͨѶ¼

int main()
{
	//����ͨѶ¼�ṹ�����
	AddressBooks abs;
	abs.m_size = 0;

	char select = '1';//��¼�û�ѡ������ı���
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case '1'://�����ϵ��
			addPerson(&abs);
			break;
		case '2'://��ʾ��ϵ��
			printAdd(&abs);
			break;
		case '3'://ɾ����ϵ��
			delPerson(&abs);
			break;
		case '4'://������ϵ��
			findPerson(&abs);
			break;
		case '5'://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case '6'://�����ϵ��
			clearBook(&abs);
			break;
		case '0'://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
//��ʾ�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
	cout << "���������ѡ��" << endl;
}
//�����ϵ��
void addPerson(AddressBooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���
	if (abs->m_size == MAX) {
		cout << "ͨѶ¼�������޷���ӣ�����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArr[abs->m_size].m_Name = name;
		//�Ա�
		int sex = 0;
		do
		{
			cout << "�������Ա�" << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->m_size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�������󣡣���" << endl;
			}
		} while (true);
		//����
		int age = 0;
		do
		{
			cout << "����������" << endl;
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArr[abs->m_size].m_Age = age;
				break;
			}
			else
			{
				cout << "�������󣡣���" << endl;
			}
		} while (true);
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArr[abs->m_size].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_size].m_Addr = address;
		//��������
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//�����������
		system("cls");//����
	}
}
//��ʾ������ϵ��
void printAdd(AddressBooks* abs)
{
	//�ж������Ƿ�Ϊ0��Ϊ0����ʾ
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����\t�Ա�\t����\t�绰\tסַ" << endl;
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << abs->personArr[i].m_Name << "\t"
				<< (abs->personArr[i].m_Sex == 1?"��":"Ů") << "\t"
				<< abs->personArr[i].m_Age << "\t"
				<< abs->personArr[i].m_Phone << "\t"
				<< abs->personArr[i].m_Addr << "\t"
				<< endl;
		}
		cout << "��������" << abs->m_size << endl;
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ����
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArr[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;//û���ҵ�����-1
}
//ɾ����ϵ��
void delPerson(AddressBooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int response = isExist(abs, name);
	if (response == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		//ɾ���������������ǰ�ƣ���������-1
		for (int i = response; i < abs->m_size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		cout << "����:" << abs->personArr[res].m_Name << "\t"
			<< "�Ա�:" << (abs->personArr[res].m_Sex == 1 ? "��" : "Ů") << "\t"
			<< "����:" << abs->personArr[res].m_Age << "\t"
			<< "�绰:" << abs->personArr[res].m_Phone << "\t"
			<< "סַ:" << abs->personArr[res].m_Addr << "\t" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(AddressBooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res == -1)
	{
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArr[res].m_Name = name;
		//�Ա�
		int sex = 0;
		do
		{
			cout << "�������Ա�" << endl;
			cout << "1 --- ��" << endl;
			cout << "2 --- Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[res].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�������󣡣���" << endl;
			}
		} while (true);
		//����
		int age = 0;
		do
		{
			cout << "����������" << endl;
			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArr[res].m_Age = age;
				break;
			}
			else
			{
				cout << "�������󣡣���" << endl;
			}
		} while (true);
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArr[res].m_Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArr[res].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//���ͨѶ¼
void clearBook(AddressBooks* abs) 
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}