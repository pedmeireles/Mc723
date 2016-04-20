#include <stdio.h>
#include <stdlib.h>

int main(){
  char l[] = "hello world!\n" ;
  int i;
  for (i = 0; l[i] != 0; i++){
  printf("%c", l[i]);
  }

  return 0;
}
