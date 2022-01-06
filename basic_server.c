#include "pipe_networking.h"
#include <signal.h>

char* toUpper(char input[]) {
  char* start = input;
  int i;
  for (i = 0; i < strlen(input); i++) {
    if (input[i] >= 'a' && input[i] <= 'z')
      input[i] -= 32;
    }
  return start;
}

static void sighandler(int signo) {
  if ( signo == SIGINT )
  printf("Exiting and removing WKP\n");
  exit(0);

}


int main() {
  signal(SIGINT, sighandler);

  char clientmsg[100];

  
  int sd = server_setup();
  

  while (1) {

    int client_socket = server_connect(sd);
    printf("[server]: Creating subserver\n");
    int a = fork();

    if (a == 0) { 
      while (1) {
        read(client_socket, clientmsg, 100);
        printf("Processing\n");
        toUpper(clientmsg);
        write(client_socket, clientmsg, 100);
      }
      return 0;
    }
  }


}