#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int value;
  struct node* left;
  struct node* right;
}
node;

bool binarySearch (int value, node* root);
node* newNode (int value, node* left, node* right);

int main (void)
{
  node* nodeTwo = newNode(2, NULL, NULL);
  node* nodeEight = newNode(8, NULL, NULL);
  node* nodeFive = newNode(5, nodeTwo, nodeEight);

  node* nodeTwelve = newNode(12, NULL, NULL);
  node* nodeEighteen = newNode(18, NULL, NULL);
  node* nodeFifteen = newNode(15, nodeTwelve, nodeEighteen);

  node* root = newNode(10, nodeFive, nodeFifteen);

  if (binarySearch(2, root))
  {
    printf("It has it.\n");
  }
  else
  {
    printf("It hasn't it.\n");
  }
}

/*

               <- 10 ->
      <- 5 ->           <- 15 ->
    2         8       12        18


*/

bool binarySearch (int value, node* root)
{
  if (root == NULL) return false;

  if (value < root->value)
  {
    return binarySearch(value, root->left);
  }

  else if (value > root->value)
  {
    return binarySearch(value, root->right);
  }

  else return true;
}

node* newNode (int value, node* left, node* right)
{
  node* instance = malloc(sizeof(node));
  instance->value = value;
  instance->left = left;
  instance->right = right;

  return instance;
}
