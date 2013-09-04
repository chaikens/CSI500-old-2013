#include "csapp.h"

int main(int argc, char *argv[])
{
  char *pInline;
  int nread=0;
  int nret;
  pInline = 0;

  printf("Hellow from an interactive prg\nPlese type your command");
  nret = getline( & pInline, &nread, stdin );
  printf("Thanks for line %s It's length is nread=%d nret=%d,", pInline, nread, nret);
  printf("\nGive me another command:");
  nret = getline( & pInline, &nread, stdin );
  printf("Thanks for line %s It's length is nread=%d nret=%d,", pInline, nread, nret);

  return 0;
}
