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
	//默认构造函数
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void checkOwnOrder();
	//查看所有预约
	void checkAllOrder();
	//取消自身预约
	void cancleOwnOrder();
	//房间容器
	vector<computerRoom> vcomR;
	int m_Id;//学生学号


};
