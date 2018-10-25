; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAdd
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AddStudent.h"

ClassCount=5
Class1=CAddStudentApp
Class2=CAddStudentDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_Query
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_ADDSTUDENT_DIALOG
Class4=CAdd
Class5=CQuery
Resource5=IDD_Add

[CLS:CAddStudentApp]
Type=0
HeaderFile=AddStudent.h
ImplementationFile=AddStudent.cpp
Filter=N

[CLS:CAddStudentDlg]
Type=0
HeaderFile=AddStudentDlg.h
ImplementationFile=AddStudentDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CAddStudentDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=AddStudentDlg.h
ImplementationFile=AddStudentDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADDSTUDENT_DIALOG]
Type=1
Class=CAddStudentDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_Add]
Type=1
Class=CAdd
ControlCount=16
Control1=IDC_Add_Student,button,1342242816
Control2=IDC_Del_Student,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_EDIT5,edit,1350631552
Control10=IDC_EDIT6,edit,1350631552
Control11=IDC_EDIT7,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352

[DLG:IDD_Query]
Type=1
Class=CQuery
ControlCount=5
Control1=IDC_EDIT2,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_LIST1,SysListView32,1350631425
Control5=IDC_BUTTON2,button,1342242816

[CLS:CAdd]
Type=0
HeaderFile=Add.h
ImplementationFile=Add.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAdd

[CLS:CQuery]
Type=0
HeaderFile=Query.h
ImplementationFile=Query.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CQuery

