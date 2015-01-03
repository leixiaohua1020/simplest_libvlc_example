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
#include <string>
#include "vlc/vlc.h"
#include "vlc/libvlc.h"

#define MAX_URL_LENGTH 500

enum PlayerState{
	STATE_PREPARE,
	STATE_PLAY,
	STATE_PAUSE
};

// CplayerGUIDlg 对话框
class CplayerGUIDlg : public CDialogEx
{
// 构造
public:
	CplayerGUIDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PLAYERGUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	libvlc_instance_t * libvlc_inst;
	libvlc_media_player_t *libvlc_mp;
	libvlc_media_t *libvlc_m;
	PlayerState playerstate;

	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedFilebrowse();
	CEdit m_curtime;
	CEdit m_duration;
	CSliderCtrl m_progress;
	CEdit m_url;
	void SystemClear();
	void SetBtn(PlayerState state);

	void UNICODE_to_UTF8(CStringW& unicodeString, std::string& str);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnDestroy();
	afx_msg void OnWebsite();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedInfo();
};
