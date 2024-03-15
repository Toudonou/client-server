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

#define PORT 30145
#define HOST "192.162.145.90"

typedef struct sockaddr_in sockaddr_in;
typedef struct sockaddr sockaddr;

void recepteur();


#endif //RECEPTEUR_H
