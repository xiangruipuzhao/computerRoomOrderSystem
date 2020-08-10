#pragma once
#include "Identity.h"
#include "orderFile.h"
#include <vector>
class Teacher :public Identity
{
public:
	//无参构造函数
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//查看预约
	void checkAllOrder();
	//审核预约
	void validOrder();
	//职工号
	int m_EmpId;

};
