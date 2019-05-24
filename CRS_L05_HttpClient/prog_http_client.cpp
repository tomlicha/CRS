//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
std::string protocol,hostname,resource;
uint16_t port;
if((args.size()!=3)||
   !crs::parseUri(args[1],protocol,hostname,port,resource))
  {
  crs::err("usage: % uri output_file\n",args[0]);
  crs::exit(1);
  }
crs::out("protocol=%\n"
         "hostname=%\n"
         "port=%\n"
         "resource=%\n",
         protocol,hostname,port,resource);
auto uri=args[1];
auto outputFileName=args[2];

//---- detect proxy ----
std::string connectHost=hostname;
uint16_t connectPort=port;
std::string proxyProtocol,proxyHost;
uint16_t proxyPort=0;
if(crs::parseProxyUri(crs::getenv("http_proxy"),
                      proxyProtocol,proxyHost,proxyPort))
  {
  crs::out("proxyHost=%\n"
           "proxyPort=%\n",
           proxyHost,proxyPort);
  connectHost=proxyHost;
  connectPort=proxyPort;
  }

(void)connectHost; // avoid ``unused variable'' warning
(void)connectPort;

//---- extract destination IP address ----
//
// ... À COMPLÉTER {A-1} ...
//
// Déterminer l'adresse IP de ``connectHost''.
//
uint32_t ipAddress = crs::gethostbyname(connectHost);
//...

//---- create client socket ----
SOCKET clientSocket=INVALID_SOCKET;
//
// ... À COMPLÉTER {A-2} ...
//
// Réaliser, dans ``clientSocket'', une connexion TCP vers le port
// ``connectPort'' de ``connectHost'' (qui désigne le serveur ou le proxy).
//
clientSocket = crs::socket(AF_INET,SOCK_STREAM,0);
crs::connect(clientSocket,ipAddress,connectPort);
// ...

if(protocol=="http") //---- handle HTTP protocol ----
  {
  //---- send HTTP request ----
  //
  // ... À COMPLÉTER {A-4} {B-1} ...
  //
  // Rédiger (avec ``crs::txt()'') l'entête de la requête HTTP permettant
  // de réclamer la ressource au destinataire (serveur ou proxy).
  // nb : puisqu'une seule requête aura lieu, nous réclamons la fermeture
  //      de la connexion après la réponse.
  // Envoyer cet entête vers la socket avec ``crs::send()''.
  //
  std::string header;
  if (proxyPort != 0 ){
      header = crs::txt("GET % HTTP/1.1\r\nHost: %:%\r\nConnection: close\r\n\r\n",uri,hostname,port);
  }
  else {
    header = crs::txt("GET % HTTP/1.1\r\nHost: %:%\r\nConnection: close\r\n\r\n",resource,hostname,port);
  }
  crs::send(clientSocket,header);
  // ...

  //---- receive HTTP reply header ----
  //
  // ... À COMPLÉTER {A-5} ...
  //
  // Effectuer une boucle de lecture de l'entête complet de la requête.
  // Chaque ligne ``l'' est obtenue avec ``crs::recvLine()'' depuis la
  // socket.
  // * Si une ligne est vide ou n'est constituée que de "\n" ou "\r\n",
  //   c'est que l'entête est fini ; il faut quitter cette boucle de
  //   lecture pour passer à la suite.
  // nb : nous ne nous intéressons pas ici au contenu de l'entête reçu.
  //
  for (;;){
    auto l = crs::recvLine(clientSocket);
    if ((l=="\n") | (l=="\r\n")) break;
  }

  // ...

  //---- receive HTTP reply content ----
  crs::out("--> writing to '%'\n",outputFileName);
  char buffer[0x400];
  (void)buffer; // avoid ``unused variable'' warning
  //
  // ... À COMPLÉTER {A-6} ...
  //
  // Ouvrir le fichier ``outputFileName'' avec ``crs::openW()'',
  // puis effectuer en boucle :
  // * Obtenir ``r'' octets depuis la socket vers ``buffer'' à l'aide
  //   de ``crs::recv()''.
  //   (nb : il s'agit de données brutes, pas forcément de texte)
  // * Si ``r'' est nul (fin-de-fichier), il faut quitter cette boucle.
  // * Utiliser ``crs::writeAll()'' pour envoyer vers le fichier les ``r''
  //   octets précédemment obtenus dans ``buffer''.
  // Après cette boucle, il ne reste plus qu'à fermer le fichier avec
  // ``crs::close()''.
  //
  int outputfile = crs::openW(outputFileName);
  
  for(;;){
    int r = crs::recv(clientSocket,&buffer,sizeof(buffer));
    if (r == 0) break;
    crs::writeAll(outputfile,&buffer,r);
  }
  
  crs::close(outputfile);
  // ...
  }
else if(protocol=="https") //---- handle HTTPS protocol ----
  {
  //---- initialise SSL context ----
  // The list of well-known certification authorities "cacert.pem"
  // was obtained from this site:
  //   https://curl.haxx.se/docs/caextract.html
  SSL_CTX *sslCtx=crs::sslInit("cacert.pem");

  if(proxyPort)
    {
    //---- ask the proxy for a connection to the server ----
    //
    // ... À COMPLÉTER {D-1} ...
    //
    // Lorsqu'un proxy doit être utilisé, lui demander (en clair) la
    // connexion au serveur et obtenir l'entête complet de sa réponse.
    //
    std::string headerHTTPS = crs::txt("CONNECT %:% HTTP/1.1\r\nHost: %:%\r\n\r\n",hostname,port,hostname,port);
    crs::send(clientSocket,headerHTTPS);
    // ...
    for (;;){
      auto l = crs::recvLine(clientSocket);
      if ((l=="\n") | (l=="\r\n")) break;
    }
    }

  //---- initialise client-side SSL connection over the TCP connection ----
  SSL *ssl=crs::sslConnect(clientSocket,sslCtx,hostname);
 
  //---- send HTTP(S) request ----
  //
  // ... À COMPLÉTER {C-1} ...
  //
  // Rédiger (avec ``crs::txt()'') l'entête de la requête HTTP permettant
  // de réclamer la ressource au serveur (le proxy n'est pas concerné).
  // nb : puisqu'une seule requête aura lieu, nous réclamons la fermeture
  //      de la connexion après la réponse.
  // Envoyer cet entête vers la connexion sécurisée avec ``crs::sslSend()''.
  //
  std::string headerSSL = crs::txt("GET % HTTP/1.1\r\nHost: %:%\r\nConnection: close\r\n\r\n",uri,hostname,port);
  crs::sslSend(ssl,headerSSL);
  
  // ...

  //---- receive HTTP(s) reply header ----
  //
  // ... À COMPLÉTER {C-2} ...
  //
  // Effectuer une boucle de lecture de l'entête complet de la requête.
  // Chaque ligne ``l'' est obtenue avec ``crs::sslRecvLine()'' depuis la
  // connexion sécurisée.
  // * Si une ligne est vide ou n'est constituée que de "\n" ou "\r\n",
  //   c'est que l'entête est fini ; il faut quitter cette boucle de
  //   lecture pour passer à la suite.
  // nb : nous ne nous intéressons pas ici au contenu de l'entête reçu.
  //
  for (;;){
    auto l = crs::sslRecvLine(ssl);
    if ((l=="\n") | (l=="\r\n")) break;
  }
  // ...

  //---- receive HTTP(S) reply content ----
  crs::out("--> writing to '%'\n",outputFileName);
  char buffer[0x100];
  (void)buffer; // avoid ``unused variable'' warning
  //
  // ... À COMPLÉTER {C-3} ...
  //
  // Ouvrir le fichier ``outputFileName'' avec ``crs::openW()'',
  // puis effectuer en boucle :
  // * Obtenir ``r'' octets depuis la connexion sécurisée vers ``buffer''
  //   à l'aide de ``crs::sslRecv()''.
  //   (nb : il s'agit de données brûtes, pas forcément de texte)
  // * Si ``r'' est nul (fin-de-fichier), il faut quitter cette boucle.
  // * Utiliser ``crs::writeAll()'' pour envoyer vers le fichier les ``r''
  //   octets précédemment obtenus dans ``buffer''.
  // Après cette boucle, il ne reste plus qu'à fermer le fichier avec
  // ``crs::close()''.
  //
  int outputfile = crs::openW(outputFileName); 
  // ...
  for(;;){
    int r = crs::sslRecv(ssl,&buffer,sizeof(buffer));
    if (r == 0) break;
    crs::writeAll(outputfile,&buffer,r);
  }
  
  crs::close(outputfile);
  
  //---- close SSL resources ---
  crs::sslClose(ssl);
  crs::sslDestroy(sslCtx);
  }
else
  {
  crs::err("unsupported protocol %\n",protocol);
  crs::exit(1);
  }

//---- close client socket ----
//
// ... À COMPLÉTER {A-3} ...
//
// Fermer la connexion.
//
crs::close(clientSocket);
// ...

return 0;
}

//----------------------------------------------------------------------------
