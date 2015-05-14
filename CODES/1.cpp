#include<stdio.h>
int mul(int, int); /* Function prototype */

int main()
{
    int a = 4, b = 3, c;
    c = mul(a, b);
    printf("c = %d\n", c);
    return 0;
}
int mul(int a, int b)
{
   return (a * b);
   return (a - b); /* Warning: Unreachable code */
}
