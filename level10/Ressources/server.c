#include <sys/types.h>
#include <sys/socket.h>
#include <err.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <poll.h>

#define BUFFER_SIZE 255
#define PIVOT 1

typedef unsigned int uint;

typedef struct	s_client {
	int		fd;
	uint	len;
	struct	sockaddr_in addr;
	char	buffer[BUFFER_SIZE + 1];
	int		read;
}				t_client;

typedef struct	s_server {
	int	fd;
	int	nb_fd;
	int	run;
	struct sockaddr_in addr;
	struct pollfd	set[3];
}				t_server;

void add_pollfd(t_server *server, int fd) {
	struct pollfd	*pollfd = (server->set) + server->nb_fd;

	pollfd->fd = fd;
	pollfd->events = POLLIN;
	pollfd->revents = 0;
	(server->nb_fd)++;
}

void remove_client(t_server *server, t_client *client) {
	close(client->fd);
	client->fd = 0;
	(server->nb_fd)--;
	printf("remove client\n");
}

void create_server(t_server *server) {
	bzero(server, sizeof(*server));
	server->fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server->fd ==  -1)
		err(1, "socket");
	server->addr.sin_family = AF_INET;
	server->addr.sin_addr.s_addr = htonl(2130706433);
	server->addr.sin_port = htons(6969);
	if (bind(server->fd, (const struct sockaddr *)&(server->addr), sizeof(server->addr)) == -1 )
		err(2, "bind");
	if (listen(server->fd, 5) == -1)
		err(3, "listen");
	server->run = 1;
}

void read_stdin(t_server *server) {
	char	buffer[BUFFER_SIZE + 1]	= {0};
	ssize_t	_read					= 0;
	
	_read = read(server->set->fd, buffer, BUFFER_SIZE);
	if (_read == -1)
		perror("read");
	if (_read == 0) {
		server->run = 0;
	}
}

void connection(t_server *server, t_client *client) {
	bzero(client, sizeof(*client));
	client->fd = accept(server->fd, (struct sockaddr *)&client->addr, &(client->len));
	add_pollfd(server, client->fd);
	if (client->fd == -1)
		err(4, "accept");
	printf("new client accepted\n");
}

void read_msg(t_client *client, t_server *server) {
	client->read = recv(client->fd, client->buffer, BUFFER_SIZE, 0);
	if (client->read == -1)
		err(5, "accept");
	if (client->read == 0) {
		remove_client(server, client);
		return;
	}
	printf("read %d character from client\n=========\n", client->read);
	write(1, client->buffer, client->read);
	printf("\n=========\n");
}

void	clean_revent(t_server *server) {
	size_t i;
	
	for (i = 0; i < 3; i++)
		(server->set + i)->revents = 0;
}

void wait_client(t_server *server, t_client *client) {
	add_pollfd(server, 0);
	add_pollfd(server, server->fd);

	printf("wait for client...\n");
	while (server->run)
	{
		if (poll(server->set, server->nb_fd, -1) == -1)
			err(1, "poll");
		if (server->set->revents & POLLIN)
			read_stdin(server);
		if ((server->set + 1)->revents & POLLIN)
			connection(server, client);
		if (server->nb_fd > PIVOT && (server->set + 2)->revents & POLLIN)
			read_msg(client, server);
		clean_revent(server);
	}
}

void close_server(t_server *server, t_client *client) {
	if (client->fd)
		close(client->fd);
	close(server->fd);
	printf("close server\n");
}

int main () {
	t_server server;
	t_client client;

	create_server(&server);
	wait_client(&server, &client);
	close_server(&server, &client);
}