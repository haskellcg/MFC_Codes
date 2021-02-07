// MyDialogInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentLinkTB.h"
#include "MFCExp4.h"
#include "MyDialogInput.h"


// MyDialogInput �Ի���

IMPLEMENT_DYNAMIC(MyDialogInput, CDialog)

MyDialogInput::MyDialogInput(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialogInput::IDD, pParent)
	, m_Name_In(_T(""))
	, m_Stunum_In(_T(""))
	, m_Age_In(0)
	, m_English_In(0)
	, m_Math_In(0)
	, m_Chinese_In(0)
	, m_CLPG_In(0)
{

}

MyDialogInput::~MyDialogInput()
{
}

void MyDialogInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_NAME, m_Name_In);
	DDX_Text(pDX, IDC_EDIT_IN_STUNUM, m_Stunum_In);
	DDX_Text(pDX, IDC_EDIT_IN_AGE, m_Age_In);
	DDX_Text(pDX, IDC_EDIT_IN_ENGLISH, m_English_In);
	DDX_Text(pDX, IDC_EDIT_IN_MATH, m_Math_In);
	DDX_Text(pDX, IDC_EDIT_CHINESE, m_Chinese_In);
	DDX_Text(pDX, IDC_EDIT_IN_CLPG, m_CLPG_In);
}


BEGIN_MESSAGE_MAP(MyDialogInput, CDialog)
	ON_BN_CLICKED(IDOK, &MyDialogInput::OnBnClickedOk)
END_MESSAGE_MAP()


// MyDialogInput ��Ϣ�������

void MyDialogInput::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	OnOK();
}
