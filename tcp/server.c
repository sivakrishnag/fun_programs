#include <stdio.h> 
#include <unistd.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

#define MAX 80 
#define PORT 7777
#define SA struct sockaddr 

// Function designed for chat between client and server. 
void handle_client (int sockfd) 
{
    char buffer[MAX];
    int bytes_read;

    // infinite loop for chat 
    for (;;) {
        bzero(buffer, MAX);

        // read the message from client and copy it in buffer.
        bytes_read = read(sockfd, buffer, sizeof(buffer)); 

        // if msg contains "Exit" or reached EOF, then server exit and chat ended. 
        if (bytes_read == 0 || strncmp("exit", buffer, 4) == 0) { 
            fprintf(stdout, "Server: Exit...\n"); 
            break; 
        }

        buffer[strlen(buffer) - 1] = 0;
        // print buffer which contains the client contents 
        fprintf(stdout, "Server: Message from client: %s - Length = %lu\n", buffer, strlen(buffer)); 
        bzero(buffer, MAX); 
    }
    close(sockfd);
    fprintf (stdout, "Server: Connection with client closed\n");
    exit (0);
}

void sig_child_handler (int signum) 
{
    fprintf (stdout, "Server: reaping a child process\n");
    wait(NULL);
}

int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cliaddr; 
    signal(SIGCHLD, sig_child_handler);

    // Create a socket to listen on
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        fprintf(stderr, "Server: Socket creation failed..\n"); 
        exit(0); 
    } else {
        fprintf(stdout, "Server: Socket successfully created..\n"); 
    }
    bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 

    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        fprintf(stderr, "Server: Socket bind failed...\n"); 
        exit(0); 
    } else {
        fprintf(stdout, "Server: Socket successfully binded..\n"); 
    }

    // Listen for connections (Queue upto 5 connections)
    if ((listen(sockfd, 5)) != 0) { 
        fprintf(stderr, "Server: Listen failed...\n"); 
        exit(0); 
    } else {
        printf("Server listening..\n"); 
    }
    len = sizeof(cliaddr); 

    while (1) {
        // Accept the data packet from client and verification 
        connfd = accept(sockfd, (SA*)&cliaddr, &len); 
        if (connfd < 0) { 
            fprintf(stderr, "Server: accept failed...\n"); 
            exit(0); 
        } else {
            fprintf(stdout, "Server: accept the client...\n"); 
        }

        {
            pid_t pid = fork();
            switch (pid) {
                case -1:
                    fprintf (stderr, "Server: Unable to fork\n");
                    exit (0);
                    break;
                case 0:
                    /* Child */
                    /* Function for chatting between client and server */
                    handle_client(connfd);
                    break;
                default:
                    /* Go back to accept request */
                    close(connfd);
                    break;
            }
        }
    }

    // After chatting close the socket 
    close(sockfd); 
}
