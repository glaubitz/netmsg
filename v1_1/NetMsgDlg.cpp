// NetMsgDlg.cpp : Implementierungsdatei
//

#include "StdAfx.h"
#include "NetMsg.h"
#include "NetMsgDlg.h"
#include "SvrWaitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define __STR_ERROR "Net Message 1.1.2 - Error"
#define WM_SERVER WM_APP

extern CNetMsgApp theApp;
CSvrWaitDlg SvrWaitDlg;

UINT StartServerThread (LPVOID pParam);
UINT ReceiveDataThread (LPVOID pParam);

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetMsgDlg Dialogfeld

CNetMsgDlg::CNetMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNetMsgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNetMsgDlg)
	m_clear_after_send = TRUE;
	m_recvtxt = _T("");
	m_sndtxt = _T("");
	m_enableecho = TRUE;
	m_host = _T("");
	m_port = 5001;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetMsgDlg)
	DDX_Control(pDX, IDC_RECVTXT, m_hrecvtxt);
	DDX_Check(pDX, IDC_CLRAFTRSEND, m_clear_after_send);
	DDX_Text(pDX, IDC_RECVTXT, m_recvtxt);
	DDX_Text(pDX, IDC_SNDTXT, m_sndtxt);
	DDV_MaxChars(pDX, m_sndtxt, 127);
	DDX_Check(pDX, IDC_ENABLEECHO, m_enableecho);
	DDX_Text(pDX, IDC_HOST, m_host);
	DDX_Text(pDX, IDC_PORT, m_port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CNetMsgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_STARTSVR, OnStartsvr)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	ON_MESSAGE(WM_SERVER, OnServer)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_COMMAND(ID_RETURN, OnReturn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetMsgDlg Nachrichten-Handler

BOOL CNetMsgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			pSysMenu->EnableMenuItem (2, MF_BYPOSITION|MF_GRAYED);
			pSysMenu->EnableMenuItem (4, MF_BYPOSITION|MF_GRAYED);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, TRUE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen

	m_hAccel = ::LoadAccelerators (AfxGetInstanceHandle (),
					MAKEINTRESOURCE(IDR_ACCEL));

	ASSERT(m_hAccel);

	if (WSAStartup (0x202, &WsaData)) {
		
		MessageBox ("Could not initialize WinSock. Possibly WinSock installed\r\nis too old. This program requires version 1.1 or higher",
						__STR_ERROR, MB_OK|MB_ICONSTOP);
		
		ExitProcess (-1);
	}

	Connection.Socket = 0;
	
	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CNetMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CNetMsgDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CNetMsgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNetMsgDlg::OnSend() {

	UpdateData (TRUE);

	if (m_sndtxt.GetLength () < 1)
		return;

	SendData ((char*) m_sndtxt.operator LPCTSTR (), m_sndtxt.GetLength (), &Connection);
	
	if (m_enableecho)
		m_recvtxt += "You: " + m_sndtxt + "\r\n";
	
	if (m_clear_after_send)
		m_sndtxt = "";

	CWnd * SendField = GetDlgItem (IDC_SNDTXT);

	SendField->SetFocus ();

	UpdateData (FALSE);

	m_hrecvtxt.LineScroll (m_hrecvtxt.GetLineCount ()); // scroll the x lines edit field to last line
									// see docu on LineScroll
}

void CNetMsgDlg::OnConnect() 
{	
	unsigned int addr;

	UpdateData (TRUE);

	if ((addr = inet_addr (m_host.operator LPCTSTR ())) == INADDR_NONE ||
		m_host.GetLength () == 0) {

		MessageBox ("The host address is either invalid or has not been specified",
						__STR_ERROR, MB_OK|MB_ICONSTOP);
		return;
	}

	Connection.Port = m_port;

	Connection = ConnectWithServer (addr, Connection.Port);

	if (!Connection.Socket)
		MessageBox ("Could not connect with server\r\n\r\nMake sure the server is running at\r\nspecified host-address and port\r\n\r\nCheck your TCP/IP-configuration", __STR_ERROR, MB_OK|MB_ICONSTOP);
	
	else {
		
		hReceiveDataThread = AfxBeginThread (ReceiveDataThread, NULL);

		GetDlgItem (IDC_DISCONNECT)->EnableWindow (TRUE);
		GetDlgItem (IDC_SEND)->EnableWindow (TRUE);
		GetDlgItem (IDC_CONNECT)->EnableWindow (FALSE);
		GetDlgItem (IDC_STARTSVR)->EnableWindow (FALSE);
	}
}

void CNetMsgDlg::OnStartsvr() 
{
	UpdateData (TRUE);

	Connection.Port = m_port;
	
	hStartServerThread = AfxBeginThread (StartServerThread, NULL); //, NULL, THREAD_PRIORITY_NORMAL, 0, 0, NULL);

	SvrWaitDlg.DoModal ();
	
	//KillServer (&Connection);
	
	/*
	if (StartServer (5001, &Connection))
		MessageBox ("Could not start server", __STR_ERROR, MB_OK|MB_ICONSTOP);
	*/
}

LRESULT CNetMsgDlg::OnServer (WPARAM wParam, LPARAM lParam) {
	

	if (wParam != 0) {
		
		SvrWaitDlg.MessageBox ("Could not start server\r\n\r\nCheck your TCP/IP-configuration", __STR_ERROR, MB_OK|MB_ICONSTOP);

		SvrWaitDlg.EndDialog (0);

		return -1;
	}

	else {
		
		SvrWaitDlg.EndDialog (0);

		GetDlgItem (IDC_CONNECT)->EnableWindow (FALSE);
		GetDlgItem (IDC_STARTSVR)->EnableWindow (FALSE);


		GetDlgItem (IDC_SEND)->EnableWindow (TRUE);
		GetDlgItem (IDC_DISCONNECT)->EnableWindow (TRUE);

		hReceiveDataThread = AfxBeginThread (ReceiveDataThread, NULL);

		return 0;
	}

}

UINT StartServerThread (LPVOID pParam) {

	DWORD retval;
	
	retval = StartServer (&((CNetMsgDlg *)theApp.m_pMainWnd)->Connection);

	((CNetMsgDlg *)theApp.m_pMainWnd)->PostMessage (WM_SERVER, (WPARAM) retval, (LPARAM) 0);

	return 0;
}

UINT ReceiveDataThread (LPVOID pParam) {

	char buf [130];

	int BytesReceived;

	while ((BytesReceived = ReceiveData (buf, 127,
		&((CNetMsgDlg*) theApp.m_pMainWnd)->Connection)) > 0) {

		((CNetMsgDlg*) theApp.m_pMainWnd)->UpdateData (TRUE); // save evtentually typed message
		
		CopyMemory ((char*) (buf + BytesReceived), "\r\n\0", 6);
		
		((CNetMsgDlg*) theApp.m_pMainWnd)->m_recvtxt += "Host: ";

		((CNetMsgDlg*) theApp.m_pMainWnd)->m_recvtxt += buf;

		((CNetMsgDlg*) theApp.m_pMainWnd)->UpdateData (FALSE);

		((CNetMsgDlg*) theApp.m_pMainWnd)->m_hrecvtxt.LineScroll 
			(((CNetMsgDlg*) theApp.m_pMainWnd)->m_hrecvtxt.GetLineCount ()); // see in OnSend ()
	}

	/*
	while (!ReceiveData (((CNetMsgDlg *)theApp.m_pMainWnd)->m_recvtxt.GetBuffer (128),
		128, &((CNetMsgDlg *)theApp.m_pMainWnd)->Connection)) {

		((CNetMsgDlg *) theApp.m_pMainWnd)->m_recvtxt.ReleaseBuffer ();

		((CNetMsgDlg *) theApp.m_pMainWnd)->UpdateData (FALSE);
	}

	((CNetMsgDlg *) theApp.m_pMainWnd)->m_recvtxt.ReleaseBuffer ();

	*/

	((CNetMsgDlg*) theApp.m_pMainWnd)->OnDisconnect ();

	return -1;
}

void CNetMsgDlg::OnDisconnect() 
{
	DisConnect (&Connection);

	GetDlgItem (IDC_CONNECT)->EnableWindow (TRUE);
	GetDlgItem (IDC_STARTSVR)->EnableWindow (TRUE);
	GetDlgItem (IDC_DISCONNECT)->EnableWindow (FALSE);
	GetDlgItem (IDC_SEND)->EnableWindow (FALSE);
	
	//TerminateThread (hReceiveDataThread->m_hThread, 0);

	//GetDlgItem (IDC_CONNECT)->EnableWindow (TRUE);
	//GetDlgItem (IDC_STARTSVR)->EnableWindow (TRUE);
}

BOOL CNetMsgDlg::PreTranslateMessage (MSG * pMsg) {

	if (pMsg->message >= WM_KEYFIRST &&
		pMsg->message <= WM_KEYLAST)

		return ::TranslateAccelerator (m_hWnd, m_hAccel, pMsg);
	else
		return CDialog::PreTranslateMessage (pMsg);

}

void CNetMsgDlg::OnReturn () {

	if (GetDlgItem (IDC_SEND)->IsWindowEnabled ())
		OnSend ();
}
