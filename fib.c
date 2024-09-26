#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int64_t iterative(int s)
{
   int64_t prev_num = 0;
   int64_t saved_num = 1;
   int64_t current_num;

   for (int i = 2; i < s; i++)
   {
      current_num = prev_num + saved_num;
      prev_num = saved_num;
      saved_num = current_num;
   }
   return current_num;
}

typedef int64_t (*Functionpointer)(int);
Functionpointer fib_provider = NULL;

int64_t recursive_wrap(int n)//, int64_t *memo)
{
   //printf("Recursive wrap is called: %d\n", n);
   if (n == 1)
   {
      return 0;
   }
   else if (n == 2)
   {
      return 1;
   }
   else
   {
      return (fib_provider(n - 1) + fib_provider(n - 2));
   }
}
int64_t *memo = NULL;
int64_t fib_memo(int user_num)
{
   if (memo == NULL)
   {
      memo = (int64_t *)malloc((1000) * sizeof(int64_t));
      for (int i = 0; i < 1000; i++)
      {
         memo[i] = 4;
      }
   }
   if (memo[user_num] == 4)
   {
      memo[user_num] = recursive_wrap(user_num);
      //printf("Adding to cache: %d\n", user_num);
   }
   /*else
   {
      printf("Recieving from cache: %d\n", user_num);
   }*/
   return memo[user_num];
}

int main(int argc, char *argv[])
{

   int user_number = atoi(argv[1]);

   int64_t fibo;

   if (strcmp(argv[2], "i") == 0)
   {
      fibo = iterative(user_number);
   }
   else
   {
      fib_provider = fib_memo;
      fibo = fib_provider(user_number);

   }
   
   printf("%" PRIi64 "\n", fibo);

   return 0;
}
