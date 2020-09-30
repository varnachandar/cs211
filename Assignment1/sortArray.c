#include <stdio.h>

void evenSort(int amt, int* arr){
  for(int i=0; i<amt-1; i++)
  {
    for(int j=0; j<amt-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
 
void oddSort(int amt, int* arr, int arg){
  for(int i = amt; i<arg-1; i++)
  {
    for(int j = amt; j<arg-1; j++)
    {
      if(arr[j]<arr[j+1])
      {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(int argc, char* argv[])
{
    FILE* openFile = fopen(argv[1], "r");
 
    int arguments;
     int n = fscanf(openFile, "%d", &arguments);
     int* holdNums = (int*)malloc(sizeof(int*)*arguments);
 
    int scan;
 
    for(int i = 0; i<arguments; i++)
     {
      int nums = fscanf(openFile, "%d\t", &scan);
      //printf("before assignment: %d, ", scan);                                             
      holdNums[i] = scan;
      //printf("%d ", holdNums[i]);                                                         
    }
 
    //printf("\n");                                                                             
 
    int left = 0;
    int right = arguments -1;
    int temp;
    int evenCount = 0;
    
    while(left < right)
    {
        while(holdNums[left]%2 == 0)
        {
        left++;
        evenCount++;
        }

        while(holdNums[right]%2!=0 && left<right) {right--;}
 
        if(left<right)
        {
          int temp = holdNums[left];
          holdNums[left] = holdNums[right];
          holdNums[right] = temp;
        }
    }
 
   //  printf("%d\n", evenCount);                                                              
   evenSort(evenCount, holdNums);
   oddSort(evenCount, holdNums, arguments);
   ///*                                                                                        
   for(int j=0; j<arguments; j++)
   {
    printf("%d\t", holdNums[j]);
   }
 
   printf("\n");
   free(holdNums);
   fclose(openFile);
   return 0; //*/                                                                              

}
