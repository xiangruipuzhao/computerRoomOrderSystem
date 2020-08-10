#pragma once
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>;
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include "computerRoom.h"
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//����˺�
	void addAccount();
	//�鿴�˺�
	void checkAccount();
	//�鿴������Ϣ
	void checkCmInfo();
	//���ԤԼ��¼
	void clearOrdRecord();
	//��ʼ������
	void initVec();
	//���ID�ظ�
	bool checkRepeat(int id,int type);
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��������
	vector<computerRoom> vcomR;


};