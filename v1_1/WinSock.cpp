/*
* Net Message
* v 1.1.2
* WinSock.cpp - windows sockets interface functions
* may, 31 2001
*/

#include "stdafx.h"
#include "winsock.h"

DWORD StartServer (WSCONNECT * Connection) { /* returns Winsock Error Code */

	if (Connection->Port == 0)
		return 0;
	
	struct sockaddr_in Local, Host;

	int HostLength;

	SOCKET ListenSocket, MsgSocket; // do we really need two sockets, Listen and Transfer ??

	// two sockets would be better, as we need one to listen and to
	// transfer and addionally, we could then accept more than one
	// connection

	Local.sin_family = AF_INET;
	Local.sin_addr.s_addr = INADDR_ANY; // use any interface for connection
	Local.sin_port = htons(Connection->Port); // re-arrange the byte order of this word for network

	ListenSocket = socket (AF_INET, SOCK_STREAM, 0); // 0 specifies IP protocol from C:\WINDOWS\PROTOCOL


	if (!ListenSocket)
		return WSAGetLastError ();
	
	/* if this socket != 0, then it is in use,
		the accept () function was terminated by user
		and we need now to close the socket
		and open a new one, this is a bit stupid
		but it works, i'm gonna improve it later on
	*/
	
	if (Connection->Socket != 0)
		closesocket (Connection->Socket);
		
		if (bind (ListenSocket, (struct sockaddr*) &Local,
		sizeof (Local)) == SOCKET_ERROR)
		return WSAGetLastError ();

	if (listen (ListenSocket, 5) == SOCKET_ERROR)
		return WSAGetLastError ();

	Connection->Socket = ListenSocket;


//	while (1) {


	HostLength = sizeof (Host);

	MsgSocket = accept (ListenSocket, (struct sockaddr *) &Host, &HostLength);

	if (MsgSocket == INVALID_SOCKET)
		return WSAGetLastError ();

	closesocket (ListenSocket);

	Connection->Socket = MsgSocket;

	return 0;
//	}
}

DWORD DisConnect (WSCONNECT * Connection) {

	closesocket (Connection->Socket);

	return WSAGetLastError ();
}

WSCONNECT ConnectWithServer (unsigned int ServerAddress, unsigned short Port) {

	WSCONNECT Connection;
	struct hostent * hostinfo;
	struct sockaddr_in Host;

	hostinfo = gethostbyaddr ((char *) &ServerAddress, 4, AF_INET);

	if (!hostinfo) {

		Connection.Socket = 0;

		return Connection;
	}

	ZeroMemory (&Host, sizeof (Host));
	CopyMemory (&(Host.sin_addr), hostinfo->h_addr, hostinfo->h_length);
	Host.sin_family = hostinfo->h_addrtype;
	Host.sin_port = htons (Port);

	Connection.Socket = socket (AF_INET, SOCK_STREAM, 0);

	if (!Connection.Socket)
		return Connection;

	if (connect (Connection.Socket, (struct sockaddr *) &Host,
		sizeof (Host)) == SOCKET_ERROR) {
			closesocket (Connection.Socket); // needed ?
			
			Connection.Socket = 0;
			
			return Connection;
	}
	
	return Connection;
}

DWORD SendData (char Data [], unsigned int ByteCount, WSCONNECT * Connection) {
	
	return send (Connection->Socket, Data, ByteCount, 0);
}

DWORD ReceiveData (char Data [], unsigned int ByteCount, WSCONNECT * Connection) {

	return recv (Connection->Socket, Data, ByteCount, 0);
}