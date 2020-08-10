#include "Manager.h"


//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Password = pwd;
	//初始化容器 获取老师和学生的信息
	this->initVec();
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom cRoom;
	while (ifs >> cRoom.m_RoomId && ifs >> cRoom.m_MaxNum)
	{
		this->vcomR.push_back(cRoom);
	}
	ifs.close();
	cout << "机房数量：" << vcomR.size() << endl;
}
//菜单界面
void Manager::operMenu()
{
	cout << "------欢迎管理员" << this->m_Name << "登录系统！！------" << endl;
	cout << "******************************************************\n";
	cout << "===================   1、添加账号   ==================\n";
	cout << "===================   2、查看账号   ==================\n";
	cout << "===================   3、查看机房   ==================\n";
	cout << "===================   4、清空预约   ==================\n";
	cout << "===================   0、注销登录   ==================\n";
	cout << "******************************************************\n";
	cout << "请输入您的选择：" << endl;



}
//添加账号
void Manager::addAccount()
{
	cout << "请输入添加账号类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	string fileName; //操作文件对象
	string tip; //提示ID号
	string erroTip;//错误信息提示
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		erroTip = "学号重复，请重新输入！";
	}
	else
	{
		//添加老师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		erroTip = "职工号重复，请重新输入！";
	}
	//利用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);
	int id;//学号 职工号
	string name;
	string pwd;
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << erroTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入登录密码：" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << "\n"<<id << " " << name << " " << pwd << " " << endl;
	cout << "恭喜添加账号成功！！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//调用初始化
	this->initVec();//使得容器能够及时被更新
}
//初始化容器
void Manager::initVec()
{
	this->vStu.clear();
	this->vTea.clear();
	//读取信息 学生 老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！！" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}
	cout << "当前学生的数量：" << vStu.size() << endl;
	ifs.close();
	
    //读取老师的信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！！" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}
	cout << "当前老师的数量：" << vTea.size() << endl;
	ifs.close();
}
//检测ID重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
				return true;
		}
	}
	else
	{
		//检测学生
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
				return true;
		}
	}
	return false;
}
//打印学生
void printStu(Student& s)
{
	cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << endl;
}
//打印老师
void printTea(Teacher& t)
{
	cout << "职工编号：" << t.m_EmpId << "\t姓名：" << t.m_Name << endl;
}
//查看账号
void Manager::checkAccount()
{
	cout << "请输入查看对象类型：" << endl;
	cout << "1、学生" << endl;
	cout << "2、老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息：" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStu);//函数对象打印用户
	}
	else if (select == 2)
	{
		cout << "所有老师信息：" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTea);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::checkCmInfo()
{
	cout << "机房信息如下：" << endl;
	for (vector<computerRoom>::iterator it = this->vcomR.begin(); it != vcomR.end(); it++)
	{
		cout << "机房编号：" << it->m_RoomId << "\t\t机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::clearOrdRecord()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "记录清空完毕！！" << endl;
	system("pause");
	system("cls");
}
