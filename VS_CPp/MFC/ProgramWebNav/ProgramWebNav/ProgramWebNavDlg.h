
// ProgramWebNavDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CProgramWebNavDlg dialog
class CProgramWebNavDlg : public CDialog
{
// Construction
public:
	CProgramWebNavDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAMWEBNAV_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:

	int p;
	CRect rc, w1, w2, w3, w4, w5, w6;
	CBitmap pic1, pic2, pic3, pic4, pic5, pic6;


public:
	CStatic mpic1;
	CStatic mpic2;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
