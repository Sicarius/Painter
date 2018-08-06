
// painterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "painter.h"
#include "painterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	

// Implementation
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


// CpainterDlg dialog



CpainterDlg::CpainterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PAINTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpainterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CpainterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CpainterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CpainterDlg::OnBnClickedButton2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON3, &CpainterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CpainterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CpainterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CpainterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CpainterDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON8, &CpainterDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CpainterDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON7, &CpainterDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CpainterDlg message handlers

BOOL CpainterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CpainterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpainterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpainterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




int option = NULL;
void CpainterDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	option = 1;

}
void CpainterDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnMouseMove(nFlags, point);
	CClientDC painter(this);
	CPen pen1(PS_SOLID, 2,color);
	painter.SelectObject(&pen1);


	if (nFlags == MK_LBUTTON)
	{
		switch (option)
		{

		case 1:
			painter.SetPixel(point, color);
			break;

		case 2:

			painter.SetROP2(R2_NOTXORPEN);
			painter.MoveTo(p1);
			painter.LineTo(p2);
			painter.MoveTo(p1);
			painter.LineTo(point);
			p2 = point;
			break;

		case 3:
			painter.MoveTo(p1);
			painter.LineTo(point);
			p1 = point;
			break;


		case 4:
			painter.SetROP2(R2_NOTXORPEN);
			painter.Rectangle(p1.x, p1.y, p2.x, p2.y);
			painter.Rectangle(p1.x, p1.y, point.x, point.y);
			p2 = point;
			break;
	
		case 5:
			painter.SetPixel(point, color=RGB(255,255,255));
			painter.MoveTo(p1);
			painter.LineTo(point);
			p1 = point;
			break;

		//case 6:
		//	
		//	painter.SetViewportOrg(CPoint(25, 25));
		//	painter.Rectangle(0, 0, 200, 100); // draws rectangle
		//	painter.SetTextColor(RGB(255, 0, 0)); // sets text color to red
		//	painter.TextOutW(25, 25, "Hello, World!"); // draws text on rectangle
		//	break;


		case 10:
			painter.SetROP2(R2_NOTXORPEN);
			CRect rect1(p1, p2);
			painter.Ellipse(rect1);
			CRect rect2(p1, point);
			painter.Ellipse(rect2);
			p2 = point;
			break;  
			
		}
	}
}




void CpainterDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	int res = dlg.DoModal();
	if (res == IDOK)
	{
		color = dlg.GetColor();
		
	}
}


void CpainterDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonDown(nFlags, point);
	CClientDC painter(this);
	if (option == 1||option == 5 )
	{
		painter.SetPixel(point, color);
	}
	p1 = p2 = point;
}


void CpainterDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CpainterDlg::OnBnClickedButton3()
{
	option = 2;
}


void CpainterDlg::OnBnClickedButton4()
{
	option = 3;
}


void CpainterDlg::OnBnClickedButton5()
{
	option = 4;
}


void CpainterDlg::OnBnClickedButton6()
{
	option = 10;
}


void CpainterDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	
		
	
}


void CpainterDlg::OnBnClickedButton8()
{
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}


void CpainterDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
}


void CpainterDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	option = 5;
}


