/* 
 * A server that returns your public IP address upon an http request. 
 * The main purpose is to make scripting easier involving IP easier.
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80


void _abort(char* errormsg) {

	puts(errormsg);
	exit(0);

}

int main() {

	//buffer to store incoming request to
	char buf[10000];

	//starting socker, socket to redirect to
	struct sockaddr_in servaddr, rediraddr;
	//new socket size
	socklen_t newsocket_size;
	int sockfd, bound, redirsock;

	//allocate socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//check if successful
	if (sockfd < 0) {
	
		_abort("Unable to allocate socket\n");	
	
	}

	memset(&servaddr, '\0', sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	//servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_addr.s_addr = inet_addr("67.205.162.66");

	bound = bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));


	//try to bind socket
	if(listen(sockfd, 10) == 0){
		printf("Bound socket %i!\n", PORT);
	}else{
		_abort("[-]Error in binding.\n");
	}


	while(1){

		//accept new connection
		redirsock = accept(sockfd, (struct sockaddr*)&rediraddr, &newsocket_size);
		if(redirsock < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(rediraddr.sin_addr), ntohs(rediraddr.sin_port));
		
		if(!fork()){

			//terminate previous input socket
			close(sockfd);

			//copy incoming message to buffer
			read(redirsock, buf, 10000);

			//just print buffer for now
			puts(buf);

			//create a new buffer to send the ip address in
			char* ipaddr;
			ipaddr = inet_ntoa(rediraddr.sin_addr);
			
			//convert ip address to string and send it
			send(redirsock, ipaddr, strlen(ipaddr), 0);
			bzero(ipaddr, sizeof(ipaddr));
			puts(ipaddr);

			close(redirsock);
		
		}

		close(redirsock);
	
	}




	return 0;




}

