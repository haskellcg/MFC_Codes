#pragma once
#include "afxcmn.h"


// CConflictDialog �Ի���

class CConflictDialog : public CDialog
{
	DECLARE_DYNAMIC(CConflictDialog)

public:
	CConflictDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConflictDialog();

// �Ի�������
	enum { IDD = IDD_CONFLICT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAbort();
	CString m_REditText;
};
