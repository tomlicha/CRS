//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
if(args.size()!=3)
  {
  crs::err("usage: % destination port\n",args[0]);
  crs::exit(1);
  }

//---- extract destination IP address ----
uint32_t ipAddress=0;
(void)ipAddress; // avoid ``unused variable'' warning
//
// ... À COMPLÉTER {1} ...
//
// Déterminer dans ``ipAddress'', à l'aide de ``crs::gethostbyname()'',
// l'adresse IP de ``args[1]''.
//
ipAddress = crs::gethostbyname(args[1]);
//...

//---- extract destination port number ----
uint16_t portNumber=uint16_t(std::stoi(args[2]));
(void)portNumber; // avoid ``unused variable'' warning

//---- create UDP socket ----
//
// ... À COMPLÉTER {2} ...
//
// Créer avec ``crs::socket()'' une socket UDP.
//
int socket = crs::socket(PF_INET,SOCK_DGRAM,0);
// ...

for(;;) // as long as dialog can go on...
  {
  //---- read next line on standard-input ----
  crs::out("host '%' waiting for user input... (text line)\n",
           crs::gethostname());
  auto msg=crs::readLine(STDIN_FILENO); // [Control]+[d] --> EOF
  if(msg.empty()) { crs::out("<EOF>\n"); break; }

  //---- send message to the specified destination/port ----
  //
  // ... À COMPLÉTER {4} ...
  //
  // Envoyer, à l'aide de ``crs::sendto()'', le message textuel ``msg'' au
  // serveur désigné par ``ipAddress'' et ``portNumber''.
  //
  int sendingMessage = crs::sendto(socket,msg,ipAddress,portNumber);
  // ...

  //---- receive and display reply and source address/port ----
  std::string reply;
  //
  // ... À COMPLÉTER {5} ...
  //
  // Recevoir dans ``reply'' la réponse (textuelle) depuis la socket UDP
  // avec ``crs::recvfrom()''.
  // Afficher le texte reçu ainsi que l'adresse IP et le port d'où
  // il provient (normalement ce doit être le serveur sollicité).
  //
  uint32_t fromAddr;
  uint16_t fromPort;
  reply = crs::recvfrom(socket,sendingMessage,fromAddr,fromPort);
  // ...
  }

//---- close UDP socket ----
//
// ... À COMPLÉTER {3} ...
//
// Fermer la socket avec ``crs::close()''.
//
crs::close(socket);
// ...

return 0;
}

//----------------------------------------------------------------------------
