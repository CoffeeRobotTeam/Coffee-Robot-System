// SetRobotDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CRS_Layout.h"
#include "SetRobotDlg.h"
#include "afxdialogex.h"
#include "Robot.h"

extern Robot myRobot;

double LL1=300;
double LL2=500;

double JA1Max=180;
double JA1Zero=0;
double JA1Min=-180;

double JA2Max=180;
double JA2Zero=0;
double JA2Min=-180;

// CSetRobotDlg 对话框

IMPLEMENT_DYNAMIC(CSetRobotDlg, CDialogEx)

CSetRobotDlg::CSetRobotDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetRobotDlg::IDD, pParent)
	, m_LegLength1(300)
	, m_LegLength2(500)
	, m_Joint1Max(180)
	, m_Joint1Min(-180)
	, m_Joint1Zero(0)
	, m_Joint2Min(-180)
	, m_Joint2Zero(0)
	, m_Joint2Max(180)
{

}

CSetRobotDlg::~CSetRobotDlg()
{
}

void CSetRobotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LEGLENGTH1_EDIT1, m_LegLength1);
	DDV_MinMaxDouble(pDX, m_LegLength1, 0, 2000);
	DDX_Text(pDX, IDC_LEGLENGTH2_EDIT2, m_LegLength2);
	DDV_MinMaxDouble(pDX, m_LegLength2, 0, 2000);
	DDX_Text(pDX, IDC_JOINT1_ZERO_EDIT4, m_Joint1Zero);
	DDX_Text(pDX, IDC_JOINT2_MIN_EDIT6, m_Joint2Min);
	DDX_Text(pDX, IDC_JOINT2_ZERO_EDIT7, m_Joint2Zero);
	DDX_Text(pDX, IDC_JOINT2_MAX_EDIT8, m_Joint2Max);
	DDX_Text(pDX, IDC_JOINT1_MIN_EDIT1, m_Joint1Min);
	DDX_Text(pDX, IDC_JOINT1_MAX_EDIT3, m_Joint1Max);
}


BEGIN_MESSAGE_MAP(CSetRobotDlg, CDialogEx)
	ON_EN_CHANGE(IDC_JOINT1_MAX_EDIT3, &CSetRobotDlg::OnEnChangeJoint1MaxEdit5)
	ON_BN_CLICKED(IDC_APPLYCHANGE_BUTTON1, &CSetRobotDlg::OnBnClickedApplychangeButton1)
END_MESSAGE_MAP()


// CSetRobotDlg 消息处理程序


void CSetRobotDlg::OnBnClickedApplychangeButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);

	LL1 = m_LegLength1;
	LL2 = m_LegLength2;

	JA1Max = m_Joint1Max;
	JA1Zero = m_Joint1Zero;
	JA1Min = m_Joint1Min;

	JA2Max = m_Joint2Max;
	JA2Zero = m_Joint2Zero;
	JA2Min = m_Joint2Min;

	myRobot.setlength1(LL1);
	myRobot.setlength2(LL2);
	UpdateData(FALSE);
	
}


void CSetRobotDlg::OnEnChangeJoint1MaxEdit5()
{
	// TODO:  在此添加控件通知处理程序代码


}