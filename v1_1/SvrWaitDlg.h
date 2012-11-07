#if !defined(AFX_SVRWAITDLG_H__624C4500_5229_11D5_A215_9144A4186802__INCLUDED_)
#define AFX_SVRWAITDLG_H__624C4500_5229_11D5_A215_9144A4186802__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SvrWaitDlg.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CSvrWaitDlg 

class CSvrWaitDlg : public CDialog
{
// Konstruktion
public:
	CSvrWaitDlg(CWnd* pParent = NULL);   // Standardkonstruktor

	// virtual int DoModal (LPCSTR ServerAddress, DWORD Port);

// Dialogfelddaten
	//{{AFX_DATA(CSvrWaitDlg)
	enum { IDD = IDD_SVRWAIT };
		// HINWEIS: Der Klassen-Assistent fügt hier Datenelemente ein
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(CSvrWaitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(CSvrWaitDlg)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_SVRWAITDLG_H__624C4500_5229_11D5_A215_9144A4186802__INCLUDED_
