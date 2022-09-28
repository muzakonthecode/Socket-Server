#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
{
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[500] = "Hello from the Server";
    char recv_buffer[500];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001);
    server_addr.sin_addr.s_addr = inet_addr("");

    bind(server_socket, (struct server_addr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    client_socket = accept(server_socket, NULL, NULL);
    printf("CLient Connected!\n");
    send(client_socket, buffer, sizeof(buffer), 0);
    recv(client_socket, recv_buffer, sizeof(recv_buffer), 0);
    printf("Client has sent :  %s", recv_buffer);
    close(server_socket);
    return 0;
}
