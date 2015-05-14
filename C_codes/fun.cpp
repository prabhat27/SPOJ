#include<iostream>
using namespace std;
int fun(int n)
{
	static int r=n-1;
	if(n<=0)
	return 1;
	return r+fun(n-1);
}

int main()
{
	cout<<fun(5);
}
