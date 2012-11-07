// NetMsg.cpp : Legt das Klassenverhalten für die Anwendung fest.
//

#include "stdafx.h"
#include "NetMsg.h"
#include "NetMsgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNetMsgApp

BEGIN_MESSAGE_MAP(CNetMsgApp, CWinApp)
	//{{AFX_MSG_MAP(CNetMsgApp)
		// HINWEIS - Hier werden Mapping-Makros vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetMsgApp Konstruktion

CNetMsgApp::CNetMsgApp()
{
	// ZU ERLEDIGEN: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance platzieren
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CNetMsgApp-Objekt

CNetMsgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNetMsgApp Initialisierung

BOOL CNetMsgApp::InitInstance()
{
	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht nutzen und die Größe Ihrer fertigen 
	//  ausführbaren Datei reduzieren wollen, sollten Sie die nachfolgenden
	//  spezifischen Initialisierungsroutinen, die Sie nicht benötigen, entfernen.

	CNetMsgDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// ZU ERLEDIGEN: Fügen Sie hier Code ein, um ein Schließen des
		//  Dialogfelds über OK zu steuern
	}
	else if (nResponse == IDCANCEL)
	{
		// ZU ERLEDIGEN: Fügen Sie hier Code ein, um ein Schließen des
		//  Dialogfelds über "Abbrechen" zu steuern
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zurückliefern, so dass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}

int CNetMsgApp::ExitInstance () {

	int retval;

	retval = CWinApp::ExitInstance ();

	WSACleanup ();

	return retval;

}