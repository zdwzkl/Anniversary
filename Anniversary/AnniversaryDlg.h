
// AnniversaryDlg.h : ͷ�ļ�
//

#pragma once


// CAnniversaryDlg �Ի���
class CAnniversaryDlg : public CDialogEx
{
// ����
public:
	CAnniversaryDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ANNIVERSARY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
    void RefreshTime();

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

    CTime m_timeStart;
    CTime m_timeGirlFriend;
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
