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
};
