#include "Teacher.h"
//无参构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}
//菜单界面
void Teacher::operMenu()
{
	cout << "------欢迎老师" << this->m_Name << "登录系统！！------" << endl;
	cout << "***********************************************************\n";
	cout << "===================     1、查看所有预约  ==================\n";
	cout << "===================     2、审核预约      ==================\n";
	cout << "===================     0、注销登录      ==================\n";
	cout << "***********************************************************\n";
	cout << "请输入您的选择：" << endl;
}
//查看预约
void Teacher::checkAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
		cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_OrderData[i]["stuId"] << " ";
		cout << "姓名：" << of.m_OrderData[i]["stuName"] << " ";
		cout << "机房号：" << of.m_OrderData[i]["roomId"] << " ";
		string status = "状态: ";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消。";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}
//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	vector<int>v;
	int index = 0;
	//
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			string status = "状态: 审核中！";
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "学号：" << of.m_OrderData[i]["stuId"] << " ";
			cout << "姓名：" << of.m_OrderData[i]["stuName"] << " ";
			cout << "机房号：" << of.m_OrderData[i]["roomId"] << " ";
			cout << status << endl;
		
		}

	}
	//
	cout << "请输入待审核的预约记录！" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约结果审核记录
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{

			if (select == 0)
			{
				break;
			}
			else
			{
			
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过情况
					//cout << of.m_OrderData[v[select - 1]]["stuName"] << endl;
					of.m_OrderData[v[select - 1]]["status"] = "2";
					//cout << of.m_OrderData[v[select - 1]]["status"] << endl;
				}
				else
				{
					//不通过情况
					of.m_OrderData[v[select - 1]]["status"] = "-1";
					//cout << of.m_OrderData[v[select - 1]]["status"] << endl;
				}
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;

	}
	system("pause");
	system("cls");
}