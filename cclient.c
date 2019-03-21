#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
	char cclient_msg[256] = "Ni hao ma" ;
	char cclient_respond[256] ;
	int network_socket ;
	network_socket = socket(AF_INET, SOCK_STREAM, 0) ;

	struct sockaddr_in cclient_address ;
	cclient_address.sin_family = AF_INET ;
	cclient_address.sin_port = htons(10000) ;
	cclient_address.sin_addr.s_addr = inet_addr("ipaddr") ;

	int status = connect(network_socket, (struct sockaddr *) 
&cclient_address, sizeof(cclient_address)) ;

	if(status == -1)
	{
		printf("Error\n") ;
	}

	send (network_socket, cclient_msg, sizeof(cclient_msg) ,0) ;

	recv(network_socket, cclient_respond, sizeof(cclient_respond) , 
0) ;

	printf("Client message : %s\n" , cclient_respond) ;
	close(network_socket) ;

	return 0 ;


}
