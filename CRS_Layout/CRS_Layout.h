
// CRS_Layout.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCRS_LayoutApp: 
// �йش����ʵ�֣������ CRS_Layout.cpp
//

class CCRS_LayoutApp : public CWinApp
{
public:
	CCRS_LayoutApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCRS_LayoutApp theApp;