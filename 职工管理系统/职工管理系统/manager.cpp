#include"manager.h"

//���캯��
Manager::Manager(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = Did;
}
//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ�����񣬲��·�����" << endl;;
}
//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}