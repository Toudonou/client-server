//
// Created by toudonou on 29/02/24.
//

#include "client.h"

void write_carac(char message[], const int size, const char carac) {
    for (int i = 0; i < size; ++i) message[i] = carac;
}

void getInformation(char message[], const int message_lenght) {
    if (message_lenght <= 0) return ;
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        message[i++] = c;
    }
    message[i] = '\0';
}

void recepteur() {
    char  message[255];
    const int message_len = 255;


    sockaddr_in informations_serveur;
    socklen_t serveur_taille = sizeof(informations_serveur);

    // initialisation TCP
    informations_serveur.sin_family = AF_INET;
    informations_serveur.sin_port = htons(PORT);
    informations_serveur.sin_addr.s_addr = inet_addr(HOST);

    const int socketId = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

//    connect(socketId, (sockaddr *) &informations_serveur, sizeof(sockaddr_in));


    do {
        printf("moi : ");
        write_carac(message, message_len, '\0');
        getInformation(message, message_len);
        if(strcmp(message, "deconnexion") == 0){
            printf("Déconnexion");
            shutdown(socketId, SHUT_RDWR);
            break;
        }
//        if (send(socketId, message, strlen(message), 0) == -1) perror("send");
        if (sendto(socketId, message, strlen(message), 0, (sockaddr *) &informations_serveur, serveur_taille) <= -1) perror("send");
//        if (strcmp(message, "aurevoir") == 0) break;
//
//        write_carac(message, message_len, '\0');
//        recvfrom(socketId, message, message_len, 0, (sockaddr *) &informations_serveur, &serveur_taille);
//        printf("Phrase reçue : %s\n", message);
    } while (strcmp(message, "aurevoir") != 0);

    printf("Fin de la connection\n");
}
