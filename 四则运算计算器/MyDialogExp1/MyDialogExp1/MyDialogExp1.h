// MyDialogExp1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyDialogExp1App:
// �йش����ʵ�֣������ MyDialogExp1.cpp
//

class CMyDialogExp1App :public CWinApp
{
public:
	CMyDialogExp1App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyDialogExp1App theApp;