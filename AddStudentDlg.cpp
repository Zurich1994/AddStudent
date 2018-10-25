// AddStudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AddStudent.h"
#include "AddStudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg dialog

CAddStudentDlg::CAddStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddStudentDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CAddStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddStudentDlg)
	DDX_Control(pDX, IDC_TAB1, m_BackTab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAddStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CAddStudentDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg message handlers

BOOL CAddStudentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_BackTab.InsertItem(0,"添加");
	m_BackTab.InsertItem(1,"查询");
	
	m_addstudent.Create(IDD_Add,GetDlgItem(IDC_TAB1));
	m_query.Create(IDD_Query,GetDlgItem(IDC_TAB1));
	
	//位置设置
	CRect rect;
	m_BackTab.GetClientRect(rect);
 	rect.top += 20;
// 	rect.bottom -= 4;
// 	rect.left += 4;
// 	rect.right -= 4;
	
	m_addstudent.MoveWindow(rect);
	m_query.MoveWindow(rect);
	
	m_addstudent.ShowWindow(TRUE);
	m_query.ShowWindow(FALSE);
	
	m_BackTab.SetCurSel(0);


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAddStudentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAddStudentDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAddStudentDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAddStudentDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nCurSel = m_BackTab.GetCurSel();
	

	switch(nCurSel)
	{
	case 0:
		m_addstudent.ShowWindow(TRUE);
		m_query.ShowWindow(FALSE);
		
		break;
	case 1:
		m_addstudent.ShowWindow(FALSE);
		m_query.ShowWindow(TRUE);
		m_query.m_querylist1.DeleteAllItems();
		m_query.GetDlgItem(IDC_EDIT2)->SetWindowText("");
		

	}
	*pResult = 0;
}
