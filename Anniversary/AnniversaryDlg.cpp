
// AnniversaryDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Anniversary.h"
#include "AnniversaryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnniversaryDlg 对话框



CAnniversaryDlg::CAnniversaryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAnniversaryDlg::IDD, pParent)
    , m_timeStart(2015, 4, 20, 8, 57, 4)
    , m_timeGirlFriend(2015, 5, 17 ,0 , 0, 0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnniversaryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAnniversaryDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDCANCEL, &CAnniversaryDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDOK, &CAnniversaryDlg::OnBnClickedOk)
    ON_WM_TIMER()
END_MESSAGE_MAP()


// CAnniversaryDlg 消息处理程序

BOOL CAnniversaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

    RefreshTime();
    SetTimer(1, 500, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAnniversaryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAnniversaryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAnniversaryDlg::OnBnClickedCancel()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnCancel();
}


void CAnniversaryDlg::OnBnClickedOk()
{
    // TODO: Add your control notification handler code here
    CDialogEx::OnOK();
}

void CAnniversaryDlg::RefreshTime()
{
    CString strTime;
    CString strTimeGirlFriend;

    CTime timeNow = CTime::GetCurrentTime();
    CTimeSpan timeSpan = timeNow - m_timeStart;

    int nDays = timeSpan.GetDays();
    int nHours = timeSpan.GetHours();
    int nMins = timeSpan.GetMinutes();
    int nSecs = timeSpan.GetSeconds();

    strTime.Format(_T("%d天%02d小时%02d分%02d秒"), nDays, nHours, nMins, nSecs);



    CTimeSpan timeSpanGirlFriend= timeNow - m_timeGirlFriend;

    int nDays2 = timeSpanGirlFriend.GetDays();
    int nHours2 = timeSpanGirlFriend.GetHours();
    int nMins2 = timeSpanGirlFriend.GetMinutes();
    int nSecs2 = timeSpanGirlFriend.GetSeconds();

    strTimeGirlFriend.Format(_T("%d天%02d小时%02d分%02d秒"),
        nDays2, nHours2, nMins2, nSecs2);

    GetDlgItem(IDC_TIME_RESULT)->SetWindowText(strTime);
    GetDlgItem(IDC_TIME_RESULT_GIRL_FRIEND)->SetWindowText(strTimeGirlFriend);
}


void CAnniversaryDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
    RefreshTime();
    CDialogEx::OnTimer(nIDEvent);
}
