// STUpload.h : STUpload Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CSTUploadApp:
// �йش����ʵ�֣������ STUpload.cpp
//

class CSTUploadApp : public CWinApp
{
public:
	CSTUploadApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSTUploadApp theApp;