/*
* Net Message
* v1.2.0
* wndproc.c - window procedures
* mar., 01 2002
*/

#include "global.h"

BOOL CALLBACK MainDlgProc (HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	HMENU hMenu;

	switch (uMsg) {

	case WM_INITDIALOG:

		hMenu = GetSystemMenu (hwndDlg, FALSE);
		EnableMenuItem (hMenu, 0, MF_BYPOSITION | MF_GRAYED);
		EnableMenuItem (hMenu, 2, MF_BYPOSITION | MF_GRAYED);
		EnableMenuItem (hMenu, 4, MF_BYPOSITION | MF_GRAYED);
		break;

	case WM_ACTIVATE:

		SetFocus (GetDlgItem (hwndDlg, ID_SENDMESSAGE));

		break;

	case WM_SIZE:

		if (wParam == SIZE_MINIMIZED) {
		
			hMenu = GetSystemMenu (hwndDlg, FALSE);
			EnableMenuItem (hMenu, 0, MF_BYPOSITION | MF_ENABLED);
		}
		else {
			hMenu = GetSystemMenu (hwndDlg, FALSE);
			EnableMenuItem (hMenu, 0, MF_BYPOSITION | MF_GRAYED);
		}
		break;

	case WM_CLOSE:

		EndDialog (hwndDlg, 0);
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam)) {

		case ID_CONNECTIONONLINE:

			break;

		case ID_CONNECTIONOFFLINE:

			break;

		case ID_CONNECTIONQUIT:

			EndDialog (hwndDlg, ID_CONNECTIONQUIT);
			break;

		case ID_HELPABOUT:

			DialogBox (g_Instance, MAKEINTRESOURCE(ID_ABOUTDLG), hwndDlg, AboutDlgProc);
			break;

		default:
			break;
		}
	
	default:
		return 0;

	}
}

BOOL CALLBACK AboutDlgProc (HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	switch (uMsg) {

	case WM_CLOSE:

		EndDialog (hwndDlg, 0);
		break;

	case WM_COMMAND:

		switch (LOWORD(wParam)) {

		case ID_CLOSE:
		
			EndDialog (hwndDlg, 0);

		default:
			break;
		}

	default:
		return 0;
	}
}