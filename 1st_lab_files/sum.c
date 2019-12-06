
#include <stdio.h>
int main ()
{
  int i,sum=0;
  printf("\nWe are calculating the sum from 1 to 10\n \n");
  for(i=1; i<=9; i++)
  { 
    sum = sum + i;
  }
  printf("Sum is : %d \n \n", sum) ;
  return 0;
}
