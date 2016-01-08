#pragma once


// CSaleDetailsDlg 对话框

class CSaleDetailsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSaleDetailsDlg)

public:
	CSaleDetailsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSaleDetailsDlg();

// 对话框数据
	enum { IDD = IDD_SALEDETAILS_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
