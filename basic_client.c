#include "pipe_networking.h"


int main() {


  char line[100];

  int sd = client_connect();
  while (1) {
    printf("Input: ");
    fgets(line, 100, stdin);
    write(sd, line, 100);
    read(sd, line, 100);
    printf("Processed response: %s", line);
  }
}