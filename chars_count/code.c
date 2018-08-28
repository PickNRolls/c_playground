#include <stdio.h>

int main()
{
  int character;
  int tabsCount = 0, nCount = 0, spaceCount = 0;

  while ((character = getchar()) != EOF)
  {
    putchar(character);
    if (character == '\n') nCount++;
    else if (character == 9) tabsCount++;
    else if (character == ' ') spaceCount++;
  }

  printf("Tabs: %i\nLines: %i\nSpaces: %i\n", tabsCount, nCount, spaceCount);

  return 0;
}
