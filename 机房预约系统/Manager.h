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
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//添加账号
	void addAccount();
	//查看账号
	void checkAccount();
	//查看机房信息
	void checkCmInfo();
	//清空预约记录
	void clearOrdRecord();
	//初始化容器
	void initVec();
	//检测ID重复
	bool checkRepeat(int id,int type);
	//学生容器
	vector<Student> vStu;
	//老师容器
	vector<Teacher> vTea;
	//房间容器
	vector<computerRoom> vcomR;


};