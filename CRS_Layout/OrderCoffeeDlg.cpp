// OrderCoffeeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CRS_Layout.h"
#include "OrderCoffeeDlg.h"
#include "afxdialogex.h"
#include "Robot.h"
#include "Coffee.h"
#include<vector>
#include "delay.h"

#include "ExternValue.h"

extern double LL1;
extern double LL2;

extern double JA1Max;
extern double JA1Zero;
extern double JA1Min;

extern double JA2Max;
extern double JA2Zero;
extern double JA2Min;

Vector2d WF_vx(1, 0), WF_vy(0, 1);
Point wf_origin("wf_origin", 0, 0);

Joint jt1(0, 0, 0, -180, 180, 0), jt2(0, 0, 0, -180, 180, 0); //根据传参数设定
Frame WF("wf", WF_vx, WF_vy, wf_origin);

Robot myRobot(LL1, LL2, jt1, jt2, WF);



// COrderCoffeeDlg 对话框

IMPLEMENT_DYNAMIC(COrderCoffeeDlg, CDialogEx)

COrderCoffeeDlg::COrderCoffeeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderCoffeeDlg::IDD, pParent)
	/*, m_BigCup(false)
	, m_MiddleCup(false)
	, m_SmallCup(false)*/
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
	, m_CupRadio1(0)
	, m_CupRadio2(0)
	, m_CupRadio3(0)
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
	ON_BN_CLICKED(IDC_BIGCUP_RADIO1, &COrderCoffeeDlg::OnBnClickedBigcupRadio1)
END_MESSAGE_MAP()


// COrderCoffeeDlg 消息处理程序


void COrderCoffeeDlg::OnBnClickedOrdercoffeeButton()
{
	// TODO:  在此添加控件通知处理程序代码
	//AppInit();
	
}

void COrderCoffeeDlg::DisplayAngle(Point &prepoint, Point &nowpoint)
{
	double delta1 = (nowpoint.getx()- prepoint.getx()) / 10;
	double delta2 = (nowpoint.gety() - prepoint.gety()) / 10;
	double display_x, display_y;

	display_x = prepoint.getx();
	display_y = prepoint.gety();
	for (int i = 1; i <= 10; i++)
	{
		UpdateData(TRUE);
		display_x = display_x + 1 * delta1;
		display_y = display_y + 1 * delta2;

		
		m_X_Angle = display_x*180/PI;
		m_Y_Angle = display_y*180/PI;
		UpdateData(FALSE);	
		delay(500);		
	}
}





void COrderCoffeeDlg::OnBnClickedConfirmButton3()
{
	// TODO:  在此添加控件通知处理程序代码]
	UpdateData(TRUE);

	Coffee coffee1;
	Point PrePoint;
	double price, price_k, price_type,price_num;


	/**************获取杯型******************/
	Point CupPosition;
	if (((CButton *)GetDlgItem(IDC_BIGCUP_RADIO1))->GetCheck() == TRUE)
	   {
		coffee1.setmycup(Big);
		price_k = 1.2;
		CupPosition = BigCupPos;
	   }
	else if (((CButton *)GetDlgItem(IDC_MIDDLECUP_RADIO2))->GetCheck() == TRUE)
	   {
		coffee1.setmycup(Middle);
		price_k = 1;
		CupPosition = MidCupPos;
	   }
	else if (((CButton *)GetDlgItem(IDC_SMALLCUP_RADIO3))->GetCheck() == TRUE)
	  {
		coffee1.setmycup(Micro);
		price_k = 0.8;
		CupPosition = MicroCupPos;
	  }

	Point CoffeeAddMaterialPos;
	

	Point CoffeeKindsPos;
	/*****************获取咖啡种类*******************/
	if (((CButton *)GetDlgItem(IDC_TPYE1_RADIO4))->GetCheck() == TRUE)
	{
		coffee1.setmycoffeekind(kind1);
		price_type = 15;
		CoffeeKindsPos = Coffeekind1Pos;
	}
	else if (((CButton *)GetDlgItem(IDC_TYPE2_RADIO5))->GetCheck() == TRUE)
	{
		coffee1.setmycoffeekind(kind2);
		price_type = 20;
		CoffeeKindsPos = Coffeekind2Pos;
	}
	else if (((CButton *)GetDlgItem(IDC_TYPE3_RADIO6))->GetCheck() == TRUE)
	{
		coffee1.setmycoffeekind(kind3);
		price_type = 25;
		CoffeeKindsPos = Coffeekind2Pos;
	}

	/**************添加物*********************************/
	//coffee1.setmycoffeeaddmaterial(m_AddMilk, m_AddSugar);
	// 咖啡类 要加数量；
	//做计算
	price_num = m_Num;
	price = price_num*price_k*price_type;
	m_TotalCost = price;
	UpdateData(FALSE);

	/************************取杯子动作*************************************/
	PrePoint = myRobot.getjointframe_angle();
	myRobot.PTPMove(WF, CupPosition);
	m_RobotAction = "正在取杯子...";
	UpdateData(FALSE);
	DisplayAngle(PrePoint, myRobot.getjointframe_angle());
	m_RobotAction = "取杯子完成!";
	UpdateData(FALSE);
	delay(1000);
	/************************选种类动作*************************************/
	PrePoint = myRobot.getjointframe_angle();
	myRobot.PTPMove(WF, CoffeeKindsPos);
	m_RobotAction = "正在选种类...";
	UpdateData(FALSE);
	DisplayAngle(PrePoint, myRobot.getjointframe_angle());
	m_RobotAction = "选种类完成!";
	UpdateData(FALSE);
	delay(1000);

	/************************添加奶*************************************/
	if (m_AddMilk)
	{
		PrePoint = myRobot.getjointframe_angle();
		myRobot.PTPMove(WF, MilkPos);
		m_RobotAction = "正在加奶...";
		UpdateData(FALSE);
		DisplayAngle(PrePoint, myRobot.getjointframe_angle());
		m_RobotAction = "加奶完成!";
		UpdateData(FALSE);
		delay(1000);
	}
	/************************添加糖*************************************/
	if (m_AddSugar)
	{
		PrePoint = myRobot.getjointframe_angle();
		myRobot.PTPMove(WF, SugarPos);
		m_RobotAction = "正在加糖...";
		UpdateData(FALSE);
		DisplayAngle(PrePoint, myRobot.getjointframe_angle());
		m_RobotAction = "加糖完成!";
		UpdateData(FALSE);
		delay(1000);
	}
	m_RobotAction = "您的咖啡已完成!";
	UpdateData(FALSE);
}


void COrderCoffeeDlg::OnBnClickedBigcupRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	
}
