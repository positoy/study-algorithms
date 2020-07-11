#include <stdio.h>

int main()
{
  int i, length, prefix;
  char buf[200] = "";

  scanf("%s", buf);

  for (i=0; buf[i]!='\0'; i++);
  length = i;
  prefix = length % 3;

  for (i=0; i<prefix; i++)
  printf("%c", buf[i]);

  for (; buf[i]!='\0'; i++)
  {
    if (i > 0 && (i - prefix) % 3 == 0)
      printf(",");
    printf("%c", buf[i]);
  }
}
