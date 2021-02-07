// ConflictDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "STUpload.h"
#include "ConflictDialog.h"


// CConflictDialog 对话框

IMPLEMENT_DYNAMIC(CConflictDialog, CDialog)

CConflictDialog::CConflictDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CConflictDialog::IDD, pParent)
	, m_REditText(_T(""))
{

}

CConflictDialog::~CConflictDialog()
{
}

void CConflictDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONFLICT_RICHEDIT, m_REditText);
}


BEGIN_MESSAGE_MAP(CConflictDialog, CDialog)
	ON_BN_CLICKED(IDABORT, &CConflictDialog::OnBnClickedAbort)
END_MESSAGE_MAP()


// CConflictDialog 消息处理程序

void CConflictDialog::OnBnClickedAbort()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(IDABORT);
}
