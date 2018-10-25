// Add.cpp : implementation file
//

#include "stdafx.h"
#include "AddStudent.h"
#include "Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdd dialog


CAdd::CAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdd)
	m_Num = _T("");
	m_Name = _T("");
	m_Age = _T("");
	m_HomeTown = _T("");
	m_Politic = _T("");
	m_High = _T("");
	m_Weight = _T("");
	m_Math=_T(NULL);
	m_English=_T(NULL);
	m_Os=_T(NULL);
	m_Database=_T(NULL);
	m_Sum=_T(NULL);
	m_Average=_T(NULL);
	//}}AFX_DATA_INIT
}


void CAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdd)
	DDX_Control(pDX, IDC_LIST1, m_addlist1);
	DDX_Text(pDX, IDC_EDIT1, m_Num);
	DDX_Text(pDX, IDC_EDIT2, m_Name);
	DDX_Text(pDX, IDC_EDIT3, m_Age);
	DDX_Text(pDX, IDC_EDIT4, m_HomeTown);
	DDX_Text(pDX, IDC_EDIT5, m_Politic);
	DDX_Text(pDX, IDC_EDIT6, m_High);
	DDX_Text(pDX, IDC_EDIT7, m_Weight);
	DDX_Text(pDX, IDC_EDIT8, m_Math);
	DDX_Text(pDX, IDC_EDIT9, m_English);
	DDX_Text(pDX, IDC_EDIT10, m_Os);
	DDX_Text(pDX, IDC_EDIT13, m_Database);
	DDX_Text(pDX, IDC_EDIT12, m_Sum);
	DDX_Text(pDX, IDC_EDIT11, m_Average);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdd, CDialog)
	//{{AFX_MSG_MAP(CAdd)
	ON_BN_CLICKED(IDC_Add_Student, OnAddStudent)
	ON_BN_CLICKED(IDC_Del_Student, OnDelStudent)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT5, &CAdd::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT12, &CAdd::OnEnChangeEdit12)
	ON_EN_CHANGE(IDC_EDIT6, &CAdd::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON4, &CAdd::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT8, &CAdd::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT3, &CAdd::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON5, &CAdd::OnBnClickedButton5)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdd message handlers

BOOL CAdd::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdd::OnAddStudent() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_Num == "")
	{
		MessageBox("ѧ�Ų���Ϊ��");
		return;
	}

	if (m_Name == "")
	{
		MessageBox("��������Ϊ��");
		return;
	}

	if (m_Age == "")
	{
		MessageBox("���䲻��Ϊ��");
		return;
	}

	if (m_HomeTown == "")
	{
		MessageBox("���᲻��Ϊ��");
		return;
	}

	if (m_Politic == "")
	{
		MessageBox("������ò����Ϊ��");
		return;
	}

	if (m_High == "")
	{
		MessageBox("��߲���Ϊ��");
		return;
	}

	if (m_Weight == "")
	{
		MessageBox("���ز���Ϊ��");
		return;
	}
	if (m_Math == ' ')
	{
		MessageBox("��ѧ�ɼ������Ϊ��֣�");
		return;
	}
	if (m_English == ' ')
	{
		MessageBox("Ӣ��ɼ������Ϊ��֣�");
		return;
	}
	if (m_Os == ' ')
	{
		MessageBox("����ϵͳ�ɼ������Ϊ��֣�");
		return;
	}
	if (m_Database == ' ')
	{
		MessageBox("���ݿ�ɼ������Ϊ���");
		return;
	}

	CString sql = "Select * from studentinfo where ѧ�� ='" + m_Num + "'";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(!m_pRs->adoEOF)
		{
			AfxMessageBox("��ѧ���Ѵ��ڣ�����ģ�");
			GetDlgItem(IDC_EDIT1)->SetWindowText("");
			GetDlgItem(IDC_EDIT2)->SetWindowText("");
			GetDlgItem(IDC_EDIT3)->SetWindowText("");
			GetDlgItem(IDC_EDIT4)->SetWindowText("");
			GetDlgItem(IDC_EDIT5)->SetWindowText("");
			GetDlgItem(IDC_EDIT6)->SetWindowText("");
        	GetDlgItem(IDC_EDIT7)->SetWindowText("");
			GetDlgItem(IDC_EDIT8)->SetWindowText("");
			GetDlgItem(IDC_EDIT9)->SetWindowText("");
			GetDlgItem(IDC_EDIT10)->SetWindowText("");
			GetDlgItem(IDC_EDIT13)->SetWindowText("");
			m_AdoConn.ExitConn();
			return;
		}
		else
		{
			sql.Format("insert into studentinfo(ѧ��,����,����,����,������ò,���,����,��ѧ,Ӣ��,����ϵͳ,���ݽṹ,�ܷ�,��Ȩƽ����)values('%s','%s','%s','%s','%s','%s','%s','%f','%f','%f','%f','%f','%f')",m_Num,m_Name,m_Age,m_HomeTown,m_Politic,m_High,m_Weight,m_Math,m_English,m_Os,m_Database,m_Sum,m_Average);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConn();
		}
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}	

	MessageBox("��ӳɹ���");
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_EDIT3)->SetWindowText("");
	GetDlgItem(IDC_EDIT4)->SetWindowText("");
	GetDlgItem(IDC_EDIT5)->SetWindowText("");
	GetDlgItem(IDC_EDIT6)->SetWindowText("");
	GetDlgItem(IDC_EDIT7)->SetWindowText("");
    GetDlgItem(IDC_EDIT8)->SetWindowText("");
	GetDlgItem(IDC_EDIT9)->SetWindowText("");
	GetDlgItem(IDC_EDIT10)->SetWindowText("");
	GetDlgItem(IDC_EDIT13)->SetWindowText("");
}

void CAdd::OnDelStudent() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if (m_Num == "")
	{
		MessageBox("ѧ���Ǳ����");
		return;
	}

	CString sql = "Select * from studentinfo where ѧ�� ='" + m_Num + "'";
	try
	{
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
		if(m_pRs->adoEOF)
		{
			AfxMessageBox("��ѧ�Ų����ڣ��޷�ɾ����");
			GetDlgItem(IDC_EDIT1)->SetWindowText("");
			GetDlgItem(IDC_EDIT2)->SetWindowText("");
			GetDlgItem(IDC_EDIT3)->SetWindowText("");
			GetDlgItem(IDC_EDIT4)->SetWindowText("");
			GetDlgItem(IDC_EDIT5)->SetWindowText("");
			GetDlgItem(IDC_EDIT6)->SetWindowText("");
			GetDlgItem(IDC_EDIT7)->SetWindowText("");
		    GetDlgItem(IDC_EDIT8)->SetWindowText("");
	        GetDlgItem(IDC_EDIT9)->SetWindowText("");
	        GetDlgItem(IDC_EDIT10)->SetWindowText("");
	        GetDlgItem(IDC_EDIT13)->SetWindowText("");
			m_AdoConn.ExitConn();
			return;
		}
		else
		{
			sql = "delete from studentinfo where ѧ�� = '" + m_Num + "'";
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConn();
		}
	}
	catch(...)
	{
		AfxMessageBox("����ʧ��");
		return;
	}	
	
	MessageBox("ɾ���ɹ���");
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_EDIT3)->SetWindowText("");
	GetDlgItem(IDC_EDIT4)->SetWindowText("");
	GetDlgItem(IDC_EDIT5)->SetWindowText("");
	GetDlgItem(IDC_EDIT6)->SetWindowText("");
	GetDlgItem(IDC_EDIT7)->SetWindowText("");
    GetDlgItem(IDC_EDIT8)->SetWindowText("");
	GetDlgItem(IDC_EDIT9)->SetWindowText("");
	GetDlgItem(IDC_EDIT10)->SetWindowText("");
	GetDlgItem(IDC_EDIT13)->SetWindowText("");
}


void CAdd::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::OnEnChangeEdit12()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::OnBnClickedButton4()
{
	UpdateData(TRUE);   
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Sum=m_Math+m_English+m_Os+m_Database;
    UpdateData(FALSE); 
}


void CAdd::OnEnChangeEdit8()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAdd::OnBnClickedButton5()
{
    UpdateData(TRUE);   
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Average=(m_Math*1.5+m_English*2.0+m_Os*3.5+m_Database*1.5)/8.5;
	UpdateData(FALSE); 
}
