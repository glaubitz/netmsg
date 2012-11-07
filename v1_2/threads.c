/*
* Net Message
* v1.2.0
* threads.c - the program threads
* mar., 01 2002
*/

#include "global.h"

void thread_routing () {

	char buf [130];

	int BytesReceived;

	while ((BytesReceived = ReceiveData (buf, 127, &RoutingConnection)) > 0) {

		// receive routing data, decode command and execute it
	}

}

void thread_receive () {

	char buf [130];

	int BytesReceived;

	while ((BytesReceived = ReceiveData (buf, 127, &ReceiveConnection)) > 0) {

		// receive text data, decode user name and write to window
	}
}