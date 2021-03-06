
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

	SetWindowTextW(L"Двійкове кодування");

	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_E, E);
	E.SetWindowTextW(L"\n\n\n\t\tНатисніть кнопку <A10=A2>");
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CProgramDlg::OnBnClickedButton1)
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProgramDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	char z[256];
	ms.Empty();
	for (k = 0; k < 256; k++) z[k] = '\0';

	ms = "\n\tРезультати кодування:\n";
	
	CStdioFile inf(L"data.txt", CFile::modeRead);
	if (!inf) return;

	while (inf.ReadString(t))
	{
		ms += "\n\tдесяткове число: ";
		ms += t;
		int n=_wtoi(t);
		k = 0; t.Empty();
		while (n > 0)
		{
			int m = n % 2;
			n = n / 2;
			if (m == 1) z[k] = '1'; else z[k] = '0';
			k++;
		}
		for (int i = strlen(z) - 1; i >= 0; i--)
		{
			t += z[i];
		}
		ms += "\tдвійковий запис числа: ";
		ms += t;
		for (k = 0; k < 256; k++) z[k] = '\0';
	}
	inf.Close();

	E.SetWindowTextW(ms);

}
