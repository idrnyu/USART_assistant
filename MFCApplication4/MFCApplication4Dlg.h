
// MFCApplication4Dlg.h : ͷ�ļ�
//

#pragma once
#include "CMSComm.h"
#include "afxwin.h"


// CMFCApplication4Dlg �Ի���
class CMFCApplication4Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication4Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	void InitCombox();//�����б���ʼ��
	void TimeInit(); //ʱ���ʼ��
public:
	CEdit m_Edit;
	int icocc;
	afx_msg void OnBnClickedButtonSend();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void GetComm();
	// ���ڶ�ʱ��ʹ��
	CComboBox m_cbExample;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	// ���ڸ�ѡ�ؼ�  ѡ��  ������ǰ����ʾ  ��������ϵͳ
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
	// �绰���������
	CString m_nUmber;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
//	BOOL PreTranslateMessage(MSG* pMsg);  //��ȫ����ESC����ENTER�س���
};
