#if !defined(AFX_QUERY_H__23869FF9_B070_4290_A5FE_8ED34395036C__INCLUDED_)
#define AFX_QUERY_H__23869FF9_B070_4290_A5FE_8ED34395036C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Query.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQuery dialog

#include "ADOConn.h"

class CQuery : public CDialog
{
// Construction
public:
	CQuery(CWnd* pParent = NULL);   // standard constructor

	_RecordsetPtr m_pRs;
	ADOConn m_AdoConn;

// Dialog Data
	//{{AFX_DATA(CQuery)
	enum { IDD = IDD_Query };
	CListCtrl	m_querylist1;
	CString	m_NUM;
	CString	m_Name;
	CString	m_Hometown;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQuery)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit6();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERY_H__23869FF9_B070_4290_A5FE_8ED34395036C__INCLUDED_)
