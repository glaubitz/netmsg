// NetMsgDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "NetMsg.h"
#include "NetMsgDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define IDC_TIMER	4000

CNetMsgDlg * pNetMsgDlg;

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
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
	m_msg_for_host = _T("");
	m_host_name = _T("");
	m_send_to_all_users = FALSE;
	m_clear_after_send = FALSE;
	m_repeatcycle = 5;
	m_loop = FALSE;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNetMsgDlg)
	DDX_Text(pDX, IDC_EDITMSG, m_msg_for_host);
	DDV_MaxChars(pDX, m_msg_for_host, 300);
	DDX_Text(pDX, IDC_EDITHOST, m_host_name);
	DDX_Check(pDX, IDC_TOALL, m_send_to_all_users);
	DDX_Check(pDX, IDC_CLRAFTRSEND, m_clear_after_send);
	DDX_Text(pDX, IDC_REPEATCYCLE, m_repeatcycle);
	DDX_Check(pDX, IDC_LOOP, m_loop);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNetMsgDlg, CDialog)
	//{{AFX_MSG_MAP(CNetMsgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_SEND, OnSend)
	ON_BN_CLICKED(IDC_STOPLOOP, OnStoploop)
	ON_BN_CLICKED(IDC_RENAMEWIN, OnRenamewin)
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
	
	pNetMsgDlg = this;
	UpdateData(TRUE); // Get data from main window
	SendMsg (m_msg_for_host, m_host_name, m_send_to_all_users);
	
	if (m_clear_after_send) {
		m_msg_for_host = "";
		UpdateData(FALSE);
	}
	CWnd * hEdit = GetDlgItem (IDC_EDITMSG);
	hEdit->SetFocus();

	if (m_loop) {

		if (m_repeatcycle < 5 || m_repeatcycle > 1200) {
			MessageBox ("We don't want to exaggerate, do we ?", "Come on", MB_OK|MB_ICONSTOP);
			return;
		}
		CWnd * hButton = GetDlgItem (IDC_STOPLOOP);
		hButton->EnableWindow (TRUE);
		::SetTimer(GetSafeHwnd (), IDC_TIMER, m_repeatcycle * 1000, TimerProc);

	}
 
}


void CNetMsgDlg::OnStoploop() 
{
	::KillTimer (GetSafeHwnd (), IDC_TIMER);
	CWnd * hEdit = GetDlgItem (IDC_EDITMSG);
	hEdit->SetFocus();
}

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime) {
 
	SendMsg (pNetMsgDlg->m_msg_for_host, pNetMsgDlg->m_host_name, FALSE);
}

void CNetMsgDlg::OnRenamewin() 
{
	UpdateData (TRUE);
	SetWindowText (m_msg_for_host);
	m_msg_for_host = "";
	UpdateData (FALSE);
	CWnd * hEdit = GetDlgItem (IDC_EDITMSG);
	hEdit->SetFocus();
}
