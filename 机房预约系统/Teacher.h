#pragma once
#include "Identity.h"
#include "orderFile.h"
#include <vector>
class Teacher :public Identity
{
public:
	//�޲ι���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴ԤԼ
	void checkAllOrder();
	//���ԤԼ
	void validOrder();
	//ְ����
	int m_EmpId;

};
