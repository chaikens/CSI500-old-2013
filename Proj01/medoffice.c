#include "csapp.h"

struct command_struct {
  char *role;
  char *choice;
  char *command;
};

static struct command_struct ARRAY[ ] =
  {
    {
      .role = "Doctor",
      .choice = "d\n",
      .command = "./doctor"
    },
    {
      .role = "Nurse",
      .choice = "n\n",
      .command = "./nurse"
    },
    {
      .role = "Receptionist",
      .choice = "r\n",
      .command = "./receptionist"
    }
  };


static void printmenu()
{
  int nchoices =  sizeof( ARRAY )/sizeof( struct command_struct );
  int i;
  printf("Role\tType this and ENTER:\n");
  for( i = 0; i < nchoices; i++ ) {
    printf("%s\t%s", ARRAY[i].role, ARRAY[i].choice );
  }
}

static char * getappfile(char *choice )
{
  char *ret = 0;
  int i = 0;
  int nchoices =  sizeof( ARRAY )/sizeof( struct command_struct );
  while( i < nchoices && ret == NULL ) {
    if( strcmp( choice, ARRAY[i].choice ) == 0 ) {
      ret  = ARRAY[i].command;
    }
    i++;
  }
  return ret;
}


static void docommandwaiting( char * command )
{
  printf("docommandwaiting stub we will run %s\n", command);
}

int main(int argc, char *argv[])
{
  char *inbuffer = 0; /* Must initialize so getline allocates the buffer for us. */
  size_t bufsize; /* Initialization not needed since getline will ignore when inbuffer==0. */
  int looping = 1;

  while( looping ) {
    printmenu( );
    printf("Type admin to administer\n");
    getline( &inbuffer, &bufsize, stdin);
    if( strcmp(inbuffer,"admin\n") == 0 ) { 
      printf("Your password please:");
      getline( &inbuffer, &bufsize, stdin);
      if( strcmp(inbuffer,"IAmTheBoss\n") == 0 ) {
	looping = 0;
      } 
    }
    else {
      char * command = getappfile( inbuffer );
      if( command == NULL ) {
	printf("Unrecognized office role.\n");
      }
      else {
	docommandwaiting( command );
      }
    }
  }
  printf("If you see this, either you're an admin or you broke into our system.\n");
  return 0;
}
