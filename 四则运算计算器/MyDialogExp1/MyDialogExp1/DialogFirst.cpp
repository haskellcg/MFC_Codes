// DialogFirst.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyDialogExp1.h"
#include "DialogFirst.h"


// DialogFirst �Ի���

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


// DialogFirst ��Ϣ�������
void DialogFirst::OnPaint()
{
	CDialog::OnPaint();
}