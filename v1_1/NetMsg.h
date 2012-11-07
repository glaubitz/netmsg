// NetMsg.h : Haupt-Header-Datei für die Anwendung NETMSG
//

#if !defined(AFX_NETMSG_H__4B6D6BE2_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_)
#define AFX_NETMSG_H__4B6D6BE2_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "WinSock.h"
#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CNetMsgApp:
// Siehe NetMsg.cpp für die Implementierung dieser Klasse
//

class CNetMsgApp : public CWinApp
{
public:
	CNetMsgApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CNetMsgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	virtual int ExitInstance ();

// Implementierung

	//{{AFX_MSG(CNetMsgApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_NETMSG_H__4B6D6BE2_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_)
