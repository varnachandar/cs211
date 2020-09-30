#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};


void traverse(struct Node* n) 
{ 

  if(n == NULL) {return;}

  traverse(n->left);
  printf("%d\t", n->val); 
  traverse(n->right);

  free(n);
} 

void insert(struct Node* n, int num)
{
    struct Node* add = NULL;
    add = (struct Node*)malloc(sizeof(struct Node));
    add->val = num;
    add->left = NULL;
    add->right = NULL;

  while(1)
  {
      if(num == n->val)
      {
          free(add);
          return; 
      }
      if((num > n->val) && (n->right != NULL))
      {
          n = n->right;
      }
      if((num > n->val) && (n->right == NULL))
      {
          n->right = add;
          return;
      }
       if((num < n->val) && (n->left != NULL))
      {
          n = n->left;
      }

      if((num < n->val) && (n->left == NULL))
      {
          n->left = add;
          return;
      }
  }
}

int main(int argc, char* argv[])
{
    FILE* openFile = fopen(argv[1], "r");
    struct Node *head = NULL;
    
    int num;
    char same;

    while(fscanf(openFile, "%c\t%d\n", &same, &num) == 2)
    {
       if(head != NULL)
       {
         insert(head, num);
        } 

        if(head == NULL)
        {
          head = (struct Node*)malloc(sizeof(struct Node)); 
          head->val = num;
          head->left = NULL;
          head->right = NULL;
        }   
    }

   fclose(openFile);
   traverse(head);
   printf("\n");
}
