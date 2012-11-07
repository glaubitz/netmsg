// SvrWaitDlg.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "netmsg.h"
#include "NetMsgDlg.h"
#include "SvrWaitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CNetMsgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CSvrWaitDlg 


CSvrWaitDlg::CSvrWaitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSvrWaitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSvrWaitDlg)
		// HINWEIS: Der Klassen-Assistent fügt hier Elementinitialisierung ein
	//}}AFX_DATA_INIT
}


void CSvrWaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSvrWaitDlg)
		// HINWEIS: Der Klassen-Assistent fügt hier DDX- und DDV-Aufrufe ein
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSvrWaitDlg, CDialog)
	//{{AFX_MSG_MAP(CSvrWaitDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CSvrWaitDlg 

void CSvrWaitDlg::OnCancel() 
{

	((CNetMsgDlg *)theApp.m_pMainWnd)->GetDlgItem (IDC_STARTSVR)->EnableWindow (TRUE);

	((CNetMsgDlg *)theApp.m_pMainWnd)->GetDlgItem (IDC_CONNECT)->EnableWindow (TRUE);

	DisConnect (&((CNetMsgDlg *)theApp.m_pMainWnd)->Connection);
	
	TerminateThread (((CNetMsgDlg *)theApp.m_pMainWnd)->hStartServerThread->m_hThread, 0);
	
	CDialog::OnCancel();
}
