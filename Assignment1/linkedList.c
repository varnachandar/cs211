#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct Node
{
  int val;
  struct Node* next;
};

void traverse(struct Node* n, int count) 
{ 

  struct Node* prev = NULL; 
  printf("%d\n", count);

  while (n != NULL) 
  { 
      printf("%d\t", n->val); 
       prev = n; 
       n = n->next; 
       free(prev);
  } 
  printf("\n");
} 

int delete(struct Node* n, int del, int* count) 
{ 
  if(n == NULL) {return 1;}
  struct Node* prev = NULL;

  while (n != NULL) 
  { 
       if(prev == NULL && n->val == del)
        {
          *count = *count-1; 
          return 0; 
        }

        if(n->val == del)
        {
          if(n->next == NULL) {prev->next = NULL;}
          else {prev->next = n->next;}
          free(n);
          *count = *count-1; 
          return 1;
        }

        prev = n;
        n = n->next; 
  } 

return 1;
} 

int sort(struct Node* n, struct Node* add)
{
  struct Node* prev = NULL;
  struct Node* curr = n; 
  int insert = add->val; 

  while(1)
  {

   if(insert< curr->val && (prev == NULL))
   {
      add-> next = curr;
      return 0;
      //change head to add in main
   }

   if((insert == curr->val) && (curr->next == NULL))
   {
     curr->next = add; 
     return 1;
   }

   if((insert == curr->val) && (curr->next != NULL))
   {
     add->next = curr->next; 
     curr->next = add; 
     return 1;
   } 


   if((insert > curr->val) && (curr->next != NULL))
   {
      prev = curr;
      curr = curr->next;
      continue; 
   }

   if((insert > curr->val) && (curr->next == NULL))
   {
     curr->next = add;
     return 1;
   }

    if((insert < curr->val) && (prev != NULL))
    {
      prev->next = add;
      add->next = curr; 
      return 1;
   }
  }
  
} 
 
 int main(int argc, char* argv[])
 {
    FILE* openFile = fopen(argv[1], "r");
    struct Node *head = NULL;

    char task;
    int num;
    int count = 0; 
    
    while(fscanf(openFile, "%c\t%d\n", &task, &num) == 2)
    {
       //printf("char: %c, int: %d\n", task, num);

       if(task == 'i') 
       {
         count = count+1;

         if(head != NULL)
         {
           struct Node* add;
           add = (struct Node*)malloc(sizeof(struct Node)); 
           add->val = num;
           add->next = NULL;
           if(sort(head, add) == 0)
           {
              head = add;
           }       
          } 

         if(head == NULL)
         {
           head = (struct Node*)malloc(sizeof(struct Node)); 
           head->val = num;
           head->next = NULL;
         }
       }
      
       if(task == 'd')
       { 
         if(delete(head, num, &count)==0)
         {
           struct Node* prev = head; 
           head = head->next;
           free(prev);
         } 
       }
    }
   traverse(head, count);
   fclose(openFile);
 } 
       



