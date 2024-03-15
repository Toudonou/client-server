//
// Created by toudonou on 29/02/24.
//

#ifndef RECEPTEUR_H
#define RECEPTEUR_H


#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>

#define PORT 3000
#define HOST "127.0.0.1"

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

void recepteur();


#endif //RECEPTEUR_H
