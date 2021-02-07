// FUNDDIALOG.cpp : 实现文件
//

#include "stdafx.h"
#include "STUpload.h"
#include "FUNDDIALOG.h"
#include "MainFrm.h"
#include "STUploadDoc.h"



// CFUNDDIALOG 对话框

IMPLEMENT_DYNAMIC(CFUNDDIALOG, CDialog)

CFUNDDIALOG::CFUNDDIALOG(CWnd* pParent /*=NULL*/)
	: CDialog(CFUNDDIALOG::IDD, pParent)
{

}

CFUNDDIALOG::~CFUNDDIALOG()
{
}

void CFUNDDIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FUNDLIST, m_listBox);
}


BEGIN_MESSAGE_MAP(CFUNDDIALOG, CDialog)
	ON_LBN_SELCHANGE(IDC_FUNDLIST, &CFUNDDIALOG::OnLbnSelchangeFundlist)
END_MESSAGE_MAP()


// CFUNDDIALOG 消息处理程序

void CFUNDDIALOG::OnLbnSelchangeFundlist()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainFrame * pWnd = 
		dynamic_cast< CMainFrame * > (AfxGetMainWnd());
	ASSERT_VALID( pWnd );
	
	CSTUploadDoc * pDoc = 
		dynamic_cast< CSTUploadDoc * >( pWnd->GetActiveDocument());
	ASSERT_VALID( pDoc );
	
	CString strCurFund;
	
	int sel = m_listBox.GetCurSel();
	
	if( sel == LB_ERR ) sel = 0;
	
	m_listBox.GetText( sel, strCurFund );
	
	pDoc->SetCurrentFund( strCurFund );
	
	pDoc->UpdateAllViews( NULL );

	pDoc->SetModifiedFlag(true);
}
