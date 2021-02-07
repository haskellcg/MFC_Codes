// MainFrm.h : CMainFrame 类的接口
//


#pragma once
#include "FUNDDIALOG.h"
#include "StockDataList.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
protected:
	CFUNDDIALOG m_wndFundDialog;
	bool        m_bFundVisible;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:

	bool AreFundVisible(void)
	{
		return m_bFundVisible;
	}
	void SetFundVisible(bool bSet)
	{
		m_bFundVisible=bSet;
		if(bSet)
		{
			m_wndFundDialog.ShowWindow(SW_SHOW);
		}
		else
		{
			m_wndFundDialog.ShowWindow(SW_HIDE);
		}
	}
	afx_msg void OnViewFund();
	afx_msg void OnUpdateViewFund(CCmdUI *pCmdUI);
	void UpdateFundList(const CStockDataList& pList,CString strCurrentFund = _T(""));
	afx_msg void OnActivateApp(BOOL bActive, DWORD dwThreadID);
};


