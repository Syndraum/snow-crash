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
#define MAX_CLIENT 32

typedef unsigned int uint;

typedef struct	s_client {
	size_t	id;
	int		fd;
	ssize_t		read;
	uint	len;
	struct sockaddr_in	addr;
	char				buffer[BUFFER_SIZE + 1];
}				t_client;

typedef struct	s_server {
	int	fd;
	size_t	nb_fd;
	int	run;
	struct sockaddr_in addr;
	struct pollfd	set[2 + MAX_CLIENT];
}				t_server;

void add_pollfd(t_server *server, int fd) {
	struct pollfd	*pollfd = (server->set) + server->nb_fd;

	pollfd->fd = fd;
	pollfd->events = POLLIN;
	pollfd->revents = 0;
	(server->nb_fd)++;
}

void remove_client(t_server *server, t_client *client) {
	size_t i;

	close(client->fd);
	for (i = client->id; i < server->nb_fd - 2 -1; i++)
	{
		client[i] = client[i + 1];
		server->set[client->id + 2] = server->set[client->id + 2 + 1];
	}
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
	if (listen(server->fd, MAX_CLIENT) == -1)
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

void connection(t_server *server, t_client *clients) {
	t_client *client = clients + server->nb_fd - 2;

	bzero(client, sizeof(*client));
	client->fd = accept(server->fd, (struct sockaddr *)&client->addr, &(client->len));
	if (client->fd == -1)
		err(4, "accept");
	client->id = server->nb_fd - 2;
	add_pollfd(server, client->fd);
	printf("new client accepted\n");
}

void read_msg(t_client *client, t_server *server) {
	client->read = recv(client->fd, client->buffer, BUFFER_SIZE, 0);
	if (client->read == -1)
		err(5, "recv");
	if (client->read == 0) {
		remove_client(server, client);
		return;
	}
	printf("read %ld character from client\n===========================\n", client->read);
	write(1, client->buffer, client->read);
	printf("\n===========================\n");
}

void	clean_revent(t_server *server) {
	size_t i;
	
	for (i = 0; i < server->nb_fd; i++)
		(server->set + i)->revents = 0;
}

void wait_client(t_server *server, t_client *clients) {
	t_client	*client = 0;
	size_t i;

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
			connection(server, clients);
		for (i = 2; i < server->nb_fd; i++)
		{
			client = clients + i - 2;
			if ((server->set + i)->revents & POLLIN) {
				read_msg(client, server);
				if (client->read == 0)
					i--;
			}
		}
		clean_revent(server);
	}
}

void close_server(t_server *server) {
	size_t i;
	
	for (i = 1; i < server->nb_fd; i++)
		close(server->set[i].fd);
	printf("close server\n");
}

int main () {
	t_server server;
	t_client clients[MAX_CLIENT];

	create_server(&server);
	wait_client(&server, clients);
	close_server(&server);
	return (0);
}