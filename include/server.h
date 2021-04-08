#ifndef __SERVER_H__
#define __SERVER_H__

class Server {
 public:
  ~Server();
  static Server* Instance();
  void connection(int sockfd);
  void serveConnection(int sockfd);
  void initialization(int portNumber);
  void waitForConnection();

 private:
  Server();
  static Server* instance;
};

typedef enum {WAIT_FOR_MSG , IN_MSG} ProcessingState;

#endif  // __SERVER_H__
