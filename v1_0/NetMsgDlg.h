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
public:
	CNetMsgDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CNetMsgDlg)
	enum { IDD = IDD_NETMSG_DIALOG };
	CString	m_msg_for_host;
	CString	m_host_name;
	BOOL	m_send_to_all_users;
	BOOL	m_clear_after_send;
	int		m_repeatcycle;
	BOOL	m_loop;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CNetMsgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CNetMsgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnStoploop();
	afx_msg void OnRenamewin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_NETMSGDLG_H__4B6D6BE4_F80A_11D3_9FB0_F2E125D53E7A__INCLUDED_)
