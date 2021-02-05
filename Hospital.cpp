//
// Created by hxm on 6/25/2020.
//

#include "Hospital.h"
#include <iostream>

// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

#define PORT 8080

using namespace std;

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

// Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }


    string fileName = "../HospitalA.txt";
    string id = "HospitalA";

    // create two child process, only parent creates child process
    int status;
    for(int i = 0; i < 2; i++){
        status = fork();

        if(status == -1){
            cout << "fork error" << endl;
            return 0;
        } else if(status == 0) {
            if(i == 0) {
                id = "HospitalB";
                fileName = "../HospitalB.txt";
            } else if (i == 1) {
                id = "HospitalC";
                fileName = "../HospitalC.txt";
            }
            break; // if it's child process, break the loop.
        }

    }

//    string fileName = "../HospitalA.txt";

    string line;
    ifstream file;
    file.open(fileName);

    if(file.is_open()){
        while(getline(file, line)){
            line += '\n';
            send(sock, line.c_str(), strlen(line.c_str()), 0);
            // <Hospital #> has sent <department> to the admission office
            cout << "<" << id << "> has sent <department" << line[1] <<"> to the health center" << endl;
        }
        cout << "Updating the admission office is done for <"  << id << ">" << endl;
        file.close();
    }else{
        cout << "error: file cannot open." << endl;
    }

    printf("Message sent\n");

    return 0;
}