
// MFCApplication4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication4Dlg �Ի���



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


// CMFCApplication4Dlg ��Ϣ�������

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	
	if (m_cComm.get_PortOpen()) //������ִ��ڱ����Ǵ򿪵ģ���رմ���
		m_cComm.put_PortOpen(FALSE);  
	GetComm();//�Զ��������ô����г������б���

	SetTimer(1, 1000, NULL);//������ʱ��  ��ʱʱ��Ϊ1�� 
	//		SetTimer(2, 2000, NULL);//��ʱʱ��  Ϊ2��

	SetDlgItemText(IDC_EDIT1, _T("15773010165")); //��ʼ���绰���봰��

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	InitCombox();//�����б���ʼ��
	TimeInit();  //ʱ���ʼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_EVENT(CMFCApplication4Dlg, IDC_MSCOMM1, 1, CMFCApplication4Dlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void CMFCApplication4Dlg::OnComm() //�Ӵ��ڽ������ݲ���ʾ�ڱ༭����
{
	
	// TODO:  �ڴ˴������Ϣ����������
	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	long len, k;
	BYTE rxdata[2048] = {0}; //����BYTE����
	CString strtemp;
	Sleep(50);//��ʱһ��
	if (m_cComm.get_CommEvent() == 2) //ֵΪ2��ʾ���ջ����������ַ�
	{
		variant_inp = m_cComm.get_Input();//����������Ϣ
		safearray_inp = variant_inp;//����ת��
		len = safearray_inp.GetOneDimSize(); //�õ���Ч�����ݳ���
		for (k = 0; k<len; k++)
			safearray_inp.GetElement(&k, rxdata + k);
		for (k = 0; k < len; k++) //������ת��Ϊ CString ���� 
		{
			if (ZH)
			{
				BYTE bt = *(char*)(rxdata + k); //�ַ���

				strtemp.Format(_T("%c"), bt);

				m_strRecvData += strtemp;//������ձ༭���Ӧ�ַ���
			}
			else
			{
				if (k == 0)
				{
					datas = (char*)rxdata; //�ַ���
					m_strRecvData += datas;
				}
			}
		}
	}
//	CString temp = (_T("\r\n")); //��ʾ��ɺ�Ҫ�Զ�����
//	m_strRecvData += temp;
//	UpdateData(FALSE); //���±༭������
//	m_Edit.SetSel(-1, -1);

	this->SetDlgItemTextW(IDC_EDIT_RECV, m_strRecvData);//��m_EditReceive������ʾ��IDΪIDC_EDIT1�ı༭������λ��
	m_Edit.LineScroll(m_Edit.GetLineCount() - 1, 0);//����ֱ���������������һ

	m_cComm.get_Input(); //Ԥ���������������������


}

void CMFCApplication4Dlg::OnBnClickedButtonSend()  //���Ͱ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString rN_mme;
	rN_mme.Format(_T("\r\n"));
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		if(RN)//�Զ�����
		{
			UpdateData(true); //��ȡ�༭������
			m_cComm.put_Output(COleVariant(m_strSendData+rN_mme));//�������� 
		}
		else
		{
			UpdateData(true); //��ȡ�༭������
			m_cComm.put_Output(COleVariant(m_strSendData));//��������
		}
	}
	else
	{
	//	CString str;
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton2()   //�򿪴��ڰ�ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString text;
	if (m_cComm.get_PortOpen())  //�жϴ��������ڴ�
	{
		m_cComm.put_PortOpen(FALSE);  //�رմ���
		text.Format(_T("�����ͨѶ_V4.8_C++֮MFC���ѧϰ_QQ��834999326  ���ڴ��ڹر�״̬"));
		this->SetDlgItemText(IDC_BUTTON2, _T("�򿪴���(Alt+&S)"));//��ť�ϵ�������ʾ  �򿪴���
	}
	else  //�򿪴���
	{
		if (icocc)  //�˿ڴ���  
		{
			CString boote, com;//�������  ������ У��λ ����λ ֹͣλ  ��Ϣ

			CComboBox* pComboComm = (CComboBox*)GetDlgItem(IDC_COMBO1);//��ȡ���ںſؼ�
			ASSERT(pComboComm);
			int nSel = pComboComm->GetCurSel(); //��ȡ���������б��е�ǰѡ�е���
			CString strComm;
			pComboComm->GetLBText(nSel, strComm);
			com = strComm.Mid(3); //ȡ�����ں�   COM  ���������
			int icomm = _ttoi(com);  //�� CString ����ת���� int ����

			CComboBox* pComboBaudrate = (CComboBox*)GetDlgItem(IDC_COMBO2);//��ȡ�����ʿؼ�
			ASSERT(pComboBaudrate);
			nSel = pComboBaudrate->GetCurSel();
			DWORD dwBaudrate = (DWORD)pComboBaudrate->GetItemData(nSel);

			CComboBox* pComboCheckbit = (CComboBox*)GetDlgItem(IDC_COMBO3);//У��λ
			ASSERT(pComboCheckbit);
			nSel = pComboCheckbit->GetCurSel();
			BYTE byParity = (BYTE)pComboCheckbit->GetItemData(nSel);

			CComboBox* pComboDatabit = (CComboBox*)GetDlgItem(IDC_COMBO4);//����λ
			ASSERT(pComboDatabit);
			nSel = pComboDatabit->GetCurSel();
			BYTE byDatasize = (BYTE)pComboDatabit->GetItemData(nSel);

			CComboBox* pComboStopbit = (CComboBox*)GetDlgItem(IDC_COMBO5);//ֹͣλ
			ASSERT(pComboStopbit);
			nSel = pComboStopbit->GetCurSel();
			BYTE byStopbits = (BYTE)pComboStopbit->GetItemData(nSel);

			boote.Format(_T("%d,%c,%d,%d"), dwBaudrate, byParity, byDatasize, byStopbits);//�����в����ʣ�У��λ������λ��ֹͣλ

			m_cComm.put_CommPort(icomm);//ѡ��COM�˿�

			m_cComm.put_InputMode(1); //���뷽ʽΪ�����Ʒ�ʽ
			m_cComm.put_InBufferSize(2048); //�������뻺����
			m_cComm.put_OutBufferSize(2048); //�������������
			m_cComm.put_RThreshold(1);//���ջ�������1����1�������ַ�ʱ���������������ݵ�OnComm

			m_cComm.put_Settings(boote);//�����ʣ�У�飬����λ��ֹͣλ

			//	m_cComm.put_Settings(_T("115200,n,8,1"));//������115200����У�飬8λ����λ��1λֹͣλ   ��ʼ������

			m_cComm.put_PortOpen(TRUE);  //�򿪴���
			
			m_cComm.put_RThreshold(1);//ÿ�����ջ�������1���ַ�����մ�������
			m_cComm.put_InputLen(0);//���õ�ǰ���������ݳ���Ϊ0,��ʾȫ����ȡ
			m_cComm.get_Input(); //Ԥ���������������������

//			m_strRecvData.Empty();  //��������ı������������  �����ѡ
//			UpdateData(false);  //������ʾ
//			m_strSendData.Empty(); //���ͺ���������
//			UpdateData(false); //���±༭�������

			this->SetDlgItemText(IDC_BUTTON2, _T("�رմ���(Alt+&S)"));	 //��ť�ϵ�������ʾ �رմ���	
			text.Format(_T("�����ͨѶ_V4.8_C++֮MFC���ѧϰ_QQ��834999326  ( COM%d ) �Դ� ")+ boote,icomm);
		}
		else
		{
			SetDlgItemText(IDC_EDIT_SEND, _T("�޿��ö˿ںţ�"));
			text.Format(_T("�����ͨѶ_V4.8_C++֮MFC���ѧϰ_QQ��834999326  �޿��ö˿ںţ�"));
		}
	}
	SetWindowText(text);//�� ������ʾ����������
}

void CMFCApplication4Dlg::OnBnClickedButton3()  //��ս���������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_strRecvData.Empty();  //��������ı������������
	if (m_cComm.get_PortOpen())
		m_cComm.get_Input(); //Ԥ���������������������
	UpdateData(FALSE);  //������ʾ
}

void CMFCApplication4Dlg::OnBnClickedButton1() //��������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString text;
	m_cbExample.ResetContent(); //��մ��ڿ������е�����
	if (m_cComm.get_PortOpen())  //�жϴ��������ڴ�
	{
		m_cComm.put_PortOpen(FALSE);  //�رմ���
		this->SetDlgItemText(IDC_BUTTON2, _T("�򿪴���"));//��ť�ϵ�������ʾ  �򿪴���
	}
	GetComm();//�������ں�
	if (!icocc)  //���û�д���
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("�޿��ö˿ںţ�"));
		text.Format(_T("�����ͨѶ_V4.8_C++֮MFC���ѧϰ_QQ��834999326  �޿��ö˿ںţ�"));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T(""));
		text.Format(_T("�����ͨѶ_V4.8_C++֮MFC���ѧϰ_QQ��834999326  ���ڴ��ڹر�״̬"));
	}
	SetWindowText(text);//�� ������ʾ����������
}

void CMFCApplication4Dlg::GetComm()  //�Զ���������
{
	// TODO:  �ڴ���������������
		//��������ʱ��ȡȫ�����ô���
		HANDLE  hCom;
		int i, num;
		CString str;
//		static CString stre;
		BOOL flag;

//		m_cbExample.ResetContent(); //��մ��ڿ������е�����

		CComboBox* pComboComm = (CComboBox*)GetDlgItem(IDC_COMBO1);//��ȡ���ںſؼ�
		ASSERT(pComboComm);//ȷ���ɹ�

		((CComboBox *)GetDlgItem(IDC_MSCOMM1))->ResetContent();  //��ȡ���ڵ绰�ؼ�
		flag = FALSE;
		num = 0;
		for (i = 1; i <= 20; i++)//֧��20������  ѭ��ɨ�贮��  ֱ��20
		{
			str.Format(_T("\\\\.\\COM%d"), i);//����ַ�
			hCom = CreateFile(str, 0, 0, 0,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);//�����ĳ��Դ�
			if (INVALID_HANDLE_VALUE != hCom)//�ܴ򿪸ô��ڣ�����Ӹô���
			{
				CloseHandle(hCom);
				str = str.Mid(4);
				((CComboBox *)GetDlgItem(IDC_MSCOMM1))->AddString(str);
				if (flag == FALSE)
				{
					flag = TRUE;
					num = i;

				}
				pComboComm->AddString(str);//���ɨ�赽�Ĵ��ں�
			}
		}

		icocc = ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCount();//���ں������б���û��������Ϊ0
		if (icocc)//����д���  ���ں������б� �Զ�ѡ���һ��������ʾ
		{
			pComboComm->SetCurSel(0);
			m_strRecvData.Empty();  //��������ı������������
			UpdateData(FALSE);  //������ʾ
		}
		else//���Ҳ������ô�������á��򿪴��ڡ�����
		{
			CString str;
//			m_cbExample.ResetContent(); //��մ��ڿ������е�����
			SetDlgItemText(IDC_EDIT_RECV, _T("�ڳ����ʼ��ʱ��δ�ҵ����ö˿ںţ�\r\n�����COM�豸���ٴ򿪱�����"));
		}
}

void CMFCApplication4Dlg::InitCombox()  //�����б��ʼ��
{
	CComboBox* pComboBaudrate = (CComboBox*)GetDlgItem(IDC_COMBO2);//��ȡ�����ʿؼ�
	ASSERT(pComboBaudrate);
	pComboBaudrate->SetItemData(pComboBaudrate->AddString(_T("300")), 300);//300������  �ַ���������
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
	pComboBaudrate->SetCurSel(10);//��ʼ������ 115200 ������

	CComboBox* pComboCheckbit = (CComboBox*)GetDlgItem(IDC_COMBO3);//У��λ
	ASSERT(pComboCheckbit);
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("��None")), 'n');
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("��DOO")), 'o');
	pComboCheckbit->SetItemData(pComboCheckbit->AddString(_T("żEVEN")), 'e');
	pComboCheckbit->SetCurSel(0); //��ʼ��ѡ��  ��У��λ

	CComboBox* pComboDatabit = (CComboBox*)GetDlgItem(IDC_COMBO4);//����λ
	ASSERT(pComboDatabit);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("6")), 6);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("7")), 7);
	pComboDatabit->SetItemData(pComboDatabit->AddString(_T("8")), 8);
	pComboDatabit->SetCurSel(2); //��ʼ��ѡ��  8λ����λ

	CComboBox* pComboStopbit = (CComboBox*)GetDlgItem(IDC_COMBO5);//ֹͣλ
	ASSERT(pComboStopbit);
	pComboStopbit->SetItemData(pComboStopbit->AddString(_T("1")), 1);
	pComboStopbit->SetItemData(pComboStopbit->AddString(_T("2")), 2);
//	pComboStopbit->SetCurSel(0); //��ʼ��ѡ�� 1λֹͣλ
	((CComboBox*)GetDlgItem(IDC_COMBO5))->SetCurSel(0);//���õ�n������Ϊ��ʾ�����ݡ�ͬ��һ����ʾ
}

void CMFCApplication4Dlg::OnTimer(UINT_PTR nIDEvent)  //��ʱ��
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	switch (nIDEvent)
	{
	case 1:TimeInit();  //��ȡʱ��
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CMFCApplication4Dlg::TimeInit()  //��ȡʱ��
{
	CTime t = CTime::GetCurrentTime(); //��ȡ��ǰʱ��
	int nYear = t.GetYear();	//��ȡ��ǰ��
	int nMonth = t.GetMonth();	//��ȡ��ǰ��
	int nDay = t.GetDay();		//��ȡ��ǰ��
	int nHour = t.GetHour();	//��ȡ��ǰʱ
	int nMin = t.GetMinute();	//��ȡ��ǰ��
	int nSec = t.GetSecond();	//��ȡ��ǰ��
	int nWeek = t.GetDayOfWeek();	//��ȡ��ǰ������
	CString time;
	time.Format(_T("��ǰϵͳʱ�䣺%d �� %02d �� %02d �� %02d:%02d:%02d"),
		nYear, nMonth, nDay, nHour, nMin, nSec);  //��������������浽str��
	this->SetDlgItemText(IDC_TIME, time);
}

void CMFCApplication4Dlg::OnBnClickedCheck1()  //���ǶԸ�ѡ���Ҽ�����¼��õ���  ����ǰ����ʾ
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();//��ȡ�ؼ���̬
	CString DOG_mode;
	if (m_bShowTopmost)              // ������ǰ����ʾ  
	{
		TRACE("True\n");
		SetWindowPos(&this->wndTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
		DOG_mode.Format(_T("���ɴ�����ʾ"));
		this->SetDlgItemTextW(IDC_CHECK1, DOG_mode);
	}
	else
	{
		TRACE("False\n");
		SetWindowPos(&this->wndNoTopMost, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
		DOG_mode.Format(_T("����ǰ����ʾ"));
		this->SetDlgItemTextW(IDC_CHECK1, DOG_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck2()//��ʾ����ѡ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();//��ȡ�ؼ���̬
	CString ZH_mode;
	if (m_ZH)
	{
		ZH = 1;
		ZH_mode.Format(_T("���ֻ���ʾ"));
		this->SetDlgItemText(IDC_CHECK2, ZH_mode);
	}
	else
	{
		ZH = 0;
		ZH_mode.Format(_T("�ַ�����ʾ"));
		this->SetDlgItemText(IDC_CHECK2, ZH_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedButton4() //�˳�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

void CMFCApplication4Dlg::OnBnClickedButton5() //AT����ʱ�ӵ�GSM
{
	CString AT_Time,AT_CCLK;
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		CTime tc = CTime::GetCurrentTime(); //��ȡ��ǰʱ��
		int nYe = tc.GetYear();	//��ȡ��ǰ��
		int nMo = tc.GetMonth();	//��ȡ��ǰ��
		int nDa = tc.GetDay();		//��ȡ��ǰ��
		int nHo = tc.GetHour();	//��ȡ��ǰʱ
		int nMi = tc.GetMinute();	//��ȡ��ǰ��
		int nSe = tc.GetSecond();	//��ȡ��ǰ��
		nYe = nYe - 2000;
		AT_Time.Format(_T("%c%02d/%02d/%02d,%02d:%02d:%02d+00%c\r\n"),
			34,nYe, nMo, nDa, nHo, nMi, nSe,34);//"04/01/01,02:21:21+00"
		AT_CCLK.Format(_T("AT+CCLK=") + AT_Time);
		m_cComm.put_Output(COleVariant(AT_CCLK));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton6()//��ȡGSM������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString AT_CCLK;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		AT_CCLK.Format(_T("AT+CCLK?\r\n"));
		m_cComm.put_Output(COleVariant(AT_CCLK));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedCheck3()//���з���
{
	UpdateData();//��ȡ�ؼ���̬
	CString Rn_mode;
	if (m_Rn)
	{
		RN = 1;
		Rn_mode.Format(_T("�������з�����"));
		this->SetDlgItemText(IDC_CHECK3, Rn_mode);
	}
	else
	{
		RN = 0;
		Rn_mode.Format(_T("�Դ����з�����"));
		this->SetDlgItemText(IDC_CHECK3, Rn_mode);
	}
}

void CMFCApplication4Dlg::OnBnClickedButton7()  //ȷ�����Ͷ��� GSM
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString Clt_z;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		Clt_z.Format(_T("%c\r\n"), 26); //0x1a   Ctrl+z
		m_cComm.put_Output(COleVariant(Clt_z));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton8()  //ȡ�����Ͷ��� GSM
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString Esc;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		Esc.Format(_T("%c\r\n"), 27); //0x1b   Esc
		m_cComm.put_Output(COleVariant(Esc));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton9() //��绰 //�ҵ绰
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str,edit1;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		GetDlgItemText(IDC_EDIT1, str);
		BOOL b = str.IsEmpty();
		if (b)
			AfxMessageBox(_T("������绰����"));
		else
		{
			if (num1 == 0)
			{
				edit1.Format(_T("ATD") + str + (";\r\n"));  //�ӵ绰
				m_cComm.put_Output(COleVariant(edit1));
				this->SetDlgItemText(IDC_BUTTON9, _T("�ҵ绰"));//��ť�ϵ�������ʾ  �ҵ绰
			}

			if (num1 == 1)
			{
				edit1.Format(_T("ATH\r\n"));  //�ҵ绰
				m_cComm.put_Output(COleVariant(edit1));
				this->SetDlgItemText(IDC_BUTTON9, _T("��绰"));//��ť�ϵ�������ʾ  ��绰
			}
			num1 = 1-num1;
		}
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton10() //�ӵ绰
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str, edit1;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		edit1.Format(_T("ATA") + str + (";\r\n"));
		m_cComm.put_Output(COleVariant(edit1));
		num1 = 1;
		this->SetDlgItemText(IDC_BUTTON9, _T("�ҵ绰"));//��ť�ϵ�������ʾ  �ҵ绰
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton11() //���ڲ�����ƥ��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString AT;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		AT.Format(_T("AT\r\n"));
		m_cComm.put_Output(COleVariant(AT));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton12() //ģ��ػ�
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString AT_QPOWD_1;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		AT_QPOWD_1.Format(_T("AT+QPOWD=1\r\n"));
		m_cComm.put_Output(COleVariant(AT_QPOWD_1));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

void CMFCApplication4Dlg::OnBnClickedButton13() //ģ������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString AT_QPOWD_2;
	if (m_cComm.get_PortOpen())  //��������Ǵ򿪵� �Ϳ��Է�������
	{
		AT_QPOWD_2.Format(_T("AT+QPOWD=2\r\n"));
		m_cComm.put_Output(COleVariant(AT_QPOWD_2));
	}
	else
	{
		SetDlgItemText(IDC_EDIT_SEND, _T("����δ�򿪣�"));
	}
}

/*

//  ��ȫ����ESC����ENTER�س���  

BOOL CMFCApplication4Dlg::PreTranslateMessage(MSG* pMsg)  //����PreTranslateMessage��Ϣ
{
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_RETURN)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam == VK_ESCAPE)
		return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

*/


/*

������PreTranslateMessage��Ϣ�������յ��س���ʱ�͵��ð�ť���¼��Ϳ����ˡ�
BOOL CXXXDlg::PreTranslateMessage(MSG* pMsg)
{
// TODO: Add your specialized code here and/or call the base class

if(pMsg->wParam==VK_RETURN)
{
����//��ť�¼�
}
return CDialog::PreTranslateMessage(pMsg);
}

*/

/*  ��ȫ����ESC������׽ENTER�س���  */
/*
BOOL CMFCApplication4Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetFocus()->GetDlgCtrlID() == IDC_MSG_SEND)//���»س��������ǰ���������Լ�������              �ؼ���
		{
			CMFCApplication4Dlg::OnBnClickedBtnSend();//����Լ��Ĵ������
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

AT+COPS?  //�鿴������Ӫ��

+COPS: 0   //����Ӫ��

OK


AT+COPS?

+COPS: 0,0,"CHINA MOBILE" //�й��ƶ�ͨѶ

OK


*/
