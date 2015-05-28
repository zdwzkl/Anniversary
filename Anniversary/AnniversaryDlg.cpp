
// AnniversaryDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Anniversary.h"
#include "AnniversaryDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnniversaryDlg �Ի���



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


// CAnniversaryDlg ��Ϣ�������

BOOL CAnniversaryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

    RefreshTime();
    SetTimer(1, 500, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAnniversaryDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

    strTime.Format(_T("%d��%02dСʱ%02d��%02d��"), nDays, nHours, nMins, nSecs);



    CTimeSpan timeSpanGirlFriend= timeNow - m_timeGirlFriend;

    int nDays2 = timeSpanGirlFriend.GetDays();
    int nHours2 = timeSpanGirlFriend.GetHours();
    int nMins2 = timeSpanGirlFriend.GetMinutes();
    int nSecs2 = timeSpanGirlFriend.GetSeconds();

    strTimeGirlFriend.Format(_T("%d��%02dСʱ%02d��%02d��"),
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
