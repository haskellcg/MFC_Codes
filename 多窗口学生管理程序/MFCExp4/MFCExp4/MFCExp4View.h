// MFCExp4View.h : CMFCExp4View 类的接口
//


#pragma once


class CMFCExp4View : public CView
{
protected: // 仅从序列化创建
	CMFCExp4View();
	DECLARE_DYNCREATE(CMFCExp4View)

// 属性
public:
	CMFCExp4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCExp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFCExp4View.cpp 中的调试版本
inline CMFCExp4Doc* CMFCExp4View::GetDocument() const
   { return reinterpret_cast<CMFCExp4Doc*>(m_pDocument); }
#endif

