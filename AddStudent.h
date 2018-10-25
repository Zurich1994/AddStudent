// AddStudent.h : main header file for the ADDSTUDENT application
//

#if !defined(AFX_ADDSTUDENT_H__AEE3EDD9_D48C_4344_92E0_08F8D0FA72B0__INCLUDED_)
#define AFX_ADDSTUDENT_H__AEE3EDD9_D48C_4344_92E0_08F8D0FA72B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAddStudentApp:
// See AddStudent.cpp for the implementation of this class
//

class CAddStudentApp : public CWinApp
{
public:
	CAddStudentApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddStudentApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAddStudentApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSTUDENT_H__AEE3EDD9_D48C_4344_92E0_08F8D0FA72B0__INCLUDED_)
