#include <stdio.h>

int primo(int n)
{
  int i;

  for(i = 3; i < n; i = i + 2)
    if (n % i == 0)
      return 0;
  
  return 1;
}
