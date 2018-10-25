// Query.cpp : implementation file
//

#include "stdafx.h"
#include "AddStudent.h"
#include "Query.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuery dialog


CQuery::CQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuery)
	m_NUM = _T("");
	m_Name=_T("");
	m_Hometown=_T("");
	//}}AFX_DATA_INIT
}


void CQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuery)
	DDX_Control(pDX, IDC_LIST1, m_querylist1);
	DDX_Text(pDX, IDC_EDIT2, m_NUM);
	DDX_Text(pDX, IDC_EDIT1, m_Name);//���������ѯ�������ܺ� ��Ҫ�ڴ���� ��ѯ��ť����Ч
	DDX_Text(pDX, IDC_EDIT6, m_Hometown);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuery, CDialog)
	//{{AFX_MSG_MAP(CQuery)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CQuery::OnLvnItemchangedList1)
	ON_EN_CHANGE(IDC_EDIT1, &CQuery::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CQuery::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT6, &CQuery::OnEnChangeEdit6)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuery message handlers

BOOL CQuery::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_querylist1.SetExtendedStyle(LVS_EX_FLATSB
		|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP
		|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES);
	m_querylist1.InsertColumn(0,"ѧ��",LVCFMT_LEFT,100,0);
	m_querylist1.InsertColumn(1,"����",LVCFMT_LEFT,60,0);
	m_querylist1.InsertColumn(2,"����",LVCFMT_LEFT,50,0);
	m_querylist1.InsertColumn(3,"����",LVCFMT_LEFT,50,0);
	m_querylist1.InsertColumn(4,"������ò",LVCFMT_LEFT,80,0);
	m_querylist1.InsertColumn(5,"���",LVCFMT_LEFT,50,0);
	m_querylist1.InsertColumn(6,"����",LVCFMT_LEFT,50,0);
	m_querylist1.InsertColumn(7,"��ѧ",LVCFMT_LEFT,50,0);
    m_querylist1.InsertColumn(8,"Ӣ��",LVCFMT_LEFT,50,0);
    m_querylist1.InsertColumn(9,"����ϵͳ",LVCFMT_LEFT,80,0);
	m_querylist1.InsertColumn(10,"���ݽṹ",LVCFMT_LEFT,80,0);
	m_querylist1.InsertColumn(11,"�ܷ�",LVCFMT_LEFT,70,0);
	m_querylist1.InsertColumn(12,"��Ȩƽ����",LVCFMT_LEFT,120,0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CQuery::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (m_NUM == ""&&m_Name==""&&m_Hometown=="")
	{
		MessageBox("�������ѯ��Ϣ��");
		return;
	}
	else
	{
		CString sql = "Select * from studentinfo where ѧ�� = '" + m_NUM + "' or ����='"+m_Name+"' or ����='"+m_Hometown+"'";
		m_AdoConn.OnInitADOConn();
		m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);

		if (m_pRs->adoEOF)
		{
			MessageBox("���޴��ˣ����������룡");
			m_AdoConn.ExitConn();
			return;
		}
		else
		{
			CString strNUM = (char*)(_bstr_t)m_pRs->GetCollect("ѧ��");
			CString strName = (char*)(_bstr_t)m_pRs->GetCollect("����");
			CString strAge = (char*)(_bstr_t)m_pRs->GetCollect("����");
			CString strHomeTown = (char*)(_bstr_t)m_pRs->GetCollect("����");
			CString strPolitic = (char*)(_bstr_t)m_pRs->GetCollect("������ò");
			CString strHigh = (char*)(_bstr_t)m_pRs->GetCollect("���");
			CString strWeight = (char*)(_bstr_t)m_pRs->GetCollect("����");
			CString strMath = (char*)(_bstr_t)m_pRs->GetCollect("��ѧ");
			CString strEnglish = (char*)(_bstr_t)m_pRs->GetCollect("Ӣ��");
			CString strOs= (char*)(_bstr_t)m_pRs->GetCollect("����ϵͳ");
			CString strDatabase = (char*)(_bstr_t)m_pRs->GetCollect("���ݽṹ");
			CString strSum= (char*)(_bstr_t)m_pRs->GetCollect("�ܷ�");
			CString strAverage = (char*)(_bstr_t)m_pRs->GetCollect("��Ȩƽ����");
			m_querylist1.DeleteAllItems();
			m_querylist1.InsertItem(0,"");
			m_querylist1.SetItemText(0,0,strNUM);
			m_querylist1.SetItemText(0,1,strName);
			m_querylist1.SetItemText(0,2,strAge);
			m_querylist1.SetItemText(0,3,strHomeTown);
			m_querylist1.SetItemText(0,4,strPolitic);
			m_querylist1.SetItemText(0,5,strHigh);
			m_querylist1.SetItemText(0,6,strWeight);
			m_querylist1.SetItemText(0,7,strMath);
			m_querylist1.SetItemText(0,8,strEnglish);
			m_querylist1.SetItemText(0,9,strOs);
			m_querylist1.SetItemText(0,10,strDatabase);
			m_querylist1.SetItemText(0,11,strSum);
			m_querylist1.SetItemText(0,12,strAverage);
		}
		m_AdoConn.ExitConn();
	}
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_EDIT6)->SetWindowText("");
}

void CQuery::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString sql = "Select * from studentinfo;";
	m_AdoConn.OnInitADOConn();
	m_pRs=m_AdoConn.GetRecordSet((_bstr_t)sql);
	m_querylist1.DeleteAllItems();

	int i=0;
	while(m_pRs->adoEOF==0)
	{
		CString strNUM = (char*)(_bstr_t)m_pRs->GetCollect("ѧ��");
		CString strName = (char*)(_bstr_t)m_pRs->GetCollect("����");
		CString strAge = (char*)(_bstr_t)m_pRs->GetCollect("����");
		CString strHomeTown = (char*)(_bstr_t)m_pRs->GetCollect("����");
		CString strPolitic = (char*)(_bstr_t)m_pRs->GetCollect("������ò");
		CString strHigh = (char*)(_bstr_t)m_pRs->GetCollect("���");
		CString strWeight = (char*)(_bstr_t)m_pRs->GetCollect("����");
		CString strMath = (char*)(_bstr_t)m_pRs->GetCollect("��ѧ");
		CString strEnglish = (char*)(_bstr_t)m_pRs->GetCollect("Ӣ��");
		CString strOs= (char*)(_bstr_t)m_pRs->GetCollect("����ϵͳ");
		CString strDatabase = (char*)(_bstr_t)m_pRs->GetCollect("���ݽṹ");
		CString strSum= (char*)(_bstr_t)m_pRs->GetCollect("�ܷ�");
		CString strAverage = (char*)(_bstr_t)m_pRs->GetCollect("��Ȩƽ����");
		m_querylist1.InsertItem(i,"");
		m_querylist1.SetItemText(i,0,strNUM);
		m_querylist1.SetItemText(i,1,strName);
		m_querylist1.SetItemText(i,2,strAge);
		m_querylist1.SetItemText(i,3,strHomeTown);
		m_querylist1.SetItemText(i,4,strPolitic);
		m_querylist1.SetItemText(i,5,strHigh);
		m_querylist1.SetItemText(i,6,strWeight);
		m_querylist1.SetItemText(i,7,strMath);
		m_querylist1.SetItemText(i,8,strEnglish);
		m_querylist1.SetItemText(i,9,strOs);
		m_querylist1.SetItemText(i,10,strDatabase);
		m_querylist1.SetItemText(i,11,strSum);
		m_querylist1.SetItemText(i,12,strAverage);
		i++;
		m_pRs->MoveNext();
	}

	m_AdoConn.ExitConn();
	GetDlgItem(IDC_EDIT1)->SetWindowText("");
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
	GetDlgItem(IDC_EDIT6)->SetWindowText("");
	
}


void CQuery::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CQuery::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CQuery::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CQuery::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
