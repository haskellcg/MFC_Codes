#pragma once


// MyDialogIn 对话框

class MyDialogIn : public CDialog
{
	DECLARE_DYNAMIC(MyDialogIn)

public:
	MyDialogIn(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialogIn();

// 对话框数据
	enum { IDD = IDD_DIALOG_CIN };

protected:
	HICON hIcon;
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name_In;
	CString m_Stunum_In;
	int m_Age_In;
	double m_English_In;
	double m_Chinese_In;
	double m_Math_In;
	double m_CLPG_In;
	afx_msg void OnBnClickedOk();
};
