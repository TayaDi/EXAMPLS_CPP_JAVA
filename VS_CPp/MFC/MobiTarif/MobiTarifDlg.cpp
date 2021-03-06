
// MobiTarifDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MobiTarif.h"
#include "MobiTarifDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMobiTarifDlg dialog



CMobiTarifDlg::CMobiTarifDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MOBITARIF_DIALOG, pParent)
	, N(3)
	, D(6)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMobiTarifDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, N);
	DDX_Text(pDX, IDC_EDIT2, D);

	SetWindowTextW(L"Вычисление стоимости разговора по телефону");

}

BEGIN_MESSAGE_MAP(CMobiTarifDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMobiTarifDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMobiTarifDlg message handlers

BOOL CMobiTarifDlg::OnInitDialog()
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

void CMobiTarifDlg::OnPaint()
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
HCURSOR CMobiTarifDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMobiTarifDlg::OnBnClickedButton1()
{
	int n, d;
	double tarif, summ;
	CString ms, t;
	
	ms.Empty(); t.Empty();
	tarif = 1.5;
	summ = 0;


	UpdateData(true);
	n = N;
	d = D;
	UpdateData(false);

	if (d > 5)
	{
		summ = n*tarif*0.8;
		ms = "Вам предоставляется скидка 20%";
	}
	else summ = tarif*n;

	ms += "\nСтоимость разговора: ";
	t.Format(L"%6.2f грн.", summ);
	ms += t;

	MessageBox(ms, L"Квитанция", MB_OK | MB_ICONINFORMATION);



}
