// ConflictDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "STUpload.h"
#include "ConflictDialog.h"


// CConflictDialog �Ի���

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


// CConflictDialog ��Ϣ�������

void CConflictDialog::OnBnClickedAbort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(IDABORT);
}
