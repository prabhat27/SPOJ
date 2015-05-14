#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> ls[10];
	list<int>::iterator it;
	
	int ar[]={2,4,6,12,14,16},i,k;
	for(i=0;i<6;i++)
	{
	 		k=ar[i]%10;
			ls[k].push_back(ar[i]);
	}

	for(i=0;i<10;i++)
	{
	    for(it=ls[i].begin();it!=ls[i].end();it++)
		cout<<*it<<" ";
		cout<<endl;
	}
}
