// MyDialogExp1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMyDialogExp1Dlg �Ի���
class CMyDialogExp1Dlg : public CDialog
{
// ����
public:
	CMyDialogExp1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYDIALOGEXP1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
