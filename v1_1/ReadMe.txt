Net Message
Version 1.1.2
(C) Adrian Glaubitz 2000-2001
adi007@germanynet.de

For new versions check out my website at:

	http://home.germany.net/adi007

Readme


1. What is Net Message ?
2. The Main Dialog
3. Connecting and Chatting
4. FAQ

----------------------------------------------------------

1. Net Message is a small Microsoft Windows program
   that allows to establish a connection over a TCP/IP
   network to exchange messages between two computers.
   This release of Net Message supports connections
   over Windows Sockets using TCP/IP. Thus it is
   compatible with all Winsock compatible
   Windows versions.

2. The main dialog has some buttons and input field
   whose functions are defined below:

   
   Caption	Values		Description
   --------------------------------------------------------

   Receiving	All Text	This text field displays all
				messages received from the
				host (the remote computer) and
				may also display the messages
				you are sending when enabled
   Sending	All Text	In this text field you type all
				the messages to send to the host
   Host(server)	IP-address	The IP-address of the server to
				connect to, the program will only
				accept valid addresses like:
				"127.0.0.1"
   Connect	N/A		Click this button to connect to
				the server specified in "Host(server)"
   Port		Integers	This specifies the port the server
				(1<x<65535) shall listen at or the client shall
				connect at, the default and recommended
				value is "5001", use other values larger
				than "1024" if you have trouble to connect,
				the port must be the same on both client
				and server
   Start Server	N/A		Clicking this button starts a Net Message
				server at the address of the local host
				(this computer) and the specified port
   Disconnect	N/A		Clicking this button will interrupt the
				connection when established and allows
				to make a new connection to other hosts
   Echo my	YES/NO		Enabling this option will display all
   messages			messages send in the receive text field

   Clear messageYES/NO		If you set this option the text field
   field after			for sending messages will be cleared
   send				after pressing the send-button

   Send		N/A		Click this button to send the message
				typed into the "Sending" text field

3. Connecting and Chatting

   To establish a connection between two computers, both computers
   must meet these requirements:

   - both must be running Microsoft Windows 95 or 100% compatible
     operating system
   - both computers must have TCP/IP protocol installed and each
     computer must have a unique IP-address in the network
     (see "Start"->"Settings"->"Control Panel"->"Network")
   - both computers must have Net Message 1.1.0 or higher installed
     and properly working

   One of the computers must act as a server (a computer that waits
   for connections and then "serves" them) and a client (the computer
   that requests information from the server).

   NOTE: At first the server needs to be started and then
         the client can connect otherwise the client will
         display an error-message, that it cannot connect
         with the server.

   To start Net Message in server mode, follow these steps:

   1. Start Net Message
   2. Click the button "Start Server", the server should
      now display a message stating that it is waiting
      for a connection, to abort this procedure, click
      the "Cancel" button in this message window, and
      you will able change settings, reconnect or
      close Net Message before a connection was
      established

   To start Net Message in client mode, follow these steps:

   1. Start Net Message
   2. Type the IP-address of the server to connect to
      in the "Host (server)" text field
   3. Click the "Connect" button

   If any errors occured thus far please start over with the
   steps and consider the note above. If you still cannot
   connect please read the FAQ further down this readme.

   When the connection was successfully established the
   server will close its message window "waiting for
   connection (...)" and enable the "Send" and "Disconnect"
   buttons. The client will also enable these buttons.

   Now with the connection established, you can type
   messages into the "Sending" text field and dispatch
   them with the "Send" button, they will immediately
   appear on the host's Net Message "Receiving" text
   field.

   If you want to disconnect, click the disconnect
   button and you are ready to establish a different
   connection or start the server.

4. FAQ

   Q: Despite several attempts a connection cannot be
      established though one computer is running as a
      server and one as a client

   A: There are several possible reasons for a failed
      attempt to establish a connection:

	  1. The IP-address specified of the server does
	     not match with the actual IP-address of the
	     server, the server can verify the its address
             by starting the program "ipconfig.exe": Open
             the MS-DOS prompt with "Start"->"Programs"->
             "MS-DOS Prompt" (in Windows Me/2000: "Start"
              ->"Programs"->"Accessories"->"MS-DOS Prompt")
             and type at the prompt: "ipconfig.exe". Search
             for the word "IP-Address" and remember the
             IP-address beside. The client must exactly
             specify the same IP-address when trying
             to connect with the server.
      
	  2. The computers did not specify the same port,
             please check if you specified the same number
             for "Port" in Net Message window.

	  3. The TCP/IP protocol is not correctly configured
             on one or both computers, you can configure
             the protocol with "Start"->"Settings"->
             "Control Panel"->"Network". In this window
             you need to check all settings, as this might
             differ from version to version of the Windows
             operating system, please consider the user's
             manual or ask some experienced Windows user
             if you don't know how to configure the
             protocol properly. You should check the file
             "<WINDIR>\HOSTS" (<WINDIR> is the folder
             where Windows has been installed), it must
             contain the IP-address of the host and its
             name.

          4. This version of Net Message is incompatible
             with your system or the misbehavior was caused
             by a bug (error in program code) in the
             Net Message software, in these cases send
             an e-mail to:

			adi007@germanynet.de

             Please specify what Windows version you are
             using and how the misbehavior of the software
             was triggered, I will then try to help you.

   Q: When trying to start the software a message states
      the the file "xyz" is missing (xyz is any filename)
      or the program crashes

   A: There are two possible reasons for this misbehavior:

	  1. Net Message 1.1.0 requires the MFC runtime libraries
	     version 4.2 or higher to be installed on your system,
             go to the Microsoft website to find out where to
             get these files or send me a mail and I will
             send the information:

			adi007@germanynet.de

	  2. See previous questions answer point #4.