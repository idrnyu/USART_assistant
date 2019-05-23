
// MFCApplication4Dlg.h : 头文件
//

#pragma once
#include "CMSComm.h"
#include "afxwin.h"


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

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
	DECLARE_EVENTSINK_MAP()
	void OnComm();
	CMSComm m_cComm;
private:
	CString m_strRecvData;
	CString m_strSendData;

private:
	void InitCombox();//下拉列表框初始化
	void TimeInit(); //时间初始化
public:
	CEdit m_Edit;
	int icocc;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void GetComm();
	// 用于定时器使用
	CComboBox m_cbExample;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// 用于复选控件  选中  窗口最前端显示  否则随意系统
	BOOL m_bShowTopmost;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	BOOL m_ZH;
	char* datas;
	int ZH,RN;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	BOOL m_Rn;
	BOOL num1 = 0;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	// 电话号码输入框
	CString m_nUmber;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
//	BOOL PreTranslateMessage(MSG* pMsg);  //完全屏蔽ESC键与ENTER回车键
};
