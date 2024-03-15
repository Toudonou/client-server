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
    socklen_t len = sizeof(sockaddr_in);
    char message[255];
    const int message_len = 255;
    int connection = 0;
    int id = 0;

    // declaration de la socket
    const int socketId = socket(AF_INET, SOCK_STREAM, 0);

    // initialisation du protocol
    memset(&informations_serveur, 0, len);
    informations_serveur.sin_port = htons(PORT);
    informations_serveur.sin_family = AF_INET;
    informations_serveur.sin_addr.s_addr = inet_addr(HOST);

    bind(socketId, (sockaddr *) &informations_serveur, sizeof(sockaddr));
    listen(socketId, CONNECTIONS_NUMBER);

    while (1) {
        // initialisation les informations clients
        memset(&informations_client, 0, len);

        // accept connection from client
        connection = accept(socketId, (sockaddr *) &informations_client, &len);

        if (connection) {
            id++;

            // child process
            close(socketId);
            printf("Connection acceptée du client %d\n", id);
            write_carac(message, message_len, '\0');
            sprintf(message, "Binevenue client %d\n", id);
            send(connection, message, strlen(message), 0);
            write_carac(message, message_len, '\0');

            do {
                write_carac(message, message_len, '\0');
                recv(connection, message, message_len, 0);

                if (strcmp(message, "aurevoir") == 0) goto sortie;

                printf("Message envoyé par le client %d : %s\n", id, message);

                printf("Réponse : ");
                write_carac(message, message_len, '\0');
                getInformation(message, message_len);

                send(connection, message, strlen(message), 0);

                if (strcmp(message, "aurevoir") == 0) {
                    goto sortie;
                }
            } while (1);

        sortie:
            printf("Fin de la connection\n");
            shutdown(connection, SHUT_RDWR);
            close(connection);
            break;
        }
    }
}
