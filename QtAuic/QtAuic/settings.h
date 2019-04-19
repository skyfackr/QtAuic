#pragma once
#ifndef SKYFACKR_QTAUIC_SETTINGS_H_
/*���ļ����������ļ���⡢�����޸����api*/
#define SKYFACKR_QTAUIC_SETTINGS_H_
#include"yuandata.h"
#include"pch.h"
#include<set>
#include"settings.h"

namespace qtauic
{
	struct AUIC_Settings//�������ݴ洢�ṹ
	{
		typedef std::string string;
		//typedef std::set set;

		//·��
		string road = yuan_settings_road;

		//�ڰ�����ģʽ
		string listmode = yuan_settings_listmode;

		//��������
		std::set<string> listdata;
	};
	
	class AUIC_Settings_Getter//�ⲿ���÷���
	{
	public:
		//�����ⲿ�����ļ��Ƿ����
		bool hasFile();

		//�����ļ�������Ƿ�Ϸ������Ϸ��Զ�������������
		bool analyse();

		//���������Ϣ
		AUIC_Settings get();

		AUIC_Settings_Getter() {};
		~AUIC_Settings_Getter() {};
	};
}

#endif // !SKYFACKR_QTAUIC_SETTINGS_H_
