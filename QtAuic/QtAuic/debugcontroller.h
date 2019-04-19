//#pragma once
#ifndef SKYFACKR_QTAUIC_DEBUGCONTROLLER_H_
/*本文件定义debug控制中心*/
#define SKYFACKR_QTAUIC_DEBUGCONTROLLER_H_
#include"pch.h"

/*debug启动标识*/
//#define startdebugmode

void debugshow();
void file_uic_start_show();
void file_finder_show();
void road_analyser_show();
void file_list_analyser_show();
void uicer_commandshow(std::string command);

#endif // !SKYFACKR_QTAUIC_DEBUGCONTROLLER_H_
