#include <stdio.h>

int main()
{
  int i,j,k;

  for (i='A'; i<='Z'; i++)
  for (j='A'; j<='Z'; j++)
  for (k='A'; k<='Z'; k++)
    printf("%c%c%c ", i, j, k);
}
