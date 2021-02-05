#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

#define PORT 6953

using namespace std;

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;
    char buffer[1024] = {0};
    string fileName = "../HospitalA.txt";
    string nameHospital = "Hospital A";
    string line;
    ifstream file;

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

    // get port number
    socklen_t len = sizeof(client_addr);
    if (getsockname(sock, (struct sockaddr *)&client_addr, (socklen_t*)&len) == -1)
    {
        perror("getsockname");
        exit(EXIT_FAILURE);
    }else{
        cout << "<Hospital A> has TCP port " << ntohs(client_addr.sin_port) << " and IP address " << inet_ntoa(client_addr.sin_addr) << " for Phase 1";
        cout << endl;
        cout << "<Hospital A> is now connected to the health center" << endl;
    }

    file.open(fileName);
    if (file.is_open()) {
        while (getline(file, line)) {
            send(sock, line.c_str(), strlen(line.c_str()), 0);
            char numDepartment = line[1];
            cout << "<" << nameHospital << "> has sent <department" << numDepartment << "> to the health center" << endl;
        }
        cout << "Updating the health center is done for <" << nameHospital << ">" << endl;
        file.close();
    } else {
        cout << "ERROR: file cannot open." << endl;
    }

    cout << "End of Phase 1 for <" << nameHospital << ">" << endl;
    return 0;
}