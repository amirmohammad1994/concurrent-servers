#include "server.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

Server::Server() {}

Server::~Server() {}

Server* Server::Instance() {
  if (instance == nullptr) {
    instance = new Server();
  }
  return instance;
}

void Server::connection(int sockfd) {
  while (1) {
  }
}

void Server::serveConnection(int sockfd) {
  if (send(sockfd, "*", 1, 0) < 1) {
    std::cout << "send error!" << std::endl;
  }

  ProcessingState state = WAIT_FOR_MSG;

  while (true) {
    uint8_t buffer[1024];
    int len = recv(sockfd, buffer, sizeof(buffer), 0);

    if (len < 0) {
      std::cout << "recv error!" << std::endl;
    }

    else if (len == 0) {
      break;
    }

    for (int i = 0; i < len; i++) {
      switch (state) {
        case WAIT_FOR_MSG:
          if (buffer[i] == '^') {
            state = IN_MSG;
          }
          break;
        case IN_MSG:
          if (buffer[i] == '$') {
            state = WAIT_FOR_MSG;
          } else {
            buffer[i] += 1;
            if (send(sockfd, &buffer[i], 1, 0) < 1) {
              std::cout << "send error 2!";
              close(sockfd);
              return;
            }
          }
          break;
        default:
          break;
      }
    }
  }
  close(sockfd);
}

void Server::initialization(int portNumber = 9090) {
  setvbuf(stdout, NULL, _IONBF, 0);
  std::cout << "Serving on port" << portNumber << std::endl;
  int sockfd = listen_in
}

void Server::waitForConnection() {}