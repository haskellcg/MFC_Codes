// MFCExp4Doc.cpp : CMFCExp4Doc ���ʵ��
//

#include "stdafx.h"
#include "MFCExp4.h"

#include "MFCExp4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCExp4Doc

IMPLEMENT_DYNCREATE(CMFCExp4Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCExp4Doc, CDocument)
END_MESSAGE_MAP()


// CMFCExp4Doc ����/����

CMFCExp4Doc::CMFCExp4Doc():position(stulink.GetHeadPosition()),color(RGB(0,0,0))
{
	// TODO: �ڴ����һ���Թ������

}

CMFCExp4Doc::~CMFCExp4Doc()
{
}

BOOL CMFCExp4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMFCExp4Doc ���л�

void CMFCExp4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CMFCExp4Doc ���

#ifdef _DEBUG
void CMFCExp4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCExp4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCExp4Doc ����
