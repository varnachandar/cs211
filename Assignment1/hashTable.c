#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int val;
  struct Node* next;
};

int hashCode(int key)
{
    int code = key%10000;
    if(code<0) {code+10000;}

    return code; 
}

void insert(int key, int* collisions, struct Node* hash)
{
    int code = hashCode(key); 

    if(hash[code].val != 0)
    {
         struct Node* add;
         add->val = key; add->next = NULL;

         struct Node* n = &hash[code];

         while(n->next != NULL)
         {
             n = n->next;
         }

         n->next = add;
         *collisions = *collisions+1;
         return; 
    } 

   if(hash[code].val == 0)  
    {
       hash[code].val = key; 
       hash[code].next = NULL;
       return;
    }
}  

void search(int key, int* success, struct Node* hash)
{
    int code = hashCode(key); 

    if(hash[code].val != 0)
    {
        struct Node* n = &hash[code];

        if(n->val == key)
        {
            *success = *success+1;
            return;
        }
         else
         {
             while(n->val != key && n->next != NULL)
             {
                 n = n->next;
             }

             if(n->val == key)
             {
                 *success = *success+1;
                 return;
             }

             if(n == NULL) {return;}
         }

         return; 
    } 

   if(hash[code].val == 0)  
    {
       return; 
    }
}


int main(int argc, char* argv[])
{
    struct Node* hash = (struct Node*)calloc(10000, sizeof(struct Node));

    FILE* openFile = fopen(argv[1], "r");
    
    int collisions = 0;
    int inserts = 0;
    int successfulSearch = 0;
    int key; char task;


    while(fscanf(openFile, "%c\t%d\n", &task, &key) == 2)
    {
        if(task == 'i')
        {
            ++inserts;
           insert(key, &collisions, hash);
        }
        if(task == 's')
        {
           search(key, &successfulSearch, hash);
        }
    }

    fclose(openFile);
    printf("%d\n", collisions);
    printf("%d\n", successfulSearch);
    free(hash);
    return 0;
}
