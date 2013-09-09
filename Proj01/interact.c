#include "csapp.h"

int main(int argc, char *arg[])
{
  char *pToInputLine = NULL;
  /*This MUST be initialized, otherwise getline might
    think the memory pointed to by garbage is good to
    use or re-allocate with realloc!*/
  int nread=0;
  int nret;
  printf("Hello. This is an interactive program.\n");
  nret = getline( &pToInputLine, &nread, stdin);
  printf("Thanks for line %s It's length is nread=%d nret=%d,", pToInputLine, nread, nret);
  printf("\nGive me another command:");
  nret = getline( & pToInputLine, &nread, stdin );
  printf("Thanks for line %s It's length is nread=%d nret=%d,", pToInputLine, nread, nret); 



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
