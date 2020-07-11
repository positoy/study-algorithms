#include <stdio.h>

int main()
{
  int i, t;
  int cup[4] = {0, 1, 0, 0};
  char buf[100] = {0};

  scanf("%s", buf);

  for (i=0; buf[i]!='\0'; i++)
  {
    switch (buf[i])
    {
      case 'A':
        t = cup[1];
        cup[1] = cup[2];
        cup[2] = t;
        break;
      case 'B':
        t = cup[2];
        cup[2] = cup[3];
        cup[3] = t;
        break;
      case 'C':
        t = cup[1];
        cup[1] = cup[3];
        cup[3] = t;
        break;
    }
  }

  for (i=1; i<=3; i++)
    if (cup[i] == 1)
      printf("%d", i);

}
