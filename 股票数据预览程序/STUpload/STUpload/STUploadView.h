// STUploadView.h : CSTUploadView ��Ľӿ�
//


#pragma once


class CSTUploadView : public CScrollView
{
protected: // �������л�����
	CSTUploadView();
	DECLARE_DYNCREATE(CSTUploadView)

// ����
public:
	CSTUploadDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSTUploadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // STUploadView.cpp �еĵ��԰汾
inline CSTUploadDoc* CSTUploadView::GetDocument() const
   { return reinterpret_cast<CSTUploadDoc*>(m_pDocument); }
#endif

