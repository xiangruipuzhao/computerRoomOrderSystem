#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;
//进入管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针强转换为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >>select;
		if (select == 1)
		{
			//添加账号
			cout << "添加账号" << endl;
			man->addAccount();
		}
		else if (select == 2)
		{
			//查看账号
			cout << "查看账号" << endl;
			man->checkAccount();
		}
		else if (select == 3)
		{
			//查看机房信息
			cout << "查看机房信息" << endl;
			man->checkCmInfo();
		}
		else if (select == 4)
		{
			//清空预约
			cout << "清空预约" << endl;
			man->clearOrdRecord();
		}
		else
		{
			delete manager;
			cout << "注销成功！！" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//进入学生子菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		//调用管理员子菜单
		student->operMenu();
		//将父类指针强转换为子类指针，调用子类里其他接口
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//申请预约
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//查看预约
			cout << "查看预约" << endl;
			stu->checkOwnOrder();
		}
		else if (select == 3)
		{
			//查看所有人预约
			cout << "查看所有人预约" << endl;
			stu->checkAllOrder();
		}
		else if (select == 4)
		{
			//取消预约
			cout << "取消预约" << endl;
			stu->cancleOwnOrder();
		}
		else
		{
			delete student;
			cout << "注销成功！！" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//进入老师子菜单
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//调用管理员子菜单
		teacher->operMenu();
		//将父类指针强转换为子类指针，调用子类里其他接口
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看预约
			cout << "查看所有人预约" << endl;
			tea->checkAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功！！" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//登录功能 参数一:操作文件名 参数二：操作身份类型
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//父类指针用于操纵子类对象
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}
	//准备接受用户信息
	int id;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fID;//从文件中读取的ID
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID== id && fName == name & fPwd == pwd)
			{
				cout << "学生客户端登录成功！！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师身份验证
		int fID;//从文件中读取的ID
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name & fPwd == pwd)
			{
				cout << "教师客户端登录成功！！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师身份子菜单
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中读取的姓名
		string fPwd;//从文件中读取的密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name & fPwd == pwd)
			{
				cout << "管理员客户端登录成功！！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！！" << endl;
	system("pause");
	system("cls");
	return;

}
int main()
{
	int select = 0;//用于接收用户的选择
	while (true)
	{
		cout << "==================欢迎来到机房预约系统！！==================" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t---------------------------------------\n";
		cout << "\t\t|             1、学生代表             |\n";
		cout << "\t\t|             2、老师                 |\n";
		cout << "\t\t|             3、管理员               |\n";
		cout << "\t\t|             0、退出系统             |\n";
		cout << "\t\t---------------------------------------\n";
		cout << "请输入您的选择：" << endl;
		cin >> select;
		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理
			LoginIn(ADMIN_FILE,3);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
	

	system("pause");
	return 0;
}