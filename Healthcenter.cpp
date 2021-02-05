#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <fstream>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 6953
#define MAXDATASIZE 100
#define NUMHOSPITAL 3
#define BACKLOG 5

using namespace std;

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};


// Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

// Forcefully attaching socket to the port 6953
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

// Forcefully attaching socket to the port 6953
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    ofstream outputFile("../HospitalData.txt");
    if (!outputFile.is_open()) {
        cout << "ERROR: outputFile cannot open." << endl;
    }

    for(int i = 0; i < NUMHOSPITAL; i++) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if(i == 0){
            socklen_t len = sizeof(address);
            if(getsockname(new_socket, (struct sockaddr *)&address, &len) == -1){
                perror("getsockname");
                exit(EXIT_FAILURE);
            }
            cout << "The health center has TCP port " << ntohs(address.sin_port) << " and IP address " << inet_ntoa(address.sin_addr) << endl;
        }

        int pid = fork();
        if (pid == 0) { //child process
            close(server_fd);
            char titleHospital;
            if ((valread = recv(new_socket, buffer, MAXDATASIZE - 1, 0)) == -1) {
                perror("recv");
                exit(1);
            }
            titleHospital = buffer[0];
            buffer[valread] = '\0';
            outputFile << buffer << endl;
            cout << "Received the department list from <Hospital " << titleHospital << ">" << endl;
            outputFile.close();
            close(new_socket);
            exit(0);
        }
        wait(NULL);
    }

    close(server_fd);
    cout << "End of Phase 1 for the health center" << endl;
    return 0;
}