/**
 * 最简单的基于libVLC的播放器-图形界面版
 * Simplest libVLC Player GUI
 *
 * 雷霄骅 Lei Xiaohua
 * leixiaohua1020@126.com
 * 中国传媒大学/数字电视技术
 * Communication University of China / Digital TV Technology
 * http://blog.csdn.net/leixiaohua1020
 *
 * 本程序是一个最简单的基于libVLC的图形界面播放器。
 * 适合初学者学习libVLC。
 *
 * This example is the simplest Player based on libVLC.
 * Suitable for the beginner of libVLC.
 */

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CplayerGUIApp:
// 有关此类的实现，请参阅 playerGUI.cpp
//

class CplayerGUIApp : public CWinApp
{
public:
	CplayerGUIApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CplayerGUIApp theApp;