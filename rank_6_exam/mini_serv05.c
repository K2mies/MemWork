#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

fd_set	readfds, activefds;
int	clients[FD_SETSIZE], count = 0, sockfd;
char	*msgs[FD_SETSIZE], in_buf[100001], out_buf[100001];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void	fatal_error(void)
{
	write( 2, "Fatal error\n", 13 );
	exit( 1 );
}

void	notify( int sent )
{
	for ( int fd = 3; fd < FD_SETSIZE; fd++ )
	{
		if ( FD_ISSET( fd, &activefds) && fd != sent && fd != sockfd)
			send( fd, out_buf, strlen( out_buf ), 0);
	}
}


int main( int argc, char **argv ) {
	if ( argc != 2 )
	{
		write( 2, "Wrong number of arguments\n", 27 );
		exit( 1 );
	}
	int connfd;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n");
	if (listen(sockfd, 10) != 0) {
		printf("cannot listen\n"); 
		exit(0); 
	}

	FD_ZERO( &activefds );
	FD_SET(sockfd, &activefds );

	while ( 1 )
	{
		readfds = activefds;
		if ( select( FD_SETSIZE, &readfds, NULL, NULL, NULL) < 0 )
		       continue;
		for ( int fd = 3; fd < FD_SETSIZE; fd++ )
		{
			if ( !FD_ISSET(fd, &readfds ) )
				continue;
			if ( fd == sockfd )
			{
				socklen_t len = sizeof( cli );
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0) { 
			        printf("server acccept failed...\n"); 
			        exit(0); 
			    	} else
			        	printf("server acccept the client...\n");
				FD_SET(connfd, &activefds);
				clients[connfd] = count;
				count++;
				msgs[connfd] = NULL;
				sprintf( out_buf, "server: client %d has arrived\n", clients[connfd]);
				notify( connfd );
			}
			else
			{
				int rec_bytes = recv( fd, in_buf, 100000, 0 );
				if ( rec_bytes <= 0 )
				{
					sprintf( out_buf, "server: client %d has left\n", clients[fd] );
					notify( fd );
					FD_CLR( fd, &activefds );
					free( msgs[fd] );
					msgs[fd] = NULL;
					close(fd);
					break;
				}
				else
				{
					in_buf[rec_bytes] = '\0';
					msgs[fd] = str_join( msgs[fd], in_buf );
					char	*temp = NULL;
					while ( extract_message( &(msgs[fd]), &temp ) )
					{
						sprintf( out_buf, "client %d: %s", clients[fd], temp );
						notify( fd );
						free( temp );
					}
				}
			}
		}	
	}
}
