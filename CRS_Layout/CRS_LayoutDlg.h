
// CRS_LayoutDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#include "OrderCoffeeDlg.h"
#include "SaleDetailsDlg.h"
#include "SetRobotDlg.h"


// CCRS_LayoutDlg 对话框
class CCRS_LayoutDlg : public CDialogEx
{
// 构造

private:
	COrderCoffeeDlg m_ordercoffeeDlg;
	CSetRobotDlg    m_setrobotDlg;
	CSaleDetailsDlg m_saledetailsDlg;


public:
	CCRS_LayoutDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CRS_LAYOUT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
