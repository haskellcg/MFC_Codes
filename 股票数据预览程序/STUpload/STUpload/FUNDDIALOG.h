#pragma once
#include "afxwin.h"


// CFUNDDIALOG 对话框

class CFUNDDIALOG : public CDialog
{
	DECLARE_DYNAMIC(CFUNDDIALOG)

public:
	CFUNDDIALOG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFUNDDIALOG();

// 对话框数据
	enum { IDD = IDD_FUNDDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeFundlist();
};
