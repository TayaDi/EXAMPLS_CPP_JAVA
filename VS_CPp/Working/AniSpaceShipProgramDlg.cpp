
// ProgramDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProgramDlg::OnPaint()
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
		
		CClientDC dc(this);
		GetClientRect(&rc);

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 4, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);

		cx = RH / 2;
		cy = RW / 2;

		dx = cx / 8;
		dy = cy / 6;

		x1 = w.left = cx;
		y1 = w.top = cy-4*dy;
		
		for (y1 = y1 + 400; y1 >= -500; y1 -= 20)
		{
			Sleep(mtime-150);
			dc.FillSolidRect(&rc, RGB(255, 255, 255));
			x2 = w.right = x1;
			y2 = w.bottom = y1 + 8 * dy;

			// Корпус ракеты
			dc.MoveTo(x1, y1);
			dc.LineTo(x1 + dx, y1 + 3 * dy);
			dc.LineTo(x1 + dx, y1 + 8 * dy);
			dc.LineTo(x2, y2);

			dc.MoveTo(x1, y1);
			dc.LineTo(x1 - dx, y1 + 3 * dy);
			dc.LineTo(x1 - dx, y1 + 8 * dy);
			dc.LineTo(x2, y2);

			// Окошки
			int r1;

			r1 = dx / 3;
			x = x1;
			y = y1 + 4.5*dy;
			dc.Ellipse(x - r1, y - r1, x + r1, y + r1);
			y = y - 1.25*dy;
			dc.Ellipse(x - r1, y - r1, x + r1, y + r1);


			// Крылья ракеты 

			dc.MoveTo(x1 + dx, y1 + 5 * dy);
			dc.LineTo(x1 + 2 * dx, y1 + 6.5*dy);
			dc.LineTo(x1 + 2 * dx, y1 + 9 * dy);
			dc.LineTo(x1 + 1.5*dx, y1 + 9 * dy);
			dc.LineTo(x1 + dx, y1 + 8 * dy);

			dc.MoveTo(x1 - dx, y1 + 5 * dy);
			dc.LineTo(x1 - 2 * dx, y1 + 6.5*dy);
			dc.LineTo(x1 - 2 * dx, y1 + 9 * dy);
			dc.LineTo(x1 - 1.5*dx, y1 + 9 * dy);
			dc.LineTo(x1 - dx, y1 + 8 * dy);

			dc.MoveTo(x1, y1 + 5.25 * dy);
			dc.LineTo(x2, y2 + dy);
		}


		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

