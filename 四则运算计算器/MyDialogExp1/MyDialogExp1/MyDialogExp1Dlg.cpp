// MyDialogExp1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDialogExp1.h"
#include "MyDialogExp1Dlg.h"
#include <math.h>
#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMyDialogExp1Dlg 对话框




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


// CMyDialogExp1Dlg 消息处理程序

BOOL CMyDialogExp1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_YS_Ctrl.EnableWindow(false);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyDialogExp1Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyDialogExp1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


	// TODO: 在此添加控件通知处理程序代码



void CMyDialogExp1Dlg::OnBnClickedButtonYs()
{
	// TODO: 在此添加控件通知处理程序代码
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
						AfxMessageBox(_T("注意！除数不可以为零!"));
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
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if(number_one!=0 || number_two!=0)
	{
		m_YS_Ctrl.EnableWindow(true);
	}
}

void CMyDialogExp1Dlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if(number_one!=0 || number_two!=0)
	{
		m_YS_Ctrl.EnableWindow(true);
	}
}

void CMyDialogExp1Dlg::OnOK()
{
	// TODO: 在此添加控件通知处理程序代码
	OnBnClickedButtonYs();
}

void CMyDialogExp1Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码;
	UpdateData(true);
	CString temp;
	m_Combobox_Ctrl.GetWindowTextW(temp);

	if(temp=="sin()" || temp=="cos()" || temp=="tan()")
		m_EDIT2_Ctrl.EnableWindow(false);
	else
		m_EDIT2_Ctrl.EnableWindow(true);
}
