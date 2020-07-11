#include <stdio.h>

int main()
{
  int i;
  char m;
  char input[300];
  fgets(input, 300, stdin);

  for (i=0; input[i]!='\0'; i++)
  {
    printf("%c", input[i]);
    switch(input[i])
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        m = input[i];
        if (input[i+1] == 'p' && input[i+2] == m)
          i = i + 2;
    }
  }
}
