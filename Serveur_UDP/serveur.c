//
// Created by toudonou on 28/02/24.
//

#include "serveur.h"

void write_carac(char message[], const int size, const char carac) {
    for (int i = 0; i < size; ++i) message[i] = carac;
}

void getInformation(char message[], const int message_lenght) {
    if (message_lenght <= 0) return;
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        message[i++] = c;
    }
    message[i] = '\0';
}

void serveur() {
    sockaddr_in informations_serveur;
    sockaddr_in informations_client;
    socklen_t serveur_taille = sizeof(informations_serveur);

    socklen_t len = sizeof(sockaddr_in);
    char message[255];
    const int message_len = 255;
    int id = 0;

    // declaration de la socket
    const int socketId = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    // initialisation du protocol
    memset(&informations_serveur, 0, len);
    informations_serveur.sin_port = htons(PORT);
    informations_serveur.sin_family = AF_INET;
    informations_serveur.sin_addr.s_addr = inet_addr(HOST);

    bind(socketId, (sockaddr *) &informations_serveur, sizeof(sockaddr));
    listen(socketId, CONNECTIONS_NUMBER);

//    close(socketId);
//    printf("Connection acceptée du client %d\n", id);
//    write_carac(message, message_len, '\0');
//    sprintf(message, "Binevenue client %d\n", id);
//
//    sendto(socketId, message, strlen(message), 0, (sockaddr *) &informations_serveur, serveur_taille);
//    write_carac(message, message_len, '\0');

    do {
        memset(&informations_client, 0, len);

        write_carac(message, message_len, '\0');
        recvfrom(socketId, message, message_len, 0, (sockaddr *) &informations_client, &serveur_taille);

//        if (strcmp(message, "aurevoir") == 0) goto sortie;

        printf("Message envoyé par %s : %s\n", inet_ntoa(informations_client.sin_addr), message);

//        printf("Réponse : ");
//        write_carac(message, message_len, '\0');
//        getInformation(message, message_len);
//
//        sendto(socketId, message, strlen(message), 0, (sockaddr *) &informations_serveur, serveur_taille);

//        if (strcmp(message, "aurevoir") == 0) {
//            goto sortie;
//        }
    } while (1);

    sortie:
    printf("Fin de la connection\n");
//    shutdown(connection, SHUT_RDWR);
//    close(connection);

}
