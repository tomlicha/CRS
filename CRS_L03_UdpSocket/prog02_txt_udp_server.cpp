//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
if(args.size()!=2)
  {
  crs::err("usage: % port\n",args[0]);
  crs::exit(1);
  }

//---- extract local port number ----
uint16_t portNumber=uint16_t(std::stoi(args[1]));

//---- create UDP socket ----
//
// ... À COMPLÉTER {1} ...
//
// Créer avec ``crs::socket()'' une socket UDP, et utiliser ``crs::bind()'' 
// pour qu'elle soit associée au port ``portNumber'' de la machine.
//
int socket = crs::socket(PF_INET,SOCK_DGRAM,0);
crs::bind(socket,portNumber);
// ...

for(;;) // as long as dialog can go on...
  {
  //---- receive and display request and source address/port ----
  crs::out("host '%' waiting for an UDP message on port '%'...\n",
           crs::gethostname(),portNumber);
  std::string request;
  //
  // ... À COMPLÉTER {3} ...
  //
  // Recevoir dans ``request'' du texte depuis la socket UDP avec
  // ``crs::recvfrom()''.
  // Afficher le texte reçu ainsi que l'adresse IP et le port d'où
  // il provient.
  //
  uint32_t fromAddr;
  uint16_t fromPort;
  request = crs::recvfrom(socket,0x100,fromAddr,fromPort);
  crs::write(STDOUT_FILENO,crs::txt("from (%:%) :%",crs::formatIpv4Address(fromAddr),fromPort,request));

  //---- prepare reply ----
  auto reply=crs::txt("server received % bytes\n",request.size());

  //---- send reply to client ----
  //
  // ... À COMPLÉTER {4} ...
  //
  // Envoyer avec ``crs::sendto()'', la réponse ``reply'' au client
  // qui nous a sollicité.
  //
  crs::sendto(socket,reply,fromAddr,fromPort);
  // ...
  }

//---- close UDP socket ----
//
// ... À COMPLÉTER {2} ...
//
// Fermer la socket avec ``crs::close()''.
// Même si cette portion de code n'est jamais atteinte ici (dans ce programme
// simpliste), il faut toujours se poser la question de la fermeture !
//
crs::close(socket);
// ...

return 0;
}

//----------------------------------------------------------------------------
