#include <stdio.h>

int main(int argc, char *argv[])
{
  char *inbuffer = 0; /* Must initialize so getline allocates the buffer for us. */
  size_t bufsize; /* Initialization not needed since getline will ignore when inbuffer==0. */
  printf("Hello doctor.  This app is a stub. Press enter to exit.");
  getline( &inbuffer, &bufsize, stdin );
  return 0;
}
