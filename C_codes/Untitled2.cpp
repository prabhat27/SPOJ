#include<iostream>
using namespace std;
int fun(int i)
{
	switch(i)
	{
	default: { cout<<"RAM"<<i<<endl; return (fun(i-1)+fun(i-2));}; 
	case 1: ;
	case 2: ;
	}
	return 1;
}
int main()
{
	cout<<fun(5);
	return 0;
}
