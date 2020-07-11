#include <stdio.h>

void print(int num)
{
  if (num < 10)
    printf("%d", num);
  else
    printf("%c", num - 10 + 'A');
}

int main()
{
  int buf[100] = {0};
  int d,r;
  int ibuf,j;
  scanf("%d %d", &d, &r);

  ibuf = 0;
  while (d != 0)
  {
    buf[ibuf++] = d % r;
    d /= r;
  }

  for (j=ibuf-1; j>=0; j--)
    print(buf[j]);
}
