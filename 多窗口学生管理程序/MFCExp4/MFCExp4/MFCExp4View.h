// MFCExp4View.h : CMFCExp4View ��Ľӿ�
//


#pragma once


class CMFCExp4View : public CView
{
protected: // �������л�����
	CMFCExp4View();
	DECLARE_DYNCREATE(CMFCExp4View)

// ����
public:
	CMFCExp4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFCExp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNewstudent();
	afx_msg void OnLoad();
	afx_msg void OnStore();
	afx_msg void OnPrev();
	afx_msg void OnNext();
	afx_msg void OnStart();
	afx_msg void OnEnd();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnMore();
};

#ifndef _DEBUG  // MFCExp4View.cpp �еĵ��԰汾
inline CMFCExp4Doc* CMFCExp4View::GetDocument() const
   { return reinterpret_cast<CMFCExp4Doc*>(m_pDocument); }
#endif

