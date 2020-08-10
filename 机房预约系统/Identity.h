#pragma once
#include <iostream>
#include <string>
using namespace std;
class Identity
{
public:
        //定义纯虚函数
	virtual void operMenu() = 0;
	//ÓÃ»§Ãû
	string m_Name;
	//ÓÃ»§ÃÜÂë
	string m_Password;
};
