#include "csapp.h"

int main(int argc, char *arg[])
{
  char *pToInputLine = NULL;
  /*This MUST be initialized, otherwise getline might
    think the memory pointed to by garbage is good to
    use or re-allocate with realloc!*/
  int bufsize=0;
  /*We MUST use a non-misleading, and even better, informative
    name for the bufsize variable. My original "nread" was WRONG*/
  int nret;
  printf("Hello. This is an interactive program.\n");
  nret = getline( &pToInputLine, &bufsize, stdin);
  printf("Thanks for line %s lengths: bufsize=%d nret=%d,", pToInputLine, bufsize, nret);
  printf("\nGive me another command:");
  nret = getline( & pToInputLine, &bufsize, stdin );
  printf("Thanks for line %s Lengths: bufsize=%d nret=%d,", pToInputLine, bufsize, nret); 



  if( strcmp(pToInputLine, "FirstCommand\n")==0)
    {
      printf("Thanks for that FirstCommand!\n");
    }
  else if( strcmp(pToInputLine, "Fork\n") == 0 )
    {
      int fret;
      printf("hey man, I see you really want to try a Fork. Here goes\n");
      fret = Fork();
      printf("Fork() returned %d\n", fret);
    }
}
