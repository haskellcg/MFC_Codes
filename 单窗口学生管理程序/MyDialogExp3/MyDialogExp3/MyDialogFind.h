#pragma once
#include "afxwin.h"


// MyDialogFind �Ի���

class MyDialogFind : public CDialog
{
	DECLARE_DYNAMIC(MyDialogFind)

public:
	MyDialogFind(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialogFind();

// �Ի�������
	enum { IDD = IDD_DIALOG_FIND };

protected:
	HICON hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
