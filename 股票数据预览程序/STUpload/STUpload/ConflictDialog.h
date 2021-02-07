#pragma once
#include "afxcmn.h"


// CConflictDialog 对话框

class CConflictDialog : public CDialog
{
	DECLARE_DYNAMIC(CConflictDialog)

public:
	CConflictDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConflictDialog();

// 对话框数据
	enum { IDD = IDD_CONFLICT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAbort();
	CString m_REditText;
};
