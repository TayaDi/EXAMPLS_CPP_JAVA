
// RunSeeHappenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RunSeeHappen.h"
#include "RunSeeHappenDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// CRunSeeHappenDlg dialog



CRunSeeHappenDlg::CRunSeeHappenDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RUNSEEHAPPEN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRunSeeHappenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	TAB[0][0] = 8;
	TAB[0][1] = 35;
	TAB[0][2] = 10;
	TAB[0][3] = 1;
	TAB[0][4] = 28;
	TAB[0][5] = 42;
	TAB[0][6] = 13;
	TAB[0][7] = 96;
	TAB[0][8] = 100;
	TAB[0][9] = 44;

	TAB[1][0] = 15;
	TAB[1][1] = 97;
	TAB[1][2] = 3;
	TAB[1][3] = 12;
	TAB[1][4] = 76;
	TAB[1][5] = 2;
	TAB[1][6] = 47;
	TAB[1][7] = 14;
	TAB[1][8] = 53;
	TAB[1][9] = 64;

	TAB[2][0] = 39;
	TAB[2][1] = 4;
	TAB[2][2] = 51;
	TAB[2][3] = 7;
	TAB[2][4] = 11;
	TAB[2][5] = 24;
	TAB[2][6] = 16;
	TAB[2][7] = 62;
	TAB[2][8] = 73;
	TAB[2][9] = 41;

	TAB[3][0] = 21;
	TAB[3][1] = 5;
	TAB[3][2] = 93;
	TAB[3][3] = 54;
	TAB[3][4] = 38;
	TAB[3][5] = 79;
	TAB[3][6] = 67;
	TAB[3][7] = 30;
	TAB[3][8] = 74;
	TAB[3][9] = 48;

	TAB[4][0] = 33;
	TAB[4][1] = 20;
	TAB[4][2] = 66;
	TAB[4][3] = 55;
	TAB[4][4] = 31;
	TAB[4][5] = 17;
	TAB[4][6] = 22;
	TAB[4][7] = 60;
	TAB[4][8] = 92;
	TAB[4][9] = 29;

	TAB[5][0] = 84;
	TAB[5][1] = 46;
	TAB[5][2] = 98;
	TAB[5][3] = 82;
	TAB[5][4] = 23;
	TAB[5][5] = 89;
	TAB[5][6] = 56;
	TAB[5][7] = 87;
	TAB[5][8] = 26;
	TAB[5][9] = 37;

	TAB[6][0] = 70;
	TAB[6][1] = 61;
	TAB[6][2] = 43;
	TAB[6][3] = 83;
	TAB[6][4] = 57;
	TAB[6][5] = 86;
	TAB[6][6] = 69;
	TAB[6][7] = 90;
	TAB[6][8] = 19;
	TAB[6][9] = 25;

	TAB[7][0] = 85;
	TAB[7][1] = 45;
	TAB[7][2] = 95;
	TAB[7][3] = 36;
	TAB[7][4] = 49;
	TAB[7][5] = 65;
	TAB[7][6] = 40;
	TAB[7][7] = 71;
	TAB[7][8] = 91;
	TAB[7][9] = 6;

	TAB[8][0] = 58;
	TAB[8][1] = 78;
	TAB[8][2] = 81;
	TAB[8][3] = 9;
	TAB[8][4] = 27;
	TAB[8][5] = 34;
	TAB[8][6] = 52;
	TAB[8][7] = 68;
	TAB[8][8] = 77;
	TAB[8][9] = 88;

	TAB[9][0] = 94;
	TAB[9][1] = 32;
	TAB[9][2] = 63;
	TAB[9][3] = 59;
	TAB[9][4] = 72;
	TAB[9][5] = 99;
	TAB[9][6] = 75;
	TAB[9][7] = 50;
	TAB[9][8] = 18;
	TAB[9][9] = 80;

	fg = true;
	SetWindowTextW(L"Порада на сьогодні");
	
	setlocale(LC_ALL, "rus");
	CStdioFile inf(L"porada100.txt", CFile::modeRead);
	if (!inf) return;
	for (k = 0; k < 100; k++) inf.ReadString(PORADA[k]);
	inf.Close();
	
}

BEGIN_MESSAGE_MAP(CRunSeeHappenDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRunSeeHappenDlg message handlers

BOOL CRunSeeHappenDlg::OnInitDialog()
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

void CRunSeeHappenDlg::OnPaint()
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

		dc.FillSolidRect(&rc, 0x00D5EFFF);

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
	
		x1 = w.left = kw[0][0].left;
		y1 = w.top = kw[0][0].top;
		x2 = w.right = kw[9][9].right;
		y2 = w.bottom = kw[9][9].bottom;
		
		cf = 0x00800080;
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);
		
		for (k = 0; k < 10; k++)
		{
			dc.MoveTo(x1+k*dx, y1);
			dc.LineTo(x1+k*dx, y2);

			dc.MoveTo(x1, y1+k*dy);
			dc.LineTo(x2, y1+k*dy);
		}

		dc.MoveTo(x1, y1);
		dc.LineTo(x2, y1);
		dc.LineTo(x2, y2);
		dc.LineTo(x1, y2);
		dc.LineTo(x1, y1);

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);

		hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
		hNew = CreateFont(52, 0, 0, 0,
			FW_BOLD,
			0, 0, 0,
			ANSI_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Trebuchet Ms");
		hold = (HFONT)SelectObject(dc, hNew);
	
		x1 = w.left = kw[0][0].left;
		y1 = w.top = kw[0][0].top;

		for (p = 0; p < 10; p++)
		{
			for (j = 0; j < 10; j++)
			{
				t.Format(L"%i", TAB[p][j]);
				
				if(TAB[p][j]==100)
					dc.TextOutW(x1 + j * dx + 4 , y1 + p * dy + dy / 5, t, t.GetLength());
				else
					dc.TextOutW(x1 + j * dx + dx / 4, y1 + p * dy + dy / 5, t, t.GetLength());

			}
		}

		hold = (HFONT)SelectObject(dc, hbk);




		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRunSeeHappenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRunSeeHappenDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	pfix = jfix = 0;
	
	CClientDC dc(this);
	GetClientRect(&rc);

	//dc.FillSolidRect(&rc, 0x00D5EFFF);

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
	
	
	
	if (fg)
	{

		for (k = 0; k < 10; k++)
		{
			for (i = 0; i < 10; i++)
			{
				if (PtInRect(&kw[k][i], point))
				{
					pfix = k; jfix = i;
				}
			}
		}

		x1 = kw[pfix][jfix].left;
		y1 = kw[pfix][jfix].top;
		x2 = kw[pfix][jfix].right;
		y2 = kw[pfix][jfix].bottom;


		w.left = kw[pfix][jfix].left + 10;
		w.top = kw[pfix][jfix].top + 10;
		w.right = kw[pfix][jfix].right - 10;
		w.bottom = kw[pfix][jfix].bottom - 10;

		if (PtInRect(&w, point))
		{
			ckw = 0x004763FD;
			hPenOxy = CreatePen(PS_SOLID, 3, ckw);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			dc.MoveTo(x1, y1);
			dc.LineTo(x2, y1);
			dc.LineTo(x2, y2);
			dc.LineTo(x1, y2);
			dc.LineTo(x1, y1);

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
		}
		else
		{
			ckw = 0x00800080;
			hPenOxy = CreatePen(PS_SOLID, 3, ckw);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);

			dc.MoveTo(x1, y1);
			dc.LineTo(x2, y1);
			dc.LineTo(x2, y2);
			dc.LineTo(x1, y2);
			dc.LineTo(x1, y1);

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
		}

	}

	CDialog::OnMouseMove(nFlags, point);
}


void CRunSeeHappenDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	fg = false;
	pfix = jfix = 0;

	CClientDC dc(this);
	GetClientRect(&rc);

	dc.FillSolidRect(&rc, 0x00D5EFFF);

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

	x1 = w.left = kw[0][0].left;
	y1 = w.top = kw[0][0].top;
	x2 = w.right = kw[9][9].right;
	y2 = w.bottom = kw[9][9].bottom;

	cf = 0x00800080;
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	for (k = 0; k < 10; k++)
	{
		dc.MoveTo(x1 + k * dx, y1);
		dc.LineTo(x1 + k * dx, y2);

		dc.MoveTo(x1, y1 + k * dy);
		dc.LineTo(x2, y1 + k * dy);
	}

	dc.MoveTo(x1, y1);
	dc.LineTo(x2, y1);
	dc.LineTo(x2, y2);
	dc.LineTo(x1, y2);
	dc.LineTo(x1, y1);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

	hbk = (HFONT)::GetStockObject(SYSTEM_FONT);
	hNew = CreateFont(52, 0, 0, 0,
		FW_BOLD,
		0, 0, 0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		L"Trebuchet Ms");
	hold = (HFONT)SelectObject(dc, hNew);

	x1 = w.left = kw[0][0].left;
	y1 = w.top = kw[0][0].top;

	for (p = 0; p < 10; p++)
	{
		for (j = 0; j < 10; j++)
		{
			t.Format(L"%i", TAB[p][j]);

			if (TAB[p][j] == 100)
				dc.TextOutW(x1 + j * dx + 4, y1 + p * dy + dy / 5, t, t.GetLength());
			else
				dc.TextOutW(x1 + j * dx + dx / 4, y1 + p * dy + dy / 5, t, t.GetLength());

		}
	}

	hold = (HFONT)SelectObject(dc, hbk);


	for (k = 0; k < 10; k++)
	{
		for (i = 0; i < 10; i++)
		{
			if (PtInRect(&kw[k][i], point))
			{
				pfix = k; jfix = i;
			}
		}
	}

	x1 = kw[pfix][jfix].left;
	y1 = kw[pfix][jfix].top;
	x2 = kw[pfix][jfix].right;
	y2 = kw[pfix][jfix].bottom;


	w.left = kw[pfix][jfix].left + 10;
	w.top = kw[pfix][jfix].top + 10;
	w.right = kw[pfix][jfix].right - 10;
	w.bottom = kw[pfix][jfix].bottom - 10;

	if (PtInRect(&w, point))
	{
		
		t.Format(L"Натиснуто %i", TAB[pfix][jfix]);
		ms = t;
		ms += "\n\n";
		ms += PORADA[TAB[pfix][jfix]-1];
		
		MessageBox(ms, L"На сьогодні Вами обрано", MB_OK | MB_ICONINFORMATION);

		fg = true;

	}


	CDialog::OnLButtonDown(nFlags, point);
}
