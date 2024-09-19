#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

long long int array[94];

/*int64_t fib_wrapper(int num) 
{
   


   return 0;
}*/
int64_t iterative(int s)
{
   int64_t  prev_num = 0;
   int64_t  saved_num = 1;
   int64_t  current_num;

   for(int i = 2; i < s; i++)
   {
      current_num = prev_num + saved_num;
      prev_num = saved_num;
      saved_num = current_num;
   }
   return current_num;
}

int64_t recursive(int n)
{
   if(n == 1)
   {
      return 0;
   }
   else if(n == 2)
   {
      return 1;
   }
   else if(array[n] != -1)
   {
      return array[n];
   }
   else
   {
      array[n] = (recursive(n - 1) + recursive(n-2));
      return array[n];
   }
}

int main(int argc, char* argv[]) 
{

   int user_number = atoi(argv[1]);

   int64_t fibo;
   
   if (strcmp(argv[2], "i") == 0)
   {
      fibo = iterative(user_number);
   }
   else
   {
      for (int i = 0; i <= user_number; i++) 
      {
        array[i] = -1;
      }

      fibo = recursive(user_number);
   }
   //fprintf(saved, "%d %" PRIi64 "\n", sum, fibo);
   printf("%" PRIi64 "\n", fibo);
   
   return 0;
}
