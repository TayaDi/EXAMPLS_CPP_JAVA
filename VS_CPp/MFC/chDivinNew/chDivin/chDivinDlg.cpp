
// chDivinDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chDivin.h"
#include "chDivinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CchDivinDlg dialog



CchDivinDlg::CchDivinDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHDIVIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CchDivinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, mpic);

	fg = true;
}

BEGIN_MESSAGE_MAP(CchDivinDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CchDivinDlg message handlers

BOOL CchDivinDlg::OnInitDialog()
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

void CchDivinDlg::OnPaint()
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

		
		
		
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CchDivinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CchDivinDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CClientDC dc(this);
	GetClientRect(&rc);

	//dc.FillSolidRect(&rc, 0x00D5EFFF);


	
	p = 0;
	j = 0;
	
	w.top = 225;
	w.bottom = 420;
	w.left = 155;
	w.right = 295;
	kw[p][j] = w;
	
	j++;

	w.top = 225;
	w.bottom = 420;
	w.left = 305;
	w.right = 438;
	kw[p][j] = w;

	j++;

	w.top = 225;
	w.bottom = 420;
	w.left = 448;
	w.right = 580;
	kw[p][j] = w;

	p++;
	j = 0;

	w.top = 440;
	w.bottom = 633;
	w.left = 165;
	w.right = 298;
	kw[p][j] = w;

	j++;
	w.top = 440;
	w.bottom = 633;
	w.left = 320;
	w.right = 450;
	kw[p][j] = w;

	j++;
	w.top = 435;
	w.bottom = 628;
	w.left = 455;
	w.right = 590;
	kw[p][j] = w;

/*
	cf = 0x00800080;
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	
	for (k = 0; k < 2; k++)
	{
		for (i = 0; i < 3; i++)
		{
			x1 = w.left = kw[k][i].left;
			y1 = w.top = kw[k][i].top;
			x2 = w.right = kw[k][i].right;
			y2 = w.bottom = kw[k][i].bottom;
			dc.MoveTo(x1, y1);
			dc.LineTo(x2, y1);
			dc.LineTo(x2, y2);
			dc.LineTo(x1, y2);
			dc.LineTo(x1, y1);
		}
	}

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);
*/

	if (fg&&PtInRect(&kw[0][0], point))
	{
		pic.LoadBitmapW(IDB_BITMAP3);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = false;
	}

	if (fg&&PtInRect(&kw[0][1], point))
	{
		pic.LoadBitmapW(IDB_BITMAP4);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = false;
	}

	if (fg&&PtInRect(&kw[0][2], point))
	{
		pic.LoadBitmapW(IDB_BITMAP5);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = false;
	}

	if (fg&&PtInRect(&kw[1][0], point))
	{
		pic.LoadBitmapW(IDB_BITMAP2);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = true;
	}

	if (fg&&PtInRect(&kw[1][1], point))
	{
		pic.LoadBitmapW(IDB_BITMAP6);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = false;
	}

	if (fg&&PtInRect(&kw[1][2], point))
	{
		pic.LoadBitmapW(IDB_BITMAP7);
		mpic.SetBitmap(pic);
		pic.DeleteObject();
		fg = false;
	}

	CDialog::OnLButtonDown(nFlags, point);
}


void CchDivinDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	pic.LoadBitmapW(IDB_BITMAP2);
	mpic.SetBitmap(pic);
	pic.DeleteObject();
	fg = true;


	CDialog::OnRButtonDown(nFlags, point);
}
