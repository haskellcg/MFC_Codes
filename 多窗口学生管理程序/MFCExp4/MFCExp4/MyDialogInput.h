#pragma once


// MyDialogInput �Ի���

class MyDialogInput : public CDialog
{
	DECLARE_DYNAMIC(MyDialogInput)

public:
	MyDialogInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialogInput();

// �Ի�������
	enum { IDD = IDD_DIALOG_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name_In;
	CString m_Stunum_In;
	int m_Age_In;
	double m_English_In;
	double m_Math_In;
	double m_Chinese_In;
	double m_CLPG_In;
	afx_msg void OnBnClickedOk();
};
