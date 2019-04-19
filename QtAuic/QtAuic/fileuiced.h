#pragma once
#ifndef SKYFACKR_QTAUIC_FILEUICED_H_
/*本文件定义文件处理接口*/
#define SKYFACKR_QTAUIC_FILEUICED_H_
#include"pch.h"
#include"settings.h"

namespace qtauic
{
	//启动处理，ok为完毕，否则输出错误信息
	std::string file_start_uic(AUIC_Settings settings);
}

#endif // !SKYFACKR_QTAUIC_FILEUICED_H_
