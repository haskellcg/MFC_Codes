// MFCExp4.h : MFCExp4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCExp4App:
// �йش����ʵ�֣������ MFCExp4.cpp
//

class CMFCExp4App : public CWinApp
{
public:
	CMFCExp4App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCExp4App theApp;