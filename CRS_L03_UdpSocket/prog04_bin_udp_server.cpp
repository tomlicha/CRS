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
// (identique à prog02_txt_udp_server.cpp)
//
int socket = crs::socket(PF_INET,SOCK_DGRAM,0);
crs::bind(socket,portNumber);
// ...

for(;;) // as long as dialog can go on...
  {
  //---- receive a 32-bit integer in network byte-order ----
  crs::out("host '%' waiting for an UDP message on port '%'...\n",
           crs::gethostname(),portNumber);
  int32_t tmpRequest;
  (void)tmpRequest; // avoid ``unused variable'' warning
  //
  // ... À COMPLÉTER {3} ...
  //
  // Recevoir dans ``&tmpRequest'' les ``sizeof(tmpRequest)'' octets
  // qui constituent cette variable depuis la socket UDP à l'aide de
  // ``crs::recvfrom()''.
  // Si la quantité d'octets reçue (le résultat de ``crs::recvfrom()'')
  // n'est pas celle attendue, afficher un message d'erreur explicite et
  // quitter avec ``crs::exit(1)''.
  //
  uint32_t fromAddr;
  uint16_t fromPort;
  int r = crs::recvfrom(socket,&tmpRequest,sizeof(tmpRequest),fromAddr,fromPort);
    if ( r != sizeof(tmpRequest)){
    crs::write(STDOUT_FILENO,crs::txt("erreur de taille"));
    crs::exit(1);
  }
  // ...

  //---- convert to host byte-order 32-bit integer and display ----
  int32_t request=0;
  (void)request; // avoid ``unused variable'' warning
  //
  // ... À COMPLÉTER {4} ...
  //
  // Placer dans ``request'' la conversion de ``tmpRequest'' de l'ordre
  // réseau vers l'ordre hôte à l'aide de ``crs::ntoh_i32()'' et afficher
  // cette valeur ainsi que l'adresse IP et le port d'où elle provient.
  //
  request = crs::ntoh_i32(tmpRequest);
  crs::write(STDOUT_FILENO,crs::txt("from (%:%) : %",crs::formatIpv4Address(fromAddr),fromPort,request));
  // ...

  //---- prepare reply ----
  int32_t reply[2]={ 2*request, request*request };
  (void)reply; // avoid ``unused variable'' warning

  //---- convert to network byte-order 32-bit integers ----
  int32_t tmpReply[2];
  (void)tmpReply; // avoid ``unused variable'' warning
  //
  // ... À COMPLÉTER {5} ...
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
  // ... À COMPLÉTER {6} ...
  //
  // Envoyer à l'aide de  ``crs::sendto()'', les ``sizeof(tmpReply)'' octets
  // qui constituent ``tmpReply'' au client qui nous a sollicité.
  //
  crs::sendto(socket,&tmpReply,sizeof(tmpReply),fromAddr,fromPort);
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
// (identique à prog02_txt_udp_server.cpp)
//
crs::close(socket);
// ...

return 0;
}

//----------------------------------------------------------------------------
