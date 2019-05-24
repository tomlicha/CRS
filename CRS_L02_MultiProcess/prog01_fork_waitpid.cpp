//----------------------------------------------------------------------------

#include "crsUtils.hpp"

int
main(int argc,
     char **argv)
{
std::vector<std::string> args(argv,argv+argc);

//---- display process identifiers ----
crs::out("process % starting... (parent=%)\n",
         crs::getpid(),crs::getppid());

//---- create a new process ----
pid_t result=-1;
//
// ... À COMPLÉTER {1} ...
//
// Utiliser ``crs::fork()'' pour faire apparaître un nouveau processus
// et mémoriser le résultat de cet appel dans ``result''.
//
result = crs::fork();
// ...

//---- display process identifiers and fork() result ----
crs::out("process % obtained % from fork() (parent=%)\n",
         crs::getpid(),result,crs::getppid());

//---- distinguish child process from parent process ----
//
// ... À COMPLÉTER {2} ...
//
// Utiliser la valeur de ``result'' pour que le nouveau processus (l'enfant)
// passe par la première branche de l'alternative alors que le processus
// initial prendra la seconde branche.
//
if( result == 0 ) // ... MODIFIER CETTE CONDITION ...
// ...
  {
  //
  // ... À COMPLÉTER {5} ...
  //
  // Provoquez un plantage du processus enfant,
  // en écrivant à l'adresse nulle par exemple :
  //   int *p=nullptr; *p=42;
  // ou en levant une exception :
  //   throw std::runtime_error("Drop dead!");
   throw std::runtime_error("Drop dead!");
  // ...

  //
  // ... À COMPLÉTER {4} ...
  //
  // Terminer le processus enfant en invoquant ``crs::exit()'' avec
  // une valeur entière de votre choix (<256).
  //
  crs::exit(154);
  // ...
  }
else
  {
  //---- wait for child process ----
  crs::out("process % waiting for child process %\n",
           crs::getpid(),result);
  int status=-1,signal=-1;
  //
  // ... À COMPLÉTER {3} ...
  //
  // Attendre la terminaison du processus enfant à l'aide de la version
  // de ``crs::waitpid()'' à trois paramètres afin de renseigner les
  // variables ``status'' et ``signal''.
  //
  crs::waitpid(result,status,signal);
  // ...
  crs::out("after waitpid(%) --> status=%, signal=% (%)\n",
            result,status,signal,crs::strsignal(signal));
  }

crs::out("process % leaving... (parent=%)\n",
         crs::getpid(),crs::getppid());
return 0;
}

//----------------------------------------------------------------------------
