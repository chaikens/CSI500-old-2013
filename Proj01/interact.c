#include "csapp.h"

int main(int argc, char *arg[])
{
  char *pToInputLine;
  int nread;
  printf("Hello. This is an interactive program.\n");
  nread = getline( &pToInputLine, &nread, stdin);
  printf("Thanks for %s A line of length %d\n", pToInputLine, nread);
  if( strcmp(pToInputLine, "FirstCommand\n")==0)
    {
      printf("Thanks for that FirstCommand!\n");
    }
  else if( strcmp(pToInputLine, "Fork\n") )
    {
      int fret;
      printf("hey man, I see you really want to try a Fork. Here goes\n");
      fret = Fork();
      printf("Fork() returned %d\n", fret);
    }
}
