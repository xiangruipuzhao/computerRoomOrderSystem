#pragma once
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include <vector>
#include <fstream>
#include "orderFile.h"
using namespace std;
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void checkOwnOrder();
	//�鿴����ԤԼ
	void checkAllOrder();
	//ȡ������ԤԼ
	void cancleOwnOrder();
	//��������
	vector<computerRoom> vcomR;
	int m_Id;//ѧ��ѧ��


};
