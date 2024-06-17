
// CaculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Caculator.h"
#include "CaculatorDlg.h"
#include "afxdialogex.h"

//自己定义的类
#include "caculate.h"//计算
#include "invert.h"//转换
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCaculatorDlg 对话框



CCaculatorDlg::CCaculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CACULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Calculations, Caculation);
}

BEGIN_MESSAGE_MAP(CCaculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Caculate, &CCaculatorDlg::OnBnClickedCaculate)
	ON_BN_CLICKED(NUM_0, &CCaculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(NUM_1, &CCaculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(NUM_2, &CCaculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(NUM_3, &CCaculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(NUM_4, &CCaculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(NUM_5, &CCaculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(NUM_6, &CCaculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(NUM_7, &CCaculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(NUM_8, &CCaculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(NUM_9, &CCaculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(ADD, &CCaculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(SUB, &CCaculatorDlg::OnBnClickedSub)
	ON_BN_CLICKED(MUL, &CCaculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(DIV, &CCaculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(DOT, &CCaculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(EMP, &CCaculatorDlg::OnBnClickedEmp)
	ON_BN_CLICKED(PERCENT, &CCaculatorDlg::OnBnClickedPercent)
	ON_BN_CLICKED(BACKSPACE, &CCaculatorDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(RIGHT_BRACK, &CCaculatorDlg::OnBnClickedBrack)
	ON_BN_CLICKED(LEFT_BRA, &CCaculatorDlg::OnBnClickedBra)
END_MESSAGE_MAP()


// CCaculatorDlg 消息处理程序

BOOL CCaculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCaculatorDlg::OnPaint()
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
HCURSOR CCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCaculatorDlg::OnBnClickedCaculate()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	caculation = CStringToStdString(Caculation);
	if (!isLegally(caculation))
	{
		Caculation = _T("计算式错误");
		UpdateData(false);
		Caculation = "";
		return;
	}
	if (isNum(caculation))
	{
		Caculation = "";
		UpdateData(false);
		Caculation = StdStringToString(caculation);
		UpdateData(false);
		return;
	}
	caculation = legitimize(caculation);
	std::string change = infixToPostfix(caculation);
	result = evaluatePostfix(change);
	Caculation = DoubleToString(result);
	UpdateData(false);
}


void CCaculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "0";
	UpdateData(0);
	lastc = '0';
}


void CCaculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "1";
	UpdateData(0);
	lastc = '1';
}


void CCaculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "2";
	UpdateData(0);
	lastc = '2';
}


void CCaculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "3";
	UpdateData(0);
	lastc = '3';
}


void CCaculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "4";
	UpdateData(0);
	lastc = '4';
}


void CCaculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "5";
	UpdateData(0);
	lastc = '5';
}


void CCaculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "6";
	UpdateData(0);
	lastc = '6';
}


void CCaculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "7";
	UpdateData(0);
	lastc = '7';
}


void CCaculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "8";
	UpdateData(0);
	lastc = '8';
}


void CCaculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "9";
	UpdateData(0);
	lastc = '9';
}


void CCaculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || lastc == '(' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += "+";
	UpdateData(0);
	lastc = '+';
}


void CCaculatorDlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation += "-";
	UpdateData(0);
	lastc = '-';
}


void CCaculatorDlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || lastc == '(' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += "*";
	UpdateData(0);
	lastc = '*';
}


void CCaculatorDlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || lastc == '(' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += "/";
	UpdateData(0);
	lastc = '/';
}


void CCaculatorDlg::OnBnClickedDot()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += ".";
	UpdateData(0);
	lastc = '.';
}


void CCaculatorDlg::OnBnClickedEmp()
{
	// TODO: 在此添加控件通知处理程序代码
	Caculation = "";
	lastc = ' ';
	UpdateData(0);
}


void CCaculatorDlg::OnBnClickedPercent()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || lastc == '%' || lastc == '(' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += "%";
	UpdateData(0);
	lastc = '%';
}


void CCaculatorDlg::OnBnClickedBackspace()
{
	// TODO: 在此添加控件通知处理程序代码
	if (Caculation.IsEmpty())
	{
		return;
	}
	int len = 0;
	len = Caculation.GetLength()-1;
	Caculation = Caculation.Left(len);
	lastc = Caculation.IsEmpty() ? ' ' : Caculation.GetAt(Caculation.GetLength()-1);
	UpdateData(0);
}


void CCaculatorDlg::OnBnClickedBrack()
{
	// TODO: 在此添加控件通知处理程序代码
	if (lastc == '+' || lastc == '-' || lastc == '*' || lastc == '/' || lastc == '.' || lastc == '(' || Caculation.IsEmpty())
	{
		return;
	}
	Caculation += ")";
	UpdateData(0);
	lastc = ')';
}


void CCaculatorDlg::OnBnClickedBra()
{
	// TODO: 在此添加控件通知处理程序代码
	if(lastc == '.' || lastc == '%' || lastc == ')')
	{
		return;
	}
	Caculation += "(";
	UpdateData(0);
	lastc = '(';
}


BOOL CCaculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == '9')
		{
			if ((::GetAsyncKeyState(VK_SHIFT) < 0))//按下左括号组合键
			{
				OnBnClickedBra();
				return true;
			}
		}
		else if (pMsg->wParam == '0')
		{
			if ((::GetAsyncKeyState(VK_SHIFT) < 0))//按下右括号组合键
			{
				OnBnClickedBrack();
				return true;
			}
		}
		else if (pMsg->wParam == '5')
		{
			if ((::GetAsyncKeyState(VK_SHIFT) < 0))//按下右括号组合键
			{
				OnBnClickedPercent();
				return true;
			}
		}
		if (pMsg->wParam == VK_ADD)				//按下+
		{
			OnBnClickedAdd();
		}
		else if (pMsg->wParam == VK_SUBTRACT)	//按下-
		{
			OnBnClickedSub();
		}
		else if (pMsg->wParam == VK_MULTIPLY)	//按下*
		{
			OnBnClickedMul();
		}
		else if (pMsg->wParam == VK_DIVIDE)		//按下/
		{
			OnBnClickedDiv();
		}
		else if (pMsg->wParam == VK_RETURN)		//按下Enter
		{
			OnBnClickedCaculate();
		}
		else if (pMsg->wParam == VK_BACK)		//按下Backspace
		{
			OnBnClickedBackspace();
		}
		else if (pMsg->wParam == VK_DECIMAL || pMsg->wParam == VK_OEM_PERIOD)
		{
			OnBnClickedDot();
		}
		else if (pMsg->wParam == VK_NUMPAD0 || pMsg->wParam == VK_NUMPAD1 || pMsg->wParam == VK_NUMPAD2 ||
			pMsg->wParam == VK_NUMPAD3 || pMsg->wParam == VK_NUMPAD4 || pMsg->wParam == VK_NUMPAD5 ||
			pMsg->wParam == VK_NUMPAD6 || pMsg->wParam == VK_NUMPAD7 || pMsg->wParam == VK_NUMPAD8 ||
			pMsg->wParam == VK_NUMPAD9 || isdigit(pMsg->wParam)
			)								   //按下数字
		{
			const char temp = pMsg->wParam - 0x30;
			Caculation += temp;
			UpdateData(0);
			lastc = temp;
		}
		return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}