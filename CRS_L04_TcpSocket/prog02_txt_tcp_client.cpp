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
// ...

//---- extract destination port number ----
uint16_t portNumber=uint16_t(std::stoi(args[2]));
(void)portNumber; // avoid ``unused variable'' warning

//---- create client socket ----
//
// ... À COMPLÉTER {2} ...
//
// Créer avec ``crs::socket()'' une socket TCP.
// Utiliser ``crs::connect()'' pour la connecter à l'adresse IP et au port
// du serveur visé.
//
auto socketTCP = crs::socket(AF_INET,SOCK_STREAM,0);
crs::connect(socketTCP,ipAddress,portNumber);
// ...

for(;;) // as long as dialog can go on...
  {
  //---- read next line on standard-input ----
  crs::out("host '%' waiting for user input... (text line)\n",
           crs::gethostname());
  auto msg=crs::readLine(STDIN_FILENO); // [Control]+[d] --> EOF
  if(msg.empty()) { crs::out("<EOF>\n"); break; }

  //---- send message to server ----
  //
  // ... À COMPLÉTER {4} ...
  //
  // Envoyer, à l'aide de ``crs::send()'', le message textuel ``msg'' au
  // serveur à travers la connexion TCP qui nous y relie.
  //
  crs::send(socketTCP,msg);
  // ...

  //---- receive and display reply ----
  std::string reply;
  //
  // ... À COMPLÉTER {5} ...
  //
  // Recevoir dans ``reply'' la réponse (textuelle) du serveur depuis la
  // connexion TCP qui nous y relie.
  // Si le texte reçu est vide, cela signifie que la fin-de-fichier (EOF)
  // est atteinte (le client a fermé la connexion) ; il suffit de quitter
  // la boucle de dialogue avec ``break;'', sinon afficher le texte reçu.
  reply = crs::recv(socketTCP,0x100);
  if (reply.empty()){
    break;
  }
  crs::out("%\n",reply);
  // ...
  }

//---- close client socket ----
//
// ... À COMPLÉTER {3} ...
//
// Fermer la socket avec ``crs::close()''.
//
crs::close(socketTCP);
// ...

return 0;
}

//----------------------------------------------------------------------------
