// AddStudentDlg.h : header file
//

#if !defined(AFX_ADDSTUDENTDLG_H__01F1EE59_9C0A_4CB4_8ADC_3F34F7012A13__INCLUDED_)
#define AFX_ADDSTUDENTDLG_H__01F1EE59_9C0A_4CB4_8ADC_3F34F7012A13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Add.h"
#include "Query.h"

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg dialog

class CAddStudentDlg : public CDialog
{
// Construction
public:
	CAddStudentDlg(CWnd* pParent = NULL);	// standard constructor

	CAdd m_addstudent;
	CQuery m_query;

// Dialog Data
	//{{AFX_DATA(CAddStudentDlg)
	enum { IDD = IDD_ADDSTUDENT_DIALOG };
	CTabCtrl	m_BackTab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAddStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	//afx_msg void  OnBnClickedButton4();
	//afx_msg void  OnBnClickedButton5();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSTUDENTDLG_H__01F1EE59_9C0A_4CB4_8ADC_3F34F7012A13__INCLUDED_)
