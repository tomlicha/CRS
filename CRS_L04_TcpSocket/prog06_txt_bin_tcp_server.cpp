//----------------------------------------------------------------------------

#include "crsUtils.hpp"

void
txtDialogThread(SOCKET dialogSocket)
{
try
  {
  for(;;) // as long as dialog can go on...
    {
    //
    // ... À COMPLÉTER {7} ...
    //
    // Reprendre ici ce qui a été réalisé dans la fonction ``dialogThread()''
    // de prog03_txt_tcp_server.cpp
    //
    std::string request;
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
    }
  }
catch(std::exception &e)
  { crs::err("\n!!! Exception: % !!!\n",e.what()); }
catch(...)
  { crs::err("\n!!! Unknown exception !!!\n"); }

//---- close dialog socket in any case! ----
crs::close(dialogSocket);

crs::out("text client disconnected\n");
}

void
binDialogThread(SOCKET dialogSocket)
{
try
  {
  for(;;) // as long as dialog can go on...
    {
    //---- receive a 32-bit integer in network byte-order ----
    int32_t tmpRequest;
    (void)tmpRequest; // avoid ``unused variable'' warning
    //
    // ... À COMPLÉTER {6} ...
    //
    // Recevoir dans ``&tmpRequest'' les ``sizeof(tmpRequest)'' octets
    // qui constituent cette variable depuis la connexion TCP à l'aide de
    // ``crs::recvAll()''.
    // Si la quantité d'octets reçue (le résultat de ``crs::recvAll()'')
    // est nulle, cela signifie que la fin-de-fichier (EOF) est atteinte
    // (le client a fermé la connexion) ; il suffit de quitter la boucle
    // de dialogue avec ``break;'', sinon, si la quantité d'octets reçue
    // n'est pas celle attendue, afficher un message d'erreur explicite et
    // quitter avec ``crs::exit(1)''.
    //
    int r = crs::recvAll(dialogSocket,&tmpRequest,sizeof(tmpRequest));
    if ( r==0) break;
    else if(r != sizeof(tmpRequest)){
      crs::out("quantité d'octets recue incorrecte\n");
      crs::exit(1);
    }
    // ...

    //---- convert to host byte-order 32-bit integer and display ----
    int32_t request=0;
    (void)request; // avoid ``unused variable'' warning
    //
    // ... À COMPLÉTER {7} ...
    //
    // Placer dans ``request'' la conversion de ``tmpRequest'' de l'ordre
    // réseau vers l'ordre hôte à l'aide de ``crs::ntoh_i32()'' et afficher
    // cette valeur.
    //
    request = crs::ntoh_i32(tmpRequest);
    crs::out("valeur obtenue : %",request);
    // ...

    //---- prepare reply ----
    int32_t reply[2]={ 2*request, request*request };
    (void)reply; // avoid ``unused variable'' warning

    //---- convert to network byte-order 32-bit integers ----
    int32_t tmpReply[2];
    (void)tmpReply; // avoid ``unused variable'' warning
    //
    // ... À COMPLÉTER {8} ...
    //
    // Placer dans chaque élément de ``tmpReply'' la conversion de l'élément
    // de ``reply'' correspondant de l'ordre hôte vers l'ordre réseau, à
    // l'aide de ``crs::hton_i32()''.
    //
    tmpReply[0] = crs::hton_i32(reply[0]);
    tmpReply[1] = crs::hton_i32(reply[1]);
    // ...

    //---- send converted reply to client ----
    //
    // ... À COMPLÉTER {9} ...
    //
    // Envoyer à l'aide de  ``crs::sendAll()'', les ``sizeof(tmpReply)''
    // octets qui constituent ``tmpReply'' au client à travers la socket de
    // dialogue TCP qui nous y relie.
    //
    crs::sendAll(dialogSocket,&tmpReply,sizeof(tmpReply));
    // ...
    }
    }
  
catch(std::exception &e)
  { crs::err("\n!!! Exception: % !!!\n",e.what()); }
catch(...)
  { crs::err("\n!!! Unknown exception !!!\n"); }

//---- close dialog socket in any case! ----
crs::close(dialogSocket);

crs::out("binary client disconnected\n");
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
if(args.size()!=3)
  {
  crs::err("usage: % txt_port bin_port\n",args[0]);
  crs::exit(1);
  }

//---- extract local port numbers ----
uint16_t txtPortNumber=uint16_t(std::stoi(args[1]));
uint16_t binPortNumber=uint16_t(std::stoi(args[2]));

//---- create listen socket (text) ----
//
// ... À COMPLÉTER {1} ...
//
// (semblable à prog03_txt_tcp_server.cpp)
//
auto socketEcouteTxt = crs::socket(AF_INET,SOCK_STREAM,0);
crs::setReuseAddrOption(socketEcouteTxt,true);
crs::bind(socketEcouteTxt,txtPortNumber);
crs::listen(socketEcouteTxt);
// ...

//---- create listen socket (binary) ----
//
// ... À COMPLÉTER {2} ...
//
// (semblable à prog04_bin_tcp_server.cpp)
//
auto socketEcouteBin = crs::socket(AF_INET,SOCK_STREAM,0);
crs::setReuseAddrOption(socketEcouteBin,true);
crs::bind(socketEcouteBin,binPortNumber);
crs::listen(socketEcouteBin);
// ...

crs::out("host '%' waiting for text/binary connections on ports '%/%'...\n",
         crs::gethostname(),txtPortNumber,binPortNumber);
for(;;)
  {
  //---- wait for connections ----
  //
  // ... À COMPLÉTER {4} ...
  //
  // Surveiller simultanément (avec ``crs::select()'') les demandes de
  // connexion sur les deux sockets d'écoute.
  //
  std::vector<SOCKET> readSet = {socketEcouteTxt,socketEcouteBin};
  crs::select(readSet);
  // ...

  //---- react to text connection (if available) ----
  //
  // ... À COMPLÉTER {5} ...
  //
  // Si la socket d'écoute pour les échanges textuels a reçu une nouvelle
  // demande de connexion (``voir crs::find()''), accepter cette connexion
  // et démarrer un thread qui exécutera le dialogue avec le client dans
  // la fonction ``txtDialogThread()''.
  //
  // (semblable à prog03_txt_tcp_server.cpp)
  //
;
  if( crs::find(readSet,socketEcouteTxt) != (-1))
 // ... MODIFIER CETTE CONDITION ...
    {
      uint32_t out_address;
      uint16_t out_port;
      auto socketDiagTxt = crs::accept(socketEcouteTxt,out_address,out_port);
      std::thread th( txtDialogThread, socketDiagTxt );
      th.detach();
      crs::out("coordonnées du client : % : %\n",crs::formatIpv4Address(out_address),out_port);
    }
  // ...

  //---- react to binary connection (if available) ----
  //
  // ... À COMPLÉTER {6} ...
  //
  // Si la socket d'écoute pour les échanges binaires a reçu une nouvelle
  // demande de connexion (``voir crs::find()''), accepter cette connexion
  // et démarrer un thread qui exécutera le dialogue avec le client dans
  // la fonction ``binDialogThread()''.
  //
  // (semblable à prog04_bin_tcp_server.cpp)
  //
  if( crs::find(readSet,socketEcouteBin) != (-1)) // ... MODIFIER CETTE CONDITION ...
    {
      uint32_t out_address1;
      uint16_t out_port1;
      auto socketDiagBin = crs::accept(socketEcouteBin,out_address1,out_port1);
      std::thread th( binDialogThread, socketDiagBin );
      th.detach();
      crs::out("coordonnées du client : % : %\n",crs::formatIpv4Address(out_address1),out_port1);
    }
  // ...
  }

//---- close listen sockets ----
//
// ... À COMPLÉTER {3} ...
//
// (semblable à prog03_txt_tcp_server.cpp et prog04_bin_tcp_server.cpp)
//
crs::close(socketEcouteTxt);
crs::close(socketEcouteBin);
// ...

return 0;
}

//----------------------------------------------------------------------------
