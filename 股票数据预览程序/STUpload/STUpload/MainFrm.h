// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once
#include "FUNDDIALOG.h"
#include "StockDataList.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
protected:
	CFUNDDIALOG m_wndFundDialog;
	bool        m_bFundVisible;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// ���ɵ���Ϣӳ�亯��
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


