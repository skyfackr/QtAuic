/*本文件设定处理部分*/
#include"pch.h"
#include"fileuiced.h"
#include"settings.h"
#include<direct.h>
#include<regex>
#include<fstream>
#include<io.h>
#include<Windows.h>
#include<tchar.h>
#include"yuandata.h"
using namespace std;
using namespace qtauic;
vector<string> file_finder(string paths, string aftername)//文件查找，若[0]返回-1则为失败
{
	vector<string> ansfile;
	ansfile.clear();
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(paths).append("\\*" + aftername).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				
			}
			else
			{
				ansfile.push_back(p.assign(paths).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		if (ansfile.size() == 0) ansfile[0] = "-1";
		_findclose(hFile);
		return ansfile;
	}
}
bool road_analyser(AUIC_Settings &settings)//路径分析，若返回错则代表非法路径
{
	string roadname = settings.road;
	if (roadname.find(":") != string::npos)
	{
		if (roadname.find_first_of(":") != roadname.find_last_of(":")) return false;
		return true;
	}
	TCHAR szFilePath[MAX_PATH + 1] = { 0 };
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0; // 删除文件名，只获得路径字串
	string str_url = (char*)szFilePath;  // 例如str_url==e:\program\Debug
	settings.road = str_url + roadname;
	return true;
}
vector<string> file_list_analyser(vector<string> files, AUIC_Settings settings)//黑白名单解析器，若[0]返回-1则表示模式异常
{
	vector<string> ansfile;
	ansfile.clear();
	if (settings.listmode == "white")
	{
		for (unsigned int i = 0; i <= files.size() - 1; i++)
		{
			if (settings.listdata.count(files[i]) == (size_t)1) ansfile.push_back(files[i]);
		}
	}
	else if (settings.listmode=="black")
	{
		for (unsigned int i = 0; i <= files.size() - 1; i++)
		{
			if (settings.listdata.count(files[i]) == (size_t)0) ansfile.push_back(files[i]);
		}
	}
	else
	{
		ansfile[0] = "-1";
	}
	return ansfile;
}
void uicer(string filename)//uic执行者
{
	string headername="ui_"+filename;
	headername.erase(headername.find_first_of('.'), 3);
	headername += ".h";
	string command = "uic " + filename + " >" + headername;
	cout << "uicing " + filename << endl;
	system((char*)command.c_str());
	cout << filename + " uiced!" << endl;
	return;
}
std::string qtauic::file_start_uic(AUIC_Settings settings)
{
	if (!road_analyser(settings)) return "invaild_roadname";
	vector<string> files;
	files = file_finder(settings.road, yuan_aftername);
	if (files[0] == "-1") return "file_not_found";
	files = file_list_analyser(files, settings);
	if (files[0] == "-1") return "invaild_listmode";
	for (unsigned int i = 0; i <= files.size() - 1; i++)
	{
		uicer(files[i]);
	}
	return "ok";
}