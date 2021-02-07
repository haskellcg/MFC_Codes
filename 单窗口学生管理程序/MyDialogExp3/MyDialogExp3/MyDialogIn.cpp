// MyDialogIn.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDialogExp3.h"
#include "MyDialogIn.h"


// MyDialogIn 对话框

IMPLEMENT_DYNAMIC(MyDialogIn, CDialog)

MyDialogIn::MyDialogIn(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialogIn::IDD, pParent)
	, m_Name_In(_T(""))
	, m_Stunum_In(_T(""))
	, m_Age_In(0)
	, m_English_In(0)
	, m_Chinese_In(0)
	, m_Math_In(0)
	, m_CLPG_In(0)
{
	hIcon=AfxGetApp()->LoadIconW(IDI_ICON_IN);
}

MyDialogIn::~MyDialogIn()
{
}

BOOL MyDialogIn::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(hIcon,true);
	SetIcon(hIcon,false);
	return true;
}


void MyDialogIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_NAME, m_Name_In);
	DDX_Text(pDX, IDC_EDIT_IN_STUNUM, m_Stunum_In);
	DDX_Text(pDX, IDC_EDIT_IN_AGE, m_Age_In);
	DDX_Text(pDX, IDC_EDIT_IN_ENGLISH, m_English_In);
	DDX_Text(pDX, IDC_EDIT_IN_CHINESE, m_Chinese_In);
	DDX_Text(pDX, IDC_EDIT_IN_MATH, m_Math_In);
	DDX_Text(pDX, IDC_EDIT_IN_CLPG, m_CLPG_In);
}


BEGIN_MESSAGE_MAP(MyDialogIn, CDialog)
	ON_BN_CLICKED(IDOK, &MyDialogIn::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialogIn 消息处理程序

void MyDialogIn::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	OnOK();
}
