#if !defined(AFX_ADD_H__E16BD90C_944E_4027_A630_2478AD7502AC__INCLUDED_)
#define AFX_ADD_H__E16BD90C_944E_4027_A630_2478AD7502AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Add.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdd dialog

#include "ADOConn.h"

class CAdd : public CDialog
{
// Construction
public:
	CAdd(CWnd* pParent = NULL);   // standard constructor

	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;

// Dialog Data
	//{{AFX_DATA(CAdd)
	enum { IDD = IDD_Add };
	CListCtrl	m_addlist1;
	CString	m_Num;
	CString	m_Name;
	CString	m_Age;
	CString	m_HomeTown;
	CString	m_Politic;
	CString	m_High;
	CString	m_Weight;
	double  m_Math;
	double	m_English;
	double	m_Os;
	double 	m_Database;
	double  m_Sum;
	double  m_Average;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdd)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddStudent();
	afx_msg void OnDelStudent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton5();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADD_H__E16BD90C_944E_4027_A630_2478AD7502AC__INCLUDED_)
