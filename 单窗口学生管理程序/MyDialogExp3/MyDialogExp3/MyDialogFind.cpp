// MyDialogFind.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDialogExp3.h"
#include "MyDialogFind.h"


// MyDialogFind �Ի���

IMPLEMENT_DYNAMIC(MyDialogFind, CDialog)

MyDialogFind::MyDialogFind(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialogFind::IDD, pParent)
	, m_Name_Find(_T(""))
	, m_Stunum_Find(_T(""))
	,flag(-1)
{
	hIcon=AfxGetApp()->LoadIconW(IDI_ICON_FIND);
}

MyDialogFind::~MyDialogFind()
{
}

BOOL MyDialogFind::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(hIcon,true);
	SetIcon(hIcon,false);

	m_Name_Find_Ctrl.EnableWindow(false);
	m_Stunum_Find_Ctrl.EnableWindow(false);
	return true;
}

void MyDialogFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name_Find);
	DDX_Text(pDX, IDC_EDIT_STUNUM, m_Stunum_Find);
	DDX_Control(pDX, IDC_EDIT_NAME, m_Name_Find_Ctrl);
	DDX_Control(pDX, IDC_EDIT_STUNUM, m_Stunum_Find_Ctrl);
}


BEGIN_MESSAGE_MAP(MyDialogFind, CDialog)
	ON_BN_CLICKED(IDC_RADIO_NAME, &MyDialogFind::OnBnClickedRadioName)
	ON_BN_CLICKED(IDC_RADIO_STUNUM, &MyDialogFind::OnBnClickedRadioStunum)
	ON_BN_CLICKED(IDOK, &MyDialogFind::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialogFind ��Ϣ�������

void MyDialogFind::OnBnClickedRadioName()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Name_Find_Ctrl.EnableWindow(true);
	m_Stunum_Find_Ctrl.EnableWindow(false);
	flag=0;
}

void MyDialogFind::OnBnClickedRadioStunum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Name_Find_Ctrl.EnableWindow(false);
	m_Stunum_Find_Ctrl.EnableWindow(true);
	flag=1;
}

void MyDialogFind::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	OnOK();
}
