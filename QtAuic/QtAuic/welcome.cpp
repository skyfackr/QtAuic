/*本文件用来输出欢迎界面*/
#include"pch.h"
#include"welcome.h"
#include"resource.h"
#include<Windows.h>
#include"yuandata.h"
#include"debugcontroller.h"
using namespace std;
using namespace qtauic;
#define welcomefile IDR_TXT4
void qtauic::welcome()
{
	const LPCTSTR filename = MAKEINTRESOURCE(welcomefile);
	HRSRC fp = FindResource(NULL, filename, TEXT("TXT"));
	if (fp == NULL) return;
	DWORD fsize = SizeofResource(NULL, fp);
	if (fsize == 0) return;
	HGLOBAL fmem = LoadResource(NULL, fp);
	if (fmem == NULL) return;
	LPVOID fmemp = LockResource(fmem);
	if (fmemp == NULL) return;
	cout.write((char*)fmem, fsize);
	cout << endl << "your versions:" << (string)yuan_versions+"_"+(string)yuan_releasemode << endl;
	FreeResource(fmem);
	debugshow();
	return;
}