/*本文件为debug定义中心*/
#include"pch.h"
#include"debugcontroller.h"
#define debugdata cout << "DEGUGDATA:" + (string)__FUNCTION__ + " on." << endl; return;
#ifdef startdebugmode
using namespace std;

void debugshow()
{
	using namespace std;
	cout << "WARNING:Debug mode is on!" << endl;
	return;
}

void file_uic_start_show()
{
	debugdata
}
void file_finder_show()
{
	debugdata
}
void road_analyser_show() {debugdata};
void file_list_analyser_show() {debugdata};
void uicer_commandshow(string command)
{
	cout << "command:" + command << endl;
	return;
}
#else

using namespace std;
void debugshow() {};
void file_uic_start_show() {};
void file_finder_show() {};
void road_analyser_show() {};
void file_list_analyser_show() {};
void uicer_commandshow(string command) {};

#endif