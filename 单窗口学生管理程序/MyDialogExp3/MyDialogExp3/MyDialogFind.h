#pragma once
#include "afxwin.h"


// MyDialogFind 对话框

class MyDialogFind : public CDialog
{
	DECLARE_DYNAMIC(MyDialogFind)

public:
	MyDialogFind(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialogFind();

// 对话框数据
	enum { IDD = IDD_DIALOG_FIND };

protected:
	HICON hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int flag;
	CString m_Name_Find;
	CString m_Stunum_Find;
	CEdit m_Name_Find_Ctrl;
	CEdit m_Stunum_Find_Ctrl;
	afx_msg void OnBnClickedRadioName();
	afx_msg void OnBnClickedRadioStunum();
	afx_msg void OnBnClickedOk();
};
