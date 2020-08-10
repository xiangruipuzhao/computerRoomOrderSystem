#include "Student.h"
//默认构造
Student::Student()
{

}
//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Password = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom ComR;
	while (ifs >> ComR.m_RoomId && ifs >> ComR.m_MaxNum)
	{
		this->vcomR.push_back(ComR);
	}
	ifs.close();
}
//菜单界面
void Student::operMenu()
{
	cout << "------欢迎学生" << this->m_Name << "登录系统！！------" << endl;
	cout << "***********************************************************\n";
	cout << "===================     1、申请预约      ==================\n";
	cout << "===================     2、查看自己预约  ==================\n";
	cout << "===================     3、查看所有预约  ==================\n";
	cout << "===================     4、取消预约      ==================\n";
	cout << "===================     0、注销登录      ==================\n";
	cout << "***********************************************************\n";
	cout << "请输入您的选择：" << endl;
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时段为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;//	日期
	int interval = 0;//时间段
	int room = 0;//机房编号
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入日期有误，请重新输入" << endl;
	}
	cout << "请输入预约时段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 || interval <= 2)
		{
			break;
		}
		cout << "输入时段有误，请重新输入" << endl;
	}
	cout << "请选择机房：" << endl;
	for (int i = 0; i < this->vcomR.size(); i++)
	{
		cout << this->vcomR[i].m_RoomId << "号机房容量为：" << this->vcomR[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room<<" ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");

		
}
//查看自身预约
void Student::checkOwnOrder()
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
		//string -> int
		//string 利用.c_str()转const char*
		//利用atoi(const char*)转为int
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			cout << "预约日期：周" << of.m_OrderData[i]["date"]<<" ";
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午")<< " ";
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
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student::checkAllOrder()
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
//取消自身预约
void Student::cancleOwnOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消记录：" << endl;
	vector<int> v;//存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//判断自身学号
		if (this->m_Id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//在筛选状态 审核中或预约成功
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_OrderData[i]["date"] << " ";
				cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
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
				cout << status << endl;

			}
		}
	}
	cout << "请输入取消的记录，0代表返回！" << endl;
	int select = 0;
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
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已成功取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;

	}
	system("pause");
	system("cls");
}