#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char* read (void);

int main (void)
{
  printf("Enter string: ");
  char* string = read();
  if (string == NULL) printf("You didn't write anything!\n");
  else printf("%s\n", string);

  free(string);
}

char* read (void)
{
  char* buffer = NULL;

  unsigned int capacity = 0;
  unsigned int len = 0;

  int c;

  while ((c = fgetc(stdin)) != '\n' && c  != EOF)
  {

    if (len + 1 > capacity)
    {

      if (capacity == 0) capacity = 32;
      else if (capacity <= (UINT_MAX / 2)) capacity *= 2;
      else
      {
        free(buffer);
        return NULL;
      }

      char* tmp = realloc(buffer, capacity * sizeof(char));
      if (tmp == NULL)
      {
        free(buffer);
        return NULL;
      }

      buffer = tmp;
    }

    buffer[len++] = c;
  }

  if (len == 0 && c == EOF)
  {
    return NULL;
  }

  return buffer;
}
