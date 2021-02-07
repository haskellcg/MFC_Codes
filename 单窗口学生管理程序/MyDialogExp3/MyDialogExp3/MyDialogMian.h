#pragma once
#include "StudentLinkTB.h"

// MyDialogMian 对话框

class MyDialogMian : public CDialog
{
	DECLARE_DYNAMIC(MyDialogMian)

public:
	MyDialogMian(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MyDialogMian();

// 对话框数据
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	HICON hIcon;
	virtual BOOL OnInitDialog();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name_Out;
	CString m_Stunum_Out;
	int m_Age_Out;
	double m_English_Out;
	double m_Chinese_Out;
	double m_Math_Out;
	double m_CLPG_Out;
	double m_Everage_Out;

public:
	StudentLinkTB stulink;
	POSITION      position;
public:
	afx_msg void OnBnClickedButtonIn();
	afx_msg void OnBnClickedButtonWrite();
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedHead();
	afx_msg void OnBnClickedTail();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedPrev();
	afx_msg void OnBnClickedButtonFind();
};
