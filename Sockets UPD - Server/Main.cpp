#define WIN32_LEAN_AND_MEAN
#define NOMINAX
#include "Windows.h"
#include "WinSock2.h"
#include "Ws2tcpip.h"


int main(int argc, char **argv)
{
	//Obrir Llibreria
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
	{
		// Log and handle error
		return false;
	}
	//----------------------------------------------------------

	//Socket
	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);

	//Bind
	int bind(s, const struct sockaddr * address, int address_len);

	//----------------------------------------------------------
	//Tancar Llibreria
	iResult = WSACleanup();
}