// MFCExp4Doc.h : CMFCExp4Doc ��Ľӿ�
//


#pragma once
#include "StudentLinkTB.h"

class CMFCExp4Doc : public CDocument
{
protected: // �������л�����
	CMFCExp4Doc();
	DECLARE_DYNCREATE(CMFCExp4Doc)

// ����
public:
		StudentLinkTB stulink;
		POSITION     position;
		COLORREF     color;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMFCExp4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


