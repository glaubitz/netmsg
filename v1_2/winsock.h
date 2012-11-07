/*
* Net Message
* v1.2.0
* winsock.h - include file for WinSock.cpp
* may, 31 2001
*/

#include <winsock2.h>

/*
	we put the socket into a struct so that
	we have space for additional (future)
	variables
*/

typedef struct __WSCONNECT {

	SOCKET Socket;
	int Port;

} WSCONNECT;

DWORD StartServer (WSCONNECT * Connection);

WSCONNECT ConnectWithServer (unsigned int ServerAddress, int Port);

DWORD DisConnect (WSCONNECT * Connection);

DWORD SendData (char Data [], int ByteCount, WSCONNECT * Connection);

DWORD ReceiveData (char Data [], int ByteCount, WSCONNECT * Connection);
