#pragma once
#include "afxwin.h"


// CFUNDDIALOG �Ի���

class CFUNDDIALOG : public CDialog
{
	DECLARE_DYNAMIC(CFUNDDIALOG)

public:
	CFUNDDIALOG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFUNDDIALOG();

// �Ի�������
	enum { IDD = IDD_FUNDDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnLbnSelchangeFundlist();
};
