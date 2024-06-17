
// CaculatorDlg.h: 头文件
//

#pragma once


// CCaculatorDlg 对话框
class CCaculatorDlg : public CDialogEx
{
// 构造
public:
	CCaculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CACULATOR_DIALOG };
#endif

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
	afx_msg void OnBnClickedCaculate();
	/// <summary>
	/// 计算式(CString)
	/// </summary>
	CString Caculation;
	/// <summary>
	/// 计算式(string)
	/// </summary>
	std::string caculation;
	/// <summary>
	/// 结果(double)
	/// </summary>
	double result;
	/// <summary>
	/// 最后一个添加的字符(char)
	/// </summary>
	char lastc;
	CString Result_UI;
	afx_msg void OnEnChangeCalculations();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedEmp();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedBrack();
	afx_msg void OnBnClickedBra();
};
