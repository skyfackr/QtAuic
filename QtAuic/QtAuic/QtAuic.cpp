// QtAuic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include"fileuiced.h"
#include"welcome.h"
#include"settings.h"
using namespace std;
using namespace qtauic;


int main()
{
	welcome();
	AUIC_Settings_Getter setget;
	AUIC_Settings settings;
	if (setget.hasFile())
	{
		cout << "Setting file found!" << endl;
		if (setget.analyse())
		{
			cout << "Load complete!" << endl;
			settings = setget.get();
			cout << "------data------" << endl;
			cout << settings.road << endl << settings.listmode << endl;
			for (set<string>::iterator i = settings.listdata.begin(); i != settings.listdata.end(); i++)
			{
				cout << *i << endl;
			}
			cout << "----------------" << endl;
		}
		else
		{
			cout << "Setting file have invaild_type.Loading normal settings....." << endl;
		}
	}
	else cout << "Setting file not found.Loading normal settings....." << endl;
	string errors= file_start_uic(settings);
	if (errors!= "ok")
	{
		cout << "Expection!QtAuic has been crashed because:" + errors << endl;
	}
	else cout << "QtAuic run completed!" << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
