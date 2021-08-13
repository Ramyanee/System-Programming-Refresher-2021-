#include <stdio.h>

long long int fibonacci(int n);
long long int array[43];
int main (int argc, char **argv)
{
    for(int i =0; i<=42; i++)
    array[i]=-1;
   long long int fib;
   int n;

   for (n = 0; n <= 42; n++) {
      fib = fibonacci(n);
      printf("fibonnaci(%d) = %lld\n",n,fib);
   }

   return 0;
}

long long int fibonacci(int n)
{   
   long long int fib;
   if (n <= 0) {
      fib = 0;
      array[0]=fib;
   }
   else if (n == 1) {
      fib = 1;
      array[1]=fib;
   }
   else if(array[n]!=-1) return array[n];
   else {

       long long int f1,f2;

       if(array[n-1]==-1)f1 = fibonacci(n-1);
       else f1 = array[n-1];
       if(array[n-2]==-1)f2 = fibonacci(n-2);
       else f2 = array[n-2];
       fib = f1+f2;
       array[n]=fib;
   }

   return fib;
}
