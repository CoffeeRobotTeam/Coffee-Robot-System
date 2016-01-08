// SaleDetailsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CRS_Layout.h"
#include "SaleDetailsDlg.h"
#include "afxdialogex.h"


// CSaleDetailsDlg 对话框

IMPLEMENT_DYNAMIC(CSaleDetailsDlg, CDialogEx)

CSaleDetailsDlg::CSaleDetailsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSaleDetailsDlg::IDD, pParent)
{

}

CSaleDetailsDlg::~CSaleDetailsDlg()
{
}

void CSaleDetailsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSaleDetailsDlg, CDialogEx)
END_MESSAGE_MAP()


// CSaleDetailsDlg 消息处理程序
