#include<iostream>
#include<stdio.h>
using namespace std;
# define x(a) a*a*a;
void swap(int *a,int *b)
{
	*a=(*a)+(*b);
	*b=(*a)-(*b);
	*a=(*a)-(*b);
}

int main()
{ 
   //x=2;
   char ch='a',ch1='d';
  cout<<ch*ch1;
   int arr[]={1,2};
   cout<<arr<<" "<<(&arr);
   //printf("%d",x);


}
