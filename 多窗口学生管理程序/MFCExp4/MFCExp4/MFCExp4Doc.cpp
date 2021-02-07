// MFCExp4Doc.cpp : CMFCExp4Doc 类的实现
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


// CMFCExp4Doc 构造/析构

CMFCExp4Doc::CMFCExp4Doc():position(stulink.GetHeadPosition()),color(RGB(0,0,0))
{
	// TODO: 在此添加一次性构造代码

}

CMFCExp4Doc::~CMFCExp4Doc()
{
}

BOOL CMFCExp4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCExp4Doc 序列化

void CMFCExp4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CMFCExp4Doc 诊断

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


// CMFCExp4Doc 命令
