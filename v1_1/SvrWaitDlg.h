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
		// HINWEIS: Der Klassen-Assistent f�gt hier Datenelemente ein
	//}}AFX_DATA


// �berschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktions�berschreibungen
	//{{AFX_VIRTUAL(CSvrWaitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst�tzung
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
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // AFX_SVRWAITDLG_H__624C4500_5229_11D5_A215_9144A4186802__INCLUDED_
