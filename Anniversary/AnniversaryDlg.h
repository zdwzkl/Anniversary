
// AnniversaryDlg.h : 头文件
//

#pragma once


// CAnniversaryDlg 对话框
class CAnniversaryDlg : public CDialogEx
{
// 构造
public:
	CAnniversaryDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ANNIVERSARY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
    void RefreshTime();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

    CTime m_timeStart;
    CTime m_timeGirlFriend;
public:
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
