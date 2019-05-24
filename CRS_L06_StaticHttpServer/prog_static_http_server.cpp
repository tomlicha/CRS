//----------------------------------------------------------------------------

#include "crsUtils.hpp"

void
dialogThread(SOCKET dialogSocket,
             SSL_CTX *sslCtx)
{
try
  {
  //---- initialise server-side SSL connection if needed ----
  SSL *ssl=sslCtx ? crs::sslAccept(dialogSocket,sslCtx) : nullptr;

  for(;;) // reuse connection as much as possible
    {
    //---- receive and analyse HTTP request line by line ----
    std::string requestMethod,requestUri,connection;
    //
    // ... À COMPLÉTER {B-1} ...
    //
    // Effectuer une boucle de lecture de l'entête complet de la requête.
    // Chaque ligne ``l'' est obtenue avec ``crs::recvLine()'' depuis la
    // socket (ou ``crs::sslRecvLine()'' dans le cas de HTTPS).
    // * Si une ligne est vide ou n'est constituée que de "\n" ou "\r\n",
    //   c'est que l'entête est fini ; il faut quitter cette boucle de
    //   lecture pour passer à la suite.
    // * Si ``requestMethod'' est vide, c'est qu'il s'agit de la première
    //   ligne de l'entête ; il faut renseigner ``requestMethod'' et
    //   ``requestUri'' avec les deux premiers mots de cette ligne en
    //   utilisant ``crs::extract(l,requestMethod,requestUri)''.
    // * Sinon, nous pouvons tenter de renseigner ``connection'' en
    //   utilisant ``crs::extract(l,"Connection",':',connection)''.
    //
    if (ssl == nullptr){
      for (;;){
        auto l = crs::recvLine(dialogSocket);
        if ((l=="\n") | (l=="\r\n")) break;
        if (requestMethod.empty()) crs::extract(l,requestMethod,requestUri);
        else {
          crs::extract(l,"Connection",':',connection);
        }
      }
    }
    else {
        for (;;){
          auto l = crs::sslRecvLine(ssl);
          if ((l=="\n") | (l=="\r\n")) break;
          if (requestMethod.empty()) crs::extract(l,requestMethod,requestUri);
          else {
            crs::extract(l,"Connection",':',connection);
        }
      }
    }
    // ...
    if(requestMethod.empty()) { break; } // no request
    connection=crs::find(connection,"close")!=-1
               ? "close" : "keep-alive"; // assume keep-alive by default

    //---- deduce filesystem path from request URI ----
    auto path="TopDir"+requestUri;
    if(crs::isFile(path+"/index.html"))
      { path+="/index.html"; } // use index.html found in directories

    //---- deduce content type from path extension (ugly!) ----
    std::string contentType;
    if(crs::endsWith(path,".html"))
      { contentType="text/html"; }
    else if(crs::endsWith(path,".png"))
      { contentType="image/png"; }
    else if(crs::endsWith(path,".ico"))
      { contentType="image/vnd.microsoft.icon"; }
    else
      { contentType="unknown/unknown"; }

    //---- handle file transfer ----
    //
    // ... À COMPLÉTER {C-1} ...
    //
    // Tester si ``path'' désigne bien un fichier (``crs::isFile()'') et
    // s'il nous est accessible en lecture (``crs::access()'' avec R_OK).
    //
    crs::out("--> sending file: %\n",path);
    if( crs::isFile(path) &&  crs::access(path,R_OK)) // ... MODIFIER CETTE CONDITION ...
    // ...
      {
      crs::out("--> sending file: %\n",path);
      //
      // ... À COMPLÉTER {C-2} ...
      //
      // Rédiger (avec ``crs::txt()'') l'entête complet de la réponse HTTP
      // (200 OK) en y inserrant ``connection'', ``contentType'' et la taille
      // du fichier à transférer (avec ``crs::fileSize()'').
      // Utiliser ensuite ``crs::send()'' pour l'envoyer vers la socket
      // (ou ``crs::sslSend()'' dans le cas de HTTPS).
      //
      if (ssl == nullptr){
      auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Type: %\r\nContent-Length: %\r\n\r\n",connection,contentType,crs::fileSize(path));
      // ...
      crs::send(dialogSocket,header);
      }
      else {
      auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Type: %\r\nContent-Length: %\r\n\r\n",connection,contentType,crs::fileSize(path));
      // ...
      crs::sslSend(ssl,header);
      }
      char buffer[0x400];
      (void)buffer; // avoid ``unused variable'' warning
      //
      // ... À COMPLÉTER {C-3} ...
      //
      // Ouvrir le fichier avec ``crs::openR()'', puis effectuer en boucle :
      // * Obtenir ``r'' octets depuis le fichier vers ``buffer'' à l'aide
      //   de ``crs::read()''.
      //   (nb : il s'agit de données brûtes, pas forcément de texte)
      // * Si ``r'' est nul (fin-de-fichier), il faut quitter cette boucle.
      // * Utiliser ``crs::sendAll()'' pour envoyer vers la socket les ``r''
      //   octets précédemment obtenus dans ``buffer''
      //   (ou ``crs::sslSendAll()'' dans le cas de HTTPS).
      // Après cette boucle, il ne reste plus qu'à fermer le fichier avec
      // ``crs::close()''.
      //
      int inputFile = crs::openR(path);
      // ...
      if (ssl == nullptr){
        for(;;){
          int r = crs::read(inputFile,&buffer,sizeof(buffer));
          if ( r==0) break;
          crs::sendAll(dialogSocket,&buffer,r);
        }
      }
      else {
        for(;;){
          int r = crs::read(inputFile,&buffer,sizeof(buffer));
          if ( r==0) break;
          crs::sslSendAll(ssl,&buffer,r);
        }
      }
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }

    //---- any other unhandled case ----
    if(true) // the last resort!
      {
      crs::out("--> sending 404 Not Found: %\n",requestUri);
      // prepare content first to provide the header with its length
      //
      // ... À COMPLÉTER {B-2} ...
      //
      // Rédiger (avec ``crs::txt()'') le __contenu__ de la réponse.
      // Il s'agit d'une page HTML simpliste qui indique au lecteur que
      // la resource demandée n'est pas disponible. Vous avez tout intérêt
      // à y inserrer ``requestMethod'' et ``requestUri'' afin d'expliciter.
      //
      auto reply = crs::txt("<html><body><hr><p>la ressource demandee n est pas disponible, \r\nmethode: %\r\n uri: %</p><hr></body></html>",requestMethod,requestUri);
      // ...
      //
      // ... À COMPLÉTER {B-3} ...
      //
      // Rédiger ensuite (avec ``crs::txt()'') l'entête complet de la réponse
      // HTTP (404 Not Found) en y inserrant ``connection'' et la taille du
      // contenu préalablement préparé.
      // Utiliser ensuite ``crs::send()'' pour l'envoyer vers la socket
      // (ou ``crs::sslSend()'' dans le cas de HTTPS),
      // puis faire de même avec le contenu.
      //
      auto header = crs::txt("HTTP/1.1 404 Not Found\r\nConnection: %\r\nContent-Type: text/html\r\nContent-Length: %\r\n\r\n",connection,(reply.length()));
      if (ssl == nullptr){
        crs::send(dialogSocket,header);
        crs::send(dialogSocket,reply);
      }
      else {
        crs::sslSend(ssl,header);
        crs::sslSend(ssl,reply);
      }
      // ...
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }
    }

  //---- close SSL connection if any ----
  if(ssl) { crs::sslClose(ssl); }
  }
catch(std::exception &e)
  { crs::err("\n!!! Exception: % !!!\n",e.what()); }
catch(...)
  { crs::err("\n!!! Unknown exception !!!\n"); }

//---- close dialog socket in any case! ----
crs::close(dialogSocket);
crs::out("client disconnected\n");
}

void
runHttpServer(SOCKET httpSocket)
{
(void)httpSocket; // avoid ``unused parameter'' warning

for(;;)
  {
  //---- accept new connection ----
  //
  // ... À COMPLÉTER {A-2} ...
  //
  // Accepter la prochaine connexion sur la socket d'écoute HTTP.
  //
  uint32_t out_address;
  uint16_t out_port;
  auto socketDiag = crs::accept(httpSocket,out_address,out_port);
  crs::out("coordonnées du client : % : %",crs::formatIpv4Address(out_address),out_port);
  // ...

  //---- start a new dialog thread ----
  //
  // ... À COMPLÉTER {A-3} ...
  //
  // Démarrer un thread (détaché) qui assurera le dialogue avec ce
  // nouveau client dans la fonction ``dialogThread()''.
  // On lui transmet en argument la socket de dialogue obtenue et
  // ``nullptr'' // (pas de contexte SSL pour HTTP).
  //
  std::thread th(dialogThread,socketDiag,nullptr);
  th.detach();
  // ...
  }
}

void
runHttpAndHttpsServer(SOCKET httpSocket,
                      SOCKET httpsSocket)
{
(void)httpSocket; // avoid ``unused parameter'' warning
(void)httpsSocket;

//---- initialise SSL context ----
/* The self-signed certificate "cert.pem" and its private key "key.pem"
// were obtained with the following command:
//   $ openssl req -x509 -newkey rsa:1024 -nodes -days 3650 \
//             -keyout key.pem -out cert.pem \
//             -subj '/C=FR/ST=Bretagne/L=Brest/O=ENIB/OU=CRS/CN=localhost'
*/
SSL_CTX *sslCtx=crs::sslInit({},"cert.pem","key.pem");

for(;;)
  {
  //---- wait for connections ----
  //
  // ... À COMPLÉTER {D-2} ...
  //
  // Surveiller simultanément (avec ``crs::select()'') les demandes de
  // connexion sur les deux sockets d'écoute.
  //
  std::vector<SOCKET> httpset = {httpSocket,httpsSocket};
  crs::select(httpset);
  // ...

  //---- accept new HTTP connection (if available)----
  //
  // ... À COMPLÉTER {D-3} ...
  //
  // Si la socket d'écoute HTTP est prête à fournir une connexion
  // (``voir crs::find()''), accepter cette connexion et démarrer un
  // thread (détaché) qui assurera le dialogue avec ce nouveau client
  // dans la fonction ``dialogThread()''.
  // On lui transmet en argument la socket de dialogue obtenue et
  // ``nullptr'' // (pas de contexte SSL pour HTTP).
  //
  if( crs::find(httpset,httpSocket) != (-1))
 // ... MODIFIER CETTE CONDITION ...
    {
      uint32_t out_address;
      uint16_t out_port;
      auto socketDiagHTTP= crs::accept(httpSocket,out_address,out_port);
      std::thread th( dialogThread,socketDiagHTTP,nullptr);
      th.detach();
      crs::out("coordonnées du client : % : %\n",crs::formatIpv4Address(out_address),out_port);
    }
  // ...

  //---- accept new HTTPS connection (if available)----
  //
  // ... À COMPLÉTER {D-4} ...
  //
  // Si la socket d'écoute HTTPS est prête à fournir une connexion
  // (``voir crs::find()''), accepter cette connexion et démarrer un
  // thread (détaché) qui assurera le dialogue avec ce nouveau client
  // dans la fonction ``dialogThread()''.
  // On lui transmet en argument la socket de dialogue obtenue ainsi que
  // le contexte SSL ``sslCtx'' puisqu'il s'agit de HTTPS.
  //
  if( crs::find(httpset,httpsSocket) != (-1))
 // ... MODIFIER CETTE CONDITION ...
    {
      uint32_t out_address;
      uint16_t out_port;
      auto socketDiagHTTPS= crs::accept(httpsSocket,out_address,out_port);
      std::thread th( dialogThread,socketDiagHTTPS,sslCtx);
      th.detach();
      crs::out("coordonnées du client : % : %\n",crs::formatIpv4Address(out_address),out_port);
    }
  // ...
  }

//---- destroy SSL context ----
crs::sslDestroy(sslCtx);
}

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
if((args.size()!=2)&&(args.size()!=3))
  {
  crs::err("usage: % http_port [https_port]\n",args[0]);
  crs::exit(1);
  }

//---- extract local port numbers ----
uint16_t httpPortNumber=uint16_t(std::stoi(args[1]));
uint16_t httpsPortNumber=args.size()==3 ? uint16_t(std::stoi(args[2])) : 0;

//---- create HTTP listen socket ----
SOCKET httpSocket=INVALID_SOCKET;
//
// ... À COMPLÉTER {A-1} ...
//
// Créer dans ``httpSocket'' une socket TCP écoutant sur le port
// ``httpPortNumber''.
//
httpSocket = crs::socket(AF_INET,SOCK_STREAM,0);
crs::setReuseAddrOption(httpSocket,true);
crs::bind(httpSocket,httpPortNumber);
crs::listen(httpSocket,SOCK_STREAM);
// ...

if(!httpsPortNumber) // only HTTP to make things easy at first...
  {
  //---- run server ----
  crs::out("host '%' waiting for HTTP connections on port '%'...\n",
           crs::gethostname(),httpPortNumber);
  runHttpServer(httpSocket);

  //---- close listen socket ----
  crs::close(httpSocket);
  }
else // HTTP __and__ HTTPS
  {
  //---- create HTTPS listen socket ----
  SOCKET httpsSocket=INVALID_SOCKET;
  //
  // ... À COMPLÉTER {D-1} ...
  //
  // Créer dans ``httpsSocket'' une socket TCP écoutant sur le port
  // ``httpsPortNumber''.
  //
  httpsSocket= crs::socket(AF_INET,SOCK_STREAM,0);
  crs::setReuseAddrOption(httpsSocket,true);
  crs::bind(httpsSocket,httpsPortNumber);
  crs::listen(httpsSocket,SOCK_STREAM);
  // ...

  //---- run server ----
  crs::out("host '%' waiting for HTTP/S connections on ports '%/%'...\n",
           crs::gethostname(),httpPortNumber,httpsPortNumber);
  runHttpAndHttpsServer(httpSocket,httpsSocket);

  //---- close listen sockets ----
  crs::close(httpSocket);
  crs::close(httpsSocket);
  }

return 0;
}

//----------------------------------------------------------------------------
