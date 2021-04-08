// int listen_inet_socket(int portnum) {
//   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//   if (sockfd < 0) {
//     perror_die("ERROR opening socket");
//   }

//   // This helps avoid spurious EADDRINUSE when the previous instance of this
//   // server died.
//   int opt = 1;
//   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
//     perror_die("setsockopt");
//   }

//   struct sockaddr_in serv_addr;
//   memset(&serv_addr, 0, sizeof(serv_addr));
//   serv_addr.sin_family = AF_INET;
//   serv_addr.sin_addr.s_addr = INADDR_ANY;
//   serv_addr.sin_port = htons(portnum);

//   if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
//     perror_die("ERROR on binding");
//   }

//   if (listen(sockfd, N_BACKLOG) < 0) {
//     perror_die("ERROR on listen");
//   }

//   return sockfd;
// }
