#include "csapp.h"
#include <string.h>

int main( int argc, char *argv[] )
{
  char cmdline[MAXLINE];
  printf("Gimme a Nine:");
  Fgets(cmdline, MAXLINE, stdin);
  if(feof(stdin))
    exit(0);
  if( strcmp(cmdline, "Nine\n") != 0 )
    {
      printf("Hey, that's %s, not Nine!\n", cmdline);
      printf("Now why did it print a newline just before the , ??\n");
    }
  else
    {
      printf("GREAT!  I love getting a Nine\n");
    }
  exit (0);
}


  
