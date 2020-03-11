#include "workerManager.h"


WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڣ���������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ䣬�����ļ����ݴ浽������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}
//չʾ�˵�
void WorkerManager::showMenu()
{
	cout << "*******************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� *********" << endl;
	cout << "*************  1.����ְ����Ϣ  ************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  ************" << endl;
	cout << "*************  3.ɾ����ְԱ��  ************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  ************" << endl;
	cout << "*************  5.����ְ����Ϣ  ************" << endl;
	cout << "*************  6.���ձ������  ************" << endl;
	cout << "*************  7.��������ĵ�  ************" << endl;
	cout << "*************  0.�˳�ְ��ϵͳ  ************" << endl;
	cout << "*******************************************" << endl;
	cout << endl;
}
//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	exit(0);
}
//���Ա��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���Ա��
		//���¼����¿ռ��С
		//�¿ռ����� = ԭ�ռ����� + ��������
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ�ռ����ݿ������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "�������ְ����λ��" << endl;
			cout << "1������ְͨ��" << endl;
			cout << "2��������" << endl;
			cout << "3�����ϰ�" << endl;
			cin >> dSelect;

			//��������ָ��
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
			//��ְ��ָ�뱣�浽����
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_EmpNum = newSize;
		//����ְ����־
		this->m_FileIsEmpty = false;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}
//��������
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
//��ȡ��¼������
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
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}
//��ʾְ��
void WorkerManager::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//�鿴ְ���Ƿ����
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
//ɾ��ְ��
void WorkerManager::del_Emp()
{
	//���ж��ļ��Ƿ����
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "��������Ҫɾ����ְ����" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index == -1)
		{
			cout << "��ְ��������" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//ͬ������
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
//�޸�ְ��
void WorkerManager::modify_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "�������޸�ְ���ı��" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index == -1)
		{
			cout << "��Ա��������" << endl;
		}
		else
		{
			//�ͷ�ԭ�пռ�
			delete this->m_EmpArray[index];

			int newId = 10;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;
			cout << "�������¸�λ��" << endl;
			cout << "1������ְͨ��" << endl
				<< "2��������" << endl
				<< "3�����ϰ�" << endl;
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
			//�������ݵ�������
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ�" << endl;
			//��������
			this->save();
		}
	}
	system("pause");
	system("cls");
}
//����Ա�������ݱ�š��������ң�
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl
			<< "1��������ְ���Ų���" << endl
			<< "2������ְ����������" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int index = this->isExist(id);
			if (index != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			//����������
			string findName;
			bool flag = false;
			cout << "��������ҵ�����" << endl;
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
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ�����󣡣���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����Ա��
void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl
			<< "1������ְ��������" << endl
			<< "2������ְ���Ž���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;//������Сֵ�����ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			//�����ʼ�жϵ����ֵ����Сֵ�����ռ���Ĳ�ͬ������λ��
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ���������Ϊ��" << endl;
		this->save();
		this->show_Emp();
	}
}
//����ļ�
void WorkerManager::clean_File()
{
	cout << "ȷ����գ�" << endl
		<< "1����ȷ��" << endl
		<< "2��������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);//truncɾ���ļ��������´���
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
		cout << "���������" << endl;
	}
	system("pause");
	system("cls");
}
//��ʼ��ְ��
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
		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if(dId == 3)//�ϰ�
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
	//�ͷŶ�������
	if (this->m_EmpArray != NULL)
	{
		//�ͷ�ÿ����������
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		//���ͳһ�������
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}