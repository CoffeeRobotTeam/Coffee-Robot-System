#pragma once


// COrderCoffeeDlg �Ի���

class COrderCoffeeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderCoffeeDlg)

public:
	COrderCoffeeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COrderCoffeeDlg();

// �Ի�������
	enum { IDD = IDD_ORDERCOFFEE_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOrdercoffeeButton();
	bool m_BigCup;
	bool m_MiddleCup;
	bool m_SmallCup;
	bool m_Type1;
	bool m_Type2;
	bool m_Tpye3;
	BOOL m_AddSugar;
	BOOL m_AddMilk;
//	int m_Num;
	double m_TotalCost;
	int m_Num;
	afx_msg void OnBnClickedConfirmButton3();
	CString m_RobotAction;
	double m_X_Angle;
	double m_Y_Angle;
};
