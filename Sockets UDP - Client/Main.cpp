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

	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);


	sockaddr_in remoteAddr;
	remoteAddr.sin_family = AF_INET; // IPv4
	remoteAddr.sin_port = htons(8000); // Port
	const char *remoteAddrStr = "127.0.0.1"; // Not so remote...​ :-P
	inet_pton(AF_INET, remoteAddrStr, &remoteAddr.sin_addr);

	sockaddr_in address;
	bind(s, (const sockaddr*)&address, sizeof(address));

	/*int sendto(s, const char * buf, int len, 0, const struct sockaddr * to, int tolen);

	int recvfrom(s, char * buf, int len, 0, struct sockaddr * from, int *fromlen);*/



	//----------------------------------------------------------
	//Tancar Llibreria
	iResult = WSACleanup();

}