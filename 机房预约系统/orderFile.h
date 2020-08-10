#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "globalFile.h"
using namespace std;
class OrderFile
{
public:
	//构造函数
	OrderFile();
	//更新预约记录
	void updateOrder();
	//内容条数
	int m_Size;
	//容器
	map<int, map<string, string>> m_OrderData;
};

