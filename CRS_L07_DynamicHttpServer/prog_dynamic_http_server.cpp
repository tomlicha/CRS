//----------------------------------------------------------------------------

#include "crsUtils.hpp"

class SharedLog
{
public:
  SharedLog() =default;
  ~SharedLog() =default;
  SharedLog(SharedLog const &) =delete;
  SharedLog(SharedLog &&) =delete;
  SharedLog & operator =(SharedLog const &) =delete;
  SharedLog & operator =(SharedLog &&) =delete;

  template<typename Info>
  void
  add(SOCKET dialogSocket,
      SSL_CTX *sslCtx,
      Info &&info)
  {
  try
    {
    uint32_t fromIpAddr;
    uint16_t fromPort;
    crs::getpeername(dialogSocket,fromIpAddr,fromPort);
    auto &&line=crs::txt("%:% %(%) %",
                         crs::formatIpv4Address(fromIpAddr),fromPort,
                         sslCtx ? "HTTPS" : "HTTP",dialogSocket,
                         std::forward<Info>(info));
    std::lock_guard<std::mutex> lk(_mtx);
    _log.emplace_back(line);
    }
  catch(...) { }
  }

  std::vector<std::string> // copy of log content
  get()
  {
  std::lock_guard<std::mutex> lk(_mtx);
  return _log;
  }

private:
  std::mutex _mtx{};
  std::vector<std::string> _log{};
};

void
dialogThread(SOCKET dialogSocket,
             SSL_CTX *sslCtx,
             SharedLog &log)
{
log.add(dialogSocket,sslCtx,"client connected");
try
  {
  //---- initialise server-side SSL connection if needed ----
  SSL *ssl=sslCtx ? crs::sslAccept(dialogSocket,sslCtx) : nullptr;

  for(;;) // reuse connection as much as possible
    {
    //---- receive and analyse HTTP request line by line ----
    std::string requestMethod,requestUri,connection,contentLength;
    for(;;)
      {
      auto l=ssl ? crs::sslRecvLine(ssl) : crs::recvLine(dialogSocket);
      crs::out("header: %",l);
      if(l.empty()||(l=="\n")||(l=="\r\n")) { break; }
      if(requestMethod.empty()) // first line
        { crs::extract(l,requestMethod,requestUri); }
      else if(crs::extract(l,"Connection",':',connection)==3)
        { /* nothing more to be done */ }
      //
      // ... À COMPLÉTER {C-1} ...
      //
      // Tenter de renseigner ``contentLength'' depuis la ligne obtenue.
      //
      if (contentLength.empty()) crs::extract(l,"Content-Length",':',contentLength);
      //...
      }
    if(requestMethod.empty()) { break; } // no request
    connection=crs::find(connection,"close")!=-1
               ? "close" : "keep-alive"; // assume keep-alive by default
    log.add(dialogSocket,sslCtx,crs::txt("% %",requestMethod,requestUri));

    //---- deduce filesystem path from request URI ----
    auto path="TopDir"+crs::split(requestUri,"?").front(); // remove ?...
    if(crs::isFile(path+"/index.html"))
      { path+="/index.html"; } // use index.html found in directories

    //---- handle log content ----
    if(requestUri=="/server_log")
      {
      crs::out("--> sending log content:\n");
      // prepare content first to provide the header with its length
      //
      // ... À COMPLÉTER {A-1} ...
      //
      // Rédiger (avec ``crs::txt()'') le __contenu__ de la réponse.
      // Il s'agit d'une page HTML simpliste qui présente les lignes de
      // texte du journal obtenues par ``log.get()''.
      // Vous pouvez par exemple générer une construction <ul>...</ul>
      // contenant des éléments "<li><tt>%<tt>\n" pour chacune des lignes
      // du journal à afficher.
      //
      auto logs = log.get();
      auto response = crs::txt("<html><body><h1>server logs</h1><ul>");
      for (auto l:logs){

        response += crs::txt("<li><tt>%<tt>\n",l);

      
      }
      response += crs::txt("</ul></body></html>");//...
      //
      // ... À COMPLÉTER {A-2} ...
      //
      // Rédiger ensuite (avec ``crs::txt()'') l'entête complet de la réponse
      // HTTP (200 OK) en y insérant ``connection'' et la taille du contenu
      // préalablement préparé.
      // Utiliser ensuite ``crs::send()'' pour l'envoyer vers la socket
      // (ou ``crs::sslSend()'' dans le cas de HTTPS),
      // puis faire de même avec le contenu.
      //
      if (ssl == nullptr){
        auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Length: %\r\n\r\n",connection,response.length());
        crs::send(dialogSocket,header);
        crs::send(dialogSocket,response);
      }
      else{
        auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Length: %\r\n\r\n",connection,response.length());
        crs::sslSend(ssl,header);
        crs::sslSend(ssl,response);
      }
      //...
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }

    //---- handle directory content ----
    if(crs::isDir(path)&&      // ensure it is a directory
       crs::access(path,R_OK)) // which is readable
      {
      crs::out("--> sending directory content: %\n",path);
      // prepare content first to provide the header with its length
      //
      // ... À COMPLÉTER {B-1} ...
      //
      // Rédiger (avec ``crs::txt()'') le __contenu__ de la réponse.
      // Il s'agit d'une page HTML simpliste qui présente les entrées du
      // répertoire ``path'' obtenues par ``crs::listDir()''.
      // Vous pouvez par exemple générer une construction <ul>...</ul>
      // contenant des éléments "<li><a href=\"%\">%</a>\n" pour chacune des
      // entrées du répertoire à afficher.
      // Les entrées qui sont elles-mêmes des répertoires (``crs::isDir()'')
      // doivent être suivies de "/" afin que le navigateur interprète
      // correctement le lien.
      //
      auto response = crs::txt("<html><body>\n<h1>directory</h1>\n<ul>");
      auto listdir = crs::listDir(path);
      for (auto  dir:listdir){
        if (crs::isDir(path+'/'+dir)){
          response += crs::txt("<li><a href=\"%/\">%</a></li>\n",dir,dir);
        }
        else{

         response += crs::txt("<li><a href=\"%\">%</a></li>\n",dir,dir);
 
        }
      } 
      response += crs::txt("</ul></body></html>");
      //...
      //
      // ... À COMPLÉTER {B-2} ...
      //
      // Rédiger ensuite (avec ``crs::txt()'') l'entête complet de la réponse
      // HTTP (200 OK) en y insérant ``connection'' et la taille du contenu
      // préalablement préparé.
      // Utiliser ensuite ``crs::send()'' pour l'envoyer vers la socket
      // (ou ``crs::sslSend()'' dans le cas de HTTPS),
      // puis faire de même avec le contenu.
      //
      if (ssl == nullptr){
        auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Length: %\r\n\r\n",connection,response.length());
        crs::send(dialogSocket,header);
        crs::send(dialogSocket,response);
      }
      else{
        auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\nContent-Length: %\r\n\r\n",connection,response.length());
        crs::sslSend(ssl,header);
        crs::sslSend(ssl,response);
      }
      //...
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }

    //---- handle CGI process execution ----
    if(crs::isFile(path)&&                       // ensure it is a file
       crs::startsWith(requestUri,"/cgi-bin/")&& // which stands in /cgi-bin/
       crs::access(path,R_OK|X_OK))              // and is executable
      {
      crs::out("--> executing CGI file: %\n",path);
      connection="close"; // no easy way to determine content length
      //
      // ... À COMPLÉTER {C-2} ...
      //
      // Rédiger (avec ``crs::txt()'') le __début__de l'entête de la réponse
      // HTTP (200 OK) en y insérant ``connection'' ; il ne faut surtout
      // pas produire la ligne vide marquant la fin de l'entête car c'est le
      // processus CGI qui s'en chargera après avoir complété l'entête.
      // Utiliser ensuite ``crs::send()'' pour l'envoyer vers la socket.
      //
      auto header = crs::txt("HTTP/1.1 200 OK\r\nConnection: %\r\n",connection);
      if (ssl == nullptr){
        crs::send(dialogSocket,header);
      }
      else {
        crs::sslSend(ssl,header);
      }
      // ...
      if(!ssl) // only HTTP to make things easy at first...
        {
        //
        // ... À COMPLÉTER {C-3} ...
        //
        // Créer un processus enfant, et se contenter de l'attendre.
        // Le processus enfant doit renseigner avec ``crs::setenv()''
        // les variables d'environnement "REQUEST_METHOD", "REQUEST_URI"
        // et "CONTENT_LENGTH" avec les valeurs des variables ayant des
        // noms similaires dans notre programme.
        // Il doit ensuite effectuer une redirection des entrées/sorties
        // (avec ``crs::dup2()'') dans la socket de dialogue.
        // Il ne lui reste plus qu'à provoquer son recouvrement par le
        // programme CGI choisi (avec crs::exec()'').
        //
        auto child = crs::fork();
        if (child==0){
          crs::setenv("REQUEST_METHOD",requestMethod);
          crs::setenv("REQUEST_URI",requestUri);
          crs::setenv("CONTENT_LENGTH",contentLength);
          crs::dup2(dialogSocket,STDOUT_FILENO);
          crs::dup2(dialogSocket,STDIN_FILENO);
          crs::exec({path});
        }
        else {

          crs::waitpid(child);
 
        }
        // ...
        }
      else // HTTPS is a bit trickier!
        {
        //
        // ... À COMPLÉTER {D-1} ...
        //
        // Reprendre le même procédé qu'en HTTP mais en effectuant la 
        // redirection dans une des deux extrémités de la socket locale
        // obtenue par ``crs::socketpair(SOCK_STREAM)''.
        // Le processus parent doit effectuer une boucle de scrutation
        // passive (avec ``crs::select()'') entre la socket de dialogue et
        // l'autre extrémité de la socket locale afin de retranscrire les
        // échanges entre le client HTTPS (chiffré) et le processus CGI
        // (non chiffré).
        // * Lorsque des données sont disponibles depuis la socket de
        //   dialogue on les extrait avec ``crs::sslRecv()'' et on les
        //   retransmet sur la socket locale avec ``crs::sendAll()''.
        // * Lorsque des données sont disponibles depuis la socket locale
        //   on les extrait avec ``crs::recv()'' et on les retransmet sur la
        //   socket de dialogue avec ``crs::sslSendAll()''.
        // Cette boucle de scrutation passive se termine dès qu'une
        // fin-de-fichier est détectée sur l'une des deux sockets ; seulement
        // à ce moment pourra avoir lieu l'attente du processus enfant.
        //
        auto socketLocale = crs::socketpair(SOCK_STREAM);
        auto child = crs::fork();
        if (child==0){
          crs::setenv("REQUEST_METHOD",requestMethod);
          crs::setenv("REQUEST_URI",requestUri);
          crs::setenv("CONTENT_LENGTH",contentLength);
          crs::dup2(socketLocale[0],STDOUT_FILENO);
          crs::dup2(socketLocale[0],STDIN_FILENO);
          crs::close(socketLocale[1]);
          crs::exec({path});

        }
        else {
          char buffer[0x400];
          crs::close(socketLocale[0]);
          for(;;){
            std::vector<SOCKET> readSet = {socketLocale[1],dialogSocket};
            crs::select(readSet);
            if( crs::find(readSet,socketLocale[1]) != (-1)){
              auto r = crs::recv(socketLocale[1],buffer,sizeof(buffer));
              if ( r==0) break;
              crs::sslSendAll(ssl,buffer,r);
            }
            if( crs::find(readSet,dialogSocket) != (-1)){
              auto r = crs::sslRecv(ssl,buffer,sizeof(buffer));
              if ( r==0) break;
              crs::sendAll(socketLocale[1],buffer,r);
            }
          }
 
        } 
        // ...
        }
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }

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
    if(crs::isFile(path)&&     // ensure it is a file
       crs::access(path,R_OK)) // which is readable
      {
      crs::out("--> sending file: %\n",path);
      auto header=crs::txt("HTTP/1.1 200 OK\r\n"
                           "Connection: %\r\n"
                           "Content-Type: %\r\n"
                           "Content-Length: %\r\n"
                           "\r\n",
                           connection,
                           contentType,
                           crs::fileSize(path));
      if(ssl) { crs::sslSend(ssl,header); }
      else { crs::send(dialogSocket,header); }
      char buffer[0x400];
      int input=crs::openR(path);
      for(;;)
        {
        int r=crs::read(input,buffer,sizeof(buffer));
        if(r==0) { break; } // EOF
        if(ssl) { crs::sslSendAll(ssl,buffer,r); }
        else { crs::sendAll(dialogSocket,buffer,r); }
        }
      crs::close(input);
      if(connection=="close") { break; } // dialog stops here
      else { continue; } // done with reply, but keep-alive
      }

    //---- any other unhandled case ----
    if(true) // the last resort!
      {
      crs::out("--> sending 404 Not Found: %\n",requestUri);
      // prepare content first to provide the header with its length
      auto content=crs::txt("<html><body>\n"
                            "<h2>404 - Not Found</h2>\n"
                            "<p>[<a href=\"/\">home</a>]</p>\n"
                            "<hr>\n"
                            "<p><i>method:</i> <b>%</b></p>\n"
                            "<p><i>uri:</i> <b>%</b></p>\n"
                            "<p><i>path:</i> <b>%</b></p>\n"
                            "<hr>\n"
                            "</body></html>\n",
                            requestMethod,
                            requestUri,
                            path);
      auto header=crs::txt("HTTP/1.1 404 Not Found\r\n"
                           "Connection: %\r\n"
                           "Content-Type: text/html\r\n"
                           "Content-Length: %\r\n"
                           "\r\n",
                           connection,
                           content.size());
      if(ssl) { crs::sslSend(ssl,header); }
      else { crs::send(dialogSocket,header); }
      if(ssl) { crs::sslSend(ssl,content); }
      else { crs::send(dialogSocket,content); }
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
log.add(dialogSocket,sslCtx,"client disconnected");
}

void
runHttpServer(SOCKET httpSocket,
              SharedLog &log)
{
for(;;)
  {
  //---- accept new connection ----
  uint32_t fromIpAddr;
  uint16_t fromPort;
  SOCKET dialogSocket=crs::accept(httpSocket,fromIpAddr,fromPort);
  crs::out("new connection from %:%\n",
           crs::formatIpv4Address(fromIpAddr),fromPort);

  //---- start a new dialog thread ----
  std::thread th(dialogThread,dialogSocket,nullptr,std::ref(log));
  th.detach();
  }
}

void
runHttpAndHttpsServer(SOCKET httpSocket,
                      SOCKET httpsSocket,
                      SharedLog &log)
{
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
  std::vector<SOCKET> readSet={ httpSocket, httpsSocket };
  crs::select(readSet);

  //---- accept new HTTP connection (if available)----
  if(crs::find(readSet,httpSocket)!=-1)
    {
    uint32_t fromIpAddr;
    uint16_t fromPort;
    SOCKET dialogSocket=crs::accept(httpSocket,fromIpAddr,fromPort);
    crs::out("new HTTP connection from %:%\n",
             crs::formatIpv4Address(fromIpAddr),fromPort);

    //---- start a new dialog thread ----
    std::thread th(dialogThread,dialogSocket,nullptr,std::ref(log));
    th.detach();
    }

  //---- accept new HTTPS connection (if available)----
  if(crs::find(readSet,httpsSocket)!=-1)
    {
    uint32_t fromIpAddr;
    uint16_t fromPort;
    SOCKET dialogSocket=crs::accept(httpsSocket,fromIpAddr,fromPort);
    crs::out("new HTTPS connection from %:%\n",
             crs::formatIpv4Address(fromIpAddr),fromPort);

    //---- start a new dialog thread ----
    std::thread th(dialogThread,dialogSocket,sslCtx,std::ref(log));
    th.detach();
    }
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

//---- initialise shared log ----
SharedLog log;

//---- create HTTP listen socket ----
SOCKET httpSocket=crs::socket(PF_INET,SOCK_STREAM,0);
// ... avoiding timewait problems (optional)
crs::setReuseAddrOption(httpSocket,true);
// ... bound to the specified port
crs::bind(httpSocket,httpPortNumber);
// ... listening to connections
crs::listen(httpSocket);

if(!httpsPortNumber) // only HTTP to make things easy at first...
  {
  //---- run server ----
  crs::out("host '%' waiting for HTTP connections on port '%'...\n",
           crs::gethostname(),httpPortNumber);
  runHttpServer(httpSocket,log);

  //---- close listen socket ----
  crs::close(httpSocket);
  }
else // HTTP __and__ HTTPS
  {
  //---- create HTTPS listen socket ----
  SOCKET httpsSocket=crs::socket(PF_INET,SOCK_STREAM,0);
  // ... avoiding timewait problems (optional)
  crs::setReuseAddrOption(httpsSocket,true);
  // ... bound to the specified port
  crs::bind(httpsSocket,httpsPortNumber);
  // ... listening to connections
  crs::listen(httpsSocket);

  //---- run server ----
  crs::out("host '%' waiting for HTTP/S connections on ports '%/%'...\n",
           crs::gethostname(),httpPortNumber,httpsPortNumber);
  runHttpAndHttpsServer(httpSocket,httpsSocket,log);

  //---- close listen sockets ----
  crs::close(httpSocket);
  crs::close(httpsSocket);
  }

return 0;
}

//----------------------------------------------------------------------------
