#include "Teacher.h"
//�޲ι���
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}
//�˵�����
void Teacher::operMenu()
{
	cout << "------��ӭ��ʦ" << this->m_Name << "��¼ϵͳ����------" << endl;
	cout << "***********************************************************\n";
	cout << "===================     1���鿴����ԤԼ  ==================\n";
	cout << "===================     2�����ԤԼ      ==================\n";
	cout << "===================     0��ע����¼      ==================\n";
	cout << "***********************************************************\n";
	cout << "����������ѡ��" << endl;
}
//�鿴ԤԼ
void Teacher::checkAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"] << " ";
		cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
		cout << "������" << of.m_OrderData[i]["stuName"] << " ";
		cout << "�����ţ�" << of.m_OrderData[i]["roomId"] << " ";
		string status = "״̬: ";
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_OrderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ����";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}
//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int>v;
	int index = 0;
	//
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			string status = "״̬: ����У�";
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"] << " ";
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
			cout << "������" << of.m_OrderData[i]["stuName"] << " ";
			cout << "�����ţ�" << of.m_OrderData[i]["roomId"] << " ";
			cout << status << endl;
		
		}

	}
	//
	cout << "���������˵�ԤԼ��¼��" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�����˼�¼
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
			
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ�����
					//cout << of.m_OrderData[v[select - 1]]["stuName"] << endl;
					of.m_OrderData[v[select - 1]]["status"] = "2";
					//cout << of.m_OrderData[v[select - 1]]["status"] << endl;
				}
				else
				{
					//��ͨ�����
					of.m_OrderData[v[select - 1]]["status"] = "-1";
					//cout << of.m_OrderData[v[select - 1]]["status"] << endl;
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;

	}
	system("pause");
	system("cls");
}