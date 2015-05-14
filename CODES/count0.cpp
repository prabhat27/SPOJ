#include<iostream>
using namespace std;
int main()
{
	int arr[]={0,0,0,0,0,0,0};
	int *ptr,*start;
	ptr=arr+sizeof(ptr)+4;
	start=arr;
	int c=0;
	while(start!=ptr)
    {
	if(*start==0)
    c++;
    *start++;
    }
   cout<<c;
}
