//
// Created by toudonou on 28/02/24.
//

#ifndef SERVEUR_H
#define SERVEUR_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <stdio.h>

#define PORT 3000
#define HOST "127.0.0.1"
#define CONNECTIONS_NUMBER 5

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

void serveur();

#endif //SERVEUR_H
