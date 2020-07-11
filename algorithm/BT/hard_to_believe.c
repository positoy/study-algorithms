#include <stdio.h>

int main()
{
  int a,b,c;
  char buf[100];

  int i,len;
  int done = 0;

  // input a
  i = 0;
  while (1)
  {
    scanf("%c", &buf[i]);
    if (buf[i] == '+')
      break;
  }

  len = i;
  a = 0;
  for (i=0; i<len; i++)
  {
    a = buf[i];
    a = a * 10;
  }

  a = a / 10;

  // input b

  // process

  // print
}
