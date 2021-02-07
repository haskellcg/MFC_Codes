// MyDialogExp1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMyDialogExp1Dlg 对话框
class CMyDialogExp1Dlg : public CDialog
{
// 构造
public:
	CMyDialogExp1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYDIALOGEXP1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double result;
	double number_one;
	double number_two;

	CButton m_YS_Ctrl;

	CComboBox m_Combobox_Ctrl;
	CString m_Combobox;

	CEdit m_EDIT1_Ctrl;
	CEdit m_EDIT2_Ctrl;


	afx_msg void OnBnClickedButtonYs();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnOK();
	afx_msg void OnCbnSelchangeCombo1();
};
