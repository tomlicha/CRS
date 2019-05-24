//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
if((args.size()!=2)&&(args.size()!=3))
  {
  crs::err("usage: % input [output]\n",args[0]);
  crs::exit(1);
  }
std::string inputFileName=args[1],outputFileName;
if(args.size()>2) { outputFileName=args[2]; }

//
// ... À COMPLÉTER {A} ...
//
//---- create anonymous pipe ----
std::array<int,2> pipe = crs::pipe();
//---- create child process ----
pid_t result = crs::fork();
// ...

//---- handle child process ----
//
// ... À COMPLÉTER {A} ...
//
if( result == 0 ) // ... MODIFIER CETTE CONDITION ...
// ...
  {
  //
  // ... À COMPLÉTER {A} ...
  //
  // * Le descripteur en lecture sur le tube est inutile.
  // * L'entrée standard doit correspondre au fichier ``inputFileName''.
  // * La sortie standard doit correspondre à l'écriture dans le tube.
  // * Ce processus enfant doit être recouvert par la commande "gunzip" qui,
  //   sans autre argument sur sa ligne de commande, lit des données
  //   compressées sur son entrée standard, et en produit une version
  //   décompressée sur sa sortie standard.
  //
  //---- close useless end of the pipe ----
  crs::close(pipe[0]);
  //---- redirect standard-input to input file ----
  int input=crs::openR(inputFileName);
  crs::dup2(input,STDIN_FILENO);
  crs::close(input);
  //---- redirect standard-output to pipe ----
  crs::dup2(pipe[1],STDOUT_FILENO);
  crs::close(pipe[1]);
  //---- execute decompression program ----
  crs::exec({"gunzip"});
  // ...
  }

//---- close useless end of the pipe ----
//
// ... À COMPLÉTER {A} ...
//
  crs::close(pipe[1]);
// ...

if(!outputFileName.empty()) // output file name given
  {
  //
  // ... À COMPLÉTER {B} ...
  //
  // * Utiliser les services d'un second processus enfant.
  // * Son entrée standard doit correspondre à la lecture depuis le tube.
  // * Sa sortie standard doit correspondre au fichier ``outputFileName''.
  // * Ce processus enfant doit être recouvert par la commande "bzip2" qui,
  //   sans autre argument sur sa ligne de commande, lit des données sur son
  //   entrée standard, et en produit une version compressée sur sa sortie
  //   standard.
  //
  //---- create second child process ----
  pid_t child2 = crs::fork();
  //---- handle second child process ----
  if( child2 == 0 ) // ... MODIFIER CETTE CONDITION ...
    {
    //---- redirect standard-output to output file ----
    int output=crs::openW(outputFileName);
    crs::dup2(output,STDOUT_FILENO);
    //---- redirect standard-input to pipe ----
    crs::dup2(pipe[0],STDIN_FILENO);
    //---- execute compression program ----
    crs::exec({"bzip2"});
    }

  //---- close useless end of the pipe ----
  crs::close(pipe[0]);
  //---- wait for second child process ----
  crs::waitpid(child2);
  // ...
  }
else // no output file name given
  {
  //
  // ... À COMPLÉTER {A} ...
  //
  //---- display decompressed data from pipe ----
for(;;)
  {
  std::string msg; 
  msg = crs::read(pipe[0],0x100);
  if(msg.empty()) {
    break;
  }
  // ...
  crs::write(STDOUT_FILENO,msg);
  }

  //---- close pipe ----
  crs::close(pipe[0]);
  // ...
  }

//---- wait for child process ----
//
// ... À COMPLÉTER {A} ...
//
  crs::waitpid(result);
// ...

return 0;
}

//----------------------------------------------------------------------------
