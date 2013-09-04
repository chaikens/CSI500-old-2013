#include "csapp.h"

int main(int argc, char *argv[])
{
  char *pInline;
  int nread;
  pInline = 0;

  printf("Hellow from an interactive prg\nPlese type your command");
  nread = getline( & pInline, 0, stdin );
  printf("Thanks for line %s It's length is %d,", *pInline, nread);
  return 0;
}
