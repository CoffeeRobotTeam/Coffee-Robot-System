#pragma once


// CSetRobotDlg �Ի���

class CSetRobotDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetRobotDlg)

public:
	CSetRobotDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetRobotDlg();

// �Ի�������
	enum { IDD = IDD_SETROBOT_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	double m_LegLength1;
	double m_LegLength2;
//	double m_Joint1Max;
	afx_msg void OnEnChangeJoint1MaxEdit5();
//	double m_Joint1Min;
	double m_Joint1Zero;
	double m_Joint2Min;
	double m_Joint2Zero;
	double m_Joint2Max;
	afx_msg void OnBnClickedApplychangeButton1();
	double m_Joint1Min;
	double m_Joint1Max;
};
