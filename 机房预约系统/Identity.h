#pragma once
#include <iostream>
#include <string>
using namespace std;
class Identity
{
public:
	virtual void operMenu() = 0;
	//用户名
	string m_Name;
	//用户密码
	string m_Password;
};
