#pragma once


// CSaleDetailsDlg �Ի���

class CSaleDetailsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSaleDetailsDlg)

public:
	CSaleDetailsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSaleDetailsDlg();

// �Ի�������
	enum { IDD = IDD_SALEDETAILS_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
