//----------------------------------------------------------------------------

#include "crsUtils.hpp"

void
dialogThread(SOCKET dialogSocket)
{
(void)dialogSocket; // avoid ``unused parameter'' warning
try
  {
  for(;;) // as long as dialog can go on...
    {
    //---- receive and display request from client ----
    std::string request;
    //
    // ... À COMPLÉTER {6} ...
    //
    // Recevoir dans ``request'' du texte depuis la socket de dialogue TCP
    // avec ``crs::recv()''.
    // Si le texte reçu est vide, cela signifie que la fin-de-fichier (EOF)
    // est atteinte (le client a fermé la connexion) ; il suffit de quitter
    // la boucle de dialogue avec ``break;'', sinon afficher le texte reçu.
    //
    // (identique à prog01_txt_mono_tcp_server.cpp)
    //
    request = crs::recv(dialogSocket,0x100);
    if (request.empty()){
      break;
    }
    crs::out("%\n",request);
    // ...

    //---- prepare reply ----
    auto reply=crs::txt("server received % bytes\n",request.size());

    //---- send reply to client ----
    //
    // ... À COMPLÉTER {7} ...
    //
    // Envoyer avec ``crs::send()'', la réponse ``reply'' au client à
    // travers la socket de dialogue TCP qui nous y relie.
    //
    // (identique à prog01_txt_mono_tcp_server.cpp)
    //
    crs::send(dialogSocket,reply);
    // ...
    }
  }
catch(std::exception &e)
  { crs::err("\n!!! Exception: % !!!\n",e.what()); }
catch(...)
  { crs::err("\n!!! Unknown exception !!!\n"); }

//---- close dialog socket in any case! ----
//
// ... À COMPLÉTER {5} ...
// 
crs::close(dialogSocket);
// Fermer la socket de dialogue avec ``crs::close()''.
// Que le dialogue se soit terminé normalement ou qu'une exception soit
// survenue, il est important de fermer cette socket de dialogue désormais
// inutile lorsque ce thread se termine !
//

// ...

crs::out("client disconnected\n");
}

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

//---- create listen socket ----
//
// ... À COMPLÉTER {1} ...
//
// Créer avec ``crs::socket()'' une socket TCP, et utiliser ``crs::bind()''
// pour qu'elle soit associée au port ``portNumber'' de la machine.
// Il s'agit d'une socket d'écoute ; ceci sera spécifié par l'appel à
// ``crs::listen()''.
//
// (identique à prog01_txt_mono_tcp_server.cpp)
//
auto socketEcoute = crs::socket(AF_INET,SOCK_STREAM,0);
crs::setReuseAddrOption(socketEcoute,true);
crs::bind(socketEcoute,portNumber);
crs::listen(socketEcoute,SOCK_STREAM);
// ...

crs::out("host '%' waiting for connections on port '%'...\n",
         crs::gethostname(),portNumber);
for(;;)
  {
  //---- accept and display new connection ----
  //
  // ... À COMPLÉTER {3} ...
  //
  // Accepter, à l'aide de ``crs::accept()'', la prochaine connexion sur la
  // socket d'écoute.
  // Cette opération fait apparaître une socket de dialogue TCP.
  // Afficher les coordonnées du client qui est à l'origine de cette
  // connexion.
  //
  // (identique à prog01_txt_mono_tcp_server.cpp)
  //
  uint32_t out_address;
  uint16_t out_port;
  auto socketDiag = crs::accept(socketEcoute,out_address,out_port);
  crs::out("coordonnées du client : % : %",crs::formatIpv4Address(out_address),out_port);
  // ...

  //---- start a new dialog thread ----
  //
  // ... À COMPLÉTER {4} ...
  //
  // Démarrer un thread qui va exécuter le dialogue avec ce nouveau client
  // en parallèle de cette boucle qui se contente d'accepter les nouvelles
  // connexions.
  // Le dialogue en question aura lieu dans la fonction ``dialogThread()''
  // (définie plus haut) qui attend en paramètre la socket de dialogue qui
  // vient d'être créée lors de l'acceptation précédente.
  // Pour démarrer un tel thread, nous utilisons :
  //   std::thread th( nom_de_la_fonction, paramètres_de_cette_fonction... );
  // Ce thread (variable ``th'') doit être détaché, c'est à dire que nous le
  // laissons travailler en arrière plan et retournons accepter la prochaine
  // connexion sans attendre qu'il ait fini son travail.
  // Pour cela, nous utilisons ``th.detach();''.
  //
  std::thread th( dialogThread, socketDiag );
  th.detach();
  // ...
  }

//---- close listen socket ----
//
// ... À COMPLÉTER {2} ...
//
// Fermer la socket d'écoute avec ``crs::close()''.
// Même si cette portion de code n'est jamais atteinte ici (dans ce programme
// simpliste), il faut toujours se poser la question de la fermeture !
//
// (identique à prog01_txt_mono_tcp_server.cpp)
//
crs::close(socketEcoute);
// ...

return 0;
}

//----------------------------------------------------------------------------
