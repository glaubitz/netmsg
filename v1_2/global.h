/*
* Net Message
* v1.2.0
* general.h - general include file
* mar., 01 2002
*/

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "cfgfile.h"
#include "resource.h"


typedef struct __NMUSER {

	char * name;
	unsigned int interfce;

} NMUSER;

typedef struct __ROUTINGTABLE {


	NMUSER * a_nmuser;
	unsigned short n_nmuser;

} ROUTINGTABLE;

typedef struct __WSCONNECT {

	SOCKET Socket;
	unsigned short Port;

} WSCONNECT;

HINSTANCE g_Instance;
WSCONNECT ReceiveConnection;
WSCONNECT RoutingConnection;
unsigned short g_receiveport;
unsigned short g_routingport;

/* winsock.c */

DWORD StartServer (WSCONNECT * Connection);
WSCONNECT ConnectWithServer (unsigned int ServerAddress, unsigned short Port);
DWORD DisConnect (WSCONNECT * Connection);
DWORD SendData (char Data [], int ByteCount, WSCONNECT * Connection);
DWORD ReceiveData (char Data [], int ByteCount, WSCONNECT * Connection);

/* wndproc.c */

BOOL CALLBACK MainDlgProc (HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK AboutDlgProc (HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* threads.c */

void thread_routing ();
void thread_receive ();

/* routing.c */

NMUSER * addnmuser (ROUTINGTABLE * rtable, char * newusername, unsigned int interfce);
BOOL removenmuser (ROUTINGTABLE * rtable, NMUSER * user);