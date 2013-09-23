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

/* 
 * I had to do library research to find the suitable exec variant.
 * execl is the simplest: It takes a pathname to the exe file,
 * and one or more command line args, the first should be the name
 * of the command.  But the CSAPP wrappers only wraps Execve
 * which requires argument and environment jagged array data structures.
 * So, I'll set up an argument structure, and pass our environment
 * pointer from global environ to the environment argument.
 */
static void docommandwaiting( char * command )
{
  pid_t fret;
  printf("\n docommandwaiting called with %s\n", command);
  fret = Fork( );
  if( fret ) {
    /* This code is ran by the parent only.  The parent should wait and
     * continue when wait returns.
     */
    pid_t status;
    Wait( &status );
    printf("Info: child exited with status %d\n", status);
    return ;
  } else {
    /* This code is ran by the child only.  The child should exec the
     * hopefully executable command file.
     */
    char *argv[] = { 0, 0 }; /*Allocate a length 2 array of char* on the stack*/
    /* The first pointer will be set to the address of our command.
     * The second will remain NULL to terminate the argument structure.
     */
    argv[0] = command;
    Execve( command, argv, environ );
    /* Control should NEVER return thing when things are normal. */
    printf("Something is wrong: Maybe exe file %s doesn't exist.\n");
    printf("We, the child, will exit with an error code 1.\n");
    exit( 1 );
  }
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
