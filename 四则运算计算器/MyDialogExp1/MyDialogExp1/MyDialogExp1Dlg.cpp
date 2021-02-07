// MyDialogExp1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDialogExp1.h"
#include "MyDialogExp1Dlg.h"
#include <math.h>
#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMyDialogExp1Dlg �Ի���




CMyDialogExp1Dlg::CMyDialogExp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDialogExp1Dlg::IDD, pParent)
	, result(0)
	, number_one(0)
	, number_two(0)
	, m_Combobox(_T("+"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDialogExp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, result);
	DDX_Text(pDX, IDC_EDIT5, number_one);
	DDX_Text(pDX, IDC_EDIT6, number_two);
	DDX_Control(pDX, IDC_BUTTON_YS, m_YS_Ctrl);
	DDX_Control(pDX, IDC_COMBO1, m_Combobox_Ctrl);
	DDX_CBString(pDX, IDC_COMBO1, m_Combobox);
	DDX_Control(pDX, IDC_EDIT5, m_EDIT1_Ctrl);
	DDX_Control(pDX, IDC_EDIT6, m_EDIT2_Ctrl);
}

BEGIN_MESSAGE_MAP(CMyDialogExp1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_YS, &CMyDialogExp1Dlg::OnBnClickedButtonYs)
	ON_EN_CHANGE(IDC_EDIT5, &CMyDialogExp1Dlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CMyDialogExp1Dlg::OnEnChangeEdit6)
	ON_BN_CLICKED(ID_OK, &CMyDialogExp1Dlg::OnOK)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyDialogExp1Dlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CMyDialogExp1Dlg ��Ϣ�������

BOOL CMyDialogExp1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_YS_Ctrl.EnableWindow(false);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMyDialogExp1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyDialogExp1Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyDialogExp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


	// TODO: �ڴ���ӿؼ�֪ͨ����������



void CMyDialogExp1Dlg::OnBnClickedButtonYs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString temp;
	m_Combobox_Ctrl.GetWindowTextW(temp);
	UpdateData(true);
	if(temp=="+")
	{
      result=number_one+number_two;
	  UpdateData(false);
	}
	else if(temp=="*")
		{
			result=number_one*number_two;
			UpdateData(false);
		}
		else if(temp=="-")
			{
				result=number_one-number_two;
				UpdateData(false);
			}
			else if(temp=="/")
				{
					if(number_two==0)
						AfxMessageBox(_T("ע�⣡����������Ϊ��!"));
					else
					{
						result=number_one/number_two;
						UpdateData(false);
					}
				}
				else if(temp=="sin()")
					{
						result=sin(number_one);
						UpdateData(false);
					}
					else if(temp=="cos()")
						{
							result=cos(number_one);
							UpdateData(false);
						}
						else if(temp=="tan()")
							{
								result=tan(number_one);
								UpdateData(false);
							}
	

}

void CMyDialogExp1Dlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(number_one!=0 || number_two!=0)
	{
		m_YS_Ctrl.EnableWindow(true);
	}
}

void CMyDialogExp1Dlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(number_one!=0 || number_two!=0)
	{
		m_YS_Ctrl.EnableWindow(true);
	}
}

void CMyDialogExp1Dlg::OnOK()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedButtonYs();
}

void CMyDialogExp1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������;
	UpdateData(true);
	CString temp;
	m_Combobox_Ctrl.GetWindowTextW(temp);

	if(temp=="sin()" || temp=="cos()" || temp=="tan()")
		m_EDIT2_Ctrl.EnableWindow(false);
	else
		m_EDIT2_Ctrl.EnableWindow(true);
}
