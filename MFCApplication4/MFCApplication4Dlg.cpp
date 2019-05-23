
// MFCApplication4Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 对话框



CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication4Dlg::IDD, pParent)
	, m_strRecvData(_T(""))
	, m_strSendData(_T(""))
	, m_bShowTopmost(FALSE)
	, m_ZH(FALSE)
	, m_Rn(FALSE)
	, m_nUmber(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM1, m_cComm);
	DDX_Text(pDX, IDC_EDIT_RECV, m_strRecvData);
	DDX_Text(pDX, IDC_EDIT_SEND, m_strSendData);
	DDX_Control(pDX, IDC_EDIT_RECV, m_Edit);
	DDX_Control(pDX, IDC_COMBO1, m_cbExample);
	DDX_Check(pDX, IDC_CHECK1, m_bShowTopmost);
	DDX_Check(pDX, IDC_CHECK2, m_ZH);
	DDX_Check(pDX, IDC_CHECK3, m_Rn);
	DDX_Text(pDX, IDC_EDIT1, m_nUmber);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CMFCApplication4Dlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_COMMAND(IDD_MFCAPPLICATION4_DIALOG, &CMFCApplication4Dlg::GetComm)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication4Dlg::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication4Dlg::OnBnClickedCheck2)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication4Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication4Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication4Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_CHECK3, &CMFCApplication4Dlg::OnBnClickedCheck3)
ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication4Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication4Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication4Dlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication4Dlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication4Dlg::OnBnClickedButton11)
ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication4Dlg::OnBnClickedButton12)
ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication4Dlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 消息处理程序

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	
	if (m_cComm.get_PortOpen()) //如果发现串口本来是打开的，则关闭串口
		m_cComm.put_PortOpen(FALSE);  
	GetComm();//自动收索可用串口列出下拉列表中

	SetTimer(1, 1000, NULL);//开启定时器  定时时间为1秒 
	//		SetTimer(2, 2000, NULL);//定时时间  为2秒

	SetDlgItemText(IDC_EDIT1, _T("15773010165")); //初始化电话号码窗口

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	InitCombox();//下拉列表框初始化
	TimeInit();  //时间初始化

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_EVENT(CMFCApplication4Dlg, IDC_MSCOMM1, 1, CMFCApplication4Dlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void CMFCApplication4Dlg::OnComm() //从串口接收数据并显示在编辑框中
{
	
	// TODO:  在此处添加消息处理程序代码
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	long len, k;
	BYTE rxdata[2048] = {0}; //设置BYTE数组
	CString strtemp;
	Sleep(50);//延时一下
	if (m_cComm.get_CommEvent() == 2) //值为2表示接收缓冲区内有字符
	{
		variant_inp = m_cComm.get_Input();//读缓冲区消息
		safearray_inp = variant_inp;//变量转换
		len = safearray_inp.GetOneDimSize(); //得到有效的数据长度
		for (k = 0; k<len; k++)
			safearray_inp.GetElement(&k, rxdata + k);
		for (k = 0; k < len; k++) //将数组转换为 CString 类型 
		{
			if (ZH)
			{
				BYTE bt = *(char*)(rxdata + k); //字符型

				strtemp.Format(_T("%c"), bt);

				m_strRecvData += strtemp;//加入接收编辑框对应字符串
			}
			else
			{
				if (k == 0)
				{
					datas = (char*)rxdata; //字符型
					m_strRecvData += datas;
				}
			}
		}
	}
//	CString temp = (_T("\r\n")); //显示完成后要自动换行
//	m_strRecvData += temp;
//	UpdateData(FALSE); //更新编辑框内容
//	m_Edit.SetSel(-1, -1);

	this->SetDlgItemTextW(IDC_EDIT_RECV, m_strRecvData);//将m_EditReceive内容显示到ID为IDC_EDIT1的编辑框的最后位置
	m_Edit.LineScroll(m_Edit.GetLineCount() - 1, 0);//将垂直滚动条滚动到最后一

	m_cComm.get_Input(); //预读缓冲区以清除残留数据


}

void CMFCApplication4Dlg::OnBnClickedButtonSend()  //发送按钮
{
	// TODO:  在此添加控件通知处理程序代码
	CString rN_mme;
	rN_mme.Format(_T("\r\n"));
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		if(RN)//自动换行
		{
			UpdateData(true); //读取编辑框内容
			m_cComm.put_Output(COleVariant(m_strSendData+rN_mme));//发送数据 
		}
		else
		{
			UpdateData(true); //读取编辑框内容
			m_cComm.put_Output(COleVariant(m_strSendData));//发送数据
		}
	}
	else
	{
	//	CString str;
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton2()   //打开串口按钮
{
	// TODO:  在此添加控件通知处理程序代码
	CString text;
	if (m_cComm.get_PortOpen())  //判断串口正处于打开
	{
		m_cComm.put_PortOpen(FALSE);  //关闭串口
		text.Format(_T("龚宇串口通讯_V4.8_C++之MFC编程学习_QQ：834999326  串口处于关闭状态"));
		this->SetDlgItemText(IDC_BUTTON2, _T("打开串口(Alt+&S)"));//按钮上的文字显示  打开串口
	}
	else  //打开串口
	{
		if (icocc)  //端口存在  
		{
			CString boote, com;//用来存放  波特率 校验位 数据位 停止位  信息

			CComboBox* pComboComm = (CComboBox*)GetDlgItem(IDC_COMBO1);//获取串口号控件
			ASSERT(pComboComm);
			int nSel = pComboComm->GetCurSel(); //获取串口下拉列表中当前选中的项
			CString strComm;
			pComboComm->GetLBText(nSel, strComm);
			com = strComm.Mid(3); //取出串口号   COM  后面的数字
			int icomm = _ttoi(com);  //将 CString 类型转换成 int 类型

			CComboBox* pComboBaudrate = (CComboBox*)GetDlgItem(IDC_COMBO2);//获取波特率控件
			ASSERT(pComboBaudrate);
			nSel = pComboBaudrate->GetCurSel();
			DWORD dwBaudrate = (DWORD)pComboBaudrate->GetItemData(nSel);

			CComboBox* pComboCheckbit = (CComboBox*)GetDlgItem(IDC_COMBO3);//校验位
			ASSERT(pComboCheckbit);
			nSel = pComboCheckbit->GetCurSel();
			BYTE byParity = (BYTE)pComboCheckbit->GetItemData(nSel);

			CComboBox* pComboDatabit = (CComboBox*)GetDlgItem(IDC_COMBO4);//数据位
			ASSERT(pComboDatabit);
			nSel = pComboDatabit->GetCurSel();
			BYTE byDatasize = (BYTE)pComboDatabit->GetItemData(nSel);

			CComboBox* pComboStopbit = (CComboBox*)GetDlgItem(IDC_COMBO5);//停止位
			ASSERT(pComboStopbit);
			nSel = pComboStopbit->GetCurSel();
			BYTE byStopbits = (BYTE)pComboStopbit->GetItemData(nSel);

			boote.Format(_T("%d,%c,%d,%d"), dwBaudrate, byParity, byDatasize, byStopbits);//包含有波特率，校验位，数据位，停止位

			m_cComm.put_CommPort(icomm);//选择COM端口

			m_cComm.put_InputMode(1); //输入方式为二进制方式
			m_cComm.put_InBufferSize(2048); //设置输入缓冲区
			m_cComm.put_OutBufferSize(2048); //设置输出缓冲区
			m_cComm.put_RThreshold(1);//接收缓冲区有1个及1个以上字符时，将引发接收数据的OnComm

			m_cComm.put_Settings(boote);//波特率，校验，数据位，停止位

			//	m_cComm.put_Settings(_T("115200,n,8,1"));//波特率115200，无校验，8位数据位，1位停止位   初始化设置

			m_cComm.put_PortOpen(TRUE);  //打开串口
			
			m_cComm.put_RThreshold(1);//每当接收缓冲区有1个字符则接收串口数据
			m_cComm.put_InputLen(0);//设置当前接收区数据长度为0,表示全部读取
			m_cComm.get_Input(); //预读缓冲区以清除残留数据

//			m_strRecvData.Empty();  //情况接收文本框里面的内容  这个可选
//			UpdateData(false);  //更新显示
//			m_strSendData.Empty(); //发送后清除输入框
//			UpdateData(false); //更新编辑框的内容

			this->SetDlgItemText(IDC_BUTTON2, _T("关闭串口(Alt+&S)"));	 //按钮上的文字显示 关闭串口	
			text.Format(_T("龚宇串口通讯_V4.8_C++之MFC编程学习_QQ：834999326  ( COM%d ) 以打开 ")+ boote,icomm);
		}
		else
		{
			SetDlgItemText(IDC_EDIT_SEND, _T("无可用端口号！"));
			text.Format(_T("龚宇串口通讯_V4.8_C++之MFC编程学习_QQ：834999326  无可用端口号！"));
		}
	}
	SetWindowText(text);//将 内容显示到标题栏上
}

void CMFCApplication4Dlg::OnBnClickedButton3()  //清空接收区数据
{
	// TODO:  在此添加控件通知处理程序代码

	m_strRecvData.Empty();  //情况接收文本框里面的内容
	if (m_cComm.get_PortOpen())
		m_cComm.get_Input(); //预读缓冲区以清除残留数据
	UpdateData(FALSE);  //更新显示
}

void CMFCApplication4Dlg::OnBnClickedButton1() //收索串口
{
	// TODO:  在此添加控件通知处理程序代码
	CString text;
	m_cbExample.ResetContent(); //清空串口框内所有的内容
	if (m_cComm.get_PortOpen())  //判断串口正处于打开
	{
		m_cComm.put_PortOpen(FALSE);  //关闭串口
		this->SetDlgItemText(IDC_BUTTON2, _T("打开串口"));//按钮上的文字显示  打开串口
	}
	GetComm();//收索串口号
	if (!icocc)  //如果没有串口
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("无可用端口号！"));
		text.Format(_T("龚宇串口通讯_V4.8_C++之MFC编程学习_QQ：834999326  无可用端口号！"));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T(""));
		text.Format(_T("龚宇串口通讯_V4.8_C++之MFC编程学习_QQ：834999326  串口处于关闭状态"));
	}
	SetWindowText(text);//将 内容显示到标题栏上
}

void CMFCApplication4Dlg::GetComm()  //自动收索串口
{
	// TODO:  在此添加命令处理程序代码
		//程序启动时获取全部可用串口
		HANDLE  hCom;
		int i, num;
		CString str;
//		static CString stre;
		BOOL flag;

//		m_cbExample.ResetContent(); //清空串口框内所有的内容

		CComboBox* pComboComm = (CComboBox*)GetDlgItem(IDC_COMBO1);//获取串口号控件
		ASSERT(pComboComm);//确定成功

		((CComboBox *)GetDlgItem(IDC_MSCOMM1))->ResetContent();  //获取串口电话控件
		flag = FALSE;
		num = 0;
		for (i = 1; i <= 20; i++)//支持20个串口  循环扫描串口  直到20
		{
			str.Format(_T("\\\\.\\COM%d"), i);//组合字符
			hCom = CreateFile(str, 0, 0, 0,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);//挨个的尝试打开
			if (INVALID_HANDLE_VALUE != hCom)//能打开该串口，则添加该串口
			{
				CloseHandle(hCom);
				str = str.Mid(4);
				((CComboBox *)GetDlgItem(IDC_MSCOMM1))->AddString(str);
				if (flag == FALSE)
				{
					flag = TRUE;
					num = i;

				}
				pComboComm->AddString(str);//添加扫描到的串口号
			}
		}

		icocc = ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCount();//串口号下拉列表中没有数据则为0
		if (icocc)//如果有串口  串口号下拉列表 自动选择第一个数据显示
		{
			pComboComm->SetCurSel(0);
			m_strRecvData.Empty();  //情况接收文本框里面的内容
			UpdateData(FALSE);  //更新显示
		}
		else//若找不到可用串口则禁用“打开串口”功能
		{
			CString str;
//			m_cbExample.ResetContent(); //清空串口框内所有的内容
			SetDlgItemText(IDC_EDIT_RECV, _T("在程序初始化时，未找到可用端口号！\r\n请插入COM设备后再打开本程序！"));
		}
}

void CMFCApplication4Dlg::InitCombox()  //下拉列表初始化
{
	CComboBox* pComboBaudrate = (CComboBox*)GetDlgItem(IDC_COMBO2);//获取波特率控件
	ASSERT(pComboBaudrate);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("300")), 300);//300波特率  字符关联数字
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("600")), 600);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("1200")), 1200);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("4800")), 4800);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("9600")), 9600);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("19200")), 19200);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("38400")), 38400);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("43000")), 43000);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("56000")), 56000);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("57600")), 57600);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("115200")), 115200);
	pComboBaudrate->SetCurSel(10);//初始化险种 115200 波特率

	CComboBox* pComboCheckbit = (CComboBox*)GetDlgItem(IDC_COMBO3);//校验位
	ASSERT(pComboCheckbit);
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("无None")), 'n');
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("奇DOO")), 'o');
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("偶EVEN")), 'e');
	pComboCheckbit->SetCurSel(0); //初始化选中  无校验位

	CComboBox* pComboDatabit = (CComboBox*)GetDlgItem(IDC_COMBO4);//数据位
	ASSERT(pComboDatabit);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("6")), 6);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("7")), 7);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("8")), 8);
	pComboDatabit->SetCurSel(2); //初始化选中  8位数据位

	CComboBox* pComboStopbit = (CComboBox*)GetDlgItem(IDC_COMBO5);//停止位
	ASSERT(pComboStopbit);
	pComboStopbit->SetItemData(pComboStopbit->AddString(_T("1")), 1);
	pComboStopbit->SetItemData(pComboStopbit->AddString(_T("2")), 2);
//	pComboStopbit->SetCurSel(0); //初始化选中 1位停止位
	((CComboBox*)GetDlgItem(IDC_COMBO5))->SetCurSel(0);//设置第n行内容为显示的内容。同上一样显示
}

void CMFCApplication4Dlg::OnTimer(UINT_PTR nIDEvent)  //定时器
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)
	{
	case 1:TimeInit();  //获取时间
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplication4Dlg::TimeInit()  //获取时间
{
	CTime t = CTime::GetCurrentTime(); //获取当前时间
	int nYear = t.GetYear();	//获取当前年
	int nMonth = t.GetMonth();	//获取当前月
	int nDay = t.GetDay();		//获取当前日
	int nHour = t.GetHour();	//获取当前时
	int nMin = t.GetMinute();	//获取当前分
	int nSec = t.GetSecond();	//获取当前秒
	int nWeek = t.GetDayOfWeek();	//获取当前的星期
	CString time;
	time.Format(_T("当前系统时间：%d 年 %02d 月 %02d 日 %02d:%02d:%02d"),
		nYear, nMonth, nDay, nHour, nMin, nSec);  //将数据组合起来存到str中
	this->SetDlgItemText(IDC_TIME, time);
}

void CMFCApplication4Dlg::OnBnClickedCheck1()  //这是对复选框右键添加事件得到的  窗口前端显示
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();//获取控件动态
	CString DOG_mode;
	if (m_bShowTopmost)              // 窗口最前端显示  
	{
		TRACE("True\n");
		SetWindowPos(&this->wndTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
		DOG_mode.Format(_T("自由窗口显示"));
		this->SetDlgItemTextW(IDC_CHECK1, DOG_mode);
	}
	else
	{
		TRACE("False\n");
		SetWindowPos(&this->wndNoTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
		DOG_mode.Format(_T("窗口前端显示"));
		this->SetDlgItemTextW(IDC_CHECK1, DOG_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck2()//显示问题选择
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData();//获取控件动态
	CString ZH_mode;
	if (m_ZH)
	{
		ZH = 1;
		ZH_mode.Format(_T("汉字混显示"));
		this->SetDlgItemText(IDC_CHECK2, ZH_mode);
	}
	else
	{
		ZH = 0;
		ZH_mode.Format(_T("字符串显示"));
		this->SetDlgItemText(IDC_CHECK2, ZH_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedButton4() //退出
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void CMFCApplication4Dlg::OnBnClickedButton5() //AT发送时钟到GSM
{
	CString AT_Time,AT_CCLK;
	// TODO:  在此添加控件通知处理程序代码
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		CTime tc = CTime::GetCurrentTime(); //获取当前时间
		int nYe = tc.GetYear();	//获取当前年
		int nMo = tc.GetMonth();	//获取当前月
		int nDa = tc.GetDay();		//获取当前日
		int nHo = tc.GetHour();	//获取当前时
		int nMi = tc.GetMinute();	//获取当前分
		int nSe = tc.GetSecond();	//获取当前秒
		nYe = nYe - 2000;
		AT_Time.Format(_T("%c%02d/%02d/%02d,%02d:%02d:%02d+00%c\r\n"),
			34,nYe, nMo, nDa, nHo, nMi, nSe,34);//"04/01/01,02:21:21+00"
		AT_CCLK.Format(_T("AT+CCLK=") + AT_Time);
		m_cComm.put_Output(COleVariant(AT_CCLK));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton6()//获取GSM到电脑
{
	// TODO:  在此添加控件通知处理程序代码
	CString AT_CCLK;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		AT_CCLK.Format(_T("AT+CCLK?\r\n"));
		m_cComm.put_Output(COleVariant(AT_CCLK));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck3()//新行发送
{
	UpdateData();//获取控件动态
	CString Rn_mode;
	if (m_Rn)
	{
		RN = 1;
		Rn_mode.Format(_T("不带换行符发送"));
		this->SetDlgItemText(IDC_CHECK3, Rn_mode);
	}
	else
	{
		RN = 0;
		Rn_mode.Format(_T("自带换行符发送"));
		this->SetDlgItemText(IDC_CHECK3, Rn_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedButton7()  //确定发送短信 GSM
{
	// TODO:  在此添加控件通知处理程序代码
	CString Clt_z;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		Clt_z.Format(_T("%c\r\n"), 26); //0x1a   Ctrl+z
		m_cComm.put_Output(COleVariant(Clt_z));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton8()  //取消发送短信 GSM
{
	// TODO:  在此添加控件通知处理程序代码
	CString Esc;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		Esc.Format(_T("%c\r\n"), 27); //0x1b   Esc
		m_cComm.put_Output(COleVariant(Esc));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton9() //打电话 //挂电话
{
	// TODO:  在此添加控件通知处理程序代码
	CString str,edit1;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		GetDlgItemText(IDC_EDIT1, str);
		BOOL b = str.IsEmpty();
		if (b)
			AfxMessageBox(_T("请输入电话号码"));
		else
		{
			if (num1 == 0)
			{
				edit1.Format(_T("ATD") + str + (";\r\n"));  //接电话
				m_cComm.put_Output(COleVariant(edit1));
				this->SetDlgItemText(IDC_BUTTON9, _T("挂电话"));//按钮上的文字显示  挂电话
			}

			if (num1 == 1)
			{
				edit1.Format(_T("ATH\r\n"));  //挂电话
				m_cComm.put_Output(COleVariant(edit1));
				this->SetDlgItemText(IDC_BUTTON9, _T("打电话"));//按钮上的文字显示  打电话
			}
			num1 = 1-num1;
		}
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton10() //接电话
{
	// TODO:  在此添加控件通知处理程序代码
	CString str, edit1;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		edit1.Format(_T("ATA") + str + (";\r\n"));
		m_cComm.put_Output(COleVariant(edit1));
		num1 = 1;
		this->SetDlgItemText(IDC_BUTTON9, _T("挂电话"));//按钮上的文字显示  挂电话
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton11() //串口波特率匹配
{
	// TODO:  在此添加控件通知处理程序代码
	CString AT;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		AT.Format(_T("AT\r\n"));
		m_cComm.put_Output(COleVariant(AT));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton12() //模块关机
{
	// TODO:  在此添加控件通知处理程序代码
	CString AT_QPOWD_1;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		AT_QPOWD_1.Format(_T("AT+QPOWD=1\r\n"));
		m_cComm.put_Output(COleVariant(AT_QPOWD_1));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton13() //模块重启
{
	// TODO:  在此添加控件通知处理程序代码
	CString AT_QPOWD_2;
	if (m_cComm.get_PortOpen())  //如果串口是打开的 就可以发送数据
	{
		AT_QPOWD_2.Format(_T("AT+QPOWD=2\r\n"));
		m_cComm.put_Output(COleVariant(AT_QPOWD_2));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("串口未打开！"));
	}
}

/*

//  完全屏蔽ESC键与ENTER回车键  

BOOL CMFCApplication4Dlg::PreTranslateMessage(MSG* pMsg)  //重载PreTranslateMessage消息
{
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

*/


/*

你重载PreTranslateMessage消息，当接收到回车键时就调用按钮的事件就可以了。
BOOL CXXXDlg::PreTranslateMessage(MSG* pMsg)
{
// TODO: Add your specialized code here and/or call the base class

if(pMsg->wParam==VK_RETURN)
{
……//按钮事件
}
return CDialog::PreTranslateMessage(pMsg);
}

*/

/*  完全屏蔽ESC键，捕捉ENTER回车键  */
/*
BOOL CMFCApplication4Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_MSG_SEND)//按下回车，如果当前焦点是在自己期望的              控件上
		{
			CMFCApplication4Dlg::OnBnClickedBtnSend();//添加自己的处理代码
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}
*/


//AT+COPS?
/*

AT+COPS?  //查看网络运营商

+COPS: 0   //无运营商

OK


AT+COPS?

+COPS: 0,0,"CHINA MOBILE" //中国移动通讯

OK


*/
