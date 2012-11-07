/*
* Net Message
* v1.1.2
* WinSock.h - include file for WinSock.cpp
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
	unsigned short Port;

} WSCONNECT;

DWORD StartServer (WSCONNECT * Connection);

WSCONNECT ConnectWithServer (unsigned int ServerAddress, unsigned short Port);

DWORD DisConnect (WSCONNECT * Connection);

DWORD SendData (char Data [], unsigned int ByteCount, WSCONNECT * Connection);

DWORD ReceiveData (char Data [], unsigned int ByteCount, WSCONNECT * Connection);
