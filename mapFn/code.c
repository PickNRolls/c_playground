#include <stdio.h>
#include <stdlib.h>

int* map (int* arr, int (*func)(int));
int sqr (int num);

int main (void)
{
  int array[] = {1, 2, 3};
  int* result = map(array, sqr);

  for (int i = 0; i < 3; i++)
  {
    printf("%i\n", array[i]);
  }

  printf("\n");

  for (int i = 0; i < 3; i++)
  {
    printf("%i\n", result[i]);
  }

  free(result);
}

int* map (int* arr, int (*func)(int))
{
  int* res = malloc(sizeof(int) * 3);
  for (int i = 0; i < 3; i++)
  {
    res[i] = func(arr[i]);
  }

  return res;
}

int sqr (int num)
{
  return num * num;
}
