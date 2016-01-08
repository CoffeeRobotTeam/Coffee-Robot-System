// OrderCoffeeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CRS_Layout.h"
#include "OrderCoffeeDlg.h"
#include "afxdialogex.h"
#include "Robot.h"
#include "Coffee.h"
#include "AppInit.h"
#include<vector>


// COrderCoffeeDlg 对话框

IMPLEMENT_DYNAMIC(COrderCoffeeDlg, CDialogEx)

COrderCoffeeDlg::COrderCoffeeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderCoffeeDlg::IDD, pParent)
	, m_BigCup(false)
	, m_MiddleCup(false)
	, m_SmallCup(false)
	, m_Type1(false)
	, m_Type2(false)
	, m_Tpye3(false)
	, m_AddSugar(FALSE)
	, m_AddMilk(FALSE)
	, m_Num(0)
	, m_TotalCost(0)
	, m_RobotAction(_T(""))
	, m_X_Angle(0)
	, m_Y_Angle(0)
{

}

COrderCoffeeDlg::~COrderCoffeeDlg()
{
}

void COrderCoffeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_ADDSUGAR_CHECK1, m_AddSugar);
	DDX_Check(pDX, IDC_ADDMILK_CHECK2, m_AddMilk);
	DDX_Text(pDX, IDC_SUM_EDIT1, m_Num);
	DDV_MinMaxInt(pDX, m_Num, 1, 20);
	DDX_Text(pDX, IDC_TOTALCOST_EDIT2, m_TotalCost);
	DDV_MinMaxDouble(pDX, m_TotalCost, 0, 10000);
	DDX_Text(pDX, IDC_NUM_EDIT1, m_Num);
	DDX_Text(pDX, IDC_ROBOTACTION_EDIT1, m_RobotAction);
	DDX_Text(pDX, IDC_X_ANGLE_EDIT2, m_X_Angle);
	DDX_Text(pDX, IDC_Y_ANGLE_EDIT3, m_Y_Angle);
}


BEGIN_MESSAGE_MAP(COrderCoffeeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ORDERCOFFEE_BUTTON, &COrderCoffeeDlg::OnBnClickedOrdercoffeeButton)
	ON_BN_CLICKED(IDC_Confirm_BUTTON3, &COrderCoffeeDlg::OnBnClickedConfirmButton3)
END_MESSAGE_MAP()


// COrderCoffeeDlg 消息处理程序


void COrderCoffeeDlg::OnBnClickedOrdercoffeeButton()
{
	// TODO:  在此添加控件通知处理程序代码
	//AppInit();
	
}


void COrderCoffeeDlg::OnBnClickedConfirmButton3()
{
	// TODO:  在此添加控件通知处理程序代码]
	UpdateData(TRUE);

	vector<Coffee> coffeevector;
	Coffee  coffee1; //最好用动态内存分配；
	
	/****************************
	coffee1.setmycup();  

	coffee1.setmycoffeekind(kindA);  //直接用判断

	coffee1.setmycoffeeaddmaterial(m_AddSugar, m_AddMilk);

	// 咖啡类 要加数量；

	//做计算

	/*********机器人运动，还需设置机器人手臂长度、关节转角范围、零点**********************/
    
	/*********杯子的位置、种类 、添加的坐标设置*******************************************

	
	Vector2d WF_vx(1, 0), WF_vy(0, 1);
	Point wf_origin("wf_origin", 0, 0);

	Joint jt1(0, 0, 0, -180, 180, 0), jt2(l1, 0, 0, -180, 180, 0); //根据传参数设定
	Frame WF("wf", WF_vx, WF_vy, wf_origin);
	Robot myRobot(l1, l2, jt1, jt2, WF);
	
	myRobot.PTPMove(WF, ());
	m_X_Angle = myRobot.getjoint1().gettheta();
	m_Y_Angle = myRobot.getjoint2().gettheta();
    
	********************************/
}
