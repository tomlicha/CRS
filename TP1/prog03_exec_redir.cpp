//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- check command line arguments ----
std::string inputFileName,outputFileName;
for(int i=1;i<crs::len(args);++i)
  {
  if((args[i]=="-i")&&(i+1<crs::len(args)))
    { inputFileName=args[++i]; }
  else if((args[i]=="-o")&&(i+1<crs::len(args)))
    { outputFileName=args[++i]; }
  else
    {
    crs::write(STDERR_FILENO,crs::txt(
               "usage: % [-i input] [-o output]\n",args[0]));
    crs::exit(1);
    }
  }

//---- interactively compose a new command line ----
std::vector<std::string> newArgs;
for(;;)
  {
  //---- ask the user for next argument ----
  crs::write(STDOUT_FILENO,crs::txt(
             "arguments: %\n"
             "next argument (or empty line)? ",
             crs::join(newArgs,", ")));
  auto nextArg=crs::strip(crs::readLine(STDIN_FILENO));
  if(nextArg.empty()) { break; }
  newArgs.push_back(nextArg);
  }

//---- redirect standard-input (if requested) ----
if(!inputFileName.empty())
  {
  //
  // ... À COMPLÉTER {2} ...
  //
  // Ouvrir en lecture, à l'aide de ``crs::openR()'', le fichier désigné
  // par ``inputFileName''.
  // Utiliser ensuite ``crs::dup2()'' pour que le fichier désigné par le
  // descripteur précédemment obtenu soit aussi désigné par le descripteur
  // de l'entrée standard (qui ne désignera donc plus le terminal).
  // Désormais, le descripteur obtenu à l'ouverture du fichier devient
  // inutile (puisque l'entrée standard désigne ce fichier) et peut être
  // fermé avec ``crs::close()''.
  //
  int input=crs::openR(inputFileName);
  crs::dup2(input,STDIN_FILENO);
  crs::close(input);
  // ...
  }

//---- redirect standard-output (if requested) ----
if(!outputFileName.empty())
  {
  //
  // ... À COMPLÉTER {3} ...
  //
  // Ouvrir en écriture, à l'aide de ``crs::openW()'', le fichier désigné
  // par ``outputFileName''.
  // Utiliser ensuite ``crs::dup2()'' pour que le fichier désigné par le
  // descripteur précédemment obtenu soit aussi désigné par le descripteur
  // de la sortie standard (qui ne désignera donc plus le terminal).
  // Désormais, le descripteur obtenu à l'ouverture du fichier devient
  // inutile (puisque la sortie standard désigne ce fichier) et peut être
  // fermé avec ``crs::close()''.
  //
  int output=crs::openW(outputFileName);
  crs::dup2(output,STDOUT_FILENO);
  crs::close(output);
  // ...
  }

//---- execute another program in the current process ----
//
// ... À COMPLÉTER {1} ...
//
// Utiliser simplement ``crs::exec()'' avec la ligne de commande
// ``newArgs'' préalablement constituée.
//
  crs::exec(newArgs);
// ...

//---- the current program has been replaced by the new one ----
crs::write(STDERR_FILENO,
           "on success, exec() never returns.\n"
           "this message should not appear!\n");

return 0;
}

//----------------------------------------------------------------------------
