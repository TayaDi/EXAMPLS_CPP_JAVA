
// KnightAppDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KnightApp.h"
#include "KnightAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKnightAppDlg dialog



CKnightAppDlg::CKnightAppDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_KNIGHTAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	hsb = AfxGetApp()->LoadIcon(IDI_ICON1);
	hsw = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CKnightAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKnightAppDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CKnightAppDlg message handlers

BOOL CKnightAppDlg::OnInitDialog()
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

void CKnightAppDlg::OnPaint()
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

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		dx = RH / 10;
		dy = RW / 10;
		p = 0;
		for (k = 0; k < 10; k++)
		{
			j = 0;
			for (i = 0; i < 10; i++)
			{
				w.top = k*dy; 
				w.bottom = (k + 1)*dy;
				w.left = i*dx;
				w.right = (i + 1)*dx;

				kw[p][j] = w;
				j++;
			}
			p++;
		}

		for (p = 0; p < 10; p++)
		{
			for (j = 0; j < 10; j++)
			{
				if (p == 0 || p == 9 || j == 0 || j == 9)
					cf = RGB(255, 255, 255);
				else
					cf = RGB(0, 0, 0);

				if (p>0 && p % 2 != 0 && j % 2 != 0)
					cf = RGB(255, 255, 255);
				if (j>0 && p% 2 == 0 && j % 2 == 0)
					cf = RGB(255, 255, 255);

				m = CreateSolidBrush(cf);
				oldm = (HBRUSH)dc.SelectObject(m);
				dc.FillSolidRect(&kw[p][j], cf);
				DeleteObject(m);
				SelectObject(dc, oldm);
			}

		}

		x1 = w.left = kw[1][1].left;
		y1 = w.top = kw[1][1].top;
		x2 = w.right = kw[8][8].right;
		y2 = w.bottom = kw[8][8].bottom;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);


		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(28, 0, 0, 0,
			FW_NORMAL,
			0, 0, 0,
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Arial");
		hold = (HFONT)SelectObject(dc, hNew);

		for (k = 8; k > 0; k--)
		{
			t.Format(L"%i", k);
			dc.TextOutW(x1 - dx / 2, y1 + (8 - k)*dy+dy/5, t, t.GetLength());
			dc.TextOutW(x2 + dx / 4, y1 + (8-k)*dy + dy/5, t, t.GetLength());
		}


		p = 97;
		for (k = 0; k < 8; k++)
		{
			t = char(p + k);
			dc.TextOutW(x1 + dx*k+ dx/2.5, y2 + dy /10, t, t.GetLength());
			dc.TextOutW(x1 + dx * k + dx / 2.5, y1 - dy+dy/7, t, t.GetLength());
		}

		hold = (HFONT)SelectObject(dc, hbk);
		
		
		x = kw[5][5].left+dx/8;
		y = kw[5][5].top+dy/8;	
		ps.x = x;
		ps.y = y;
		dc.DrawIcon(ps, hsw);

		x = kw[3][2].left + dx / 8;
		y = kw[3][2].top + dy / 8;
		ps.x = x;
		ps.y = y;
		dc.DrawIcon(ps, hsb);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKnightAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKnightAppDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	GetClientRect(&rc);

	dc.FillSolidRect(&rc, RGB(255, 255, 255));

	RH = abs(rc.left - rc.right);
	RW = abs(rc.top - rc.bottom);
	dx = RH / 10;
	dy = RW / 10;
	p = 0;
	for (k = 0; k < 10; k++)
	{
		j = 0;
		for (i = 0; i < 10; i++)
		{
			w.top = k * dy;
			w.bottom = (k + 1)*dy;
			w.left = i * dx;
			w.right = (i + 1)*dx;

			kw[p][j] = w;
			j++;
		}
		p++;
	}

	for (p = 0; p < 10; p++)
	{
		for (j = 0; j < 10; j++)
		{
			if (p == 0 || p == 9 || j == 0 || j == 9)
				cf = RGB(255, 255, 255);
			else
				cf = RGB(0, 0, 0);

			if (p>0 && p % 2 != 0 && j % 2 != 0)
				cf = RGB(255, 255, 255);
			if (j>0 && p % 2 == 0 && j % 2 == 0)
				cf = RGB(255, 255, 255);

			m = CreateSolidBrush(cf);
			oldm = (HBRUSH)dc.SelectObject(m);
			dc.FillSolidRect(&kw[p][j], cf);
			DeleteObject(m);
			SelectObject(dc, oldm);
		}

	}

	x1 = w.left = kw[1][1].left;
	y1 = w.top = kw[1][1].top;
	x2 = w.right = kw[8][8].right;
	y2 = w.bottom = kw[8][8].bottom;

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	dc.MoveTo(x1, y1);
	dc.LineTo(x2, y1);
	dc.LineTo(x2, y2);
	dc.LineTo(x1, y2);
	dc.LineTo(x1, y1);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);


	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(28, 0, 0, 0,
		FW_NORMAL,
		0, 0, 0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Arial");
	hold = (HFONT)SelectObject(dc, hNew);

	for (k = 8; k > 0; k--)
	{
		t.Format(L"%i", k);
		dc.TextOutW(x1 - dx / 2, y1 + (8 - k)*dy + dy / 5, t, t.GetLength());
		dc.TextOutW(x2 + dx / 4, y1 + (8 - k)*dy + dy / 5, t, t.GetLength());
	}


	p = 97;
	for (k = 0; k < 8; k++)
	{
		t = char(p + k);
		dc.TextOutW(x1 + dx * k + dx / 2.5, y2 + dy / 10, t, t.GetLength());
		dc.TextOutW(x1 + dx * k + dx / 2.5, y1 - dy + dy / 7, t, t.GetLength());
	}

	hold = (HFONT)SelectObject(dc, hbk);


	for (k = 1; k < 9; k++)
	{
		for (i = 1; i < 9; i++)
		{
			if (PtInRect(&kw[k][i], point))
			{
					x = kw[k][i].left + dx / 8;
					y = kw[k][i].top + dy / 8;
					ps.x = x;
					ps.y = y;
					p = k; j = i;
			}
		}
	}

				
	if (p % 2 != 0 && j % 2 != 0)
	{
		dc.DrawIcon(ps, hsw);
	}
	if (p % 2 != 0 && j % 2 == 0)
	{
		dc.DrawIcon(ps, hsb);
	}
	if (p % 2 == 0 && j % 2 != 0)
	{
		dc.DrawIcon(ps, hsb);
	}
	if (p % 2 == 0 && j % 2 == 0)
	{
		dc.DrawIcon(ps, hsw);
	}



	CDialog::OnLButtonDown(nFlags, point);
}
