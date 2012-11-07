/*
* Net Message
* v1.2.0
* routing.c - routing functions
* mar., 01 2002
*/

#include "global.h"

WSCONNECT CommandConnection;


NMUSER * addnmuser (ROUTINGTABLE * rtable, char * newusername, unsigned int interfce) {

	/*

	1. add to local list
	2. issue message "new user" to all in the list

	*/

	unsigned short i;

	if (rtable) {

		rtable->a_nmuser = realloc (rtable->a_nmuser, sizeof (NMUSER) * (rtable->n_nmuser + 1));

		rtable->a_nmuser [rtable->n_nmuser].name = malloc (lstrlen (newusername) + 1);
		lstrcpy (rtable->a_nmuser [rtable->n_nmuser].name, newusername);

		rtable->a_nmuser [rtable->n_nmuser].interfce = interfce;

		rtable->n_nmuser++;

		for (i = 0; i < rtable->n_nmuser; i++) {

			/* remember, we cannot differentiate whether the add-user command
					came from the new user or from another user at this interface,
					we simply must not inform users, that are accessed over this
					interface
			*/

			if (interfce != rtable->a_nmuser [i].interfce) {
				
				CommandConnection = ConnectWithServer (rtable->a_nmuser [i].interfce, g_routingport);

				SendData ("ADDUSER", lstrlen ("ADDUSER"), &CommandConnection);
				SendData (newusername, lstrlen (newusername), &CommandConnection);

				DisConnect (&CommandConnection);

			}

		}

		return &rtable->a_nmuser [rtable->n_nmuser - 1];
	}
	
	else
		return NULL;
}

BOOL removenmuser (ROUTINGTABLE * rtable, NMUSER * user) {

	/*

	1. remove from local list
	2. issue message "remove user" to all in the list

	*/

	if (rtable) {

		return TRUE;

	}

	else
		return FALSE;
}