/*
Net Message
v 1.0.0

Send.cpp
*/

#include "stdafx.h"
#include "NetMsg.h"

void SendMsg (CString MSG_FOR_HOST, CString HOST_NAME, BOOL send_to_all_users) {
	
	if (send_to_all_users)
		HOST_NAME = "/USERS";

	CString command_line = "net send " + HOST_NAME + " " + MSG_FOR_HOST;
	LPCSTR p_command_line = &*command_line;
	/*
	WinExec (p_command_line, 0);
	*/

	ShellExecute (NULL, "open", p_command_line, NULL, NULL, SW_SHOWMINIMIZED);
}

/*
Notes on WinExec()

If the function succeeds, the return value is greater than 31.
If the function fails, the return value is one of the following error values: 

Value Meaning

0 The system is out of memory or resources. 
ERROR_BAD_FORMAT The .EXE file is invalid (non-Win32 .EXE or error in .EXE image). 
ERROR_FILE_NOT_FOUND The specified file was not found. 
ERROR_PATH_NOT_FOUND The specified path was not found. 
*/