#include"boss.h"

//���캯��
Boss::Boss(int id, string name, int Did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = Did;
}
//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾����" << endl;;
}
//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}