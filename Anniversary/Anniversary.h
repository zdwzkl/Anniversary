
// Anniversary.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAnniversaryApp: 
// �йش����ʵ�֣������ Anniversary.cpp
//

class CAnniversaryApp : public CWinApp
{
public:
	CAnniversaryApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAnniversaryApp theApp;