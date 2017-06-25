#ifndef PROJECT_SOCKET_H
#define PROJECT_SOCKET_H
//
#include <netdb.h>
#include <string>
#include <mutex>
#define OK 0
#define NOK -1
#define NO_IP 0
#define MSG_NO_SIGNAL 0

using std::string;

class Socket {
 private:
  int fD;
  struct addrinfo *res;
  int filladdrinfo(const char *ip,const char *port, int
  mode);
  std::mutex m;

 public:
  Socket();
//  abre un socket y luego realiza bind seguido de listen asi queda listo
// para aceptar.
  void setServerMode(string port);
//  abre un socket y lo conecta.
  void setClientMode(string ip, string port);
//  recibe una string precedida por su largo
  string ReceiveStrWLen();
//  envia una string precedida por su largo
  void SendStrWLen(string &str);

  void Create(const char *ip, const char *port, int mode);

  void CreateAndConnect(const char *ip, const char *port);

//Hace un bind y luego un listen.
  void BindAndListen(int backlog);

//Devuelve un nuevo socket para comunicarse con el cliente
//  Socket Accept();

  void Send(unsigned char *source, size_t length);

  int Receive(unsigned char *buffer, size_t length);

  void Shutdown(int mode);

//Cierra el socket y libera addrinfo en caso que corresponda
  void Close();

  bool isConnected();

  virtual ~Socket();
};


#endif //PROJECT_SOCKET_H
