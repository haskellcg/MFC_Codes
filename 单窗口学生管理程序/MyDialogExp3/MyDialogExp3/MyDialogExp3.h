// MyDialogExp3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyDialogExp3App:
// �йش����ʵ�֣������ MyDialogExp3.cpp
//

class CMyDialogExp3App : public CWinApp
{
public:
	CMyDialogExp3App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyDialogExp3App theApp;