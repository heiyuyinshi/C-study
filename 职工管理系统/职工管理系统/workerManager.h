#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;//ʹ�ñ�׼�����ռ�

#define FILENAME "empFile.txt"

//ְ��������
class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//���ְ��
	void Add_Emp();
	//�����ļ�����
	void save();
	//��ȡ�ļ���¼����
	int get_EmpNum();
	//��������
	~WorkerManager();
	//��¼ϵͳ������
	int m_EmpNum;
	//��ʼ��Ա������
	void init_Emp();
	//��ʾְ��
	void show_Emp();
	//�ж�ְ���Ƿ����
	int isExist(int id);
	//ɾ��ְ��
	void del_Emp();
	//�޸�ְ��
	void modify_Emp();
	//����Ա��
	void find_Emp();
	//����Ա��
	void sort_Emp();
	//�������
	void clean_File();
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ļ��Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;
};
