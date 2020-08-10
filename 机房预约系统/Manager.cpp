#include "Manager.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Password = pwd;
	//��ʼ������ ��ȡ��ʦ��ѧ������Ϣ
	this->initVec();
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom cRoom;
	while (ifs >> cRoom.m_RoomId && ifs >> cRoom.m_MaxNum)
	{
		this->vcomR.push_back(cRoom);
	}
	ifs.close();
	cout << "����������" << vcomR.size() << endl;
}
//�˵�����
void Manager::operMenu()
{
	cout << "------��ӭ����Ա" << this->m_Name << "��¼ϵͳ����------" << endl;
	cout << "******************************************************\n";
	cout << "===================   1������˺�   ==================\n";
	cout << "===================   2���鿴�˺�   ==================\n";
	cout << "===================   3���鿴����   ==================\n";
	cout << "===================   4�����ԤԼ   ==================\n";
	cout << "===================   0��ע����¼   ==================\n";
	cout << "******************************************************\n";
	cout << "����������ѡ��" << endl;



}
//����˺�
void Manager::addAccount()
{
	cout << "����������˺����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string fileName; //�����ļ�����
	string tip; //��ʾID��
	string erroTip;//������Ϣ��ʾ
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		erroTip = "ѧ���ظ������������룡";
	}
	else
	{
		//�����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		erroTip = "ְ�����ظ������������룡";
	}
	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);
	int id;//ѧ�� ְ����
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
	cout << "������������" << endl;
	cin >> name;
	cout << "�������¼���룺" << endl;
	cin >> pwd;
	//���ļ����������
	ofs << "\n"<<id << " " << name << " " << pwd << " " << endl;
	cout << "��ϲ����˺ųɹ�����" << endl;
	system("pause");
	system("cls");
	ofs.close();
	//���ó�ʼ��
	this->initVec();//ʹ�������ܹ���ʱ������
}
//��ʼ������
void Manager::initVec()
{
	this->vStu.clear();
	this->vTea.clear();
	//��ȡ��Ϣ ѧ�� ��ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ���" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ����������" << vStu.size() << endl;
	ifs.close();
	
    //��ȡ��ʦ����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ���" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ��������" << vTea.size() << endl;
	ifs.close();
}
//���ID�ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (it->m_Id == id)
				return true;
		}
	}
	else
	{
		//���ѧ��
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (it->m_EmpId == id)
				return true;
		}
	}
	return false;
}
//��ӡѧ��
void printStu(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << endl;
}
//��ӡ��ʦ
void printTea(Teacher& t)
{
	cout << "ְ����ţ�" << t.m_EmpId << "\t������" << t.m_Name << endl;
}
//�鿴�˺�
void Manager::checkAccount()
{
	cout << "������鿴�������ͣ�" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ��" << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStu);
	}
	else if (select == 2)
	{
		cout << "������ʦ��Ϣ��" << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTea);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::checkCmInfo()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<computerRoom>::iterator it = this->vcomR.begin(); it != vcomR.end(); it++)
	{
		cout << "������ţ�" << it->m_RoomId << "\t\t�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::clearOrdRecord()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��¼�����ϣ���" << endl;
	system("pause");
	system("cls");
}