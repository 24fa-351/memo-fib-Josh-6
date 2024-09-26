#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


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

int64_t recursive_wrap(int n, int64_t *memo)
{
   if(n == 1)
   {
      return 0;
   }
   else if(n == 2)
   {
      return 1;
   }
   else if(memo[n] != 4)
   {
      return memo[n];
   }
   else
   {
      memo[n] = (recursive_wrap(n - 1, memo) + recursive_wrap(n-2, memo));
      return memo[n];
   }
}

int64_t fib_memo(int user_num) 
{
   int64_t *memo = (int64_t *)malloc((user_num + 1) * sizeof(int64_t));
    
    for (int i = 0; i <= user_num; i++) 
    {
        memo[i] = 4;
    }

    int64_t result = recursive_wrap(user_num, memo);

    return result;
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
      fibo = fib_memo(user_number);
   }
   //fprintf(saved, "%d %" PRIi64 "\n", sum, fibo);
   printf("%" PRIi64 "\n", fibo);
   
   return 0;
}
