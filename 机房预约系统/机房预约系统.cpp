#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;
//�������Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��ǿת��Ϊ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		cin >>select;
		if (select == 1)
		{
			//����˺�
			cout << "����˺�" << endl;
			man->addAccount();
		}
		else if (select == 2)
		{
			//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->checkAccount();
		}
		else if (select == 3)
		{
			//�鿴������Ϣ
			cout << "�鿴������Ϣ" << endl;
			man->checkCmInfo();
		}
		else if (select == 4)
		{
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->clearOrdRecord();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�����" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		student->operMenu();
		//������ָ��ǿת��Ϊ����ָ�룬���������������ӿ�
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//����ԤԼ
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//�鿴ԤԼ
			cout << "�鿴ԤԼ" << endl;
			stu->checkOwnOrder();
		}
		else if (select == 3)
		{
			//�鿴������ԤԼ
			cout << "�鿴������ԤԼ" << endl;
			stu->checkAllOrder();
		}
		else if (select == 4)
		{
			//ȡ��ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			stu->cancleOwnOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�����" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//������ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		teacher->operMenu();
		//������ָ��ǿת��Ϊ����ָ�룬���������������ӿ�
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//�鿴ԤԼ
			cout << "�鿴������ԤԼ" << endl;
			tea->checkAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�����" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}
//��¼���� ����һ:�����ļ��� �������������������
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;//����ָ�����ڲ����������
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}
	//׼�������û���Ϣ
	int id;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "����������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fID;//���ļ��ж�ȡ��ID
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID== id && fName == name & fPwd == pwd)
			{
				cout << "ѧ���ͻ��˵�¼�ɹ�����" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fID;//���ļ��ж�ȡ��ID
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name & fPwd == pwd)
			{
				cout << "��ʦ�ͻ��˵�¼�ɹ�����" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ����Ӳ˵�
				teacherMenu(person);
				return;
			}
		}

	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName;//���ļ��ж�ȡ������
		string fPwd;//���ļ��ж�ȡ������
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name & fPwd == pwd)
			{
				cout << "����Ա�ͻ��˵�¼�ɹ�����" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ���" << endl;
	system("pause");
	system("cls");
	return;

}
int main()
{
	int select = 0;//���ڽ����û���ѡ��
	while (true)
	{
		cout << "==================��ӭ��������ԤԼϵͳ����==================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t---------------------------------------\n";
		cout << "\t\t|             1��ѧ������             |\n";
		cout << "\t\t|             2����ʦ                 |\n";
		cout << "\t\t|             3������Ա               |\n";
		cout << "\t\t|             0���˳�ϵͳ             |\n";
		cout << "\t\t---------------------------------------\n";
		cout << "����������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1://ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����
			LoginIn(ADMIN_FILE,3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;

		}
	}
	

	system("pause");
	return 0;
}