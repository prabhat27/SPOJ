#include<stdio.h>
#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdio.h>
unsigned int fun(unsigned int n,unsigned int r)
{
	if(n>0)
	return (n%r+fun(n/r,r));
	return 0;
}

void f(int *p,int *q)
{
	p=q;
	*p=3;
}
int i=0,j=2;
int main()
{
    f(&i,&j);
	cout<<i<<" "<<j;
    return 0;
}
