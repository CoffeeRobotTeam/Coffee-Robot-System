
// CRS_LayoutDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "OrderCoffeeDlg.h"
#include "SaleDetailsDlg.h"
#include "SetRobotDlg.h"


// CCRS_LayoutDlg �Ի���
class CCRS_LayoutDlg : public CDialogEx
{
// ����

private:
	COrderCoffeeDlg m_ordercoffeeDlg;
	CSetRobotDlg    m_setrobotDlg;
	CSaleDetailsDlg m_saledetailsDlg;


public:
	CCRS_LayoutDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CRS_LAYOUT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
