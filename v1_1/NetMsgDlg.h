// NetMsgDlg.h : Header-Datei
//

#if !defined(AFX_NETMSGDLG_H__4B6D6BE4_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_)
#define AFX_NETMSGDLG_H__4B6D6BE4_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNetMsgDlg Dialogfeld

class CNetMsgDlg : public CDialog
{
// Konstruktion

	friend UINT StartServerThread (LPVOID pParam);
	friend UINT ReceiveDataThread (LPVOID pParam);
	friend class CSvrWaitDlg;

	HACCEL m_hAccel;

public:
	
	CNetMsgDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

	virtual BOOL PreTranslateMessage (MSG * pMsg);

	// Dialogfelddaten
	//{{AFX_DATA(CNetMsgDlg)
	enum { IDD = IDD_NETMSG_DIALOG };
	CEdit	m_hrecvtxt;
	BOOL	m_clear_after_send;
	CString	m_recvtxt;
	CString	m_sndtxt;
	BOOL	m_enableecho;
	CString	m_host;
	int		m_port;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CNetMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	CWinThread * hStartServerThread, * hReceiveDataThread;

	WSCONNECT Connection;

	WSADATA WsaData;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CNetMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnConnect();
	afx_msg void OnStartsvr();
	afx_msg void OnDisconnect();
	afx_msg LRESULT OnServer (WPARAM wParam, LPARAM lParam);
	afx_msg void OnReturn ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_NETMSGDLG_H__4B6D6BE4_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_)
