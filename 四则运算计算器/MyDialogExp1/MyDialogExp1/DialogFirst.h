#pragma once


// DialogFirst �Ի���
#include "resource.h"

class DialogFirst : public CDialog
{
	DECLARE_DYNAMIC(DialogFirst)

public:
	DialogFirst(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DialogFirst();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
public:
	afx_msg void OnPaint();
	

	DECLARE_MESSAGE_MAP()
};
