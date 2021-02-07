// DialogFirst.cpp : 实现文件
//

#include "stdafx.h"
#include "MyDialogExp1.h"
#include "DialogFirst.h"


// DialogFirst 对话框

IMPLEMENT_DYNAMIC(DialogFirst, CDialog)

DialogFirst::DialogFirst(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFirst::IDD, pParent)
{

}

DialogFirst::~DialogFirst()
{
}

void DialogFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DialogFirst, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// DialogFirst 消息处理程序
void DialogFirst::OnPaint()
{
	CDialog::OnPaint();
}