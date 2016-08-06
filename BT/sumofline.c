#include <stdio.h>

int main()
{
  int n,d,sum;
  char c;

  scanf("%d", &n);

  while(n--)
  {
    sum = 0;
    while(1)
    {
      scanf("%d%c",&d,&c);
      sum = sum + d;
      if (c == '\n')
      {
        printf("%d\n", sum);
        break;
      }
    }
  }
}
