/*
* Net Message
* v1.2.0
* netmsg.c - startup program code
* mar., 01 2002
*/

#include "global.h"

HINSTANCE g_Instance;

int WINAPI WinMain (HINSTANCE Instance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow) {

	g_Instance = Instance;

	DialogBox (Instance, MAKEINTRESOURCE(ID_MAINDLG), NULL, MainDlgProc);

	return 0;
}