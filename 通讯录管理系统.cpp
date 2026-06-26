<<<<<<< HEAD
#include"head.h"
#define MAX 1000

// 显示菜单功能
void showMenu()
{
	cout << "*********************" << endl;
	cout << "****1、添加联系人****" << endl;
	cout << "****2、显示联系人****" << endl;
	cout << "****3、删除联系人****" << endl;
	cout << "****4、查找联系人****" << endl;
	cout << "****5、修改联系人****" << endl;
	cout << "****6、清空联系人****" << endl;
	cout << "****0、退出通讯录****" << endl;
	cout << "*********************" << endl;
}
// 联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
// 通信录结构体
struct AddressBook
{
	struct Person pArr[MAX];
	int m_Size;
};

// 添加联系人功能
void addPerson(struct AddressBook * Ads)
{
	if (Ads->m_Size == MAX)
	{
		cout << "通讯录人数已满1000人，无法添加新的联系人。" << endl;
		return;
	}
	else
	{
		// 姓名
		cout << "请输入新建联系人 姓名：\n";
		cin >> Ads->pArr[Ads->m_Size].m_Name;

		// 性别
		cout << "请输入新建联系人 性别：\n1--男\n2--女\n";
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Ads->pArr[Ads->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入。" << endl;
			}
		}

		// 年龄
		cout << "请输入新建联系人 年龄：\n";
		int age = 0;
		cin >> age;
		Ads->pArr[Ads->m_Size].m_Age = age;

		// 电话号码
		cout << "请输入新建联系人 电话号码：\n";
		string phone;
		cin >> phone;
		Ads->pArr[Ads->m_Size].m_Phone = phone;

		// 居住地址
		cout << "请输入新建联系人 居住地址：\n";
		string address;
		cin >> address;
		Ads->pArr[Ads->m_Size].m_Addr = address;

		// 确认信息
		cout << "创建联系人成功，请确认新建联系人的信息：\n\n";
		cout << Ads->pArr[Ads->m_Size].m_Name << "\t";
		cout << (Ads->pArr[Ads->m_Size].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Age << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Phone << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Addr << endl;

		Ads->m_Size++;
		system("pause");
		system("cls");
	}
}
// 显示联系人功能
void showPerson(struct AddressBook* Ads)
{
	if (Ads->m_Size == 0)
	{
		cout << "您还没有添加联系人。" << endl;
	}
	else
	{
		for (int i = 0;i < Ads->m_Size;i++)
		{
			cout << i + 1 << "、\t ";
			cout << Ads->pArr[i].m_Name << "\t";
			cout << (Ads->pArr[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << Ads->pArr[i].m_Age << "\t";
			cout << Ads->pArr[i].m_Phone << "\t";
			cout << Ads->pArr[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
// 检测联系人是否存在
int isExist(struct AddressBook* Ads, string name)
{
	for (int i = 0;i < Ads->m_Size;i++)
	{
		if (Ads->pArr[i].m_Name == name)
		{
			return i;
		}
	}return -1;
}
// 删除联系人
void delatePerson(AddressBook* Ads)
{
	string name;
	cout << "请输入删除联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(Ads, name);
	if (ret != -1)
	{
		for (int i = ret;i < Ads->m_Size;i++)
		{
			//数据前移
			Ads->pArr[i] = Ads->pArr[i + 1];
		}Ads->m_Size--;
		cout << "删除成功。" << endl;
	}
	else
	{
		cout << "查无此人" << endl;	
	}
	system("pause");
	system("cls");
}
// 查找联系人
void findPerson(AddressBook* Ads)
{
	cout << "请输入您要查找的联系人名称：\n\n";
	string name;
	cin >> name;

	int ret = isExist(Ads, name);
	if (ret != -1)
	{	
		cout << "已找到联系人：\n";
		cout << Ads->pArr[ret].m_Name << "\t";
		cout << (Ads->pArr[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[ret].m_Age << "\t";
		cout << Ads->pArr[ret].m_Phone << "\t";
		cout << Ads->pArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
// 修改联系人
void modifyPerson(AddressBook* Ads)
{
	cout << "请输入您要修改的联系人：\n\n";
	// 定义变量
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	cin >> name;

	int ret = isExist(Ads, name);
	if (ret != -1)
	{
		// 显示联系人信息
		cout << "当前联系人信息：\n\n";
		cout << Ads->pArr[ret].m_Name << "\t";
		cout << (Ads->pArr[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[ret].m_Age << "\t";
		cout << Ads->pArr[ret].m_Phone << "\t";
		cout << Ads->pArr[ret].m_Addr << endl;
		// 进行个别信息修改
		cout << "请输入您要修改的部分：\n\n1--姓名\n2--性别\n3--年龄\n4--电话号码\n5--居住地址\n\n";
		int select;
		cin >> select;
		switch(select)
		{
		case 1:// 姓名
			cout << "请输入修改后的信息：" << endl;
			cin >> name;
			Ads->pArr[ret].m_Name = name;
			break;
		case 2:// 性别
			cout << "请输入修改后的信息：" << endl;
			cin >> sex;
			while (1)
			{
				if (sex == 1 || sex == 2)
				{
					Ads->pArr[ret].m_Sex = sex;
					break;
				}
				else
				{
					cout << "请正确输入性别。" << endl;
				}
			}break;
		case 3:// 年龄
			cout << "请输入修改后的信息：" << endl;
			cin >> age;
			Ads->pArr[ret].m_Age = age;
			break;
		case 4:// 电话号码
			cout << "请输入修改后的信息：" << endl;
			cin >> phone;
			Ads->pArr[ret].m_Phone = phone;
			break;
		case 5:// 居住地址
			cout << "请输入修改后的信息：" << endl;
			cin >> addr;
			Ads->pArr[ret].m_Addr = addr;
			break;
		}
		cout << "修改成功。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人。" << endl;
	}
}
// 清空通讯录
void cleanPerson(AddressBook* Ads)
{
	Ads->m_Size = 0;
	cout << "清空成功。" << endl;
	system("pause");
	system("cls");
}
int main()
{
	AddressBook Ads;

	Ads.m_Size = 0;
	int select = 0;

	// 按键功能
	while (1)
	{
		showMenu();// 调用菜单
		cout << endl << "等待数字输入中...\n" << endl;
		cin >> select;
		
		switch (select)
		{
		case 1:// 1、添加联系人
			addPerson(&Ads);
			break;
		case 2:// 2、显示联系人
			showPerson(&Ads);
			break;
		case 3:// 3、删除联系人
			delatePerson(&Ads);
			break;
		case 4:// 4、查找联系人
			findPerson(&Ads);
			break;
		case 5:// 5、修改联系人
			modifyPerson(&Ads);
			break;
		case 6:// 6、清空联系人
			cleanPerson(&Ads);
			break;
		case 0:// 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
=======
#include"head.h"
#define MAX 1000

// 显示菜单功能
void showMenu()
{
	cout << "*********************" << endl;
	cout << "****1、添加联系人****" << endl;
	cout << "****2、显示联系人****" << endl;
	cout << "****3、删除联系人****" << endl;
	cout << "****4、查找联系人****" << endl;
	cout << "****5、修改联系人****" << endl;
	cout << "****6、清空联系人****" << endl;
	cout << "****0、退出通讯录****" << endl;
	cout << "*********************" << endl;
}
// 联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
// 通信录结构体
struct AddressBook
{
	struct Person pArr[MAX];
	int m_Size;
};

// 添加联系人功能
void addPerson(struct AddressBook * Ads)
{
	if (Ads->m_Size == MAX)
	{
		cout << "通讯录人数已满1000人，无法添加新的联系人。" << endl;
		return;
	}
	else
	{
		// 姓名
		cout << "请输入新建联系人 姓名：\n";
		cin >> Ads->pArr[Ads->m_Size].m_Name;

		// 性别
		cout << "请输入新建联系人 性别：\n1--男\n2--女\n";
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Ads->pArr[Ads->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入。" << endl;
			}
		}

		// 年龄
		cout << "请输入新建联系人 年龄：\n";
		int age = 0;
		cin >> age;
		Ads->pArr[Ads->m_Size].m_Age = age;

		// 电话号码
		cout << "请输入新建联系人 电话号码：\n";
		string phone;
		cin >> phone;
		Ads->pArr[Ads->m_Size].m_Phone = phone;

		// 居住地址
		cout << "请输入新建联系人 居住地址：\n";
		string address;
		cin >> address;
		Ads->pArr[Ads->m_Size].m_Addr = address;

		// 确认信息
		cout << "创建联系人成功，请确认新建联系人的信息：\n\n";
		cout << Ads->pArr[Ads->m_Size].m_Name << "\t";
		cout << (Ads->pArr[Ads->m_Size].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Age << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Phone << "\t";
		cout << Ads->pArr[Ads->m_Size].m_Addr << endl;

		Ads->m_Size++;
		system("pause");
		system("cls");
	}
}
// 显示联系人功能
void showPerson(struct AddressBook* Ads)
{
	if (Ads->m_Size == 0)
	{
		cout << "您还没有添加联系人。" << endl;
	}
	else
	{
		for (int i = 0;i < Ads->m_Size;i++)
		{
			cout << i + 1 << "、\t ";
			cout << Ads->pArr[i].m_Name << "\t";
			cout << (Ads->pArr[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << Ads->pArr[i].m_Age << "\t";
			cout << Ads->pArr[i].m_Phone << "\t";
			cout << Ads->pArr[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
// 检测联系人是否存在
int isExist(struct AddressBook* Ads, string name)
{
	for (int i = 0;i < Ads->m_Size;i++)
	{
		if (Ads->pArr[i].m_Name == name)
		{
			return i;
		}
	}return -1;
}
// 删除联系人
void delatePerson(AddressBook* Ads)
{
	string name;
	cout << "请输入删除联系人姓名：" << endl;
	cin >> name;
	int ret = isExist(Ads, name);
	if (ret != -1)
	{
		for (int i = ret;i < Ads->m_Size;i++)
		{
			//数据前移
			Ads->pArr[i] = Ads->pArr[i + 1];
		}Ads->m_Size--;
		cout << "删除成功。" << endl;
	}
	else
	{
		cout << "查无此人" << endl;	
	}
	system("pause");
	system("cls");
}
// 查找联系人
void findPerson(AddressBook* Ads)
{
	cout << "请输入您要查找的联系人名称：\n\n";
	string name;
	cin >> name;

	int ret = isExist(Ads, name);
	if (ret != -1)
	{	
		cout << "已找到联系人：\n";
		cout << Ads->pArr[ret].m_Name << "\t";
		cout << (Ads->pArr[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[ret].m_Age << "\t";
		cout << Ads->pArr[ret].m_Phone << "\t";
		cout << Ads->pArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
// 修改联系人
void modifyPerson(AddressBook* Ads)
{
	cout << "请输入您要修改的联系人：\n\n";
	// 定义变量
	string name;
	int sex;
	int age;
	string phone;
	string addr;

	cin >> name;

	int ret = isExist(Ads, name);
	if (ret != -1)
	{
		// 显示联系人信息
		cout << "当前联系人信息：\n\n";
		cout << Ads->pArr[ret].m_Name << "\t";
		cout << (Ads->pArr[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << Ads->pArr[ret].m_Age << "\t";
		cout << Ads->pArr[ret].m_Phone << "\t";
		cout << Ads->pArr[ret].m_Addr << endl;
		// 进行个别信息修改
		cout << "请输入您要修改的部分：\n\n1--姓名\n2--性别\n3--年龄\n4--电话号码\n5--居住地址\n\n";
		int select;
		cin >> select;
		switch(select)
		{
		case 1:// 姓名
			cout << "请输入修改后的信息：" << endl;
			cin >> name;
			Ads->pArr[ret].m_Name = name;
			break;
		case 2:// 性别
			cout << "请输入修改后的信息：" << endl;
			cin >> sex;
			while (1)
			{
				if (sex == 1 || sex == 2)
				{
					Ads->pArr[ret].m_Sex = sex;
					break;
				}
				else
				{
					cout << "请正确输入性别。" << endl;
				}
			}break;
		case 3:// 年龄
			cout << "请输入修改后的信息：" << endl;
			cin >> age;
			Ads->pArr[ret].m_Age = age;
			break;
		case 4:// 电话号码
			cout << "请输入修改后的信息：" << endl;
			cin >> phone;
			Ads->pArr[ret].m_Phone = phone;
			break;
		case 5:// 居住地址
			cout << "请输入修改后的信息：" << endl;
			cin >> addr;
			Ads->pArr[ret].m_Addr = addr;
			break;
		}
		cout << "修改成功。" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人。" << endl;
	}
}
// 清空通讯录
void cleanPerson(AddressBook* Ads)
{
	Ads->m_Size = 0;
	cout << "清空成功。" << endl;
	system("pause");
	system("cls");
}
int main()
{
	AddressBook Ads;

	Ads.m_Size = 0;
	int select = 0;

	// 按键功能
	while (1)
	{
		showMenu();// 调用菜单
		cout << endl << "等待数字输入中...\n" << endl;
		cin >> select;
		
		switch (select)
		{
		case 1:// 1、添加联系人
			addPerson(&Ads);
			break;
		case 2:// 2、显示联系人
			showPerson(&Ads);
			break;
		case 3:// 3、删除联系人
			delatePerson(&Ads);
			break;
		case 4:// 4、查找联系人
			findPerson(&Ads);
			break;
		case 5:// 5、修改联系人
			modifyPerson(&Ads);
			break;
		case 6:// 6、清空联系人
			cleanPerson(&Ads);
			break;
		case 0:// 0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
>>>>>>> 1b402f6b14a005555aa6b1d3ffbb2da90f4c67d4
}