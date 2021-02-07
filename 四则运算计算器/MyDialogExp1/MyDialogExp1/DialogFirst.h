#pragma once


// DialogFirst 对话框
#include "resource.h"

class DialogFirst : public CDialog
{
	DECLARE_DYNAMIC(DialogFirst)

public:
	DialogFirst(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DialogFirst();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
public:
	afx_msg void OnPaint();
	

	DECLARE_MESSAGE_MAP()
};
