#include <stdio.h>

char buf[200] = "";
int getOctal(int i)
{
  return 4*(buf[i] - '0') + 2*(buf[i+1] - '0') + (buf[i+2] - '0');
}

int main()
{
  int i, length, head;

  scanf("%s", buf);
  for (i=0; buf[i]!='\0'; i++);
  length = i;
  head = length % 3;

  i = 0;
  switch (head)
  {
    case 1:
      printf("%d", buf[0]-'0');
      i = 1;
      break;

    case 2:
      printf("%d", 2*(buf[0]-'0') + (buf[1]-'0'));
      i = 2;
      break;
  }

  for (; buf[i]!='\0'; i+=3)
    printf("%d", getOctal(i));
}
