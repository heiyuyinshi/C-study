#include"employee.h"

//���캯��
Employee::Employee(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = Did;
}
//��ʾְԱ��Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;;
}
//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}