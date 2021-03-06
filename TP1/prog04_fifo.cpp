//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

std::string fifo1="fifo1";
std::string fifo2="fifo2";

//---- create named pipes ----
crs::write(STDOUT_FILENO,crs::txt(
           "creating named pipes '%' and '%'\n",fifo1,fifo2));
//
// ... À COMPLÉTER {1} ...
//
// Faire apparaître dans le système de fichiers, à l'aide de
// ``crs::mkfifo()'', les tubes nommés ``fifo1'' et ``fifo2''.
//
  crs::mkfifo(fifo1);
  crs::mkfifo(fifo2);
// ...

//---- open named pipes ----
crs::write(STDOUT_FILENO,crs::txt(
           "writing to '%', reading from '%'\n",fifo1,fifo2));
int fifoW,fifoR;
(void)fifoW; // avoid ``unused variable'' warning
(void)fifoR;
//
// ... À COMPLÉTER {3} ...
//
// Ouvrir en écriture, à l'aide de ``crs::openW()'', le tube nommé
// ``fifo1'' ; le descripteur sera stocké dans ``fifoW''.
// Ouvrir en lecture, à l'aide de ``crs::openR()'', le tube nommé
// ``fifo2'' ; le descripteur sera stocké dans ``fifoR''.
//
  fifoW = crs::openW(fifo1);
  fifoR = crs::openR(fifo2);
// ...

#if 1 // first solution

//---- interaction loop ----
char buffer[0x400];
(void)buffer; // avoid ``unused variable'' warning
for(;;)
  {
  //
  // ... À COMPLÉTER {5} ...
  //
  // Obtenir ``r'' octets depuis l'entrée standard vers ``buffer'' à l'aide
  // de ``crs::read()''.
  // Si ``r'' est nul (fin-de-fichier), il faut quitter cette boucle avec
  // ``break;''.
  // Utiliser ``crs::writeAll()'' pour envoyer vers ``fifoW'' les ``r''
  // octets précédemment obtenus dans ``buffer''.
  //
  // (semblable à prog02_copy.cpp)
  //
  int r=crs::read(STDIN_FILENO,&buffer,sizeof(buffer)); 
  if(r==0) {break; }
  else {crs::writeAll(fifoW,&buffer,r);
  }
  // ...

  //
  // ... À COMPLÉTER {6} ...
  //
  // Obtenir ``r'' octets depuis ``fifoR'' vers ``buffer'' à l'aide
  // de ``crs::read()''.
  // Si ``r'' est nul (fin-de-fichier), il faut quitter cette boucle avec
  // ``break;''.
  // Utiliser ``crs::writeAll()'' pour envoyer vers la sortie standard les
  // ``r'' octets précédemment obtenus dans ``buffer''.
  //
  // (semblable à prog02_copy.cpp)
  //
  r=crs::read(fifoR,&buffer,sizeof(buffer)); 
  if(r==0) {break; }
  else {crs::writeAll(STDOUT_FILENO,&buffer,r);
  }
  // ...
  }

#else // second solution

//---- bidirectional copy ----
char buffer[0x400];
(void)buffer; // avoid ``unused variable'' warning
for(;;)
  {
  //---- wait for incoming information ----
  //
  // ... À COMPLÉTER {7} ...
  //
  // Surveiller simultanément (avec ``crs::select()'') les données
  // arrivant sur l'entrée standard ou ``fifoR''.
  //

  // ...

  //---- react to standard-input (if available) ----
  //
  // ... À COMPLÉTER {8} ...
  //
  // Si l'entrée standard est prête à fournir des données
  // (``voir crs::find()''), extraire ces quelques données vers ``buffer'',
  // puis recopier toutes les données extraites vers ``fifoW''.
  //
  if( false ) // ... MODIFIER CETTE CONDITION ...
    {

    }
  // ...

  //---- react to pipe input (if available) ----
  //
  // ... À COMPLÉTER {9} ...
  //
  // Si ``fifoR'' est prêt à fournir des données (``voir crs::find()''),
  // extraire ces quelques données vers ``buffer'', puis recopier toutes
  // les données extraites vers la sortie standard.
  //
  if( false ) // ... MODIFIER CETTE CONDITION ...
    {

    }
  // ...
  }

#endif

//---- close named pipes ----
crs::write(STDOUT_FILENO,crs::txt(
           "closing named pipes '%' and '%'\n",fifo1,fifo2));
//
// ... À COMPLÉTER {4} ...
//
// Fermer ``fifoR'' et ``fifoW'' avec ``crs::close()''.
//
  crs::close(fifoR);
  crs::close(fifoW);
// ...

//---- destroy named pipes ----
crs::write(STDOUT_FILENO,crs::txt(
           "removing named pipes '%' and '%'\n",fifo1,fifo2));
//
// ... À COMPLÉTER {2} ...
//
// Faire disparaître du système de fichiers, à l'aide de
// ``crs::unlink()'', les tubes nommés ``fifo1'' et ``fifo2''.
//
  crs::unlink(fifo1);
  crs::unlink(fifo2);
// ...

return 0;
}

//----------------------------------------------------------------------------
