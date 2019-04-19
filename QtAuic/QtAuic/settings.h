#pragma once
#ifndef SKYFACKR_QTAUIC_SETTINGS_H_
/*本文件声明设置文件检测、设置修改相关api*/
#define SKYFACKR_QTAUIC_SETTINGS_H_
#include"yuandata.h"
#include"pch.h"
#include<set>
#include"settings.h"

namespace qtauic
{
	struct AUIC_Settings//设置数据存储结构
	{
		typedef std::string string;
		//typedef std::set set;

		//路径
		string road = yuan_settings_road;

		//黑白名单模式
		string listmode = yuan_settings_listmode;

		//名单数据
		std::set<string> listdata;
	};
	
	class AUIC_Settings_Getter//外部设置分析
	{
	public:
		//查找外部设置文件是否存在
		bool hasFile();

		//分析文件并输出是否合法，若合法自动分析设置内容
		bool analyse();

		//输出设置信息
		AUIC_Settings get();

		AUIC_Settings_Getter() {};
		~AUIC_Settings_Getter() {};
	};
}

#endif // !SKYFACKR_QTAUIC_SETTINGS_H_
