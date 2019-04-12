/*本文件定义设置文件相关声明*/
#include"pch.h"
#include"settings.h"
#include"jsoncpp.h"
using namespace std;
using namespace Json;
using namespace qtauic;

class AUIC_Settings_Getter
{
	AUIC_Settings setting;//设置数据

	bool hasFile()
	{
		ifstream fout;
		fout.open(yuan_settings_filename, ios::in);
		if (fout) return true;
		return false;
	}

	bool analyse()
	{
		ifstream fin;
		string filedata;
		fin.open(yuan_settings_filename, ios::in);
		{
			ostringstream oss;
			while (!fin.eof())
			{
				string s;
				getline(fin, s);
				oss << s;
			}
			filedata = oss.str();
		}
		string jserr;
		Value jsdata;
		CharReaderBuilder jsrb;
		unique_ptr<CharReader> jsread(jsrb.newCharReader());
		if (!jsread->parse(filedata.c_str(), filedata.c_str() + filedata.length() - 1, &jsdata, &jserr))
			return false;
		if (!jsdata.isMember("road") || !jsdata["road"].isString() || !jsdata.isMember("listmode") || !jsdata["listmode"].isString() || !jsdata.isMember("list") || !jsdata["list"].isArray())
			return false;
		if (jsdata["listmode"].asString() != "black"&&jsdata["listmode"].asString() != "white")
			return false;
		setting.road = jsdata["road"].asString();
		setting.listmode = jsdata["listmode"].asString();
		for (unsigned int i = 0; i <= jsdata["list"].size() - 1; i++)
		{
			setting.listdata.insert(jsdata["list"][i].asString());
		}
		return true;
	}

	AUIC_Settings get()
	{
		return setting;
	}
};
