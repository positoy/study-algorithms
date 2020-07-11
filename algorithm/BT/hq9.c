#include <stdio.h>

int main()
{
  int i;
  char code[26] = "";

  scanf("%s", code);

  for (i=0; code[i]!='\0'; i++)
  {
    switch (code[i])
    {
      case 'h':
      case 'H':
        puts("Hello, world!");
        break;
      case 'q':
      case 'Q':
        puts(code);
        break;
      case '9':
        puts("99 Bottles of Beer on the Wall");
        break;
    }

  }

}
